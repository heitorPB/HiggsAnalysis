{
//=========Macro generated from canvas: inverted1Integral/
//=========  (Sun Jul 20 15:00:26 2014) by ROOT version5.32/00
   TCanvas *inverted1Integral = new TCanvas("inverted1Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   inverted1Integral->SetHighLightColor(2);
   inverted1Integral->Range(-101.2658,-1.792352,531.6456,4.302661);
   inverted1Integral->SetFillColor(0);
   inverted1Integral->SetBorderMode(0);
   inverted1Integral->SetBorderSize(2);
   inverted1Integral->SetLogy();
   inverted1Integral->SetTickx(1);
   inverted1Integral->SetTicky(1);
   inverted1Integral->SetLeftMargin(0.16);
   inverted1Integral->SetRightMargin(0.05);
   inverted1Integral->SetTopMargin(0.05);
   inverted1Integral->SetBottomMargin(0.13);
   inverted1Integral->SetFrameFillStyle(0);
   inverted1Integral->SetFrameBorderMode(0);
   inverted1Integral->SetFrameFillStyle(0);
   inverted1Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__19 = new TH1F("hframe__19","",1000,0,500);
   hframe__19->SetMinimum(0.1);
   hframe__19->SetMaximum(9952);
   hframe__19->SetDirectory(0);
   hframe__19->SetStats(0);
   hframe__19->SetLineStyle(0);
   hframe__19->SetMarkerStyle(20);
   hframe__19->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__19->GetXaxis()->SetLabelFont(43);
   hframe__19->GetXaxis()->SetLabelOffset(0.007);
   hframe__19->GetXaxis()->SetLabelSize(27);
   hframe__19->GetXaxis()->SetTitleSize(33);
   hframe__19->GetXaxis()->SetTitleOffset(0.9);
   hframe__19->GetXaxis()->SetTitleFont(43);
   hframe__19->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__19->GetYaxis()->SetLabelFont(43);
   hframe__19->GetYaxis()->SetLabelOffset(0.007);
   hframe__19->GetYaxis()->SetLabelSize(27);
   hframe__19->GetYaxis()->SetTitleSize(33);
   hframe__19->GetYaxis()->SetTitleOffset(1.25);
   hframe__19->GetYaxis()->SetTitleFont(43);
   hframe__19->GetZaxis()->SetLabelFont(43);
   hframe__19->GetZaxis()->SetLabelOffset(0.007);
   hframe__19->GetZaxis()->SetLabelSize(27);
   hframe__19->GetZaxis()->SetTitleSize(33);
   hframe__19->GetZaxis()->SetTitleFont(43);
   hframe__19->Draw(" ");
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
      tex = new TLatex(0.4,0.7,"Integral = 26742 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1 = new TH1F("Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1","#tau p_{T}=50..60",50,0,500);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(1,1379);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(2,3763);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(3,4976);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(4,4727);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(5,4007);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(6,2837);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(7,1721);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(8,1075);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(9,632);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(10,418);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(11,247);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(12,203);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(13,148);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(14,116);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(15,113);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(16,83);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(17,66);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(18,48);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(19,31);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(20,27);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(21,18);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(22,21);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(23,14);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(24,18);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(25,5);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(26,8);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(27,5);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(28,5);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(29,4);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(30,2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(31,7);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(32,4);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(33,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(34,2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(36,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(37,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(38,2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(39,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(40,2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(41,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(44,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(45,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinContent(46,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(1,37.13489);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(2,61.3433);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(3,70.54077);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(4,68.75318);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(5,63.30087);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(6,53.2635);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(7,41.48494);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(8,32.78719);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(9,25.13961);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(10,20.44505);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(11,15.71623);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(12,14.24781);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(13,12.16553);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(14,10.77033);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(15,10.63015);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(16,9.110434);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(17,8.124038);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(18,6.928203);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(19,5.567764);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(20,5.196152);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(21,4.242641);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(22,4.582576);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(23,3.741657);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(24,4.242641);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(25,2.236068);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(26,2.828427);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(27,2.236068);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(28,2.236068);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(29,2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(30,1.414214);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(31,2.645751);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(32,2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(33,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(34,1.414214);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(36,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(37,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(38,1.414214);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(39,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(40,1.414214);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(41,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(44,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(45,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetBinError(46,1);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetEntries(26742);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetFillColor(ci);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetLineWidth(2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetMarkerStyle(20);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->SetMarkerSize(1.2);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetXaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetXaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetXaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetXaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetYaxis()->SetTitle("Events / 10 GeV");
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetYaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetYaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetYaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetYaxis()->SetTitleOffset(1.5);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetYaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetZaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetZaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetZaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->GetZaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCuts/METInvertedTauIdAfterCollinearCuts1->Draw("HIST same");
   
   TH1F *hframe__20 = new TH1F("hframe__20","",1000,0,500);
   hframe__20->SetMinimum(0.1);
   hframe__20->SetMaximum(9952);
   hframe__20->SetDirectory(0);
   hframe__20->SetStats(0);
   hframe__20->SetLineStyle(0);
   hframe__20->SetMarkerStyle(20);
   hframe__20->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__20->GetXaxis()->SetLabelFont(43);
   hframe__20->GetXaxis()->SetLabelOffset(0.007);
   hframe__20->GetXaxis()->SetLabelSize(27);
   hframe__20->GetXaxis()->SetTitleSize(33);
   hframe__20->GetXaxis()->SetTitleOffset(0.9);
   hframe__20->GetXaxis()->SetTitleFont(43);
   hframe__20->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__20->GetYaxis()->SetLabelFont(43);
   hframe__20->GetYaxis()->SetLabelOffset(0.007);
   hframe__20->GetYaxis()->SetLabelSize(27);
   hframe__20->GetYaxis()->SetTitleSize(33);
   hframe__20->GetYaxis()->SetTitleOffset(1.25);
   hframe__20->GetYaxis()->SetTitleFont(43);
   hframe__20->GetZaxis()->SetLabelFont(43);
   hframe__20->GetZaxis()->SetLabelOffset(0.007);
   hframe__20->GetZaxis()->SetLabelSize(27);
   hframe__20->GetZaxis()->SetTitleSize(33);
   hframe__20->GetZaxis()->SetTitleFont(43);
   hframe__20->Draw("sameaxis");
   inverted1Integral->Modified();
   inverted1Integral->cd();
   inverted1Integral->SetSelected(inverted1Integral);
}
