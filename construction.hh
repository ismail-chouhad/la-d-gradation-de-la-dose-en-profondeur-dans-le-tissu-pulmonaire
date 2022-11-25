#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4MaterialPropertiesTable.hh"
#include "globals.hh"

//#include "detector.hh"

namespace B4
{

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
	MyDetectorConstruction();
	~MyDetectorConstruction();
	
//	virtual G4VPhysicalVolume *Construct();	commented by my
// added by my	
  public:
    G4VPhysicalVolume* Construct() override;
   // void ConstructSDandField() override;

    // get methods
    //
    const G4VPhysicalVolume* GetLungPV() const;
    const G4VPhysicalVolume* GetBonePV() const;
    const G4VPhysicalVolume* GetMusclePV() const;
    const G4VPhysicalVolume* GetAdiposePV() const;
    const G4VPhysicalVolume* GetSkinPV() const;

  private:
    // methods
    //
    //void DefineMaterials();
    //G4VPhysicalVolume* DefineVolumes();

    // data members
    //
//    static G4ThreadLocal G4GlobalMagFieldMessenger*  fMagFieldMessenger;
                                      // magnetic field messenger

    G4VPhysicalVolume* physLung = nullptr; // the absorber physical volume
    G4VPhysicalVolume* physBone = nullptr;
    G4VPhysicalVolume* physMuscle = nullptr;
    G4VPhysicalVolume* physAdipose = nullptr;
    G4VPhysicalVolume* physSkin = nullptr;


//    G4bool fCheckOverlaps = true; // option to activate checking of volumes overlaps
};
   //inline functions

inline const G4VPhysicalVolume* MyDetectorConstruction::GetLungPV() const {
  return physLung;
}
inline const G4VPhysicalVolume* MyDetectorConstruction::GetBonePV() const {
  return physBone;
}
inline const G4VPhysicalVolume* MyDetectorConstruction::GetMusclePV() const {
  return physMuscle;
}
inline const G4VPhysicalVolume* MyDetectorConstruction::GetAdiposePV() const {
  return physAdipose;
}
inline const G4VPhysicalVolume* MyDetectorConstruction::GetSkinPV() const {
  return physSkin;
}

}
#endif
