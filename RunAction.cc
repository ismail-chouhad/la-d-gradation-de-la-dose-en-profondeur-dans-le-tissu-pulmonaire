#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
{
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(100000);

  // Create analysis manager
  // The choice of the output format is done via the specified
  // file extension.
  auto analysisManager = G4AnalysisManager::Instance();

  // Create directories
  //analysisManager->SetHistoDirectoryName("histograms");
  //analysisManager->SetNtupleDirectoryName("ntuple");
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
    // Note: merging ntuples is available only with Root output

  // Book histograms, ntuple
  //

  // Creating histograms
  analysisManager->CreateH1("LungEnergy","Edep in Lung "	, 50. , 0. , 50*MeV);
  analysisManager->CreateH1("BoneEnergy","Edep in Bone "	, 50. , 0. , 50*MeV);
  analysisManager->CreateH1("MuscleEnergy","Edep in Muscle "	, 50. , 0. , 50*MeV);
  analysisManager->CreateH1("AdiposeEnergy","Edep in Adipose ", 50. , 0. , 50*MeV);
  analysisManager->CreateH1("SkinEnergy","Edep in Skin "	 , 50. , 0. , 50*MeV);
  
  analysisManager->CreateH1("Lung_Length ","trackL in absorber in lung"	, 50, 0., 5*cm);
  analysisManager->CreateH1("Bone_Length ","trackL in absorber in Bone"	, 50, 0., 5*cm);
  analysisManager->CreateH1("Muscle_Length ","trackL in absorber in Muscle"	, 50, 0., 5*cm);
  analysisManager->CreateH1("Adipose_Length ","trackL in absorber in Adipose", 50, 0., 5*cm);
  analysisManager->CreateH1("Skin_Length ","trackL in absorber in Skin"	, 50, 0., 5*cm);


  // Creating ntuple
  analysisManager->CreateNtuple("ntuple", "Edep and Track");
  
  analysisManager->CreateNtupleDColumn("LungEnergy");
  analysisManager->CreateNtupleDColumn("BoneEnergy");
  analysisManager->CreateNtupleDColumn("MuscleEnergy");
  analysisManager->CreateNtupleDColumn("AdiposeEnergy");
  analysisManager->CreateNtupleDColumn("SkinEnergy");

  analysisManager->CreateNtupleDColumn("LungTrack");
  analysisManager->CreateNtupleDColumn("BoneTrack");
  analysisManager->CreateNtupleDColumn("MuscleTrack");
  analysisManager->CreateNtupleDColumn("AdiposeTrack");
  analysisManager->CreateNtupleDColumn("SkinTrack");
  analysisManager->CreateNtupleDColumn("TrackSum");
  
  analysisManager->CreateNtupleDColumn("LungDose");
  analysisManager->CreateNtupleDColumn("BoneDose");
  analysisManager->CreateNtupleDColumn("MuscleDose");
  analysisManager->CreateNtupleDColumn("AdiposeDose");  
  analysisManager->CreateNtupleDColumn("SkinDose");
    
  analysisManager->FinishNtuple();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{
  //inform the runManager to save random number seed
  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);

  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  //
  G4String fileName = "Dose.root";
  // Other supported output types:
  // G4String fileName = "B4.csv";
  // G4String fileName = "B4.hdf5";
  // G4String fileName = "B4.xml";
  analysisManager->OpenFile(fileName);
  G4cout << "Using " << analysisManager->GetType() << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  // print histogram statistics
  //
  auto analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->GetH1(0) ) {	////////////  2 or 1 or 0 ????!!!!
    G4cout << G4endl << " ----> print histograms statistic ";
    if(isMaster) {
      G4cout << "for the entire run " << G4endl << G4endl;
    }
    else {
      G4cout << "for the local thread " << G4endl << G4endl;
    }

    G4cout << " LungEnergy :     mean = "
       << G4BestUnit(analysisManager->GetH1(0)->mean(), "Energy")
       << "	rms = "
       << G4BestUnit(analysisManager->GetH1(0)->rms(),  "Energy") << G4endl;
       
    G4cout << " Lung_Length :    mean = "
      << G4BestUnit(analysisManager->GetH1(5)->mean(), "Length")
      << "	rms = "
      << G4BestUnit(analysisManager->GetH1(5)->rms(),  "Length") << G4endl;

    G4cout << G4endl;

    G4cout << " BoneEnergy :     mean = "
       << G4BestUnit(analysisManager->GetH1(1)->mean(), "Energy")
       << "	rms = "
       << G4BestUnit(analysisManager->GetH1(1)->rms(),  "Energy") << G4endl;
       
    G4cout << " Bone_Length :    mean = "
      << G4BestUnit(analysisManager->GetH1(6)->mean(), "Length")
      << "	rms = "
      << G4BestUnit(analysisManager->GetH1(6)->rms(),  "Length") << G4endl;
       
    G4cout << G4endl;
       
    G4cout << " MuscleEnergy :   mean = "
       << G4BestUnit(analysisManager->GetH1(2)->mean(), "Energy")
       << "	rms = "
       << G4BestUnit(analysisManager->GetH1(2)->rms(),  "Energy") << G4endl;
       
    G4cout << " Muscle_Length :  mean = "
      << G4BestUnit(analysisManager->GetH1(7)->mean(), "Length")
      << "	rms = "
      << G4BestUnit(analysisManager->GetH1(7)->rms(),  "Length") << G4endl;
      
    G4cout << G4endl;  

    G4cout << " AdiposeEnergy :  mean = "
       << G4BestUnit(analysisManager->GetH1(3)->mean(), "Energy")
       << "	rms = "
       << G4BestUnit(analysisManager->GetH1(3)->rms(),  "Energy") << G4endl;
       
    G4cout << " Adipose_Length : mean = "
      << G4BestUnit(analysisManager->GetH1(8)->mean(), "Length")
      << "	rms = "
      << G4BestUnit(analysisManager->GetH1(8)->rms(),  "Length") << G4endl;
      
    G4cout << G4endl;
      
    G4cout << " SkinEnergy :     mean = "
       << G4BestUnit(analysisManager->GetH1(4)->mean(), "Energy")
       << "	rms = "
       << G4BestUnit(analysisManager->GetH1(4)->rms(),  "Energy") << G4endl;
       
    G4cout << " Skin_Length :    mean = "
      << G4BestUnit(analysisManager->GetH1(9)->mean(), "Length")
      << "	rms = "
      << G4BestUnit(analysisManager->GetH1(9)->rms(),  "Length") << G4endl; 
         
    G4cout << G4endl;
  }

  // save histograms & ntuple
  //
  analysisManager->Write();
  analysisManager->CloseFile();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

