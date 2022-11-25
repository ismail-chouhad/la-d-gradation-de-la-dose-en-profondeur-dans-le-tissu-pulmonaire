#ifndef B4aEventAction_h
#define B4aEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"


class EventAction : public G4UserEventAction
{
  public:
    EventAction();
    ~EventAction() override;

    void  BeginOfEventAction(const G4Event* event) override;
    void    EndOfEventAction(const G4Event* event) override;

    void AddLung(G4double de, G4double dl);
    void AddBone(G4double de, G4double dl);
    void AddMuscle(G4double de, G4double dl);
    void AddAdipose(G4double de, G4double dl);
    void AddSkin(G4double de, G4double dl);
    
  private:
    G4double  fEnergyLung    = 0.;
    G4double  fEnergyBone    = 0.;
    G4double  fEnergyMuscle  = 0.;
    G4double  fEnergyAdipose = 0.;
    G4double  fEnergySkin    = 0.;
    
    G4double  fTrackLung    = 0.;
    G4double  fTrackBone    = 0.;
    G4double  fTrackMuscle  = 0.;
    G4double  fTrackAdipose = 0.;
    G4double  fTrackSkin    = 0.;
    
    G4double  fMasseLung    = 0.;
    G4double  fMasseBone    = 0.;
    G4double  fMasseMuscle   = 0.;
    G4double  fMasseAdipose  = 0.;
    G4double  fMasseSkin     = 0.;
   
};

// inline functions

inline void EventAction::AddLung(G4double de, G4double dl) {
  fEnergyLung += de;
  fTrackLung  += dl;
}
inline void EventAction::AddBone(G4double de, G4double dl) {
  fEnergyBone += de;
  fTrackBone  += dl;
}
inline void EventAction::AddMuscle(G4double de, G4double dl) {
  fEnergyMuscle += de;
  fTrackMuscle  += dl;
}
inline void EventAction::AddAdipose(G4double de, G4double dl) {
  fEnergyAdipose += de;
  fTrackAdipose  += dl;
}
inline void EventAction::AddSkin(G4double de, G4double dl) {
  fEnergySkin += de;
  fTrackSkin  += dl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif

