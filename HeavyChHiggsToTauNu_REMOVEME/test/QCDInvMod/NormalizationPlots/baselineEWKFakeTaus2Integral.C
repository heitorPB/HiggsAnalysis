{
//=========Macro generated from canvas: baselineEWKFakeTaus2Integral/
//=========  (Sun Jul 20 15:00:29 2014) by ROOT version5.32/00
   TCanvas *baselineEWKFakeTaus2Integral = new TCanvas("baselineEWKFakeTaus2Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   baselineEWKFakeTaus2Integral->SetHighLightColor(2);
   baselineEWKFakeTaus2Integral->Range(-101.2658,-1.330679,531.6456,1.213006);
   baselineEWKFakeTaus2Integral->SetFillColor(0);
   baselineEWKFakeTaus2Integral->SetBorderMode(0);
   baselineEWKFakeTaus2Integral->SetBorderSize(2);
   baselineEWKFakeTaus2Integral->SetLogy();
   baselineEWKFakeTaus2Integral->SetTickx(1);
   baselineEWKFakeTaus2Integral->SetTicky(1);
   baselineEWKFakeTaus2Integral->SetLeftMargin(0.16);
   baselineEWKFakeTaus2Integral->SetRightMargin(0.05);
   baselineEWKFakeTaus2Integral->SetTopMargin(0.05);
   baselineEWKFakeTaus2Integral->SetBottomMargin(0.13);
   baselineEWKFakeTaus2Integral->SetFrameFillStyle(0);
   baselineEWKFakeTaus2Integral->SetFrameBorderMode(0);
   baselineEWKFakeTaus2Integral->SetFrameFillStyle(0);
   baselineEWKFakeTaus2Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__47 = new TH1F("hframe__47","",1000,0,500);
   hframe__47->SetMinimum(0.1);
   hframe__47->SetMaximum(12.18488);
   hframe__47->SetDirectory(0);
   hframe__47->SetStats(0);
   hframe__47->SetLineStyle(0);
   hframe__47->SetMarkerStyle(20);
   hframe__47->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__47->GetXaxis()->SetLabelFont(43);
   hframe__47->GetXaxis()->SetLabelOffset(0.007);
   hframe__47->GetXaxis()->SetLabelSize(27);
   hframe__47->GetXaxis()->SetTitleSize(33);
   hframe__47->GetXaxis()->SetTitleOffset(0.9);
   hframe__47->GetXaxis()->SetTitleFont(43);
   hframe__47->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__47->GetYaxis()->SetLabelFont(43);
   hframe__47->GetYaxis()->SetLabelOffset(0.007);
   hframe__47->GetYaxis()->SetLabelSize(27);
   hframe__47->GetYaxis()->SetTitleSize(33);
   hframe__47->GetYaxis()->SetTitleOffset(1.25);
   hframe__47->GetYaxis()->SetTitleFont(43);
   hframe__47->GetZaxis()->SetLabelFont(43);
   hframe__47->GetZaxis()->SetLabelOffset(0.007);
   hframe__47->GetZaxis()->SetLabelSize(27);
   hframe__47->GetZaxis()->SetTitleSize(33);
   hframe__47->GetZaxis()->SetTitleFont(43);
   hframe__47->Draw(" ");
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
      tex = new TLatex(0.4,0.7,"Integral = 33 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2 = new TH1F("baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2","#tau p_{T}=60..70",50,0,500);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(3,0.765247);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(4,0.5956875);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(5,0.276906);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(6,6.092441);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(7,3.241642);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(8,2.768377);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(9,1.975966);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(10,1.872906);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(11,1.709919);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(12,4.057788);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(13,0.7341205);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(14,2.700427);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(15,1.156475);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(16,1.813762);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(17,0.5445527);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(20,1.607687);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(21,0.0651216);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(23,1.09666);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(26,0.3830814);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(3,0.6390656);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(4,0.4016146);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(5,0.276906);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(6,2.933515);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(7,1.84257);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(8,1.266461);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(9,1.0592);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(10,1.086251);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(11,1.035567);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(12,1.811748);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(13,0.5088164);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(14,1.45537);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(15,0.8407622);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(16,1.062342);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(17,0.4778393);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(20,1.151899);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(21,0.0651216);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(23,0.8374891);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(26,0.3830814);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetEntries(70);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetFillColor(ci);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetLineWidth(2);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetMarkerStyle(20);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetMarkerSize(1.2);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitle("Events / 10 GeV");
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitleOffset(1.5);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsOnlyEWKFakeTaus/METBaselineTauIdAfterCollinearCutsOnlyEWKFakeTaus2->Draw("HIST same");
   
   TH1F *hframe__48 = new TH1F("hframe__48","",1000,0,500);
   hframe__48->SetMinimum(0.1);
   hframe__48->SetMaximum(12.18488);
   hframe__48->SetDirectory(0);
   hframe__48->SetStats(0);
   hframe__48->SetLineStyle(0);
   hframe__48->SetMarkerStyle(20);
   hframe__48->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__48->GetXaxis()->SetLabelFont(43);
   hframe__48->GetXaxis()->SetLabelOffset(0.007);
   hframe__48->GetXaxis()->SetLabelSize(27);
   hframe__48->GetXaxis()->SetTitleSize(33);
   hframe__48->GetXaxis()->SetTitleOffset(0.9);
   hframe__48->GetXaxis()->SetTitleFont(43);
   hframe__48->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__48->GetYaxis()->SetLabelFont(43);
   hframe__48->GetYaxis()->SetLabelOffset(0.007);
   hframe__48->GetYaxis()->SetLabelSize(27);
   hframe__48->GetYaxis()->SetTitleSize(33);
   hframe__48->GetYaxis()->SetTitleOffset(1.25);
   hframe__48->GetYaxis()->SetTitleFont(43);
   hframe__48->GetZaxis()->SetLabelFont(43);
   hframe__48->GetZaxis()->SetLabelOffset(0.007);
   hframe__48->GetZaxis()->SetLabelSize(27);
   hframe__48->GetZaxis()->SetTitleSize(33);
   hframe__48->GetZaxis()->SetTitleFont(43);
   hframe__48->Draw("sameaxis");
   baselineEWKFakeTaus2Integral->Modified();
   baselineEWKFakeTaus2Integral->cd();
   baselineEWKFakeTaus2Integral->SetSelected(baselineEWKFakeTaus2Integral);
}
