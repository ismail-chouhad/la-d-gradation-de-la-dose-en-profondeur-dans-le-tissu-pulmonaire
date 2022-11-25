#ifndef SteppingAction_h
#define SteppingAction_h

#include "G4UserSteppingAction.hh"
#include "construction.hh"
#include "EventAction.hh"

namespace B4
{
  class MyDetectorConstruction;
}


class EventAction;

/// Stepping action class.
///
/// In UserSteppingAction() there are collected the energy deposit and track
/// lengths of charged particles in Absober and Gap layers and
/// updated in EventAction.

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(const B4::MyDetectorConstruction* detConstruction,
                 EventAction* eventAction);
  ~SteppingAction() override;

  void UserSteppingAction(const G4Step* step) override;

private:
  const B4::MyDetectorConstruction* fDetConstruction = nullptr;
  EventAction* fEventAction = nullptr;
};


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
