{
//=========Macro generated from canvas: invertedEWKFakeTaustaup_Teq60to70Integral/
//=========  (Wed Aug 13 15:49:52 2014) by ROOT version5.32/00
   TCanvas *invertedEWKFakeTaustaup_Teq60to70Integral = new TCanvas("invertedEWKFakeTaustaup_Teq60to70Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetHighLightColor(2);
   invertedEWKFakeTaustaup_Teq60to70Integral->Range(-101.2658,-1.276775,531.6456,0.8522613);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetFillColor(0);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetBorderMode(0);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetBorderSize(2);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetLogy();
   invertedEWKFakeTaustaup_Teq60to70Integral->SetTickx(1);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetTicky(1);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetLeftMargin(0.16);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetRightMargin(0.05);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetTopMargin(0.05);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetBottomMargin(0.13);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetFrameFillStyle(0);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetFrameBorderMode(0);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetFrameFillStyle(0);
   invertedEWKFakeTaustaup_Teq60to70Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__41 = new TH1F("hframe__41","",1000,0,500);
   hframe__41->SetMinimum(0.1);
   hframe__41->SetMaximum(5.569414);
   hframe__41->SetDirectory(0);
   hframe__41->SetStats(0);
   hframe__41->SetLineStyle(0);
   hframe__41->SetMarkerStyle(20);
   hframe__41->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__41->GetXaxis()->SetLabelFont(43);
   hframe__41->GetXaxis()->SetLabelOffset(0.007);
   hframe__41->GetXaxis()->SetLabelSize(27);
   hframe__41->GetXaxis()->SetTitleSize(33);
   hframe__41->GetXaxis()->SetTitleOffset(0.9);
   hframe__41->GetXaxis()->SetTitleFont(43);
   hframe__41->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__41->GetYaxis()->SetLabelFont(43);
   hframe__41->GetYaxis()->SetLabelOffset(0.007);
   hframe__41->GetYaxis()->SetLabelSize(27);
   hframe__41->GetYaxis()->SetTitleSize(33);
   hframe__41->GetYaxis()->SetTitleOffset(1.25);
   hframe__41->GetYaxis()->SetTitleFont(43);
   hframe__41->GetZaxis()->SetLabelFont(43);
   hframe__41->GetZaxis()->SetLabelOffset(0.007);
   hframe__41->GetZaxis()->SetLabelSize(27);
   hframe__41->GetZaxis()->SetTitleSize(33);
   hframe__41->GetZaxis()->SetTitleFont(43);
   hframe__41->Draw(" ");
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
      tex = new TLatex(0.43,0.96,"L=4.4 fb^{-1}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0.7,"Integral = 28 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2 = new TH1F("Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2","#tau p_{T}=60..70",50,0,500);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(1,0.1153132);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(2,0.6396906);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(3,1.169261);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(4,1.11379);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(5,0.8615965);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(6,1.38874);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(7,1.528503);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(8,2.092985);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(9,2.666056);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(10,1.959856);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(11,2.466551);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(12,2.784707);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(13,1.385075);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(14,1.544197);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(15,1.574352);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(16,1.053053);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(17,0.7253551);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(18,0.5562253);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(19,0.474306);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(20,0.5233843);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(21,0.2968612);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(22,0.3267692);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(23,0.1934911);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(24,0.0149484);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(25,0.06412233);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(26,0.09698842);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(28,0.1477498);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(31,0.007343246);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(32,0.1538751);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(33,0.08117826);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinContent(38,0.08161934);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(1,0.08981808);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(2,0.2167601);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(3,0.9211621);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(4,0.3279544);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(5,0.2279697);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(6,0.3411959);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(7,0.6518768);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(8,0.5916235);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(9,0.5895864);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(10,0.4184985);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(11,0.5689325);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(12,0.71348);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(13,0.3619861);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(14,0.4073902);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(15,0.6119908);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(16,0.3295725);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(17,0.2812706);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(18,0.2444567);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(19,0.1953774);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(20,0.2290014);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(21,0.1552447);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(22,0.157005);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(23,0.1270064);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(24,0.01425528);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(25,0.06412233);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(26,0.08569802);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(28,0.1477498);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(31,0.007343245);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(32,0.1538751);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(33,0.08117826);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetBinError(38,0.08161934);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetEntries(401);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetFillColor(ci);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetLineWidth(2);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetMarkerStyle(20);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->SetMarkerSize(1.2);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetXaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitle("Events / 10 GeV");
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitleOffset(1.5);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetYaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->GetZaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus2->Draw("HIST same");
   
   TH1F *hframe__42 = new TH1F("hframe__42","",1000,0,500);
   hframe__42->SetMinimum(0.1);
   hframe__42->SetMaximum(5.569414);
   hframe__42->SetDirectory(0);
   hframe__42->SetStats(0);
   hframe__42->SetLineStyle(0);
   hframe__42->SetMarkerStyle(20);
   hframe__42->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__42->GetXaxis()->SetLabelFont(43);
   hframe__42->GetXaxis()->SetLabelOffset(0.007);
   hframe__42->GetXaxis()->SetLabelSize(27);
   hframe__42->GetXaxis()->SetTitleSize(33);
   hframe__42->GetXaxis()->SetTitleOffset(0.9);
   hframe__42->GetXaxis()->SetTitleFont(43);
   hframe__42->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__42->GetYaxis()->SetLabelFont(43);
   hframe__42->GetYaxis()->SetLabelOffset(0.007);
   hframe__42->GetYaxis()->SetLabelSize(27);
   hframe__42->GetYaxis()->SetTitleSize(33);
   hframe__42->GetYaxis()->SetTitleOffset(1.25);
   hframe__42->GetYaxis()->SetTitleFont(43);
   hframe__42->GetZaxis()->SetLabelFont(43);
   hframe__42->GetZaxis()->SetLabelOffset(0.007);
   hframe__42->GetZaxis()->SetLabelSize(27);
   hframe__42->GetZaxis()->SetTitleSize(33);
   hframe__42->GetZaxis()->SetTitleFont(43);
   hframe__42->Draw("sameaxis");
   invertedEWKFakeTaustaup_Teq60to70Integral->Modified();
   invertedEWKFakeTaustaup_Teq60to70Integral->cd();
   invertedEWKFakeTaustaup_Teq60to70Integral->SetSelected(invertedEWKFakeTaustaup_Teq60to70Integral);
}
