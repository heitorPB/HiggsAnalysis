{
//=========Macro generated from canvas: Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus/Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus
//=========  (Wed Aug 13 16:33:40 2014) by ROOT version5.32/00
   TCanvas *Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus = new TCanvas("Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus", "Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus",0,0,600,750);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetHighLightColor(2);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->Range(0,0,1,1);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetFillColor(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetBorderMode(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetBorderSize(2);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetTickx(1);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetTicky(1);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetLeftMargin(0.16);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetRightMargin(0.05);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetTopMargin(0.05);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetBottomMargin(0.13);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetFrameFillStyle(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2
   TPad *Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2 = new TPad("Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2", "Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2",0.01,0.01,0.99,0.302);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->Draw();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->cd();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->Range(-81.01265,0.7028136,425.3165,1.140707);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetFillColor(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetFillStyle(4000);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetBorderMode(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetBorderSize(2);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetTickx(1);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetTicky(1);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetLeftMargin(0.16);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetRightMargin(0.05);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetTopMargin(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetBottomMargin(0.29);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetFrameFillStyle(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetFrameBorderMode(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetFrameFillStyle(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->SetFrameBorderMode(0);
   
   TH1F *hframe__71 = new TH1F("hframe__71","",1000,0,400);
   hframe__71->SetMinimum(0.8298027);
   hframe__71->SetMaximum(1.140707);
   hframe__71->SetDirectory(0);
   hframe__71->SetStats(0);
   hframe__71->SetLineStyle(0);
   hframe__71->SetMarkerStyle(20);
   hframe__71->GetXaxis()->SetTitle("m_{T}(tau,MET), GeV/c^{2}");
   hframe__71->GetXaxis()->SetLabelFont(43);
   hframe__71->GetXaxis()->SetLabelOffset(0.007);
   hframe__71->GetXaxis()->SetLabelSize(27);
   hframe__71->GetXaxis()->SetTitleSize(33);
   hframe__71->GetXaxis()->SetTitleOffset(2.925);
   hframe__71->GetXaxis()->SetTitleFont(43);
   hframe__71->GetYaxis()->SetTitle("Ratio");
   hframe__71->GetYaxis()->SetNdivisions(505);
   hframe__71->GetYaxis()->SetLabelFont(43);
   hframe__71->GetYaxis()->SetLabelOffset(0.007);
   hframe__71->GetYaxis()->SetLabelSize(21);
   hframe__71->GetYaxis()->SetTitleSize(33);
   hframe__71->GetYaxis()->SetTitleOffset(1.796875);
   hframe__71->GetYaxis()->SetTitleFont(43);
   hframe__71->GetZaxis()->SetLabelFont(43);
   hframe__71->GetZaxis()->SetLabelOffset(0.007);
   hframe__71->GetZaxis()->SetLabelSize(27);
   hframe__71->GetZaxis()->SetTitleSize(33);
   hframe__71->GetZaxis()->SetTitleFont(43);
   hframe__71->Draw(" ");
   Double_t xAxis51[11] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 200, 400}; 
   
   TH1F *QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72 = new TH1F("QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72","#tau p_{T}<50",10, xAxis51);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(1,1.034032);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(2,1.037006);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(3,0.991746);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(4,1.015073);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(5,0.9972583);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(6,1.014132);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(7,0.9412873);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(8,1.012255);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(9,0.9789543);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(10,0.8298027);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinContent(11,0.9523166);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(1,0.2145485);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(2,0.1867345);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(3,0.110781);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(4,0.09912395);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(5,0.08782472);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(6,0.07396552);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(7,0.08186115);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(8,0.1005176);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(9,0.09978163);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(10,0.1510138);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetBinError(11,0.7835918);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetEntries(585.5402);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetDirectory(0);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetLineWidth(4);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetMarkerStyle(20);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->SetMarkerSize(1.2);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetXaxis()->SetTitle("m_{T}(tau,MET), GeV/c^{2}");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetXaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetXaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetXaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetXaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetYaxis()->SetTitle("Ratio");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetYaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetYaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetYaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetYaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetZaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetZaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetZaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->GetZaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.__72->Draw("EP same");
   Double_t xAxis52[11] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 200, 400}; 
   
   TH1F *QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73 = new TH1F("QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73","#tau p_{T}<50",10, xAxis52);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(1,1.034032);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(2,1.037006);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(3,0.991746);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(4,1.015073);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(5,0.9972583);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(6,1.014132);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(7,0.9412873);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(8,1.012255);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(9,0.9789543);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(10,0.8298027);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinContent(11,0.9523166);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(1,0.2145485);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(2,0.1867345);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(3,0.110781);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(4,0.09912395);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(5,0.08782472);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(6,0.07396552);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(7,0.08186115);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(8,0.1005176);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(9,0.09978163);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(10,0.1510138);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetBinError(11,0.7835918);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetEntries(585.5402);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetDirectory(0);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetLineColor(14);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetLineWidth(2);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetMarkerStyle(20);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->SetMarkerSize(1.2);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetXaxis()->SetTitle("m_{T}(tau,MET), GeV/c^{2}");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetXaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetXaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetXaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetXaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetYaxis()->SetTitle("Ratio");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetYaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetYaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetYaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetYaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetZaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetZaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetZaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->GetZaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)__73->Draw("EP same");
   
   TGraph *graph = new TGraph(2);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineStyle(3);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   graph->SetPoint(0,0,1);
   graph->SetPoint(1,400,1);
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","Graph",100,0,440);
   Graph_Graph11->SetMinimum(0.9);
   Graph_Graph11->SetMaximum(2.1);
   Graph_Graph11->SetDirectory(0);
   Graph_Graph11->SetStats(0);
   Graph_Graph11->SetLineStyle(0);
   Graph_Graph11->SetMarkerStyle(20);
   Graph_Graph11->GetXaxis()->SetLabelFont(43);
   Graph_Graph11->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph11->GetXaxis()->SetLabelSize(27);
   Graph_Graph11->GetXaxis()->SetTitleSize(33);
   Graph_Graph11->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph11->GetXaxis()->SetTitleFont(43);
   Graph_Graph11->GetYaxis()->SetLabelFont(43);
   Graph_Graph11->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph11->GetYaxis()->SetLabelSize(27);
   Graph_Graph11->GetYaxis()->SetTitleSize(33);
   Graph_Graph11->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph11->GetYaxis()->SetTitleFont(43);
   Graph_Graph11->GetZaxis()->SetLabelFont(43);
   Graph_Graph11->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph11->GetZaxis()->SetLabelSize(27);
   Graph_Graph11->GetZaxis()->SetTitleSize(33);
   Graph_Graph11->GetZaxis()->SetTitleFont(43);
   graph->SetHistogram(Graph_Graph11);
   
   graph->Draw("l");
   
   TH1F *hframe__74 = new TH1F("hframe__74","",1000,0,400);
   hframe__74->SetMinimum(0.8298027);
   hframe__74->SetMaximum(1.140707);
   hframe__74->SetDirectory(0);
   hframe__74->SetStats(0);
   hframe__74->SetLineStyle(0);
   hframe__74->SetMarkerStyle(20);
   hframe__74->GetXaxis()->SetTitle("m_{T}(tau,MET), GeV/c^{2}");
   hframe__74->GetXaxis()->SetLabelFont(43);
   hframe__74->GetXaxis()->SetLabelOffset(0.007);
   hframe__74->GetXaxis()->SetLabelSize(27);
   hframe__74->GetXaxis()->SetTitleSize(33);
   hframe__74->GetXaxis()->SetTitleOffset(2.925);
   hframe__74->GetXaxis()->SetTitleFont(43);
   hframe__74->GetYaxis()->SetTitle("Ratio");
   hframe__74->GetYaxis()->SetNdivisions(505);
   hframe__74->GetYaxis()->SetLabelFont(43);
   hframe__74->GetYaxis()->SetLabelOffset(0.007);
   hframe__74->GetYaxis()->SetLabelSize(21);
   hframe__74->GetYaxis()->SetTitleSize(33);
   hframe__74->GetYaxis()->SetTitleOffset(1.796875);
   hframe__74->GetYaxis()->SetTitleFont(43);
   hframe__74->GetZaxis()->SetLabelFont(43);
   hframe__74->GetZaxis()->SetLabelOffset(0.007);
   hframe__74->GetZaxis()->SetLabelSize(27);
   hframe__74->GetZaxis()->SetTitleSize(33);
   hframe__74->GetZaxis()->SetTitleFont(43);
   hframe__74->Draw("sameaxis");
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_2->Modified();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->cd();
  
// ------------>Primitives in pad: coverpad
   coverpad = new TPad("coverpad", "coverpad",0.065,0.285,0.165,0.33);
   coverpad->Draw();
   coverpad->cd();
   coverpad->Range(0,0,1,1);
   coverpad->SetFillColor(0);
   coverpad->SetBorderMode(0);
   coverpad->SetBorderSize(2);
   coverpad->SetTickx(1);
   coverpad->SetTicky(1);
   coverpad->SetLeftMargin(0.16);
   coverpad->SetRightMargin(0.05);
   coverpad->SetTopMargin(0.05);
   coverpad->SetBottomMargin(0.13);
   coverpad->SetFrameFillStyle(0);
   coverpad->SetFrameBorderMode(0);
   coverpad->Modified();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->cd();
  
// ------------>Primitives in pad: Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1 = new TPad("Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1", "Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1",0.01,0.2,0.99,0.99);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->Draw();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->cd();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->Range(-81.01265,-1.061372,425.3165,27.82638);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetFillColor(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetFillStyle(4000);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetBorderMode(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetBorderSize(2);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetTickx(1);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetTicky(1);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetLeftMargin(0.16);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetRightMargin(0.05);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetTopMargin(0.05);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetBottomMargin(0.13);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetFrameFillStyle(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetFrameBorderMode(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetFrameFillStyle(0);
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->SetFrameBorderMode(0);
   
   TH1F *hframe__75 = new TH1F("hframe__75","",1000,0,400);
   hframe__75->SetMinimum(2.694036);
   hframe__75->SetMaximum(26.38199);
   hframe__75->SetDirectory(0);
   hframe__75->SetStats(0);
   hframe__75->SetLineStyle(0);
   hframe__75->SetMarkerStyle(20);
   hframe__75->GetXaxis()->SetLabelFont(43);
   hframe__75->GetXaxis()->SetLabelOffset(0.007);
   hframe__75->GetXaxis()->SetLabelSize(0);
   hframe__75->GetXaxis()->SetTitleSize(0);
   hframe__75->GetXaxis()->SetTitleOffset(0.9);
   hframe__75->GetXaxis()->SetTitleFont(43);
   hframe__75->GetYaxis()->SetTitle("N_{events}");
   hframe__75->GetYaxis()->SetLabelFont(43);
   hframe__75->GetYaxis()->SetLabelOffset(0.007);
   hframe__75->GetYaxis()->SetLabelSize(27);
   hframe__75->GetYaxis()->SetTitleSize(33);
   hframe__75->GetYaxis()->SetTitleOffset(1.796875);
   hframe__75->GetYaxis()->SetTitleFont(43);
   hframe__75->GetZaxis()->SetLabelFont(43);
   hframe__75->GetZaxis()->SetLabelOffset(0.007);
   hframe__75->GetZaxis()->SetLabelSize(27);
   hframe__75->GetZaxis()->SetTitleSize(33);
   hframe__75->GetZaxis()->SetTitleFont(43);
   hframe__75->Draw(" ");
   TLatex *   tex = new TLatex(0.65,0.3,"R_{BB} Loose");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(25);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.62,0.96,"CMS Preliminary");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.19,0.96,"#sqrt{s} = 8 TeV");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.43,0.96,"L=4.4 fb^{-1}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   Double_t xAxis53[11] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 200, 400}; 
   
   TH1F *QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal. = new TH1F("QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.","#tau p_{T}<50",10, xAxis53);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(1,2.785719);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(2,3.813843);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(3,10.04792);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(4,12.79853);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(5,16.65346);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(6,23.98363);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(7,18.42597);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(8,12.22635);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(9,11.70136);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(10,5.350437);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinContent(11,0.1468932);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(1,0.4089875);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(2,0.4855243);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(3,0.7803209);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(4,0.8781042);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(5,1.005691);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(6,1.205899);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(7,1.022769);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(8,0.8283683);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(9,0.7946149);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(10,0.5264743);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetBinError(11,0.08480885);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetEntries(2038.923);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetLineWidth(4);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetMarkerStyle(20);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->SetMarkerSize(1.2);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetXaxis()->SetTitle("m_{T}(tau,MET), GeV/c^{2}");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetXaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetXaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetXaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetXaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetYaxis()->SetTitle("N_{events}");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetYaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetYaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetYaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetYaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetZaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetZaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetZaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->GetZaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.->Draw("HIST same");
   Double_t xAxis54[11] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 200, 400}; 
   
   TH1F *QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau) = new TH1F("QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)","#tau p_{T}<50",10, xAxis54);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(1,2.785719);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(2,3.813843);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(3,10.04792);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(4,12.79853);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(5,16.65346);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(6,23.98363);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(7,18.42597);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(8,12.22635);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(9,11.70136);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(10,5.350437);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinContent(11,0.1468932);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(1,0.4089875);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(2,0.4855243);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(3,0.7803209);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(4,0.8781042);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(5,1.005691);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(6,1.205899);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(7,1.022769);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(8,0.8283683);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(9,0.7946149);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(10,0.5264743);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetBinError(11,0.08480885);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetEntries(2038.923);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetLineColor(14);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetLineWidth(2);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetMarkerStyle(20);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->SetMarkerSize(1.2);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetXaxis()->SetTitle("m_{T}(tau,MET), GeV/c^{2}");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetXaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetXaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetXaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetXaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetYaxis()->SetTitle("N_{events}");
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetYaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetYaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetYaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetYaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetZaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetZaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetZaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->GetZaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)->Draw("HIST same");
   Double_t xAxis55[11] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 200, 400}; 
   
   TH1F *QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau) = new TH1F("QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)","#tau p_{T}<50",10, xAxis55);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(1,2.694036);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(2,3.677743);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(3,10.13155);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(4,12.60848);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(5,16.69924);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(6,23.64941);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(7,19.57529);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(8,12.07833);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(9,11.95292);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(10,6.447843);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinContent(11,0.1542483);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(1,0.3949873);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(2,0.4683706);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(3,0.8134629);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(4,0.8761411);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(5,1.070417);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(6,1.249486);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(7,1.310563);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(8,0.8768385);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(9,0.9085457);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(10,0.9871152);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetBinError(11,0.09043094);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetEntries(2026.691);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetLineColor(2);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetLineWidth(2);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetMarkerStyle(20);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->SetMarkerSize(1.2);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetXaxis()->SetTitle("m_{T}(tau,MET), GeV/c^{2}");
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetXaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetXaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetXaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetXaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetYaxis()->SetTitle("N_{events}");
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetYaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetYaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetYaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetYaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetZaxis()->SetLabelFont(42);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetZaxis()->SetLabelSize(0.035);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetZaxis()->SetTitleSize(0.035);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->GetZaxis()->SetTitleFont(42);
   QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)->Draw("HIST same");
   
   TLegend *leg = new TLegend(0.38,0.67,0.58,0.97,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(4000);
   TLegendEntry *entry=leg->AddEntry("QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)","QCD(Data)+EWK+t#bar{t}(MC, mis-ID. #tau)","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)","QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau)","l");
   entry->SetLineColor(14);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.","QCD(Data)+EWK+t#bar{t}(Data, mis-ID. #tau), q-g bal.","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   
   TH1F *hframe__76 = new TH1F("hframe__76","",1000,0,400);
   hframe__76->SetMinimum(2.694036);
   hframe__76->SetMaximum(26.38199);
   hframe__76->SetDirectory(0);
   hframe__76->SetStats(0);
   hframe__76->SetLineStyle(0);
   hframe__76->SetMarkerStyle(20);
   hframe__76->GetXaxis()->SetLabelFont(43);
   hframe__76->GetXaxis()->SetLabelOffset(0.007);
   hframe__76->GetXaxis()->SetLabelSize(0);
   hframe__76->GetXaxis()->SetTitleSize(0);
   hframe__76->GetXaxis()->SetTitleOffset(0.9);
   hframe__76->GetXaxis()->SetTitleFont(43);
   hframe__76->GetYaxis()->SetTitle("N_{events}");
   hframe__76->GetYaxis()->SetLabelFont(43);
   hframe__76->GetYaxis()->SetLabelOffset(0.007);
   hframe__76->GetYaxis()->SetLabelSize(27);
   hframe__76->GetYaxis()->SetTitleSize(33);
   hframe__76->GetYaxis()->SetTitleOffset(1.796875);
   hframe__76->GetYaxis()->SetTitleFont(43);
   hframe__76->GetZaxis()->SetLabelFont(43);
   hframe__76->GetZaxis()->SetLabelOffset(0.007);
   hframe__76->GetZaxis()->SetLabelSize(27);
   hframe__76->GetZaxis()->SetTitleSize(33);
   hframe__76->GetZaxis()->SetTitleFont(43);
   hframe__76->Draw("sameaxis");
   
   TH1F *hframe__77 = new TH1F("hframe__77","",1000,0,400);
   hframe__77->SetMinimum(2.694036);
   hframe__77->SetMaximum(26.38199);
   hframe__77->SetDirectory(0);
   hframe__77->SetStats(0);
   hframe__77->SetLineStyle(0);
   hframe__77->SetMarkerStyle(20);
   hframe__77->GetXaxis()->SetLabelFont(43);
   hframe__77->GetXaxis()->SetLabelOffset(0.007);
   hframe__77->GetXaxis()->SetLabelSize(0);
   hframe__77->GetXaxis()->SetTitleSize(0);
   hframe__77->GetXaxis()->SetTitleOffset(0.9);
   hframe__77->GetXaxis()->SetTitleFont(43);
   hframe__77->GetYaxis()->SetTitle("N_{events}");
   hframe__77->GetYaxis()->SetLabelFont(43);
   hframe__77->GetYaxis()->SetLabelOffset(0.007);
   hframe__77->GetYaxis()->SetLabelSize(27);
   hframe__77->GetYaxis()->SetTitleSize(33);
   hframe__77->GetYaxis()->SetTitleOffset(1.796875);
   hframe__77->GetYaxis()->SetTitleFont(43);
   hframe__77->GetZaxis()->SetLabelFont(43);
   hframe__77->GetZaxis()->SetLabelOffset(0.007);
   hframe__77->GetZaxis()->SetLabelSize(27);
   hframe__77->GetZaxis()->SetTitleSize(33);
   hframe__77->GetZaxis()->SetTitleFont(43);
   hframe__77->Draw("sameaxis");
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus_1->Modified();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->cd();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->Modified();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->cd();
   Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus->SetSelected(Mt_DataDrivenVsMC_w=1_QCDTailKillerLoosePlus);
}
