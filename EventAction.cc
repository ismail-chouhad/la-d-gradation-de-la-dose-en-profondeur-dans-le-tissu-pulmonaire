#include "EventAction.hh"
#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "cmath"
#include "G4SystemOfUnits.hh"

#include "Randomize.hh"
#include <iomanip>


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* /*event*/)
{
  // initialisation per event
  fEnergyLung   = 0.;
  fEnergyBone   = 0.;
  fEnergyMuscle = 0.;
  fEnergyAdipose = 0.;
  fEnergySkin   = 0.;
  
  fTrackLung    = 0.;
  fTrackBone    = 0.;
  fTrackMuscle  = 0.;
  fTrackAdipose = 0.;
  fTrackSkin    = 0.;
  
  fMasseLung	= 0.1872;
  fMasseBone	= 0.1850;
  fMasseMuscle	= 0.1470;
  fMasseAdipose= 0.1330;
  fMasseSkin	= 0.0436;
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* /*event*/)
{
  // Accumulate statistics
  //

  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // fill histograms
  analysisManager->FillH1(0, fEnergyLung);
  analysisManager->FillH1(1, fEnergyBone);
  analysisManager->FillH1(2, fEnergyMuscle);
  analysisManager->FillH1(3, fEnergyAdipose);
  analysisManager->FillH1(4, fEnergySkin);
  
  analysisManager->FillH1(5, fTrackLung);
  analysisManager->FillH1(6, fTrackBone);
  analysisManager->FillH1(7, fTrackMuscle);
  analysisManager->FillH1(8, fTrackAdipose);
  analysisManager->FillH1(9, fTrackSkin);


  // fill ntuple
  analysisManager->FillNtupleDColumn(0, fEnergyLung);
  analysisManager->FillNtupleDColumn(1, fEnergyBone);
  analysisManager->FillNtupleDColumn(2, fEnergyMuscle);
  analysisManager->FillNtupleDColumn(3, fEnergyAdipose);
  analysisManager->FillNtupleDColumn(4, fEnergySkin);
  
  analysisManager->FillNtupleDColumn(5, fTrackLung);
  analysisManager->FillNtupleDColumn(6, fTrackBone);
  analysisManager->FillNtupleDColumn(7, fTrackMuscle);
  analysisManager->FillNtupleDColumn(8, fTrackAdipose);
  analysisManager->FillNtupleDColumn(9, fTrackSkin);
  analysisManager->FillNtupleDColumn(10,fTrackSkin+fTrackAdipose+fTrackMuscle+fTrackBone+fTrackLung);
  
  
  analysisManager->FillNtupleDColumn(11,(fEnergyLung)*1.602*pow(10,-13)/fMasseLung);
  analysisManager->FillNtupleDColumn(12,(fEnergyBone)*1.602*pow(10,-13)/fMasseBone);
  analysisManager->FillNtupleDColumn(13,(fEnergyMuscle)*1.602*pow(10,-13)/fMasseMuscle);
  analysisManager->FillNtupleDColumn(14,(fEnergyAdipose)*1.602*pow(10,-13)/fMasseAdipose);
  analysisManager->FillNtupleDColumn(15,(fEnergySkin)*1.602*pow(10,-13)/fMasseSkin);
  
  analysisManager->AddNtupleRow();
  
//(fEnergyLung)*1.602*pow(10,-13)/fMasseLung 

  // Print per event (modulo n)

 /* auto eventID = event->GetEventID();
  auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();
  if ( ( printModulo > 0 ) && ( eventID % printModulo == 0 ) ) {
    G4cout << "---> End of event: " << eventID << G4endl;

    G4cout
       << "   Lung: total energy : " << std::setw(7)
                                        << G4BestUnit(fEnergyLung,"Energy")
       << "      total track lung: " << std::setw(7)
                                        << G4BestUnit(fTrackLung,"Length")
       << G4endl
      
       << "   Bone: total energy : " << std::setw(7)
                                        << G4BestUnit(fEnergyBone,"Energy")
       << "      total track Bone: " << std::setw(7)
                                        << G4BestUnit(fTrackBone,"Length")
       << G4endl
       
       << "   Muscle: total energy : " << std::setw(7)
                                        << G4BestUnit(fEnergyMuscle,"Energy")
       << "    total track Muscle: " << std::setw(7)
                                        << G4BestUnit(fTrackMuscle,"Length")
       << G4endl
       
       << "   Adipose: total energy : " << std::setw(7)
                                        << G4BestUnit(fEnergyAdipose,"Energy")
       << "   total track Adipose: " << std::setw(7)
                                        << G4BestUnit(fTrackAdipose,"Length")
       << G4endl
       
       << "   Skin: total energy : " << std::setw(7)
                                        << G4BestUnit(fEnergySkin,"Energy")
       << "      total track Skin: " << std::setw(7)
                                        << G4BestUnit(fTrackSkin,"Length")
       << G4endl;
       
  }*/
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

