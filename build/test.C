{

TFile *file;
file=TFile::Open("EdepLenght.root");
file->ls();
ntuple->Print();

ntuple->Draw("EnergySum");
}
