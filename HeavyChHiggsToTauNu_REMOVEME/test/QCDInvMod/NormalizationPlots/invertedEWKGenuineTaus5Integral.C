{
//=========Macro generated from canvas: invertedEWKGenuineTaus5Integral/
//=========  (Sun Jul 20 15:00:37 2014) by ROOT version5.32/00
   TCanvas *invertedEWKGenuineTaus5Integral = new TCanvas("invertedEWKGenuineTaus5Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   invertedEWKGenuineTaus5Integral->SetHighLightColor(2);
   invertedEWKGenuineTaus5Integral->Range(-101.2658,-1.3658,531.6456,1.448043);
   invertedEWKGenuineTaus5Integral->SetFillColor(0);
   invertedEWKGenuineTaus5Integral->SetBorderMode(0);
   invertedEWKGenuineTaus5Integral->SetBorderSize(2);
   invertedEWKGenuineTaus5Integral->SetLogy();
   invertedEWKGenuineTaus5Integral->SetTickx(1);
   invertedEWKGenuineTaus5Integral->SetTicky(1);
   invertedEWKGenuineTaus5Integral->SetLeftMargin(0.16);
   invertedEWKGenuineTaus5Integral->SetRightMargin(0.05);
   invertedEWKGenuineTaus5Integral->SetTopMargin(0.05);
   invertedEWKGenuineTaus5Integral->SetBottomMargin(0.13);
   invertedEWKGenuineTaus5Integral->SetFrameFillStyle(0);
   invertedEWKGenuineTaus5Integral->SetFrameBorderMode(0);
   invertedEWKGenuineTaus5Integral->SetFrameFillStyle(0);
   invertedEWKGenuineTaus5Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__93 = new TH1F("hframe__93","",1000,0,500);
   hframe__93->SetMinimum(0.1);
   hframe__93->SetMaximum(20.29322);
   hframe__93->SetDirectory(0);
   hframe__93->SetStats(0);
   hframe__93->SetLineStyle(0);
   hframe__93->SetMarkerStyle(20);
   hframe__93->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__93->GetXaxis()->SetLabelFont(43);
   hframe__93->GetXaxis()->SetLabelOffset(0.007);
   hframe__93->GetXaxis()->SetLabelSize(27);
   hframe__93->GetXaxis()->SetTitleSize(33);
   hframe__93->GetXaxis()->SetTitleOffset(0.9);
   hframe__93->GetXaxis()->SetTitleFont(43);
   hframe__93->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__93->GetYaxis()->SetLabelFont(43);
   hframe__93->GetYaxis()->SetLabelOffset(0.007);
   hframe__93->GetYaxis()->SetLabelSize(27);
   hframe__93->GetYaxis()->SetTitleSize(33);
   hframe__93->GetYaxis()->SetTitleOffset(1.25);
   hframe__93->GetYaxis()->SetTitleFont(43);
   hframe__93->GetZaxis()->SetLabelFont(43);
   hframe__93->GetZaxis()->SetLabelOffset(0.007);
   hframe__93->GetZaxis()->SetLabelSize(27);
   hframe__93->GetZaxis()->SetTitleSize(33);
   hframe__93->GetZaxis()->SetTitleFont(43);
   hframe__93->Draw(" ");
   TLatex *   tex = new TLatex(0.62,0.96,"CMS Preliminary");
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
      tex = new TLatex(0.43,0.96,"L=20 fb^{-1}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0.7,"Integral = 100 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5 = new TH1F("Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5","#tau p_{T}=100..120",50,0,500);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(2,0.01488982);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(3,0.3249621);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(4,3.034453);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(5,0.9483662);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(6,2.260387);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(7,2.209904);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(8,5.45991);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(9,3.720376);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(10,6.817806);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(11,2.922797);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(12,3.966958);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(13,3.773311);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(14,6.293347);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(15,9.659235);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(16,10.14661);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(17,3.749935);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(18,5.126378);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(19,7.225852);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(20,3.04036);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(21,4.142743);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(22,2.334121);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(23,2.024163);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(24,0.3567519);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(25,1.213399);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(26,0.1332983);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(27,1.456627);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(28,2.293188);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(29,0.3478764);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(31,0.1090433);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(32,1.034889);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(33,1.168283);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(34,0.3506965);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(35,0.2894717);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(36,0.3626453);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(37,0.3620614);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(39,0.1282558);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(40,0.004094242);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(41,0.6575221);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(42,0.4038803);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(45,0.3328371);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinContent(51,0.02962778);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(2,0.01488982);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(3,0.2549523);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(4,2.226529);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(5,0.5348753);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(6,1.040199);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(7,0.9762036);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(8,1.967911);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(9,1.381409);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(10,3.945894);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(11,1.140764);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(12,1.311364);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(13,1.318834);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(14,1.623504);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(15,2.332258);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(16,3.131797);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(17,1.302165);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(18,1.762511);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(19,1.831979);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(20,1.09079);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(21,1.428985);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(22,0.9818731);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(23,0.9641027);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(24,0.3567519);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(25,0.5991095);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(26,0.1332983);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(27,0.6395474);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(28,1.218274);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(29,0.3478764);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(31,0.1090433);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(32,0.6228761);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(33,0.7476419);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(34,0.3506965);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(35,0.2894717);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(36,0.3626453);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(37,0.3620614);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(39,0.1282558);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(40,0.004094241);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(41,0.6575222);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(42,0.4038803);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(45,0.3328372);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetBinError(51,0.02962778);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetEntries(280);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetFillColor(ci);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetLineWidth(2);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetMarkerStyle(20);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->SetMarkerSize(1.2);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetXaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetXaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetXaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetXaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetYaxis()->SetTitle("Events / 10 GeV");
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetYaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetYaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetYaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetYaxis()->SetTitleOffset(1.5);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetYaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetZaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetZaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetZaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->GetZaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus5->Draw("HIST same");
   
   TH1F *hframe__94 = new TH1F("hframe__94","",1000,0,500);
   hframe__94->SetMinimum(0.1);
   hframe__94->SetMaximum(20.29322);
   hframe__94->SetDirectory(0);
   hframe__94->SetStats(0);
   hframe__94->SetLineStyle(0);
   hframe__94->SetMarkerStyle(20);
   hframe__94->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__94->GetXaxis()->SetLabelFont(43);
   hframe__94->GetXaxis()->SetLabelOffset(0.007);
   hframe__94->GetXaxis()->SetLabelSize(27);
   hframe__94->GetXaxis()->SetTitleSize(33);
   hframe__94->GetXaxis()->SetTitleOffset(0.9);
   hframe__94->GetXaxis()->SetTitleFont(43);
   hframe__94->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__94->GetYaxis()->SetLabelFont(43);
   hframe__94->GetYaxis()->SetLabelOffset(0.007);
   hframe__94->GetYaxis()->SetLabelSize(27);
   hframe__94->GetYaxis()->SetTitleSize(33);
   hframe__94->GetYaxis()->SetTitleOffset(1.25);
   hframe__94->GetYaxis()->SetTitleFont(43);
   hframe__94->GetZaxis()->SetLabelFont(43);
   hframe__94->GetZaxis()->SetLabelOffset(0.007);
   hframe__94->GetZaxis()->SetLabelSize(27);
   hframe__94->GetZaxis()->SetTitleSize(33);
   hframe__94->GetZaxis()->SetTitleFont(43);
   hframe__94->Draw("sameaxis");
   invertedEWKGenuineTaus5Integral->Modified();
   invertedEWKGenuineTaus5Integral->cd();
   invertedEWKGenuineTaus5Integral->SetSelected(invertedEWKGenuineTaus5Integral);
}
