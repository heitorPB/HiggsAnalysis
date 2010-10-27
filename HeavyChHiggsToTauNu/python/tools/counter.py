import ROOT

def histoToCounter(histo):
    ret = []

    for bin in xrange(1, histo.GetNbinsX()+1):
        ret.append( (histo.GetXaxis().GetBinLabel(bin),
                     long(histo.GetBinContent(bin))) )

    return ret

def histoToDict(histo):
    ret = {}

    for bin in xrange(1, histo.GetNbinsX()+1):
        ret[histo.GetXaxis().GetBinLabel(bin)] = histo.GetBinContent(bin)

    return ret

def rescaleInfo(d):
    factor = 1/d["control"]

    ret = {}
    for k, v in d.iteritems():
        ret[k] = v*factor

    return ret

class Dataset:
    def __init__(self, name, info, file):
        self.name = name
        self.info = info
        self.nAllEvents = None
        self.file = file

    def getName(self):
        return self.name

    def setName(self, name):
        self.name = name

    def setCrossSection(self, value):
        if self.isData():
            raise Exception("Should not set cross section for data dataset %s (has luminosity)" % self.name)
        self.info["crossSection"] = value

    def getCrossSection(self):
        return self.info["crossSection"]

    def setLuminosity(self, value):
        if self.isMC():
            raise Exception("Should not set luminosity for MC dataset %s (has crossSection)" % self.name)
        self.info["luminosity"] = value

    def getLuminosity(self):
        return self.info["luminosity"]

    def isData(self):
        return "luminosity" in self.info

    def isMC(self):
        return "crossSection" in self.info

    def setAllEvents(self, allevTuple):
        self.nAllEvents = allevTuple[1]

    def getNormFactor(self):
        return self.getCrossSection() / self.nAllEvents

    def getTFile(self):
        return self.file

class Counter:
    def __init__(self, counter):
        self.data = counter
        self.dataset = None

    def setDataset(self, dataset):
        self.dataset = dataset

    def getNames(self):
        return [x[0] for x in self.data]

    def getDataset(self):
        return self.dataset

    def getCounterValue(self, index):
        return self.data[index][1]

    def getCounterCrossSection(self, index):
        return self.dataset.getNormFactor() * self.getCounterValue(index)

class DatasetCounter:
    def __init__(self, dataset):
        self.dataset = dataset
        self.mainCounter = None
        self.subCounters = {}

    def setMainCounter(self, counter):
        counter.setDataset(self.dataset)
        self.mainCounter = counter

    def addSubCounter(self, name, counter):
        counter.setDataset(self.dataset)
        self.subCounters[name] = counter

    def getDataset(self):
        return self.dataset

    def getMainCounter(self):
        return self.mainCounter

    def getSubCounterNames(self):
        return self.subCounters.keys()

    def getSubCounter(self, name):
        return self.subCounters[name]

class Counters:
    def __init__(self):
        self.counters = []

    def addCounter(self, counter):
        self.counters.append(counter)

    def getDatasets(self):
        return [x.getDataset() for x in self.counters]

    def getMainCounters(self):
        return [x.getMainCounter() for x in self.counters]

    def getSubCounterNames(self):
        if len(self.counters) == 0:
            return []

        names = self.counters[0].getSubCounterNames()
        # Check that the subcounter names for all datasets are same
        for c in self.counters[1:]:
            cnames = c.getSubCounterNames()
            if len(names) != len(cnames):
                raise Exception("The lengths of subcounters are not equal! Dataset %s has %d, %s has %d" % (self.counters[0].getDataset().getName(), len(names), c.getDataset().getName(), len(cnames)))
            for ind, val in enumerate(names):
                if val != cnames[ind]:
                    raise Exception("The subcounter names are not equal!")

        return names

    def getSubCounters(self, name):
        return [x.getSubCounter(name) for x in self.counters]

def readDataset(fname, counterDir, datasetname, crossSections):
    f = ROOT.TFile.Open(fname)
    if f == None:
        raise Exception("Unable to open ROOT file '%s'"%fname)
    if f.Get("configInfo") == None:
        raise Exception("Unable to find directory 'configInfo' from ROOT file '%s'"%fname)

    info = rescaleInfo(histoToDict(f.Get("configInfo").Get("configinfo")))

    dataset = Dataset(datasetname, info, f)
    if datasetname in crossSections:
        dataset.setCrossSection(crossSections[datasetname])

    if f.Get(counterDir) == None:
        raise Exception("Unable to find directory '%s' from ROOT file '%s'" % (counterDir, fname))

    ctr = histoToCounter(f.Get(counterDir).Get("counter"))
    dataset.setAllEvents(ctr[0])

    return dataset

def readCountersFileDir(fname, counterDir, datasetname, crossSections):
    dataset = readDataset(fname, counterDir, datasetname, crossSections)
    f = dataset.getTFile()

    dctr = DatasetCounter(dataset)

    directory = f.Get(counterDir)
    dirlist = directory.GetListOfKeys()
    diriter = dirlist.MakeIterator()
    key = diriter.Next()

    while key:
        # main counter
        if key.GetName() == "counter":
            dctr.setMainCounter(Counter(histoToCounter(key.ReadObj())))
        else:
            dctr.addSubCounter(key.GetName(), Counter(histoToCounter(key.ReadObj())))
        key = diriter.Next()

    return dctr