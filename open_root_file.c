#include <TApplication.h>

void open_root_file()
{
    // Create a ROOT application
    TApplication app("app", nullptr, nullptr);

    // Open the ROOT file in READ mode
    TFile *file = new TFile("five_gaus.root", "READ");

    // Create a canvas to display the histograms
    TCanvas *canvas = new TCanvas("canvas", "Histograms", 800, 600);

    // Retrieve and draw each histogram
    int i = 5;  {
        TString histName = TString::Format("gaus%d", i);
        TH1F *hist = (TH1F*)file->Get(histName);

        // Set the canvas to display the current histogram
        canvas->cd();
        hist->Draw();

        // Wait for a moment (optional)
        gSystem->ProcessEvents();
        
        // Pause to allow time for the user to view the histogram
        canvas->Update();
        canvas->WaitPrimitive();
    }

    // Start the ROOT application event loop
    app.Run();
    
    // Close the ROOT file
    file->Close();
}
