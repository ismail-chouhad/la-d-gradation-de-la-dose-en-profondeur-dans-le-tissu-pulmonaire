#include "SteppingAction.hh"
#include "EventAction.hh"
#include "construction.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

using namespace B4;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(const MyDetectorConstruction* detConstruction,
                               EventAction* eventAction)
  : fDetConstruction(detConstruction),
    fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{
// Collect energy and track length step by step

  // get volume of the current step
  auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();

  // energy deposit
  auto edep = step->GetTotalEnergyDeposit();
  G4double stepLength = 0.;
  if ( step->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
    stepLength = step->GetStepLength();
  }

  if ( volume == fDetConstruction->GetLungPV() ) {
    fEventAction->AddLung(edep,stepLength);
  }
  if ( volume == fDetConstruction->GetBonePV() ) {
    fEventAction->AddBone(edep,stepLength);
  }
  if ( volume == fDetConstruction->GetMusclePV() ) {
    fEventAction->AddMuscle(edep,stepLength);
  }
  if ( volume == fDetConstruction->GetAdiposePV() ) {
    fEventAction->AddAdipose(edep,stepLength);
  }
  if ( volume == fDetConstruction->GetSkinPV() ) {
    fEventAction->AddSkin(edep,stepLength);
  }
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
