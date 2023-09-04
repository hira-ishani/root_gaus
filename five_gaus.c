void five_gaus()
{
    // Create five histograms with different Gaussian distributions
    TH1F* gaus1 = new TH1F("gaus1", "Gaus(0,1)", 30, -6, 6);
    TH1F* gaus2 = new TH1F("gaus2", "Gaus(0,2)", 30, -6, 6);
    TH1F* gaus3 = new TH1F("gaus3", "Gaus(1,1)", 30, -6, 6);
    TH1F* gaus4 = new TH1F("gaus4", "Gaus(1,2)", 30, -6, 6);
    TH1F* gaus5 = new TH1F("gaus5", "Gaus(-1,0.5)", 30, -6, 6);

    // Generate 1000 random numbers from five different Gaussian distributions and fill the histograms
    for (int i = 0; i < 1000; i++) {
        gaus1->Fill(gRandom->Gaus(0, 1));
        gaus2->Fill(gRandom->Gaus(0, 2));
        gaus3->Fill(gRandom->Gaus(1, 1));
        gaus4->Fill(gRandom->Gaus(1, 2));
        gaus5->Fill(gRandom->Gaus(-1, 0.5));
    }

    // Set line colors for each histogram
    gaus1->SetLineColor(1);
    gaus2->SetLineColor(2);
    gaus3->SetLineColor(3);
    gaus4->SetLineColor(4);
    gaus5->SetLineColor(6);

    // Create a canvas to display the histograms
    TCanvas *histo = new TCanvas("histo", "five different Gaussian distributions", 0, 0, 1366, 768);
    histo->Divide(5, 1);  // Divide the canvas into five columns

    histo->cd(1);
    gaus1->Fit("gaus");
    gaus1->Draw();

    histo->cd(2);
    gaus2->Fit("gaus");
    gaus2->Draw();

    histo->cd(3);
    gaus3->Draw();

    histo->cd(4);
    gaus4->Draw();

    histo->cd(5);
    gaus5->Draw();

    // Create a ROOT file to save the histograms
    TFile file("five_gaus.root", "create");
    gaus1->Write();
    gaus2->Write();
    gaus3->Write();
    gaus4->Write();
    gaus5->Write();
    file.Close();
}
