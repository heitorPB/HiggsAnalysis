import ROOT

class Style:
    def __init__(self, style, color):
        self.style = 22 + style
        self.color = color

    def apply(self, h):
        h.SetLineWidth(2)
        h.SetLineColor(self.color)
        h.SetMarkerColor(self.color)
        h.SetMarkerStyle(self.style)
        h.SetMarkerSize(1)
        

styles = [
    Style(3, ROOT.kBlack),
    Style(4, ROOT.kBlue),
    Style(5, ROOT.kRed),
    Style(1, ROOT.kGreen+2),
    Style(2, ROOT.kMagenta),
    Style(6, ROOT.kCyan),
    Style(7, ROOT.kYellow+2),
    Style(8, ROOT.kOrange+9),
    Style(9, ROOT.kOrange+3),
    Style(10, ROOT.kMagenta+3),
    Style(11, ROOT.kGray+2),
    Style(12, ROOT.kBlue+3),
    Style(13, ROOT.kOrange+1),
    Style(14, ROOT.kCyan-5),
    Style(0, ROOT.kBlue),
    ]

def applyStyle(h, ind):
    styles[ind].apply(h)
