#include "construction.hh"

namespace B4 
{
 
MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();

//	G4Material *WaterMat = nist->FindOrBuildMaterial("G4_WATER");

	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
//	G4Material* worldMat  = nist->FindOrBuildMaterial("G4_Galactic");
	G4Material *SkinMat = nist->FindOrBuildMaterial("G4_SKIN_ICRP");
	G4Material *AdiposeMat = nist->FindOrBuildMaterial("G4_ADIPOSE_TISSUE_ICRP");
	G4Material *MuscleMat = nist->FindOrBuildMaterial("G4_MUSCLE_SKELETAL_ICRP");
	G4Material *BoneMat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");
	G4Material *LungMat = nist->FindOrBuildMaterial("G4_LUNG_ICRP");

//for define any construction you need three volumes ; 'solid, logical, phisical'

//for solidworld box :	
	G4Box *solidWorld            = new G4Box("solidWorld", 0.1*m, 0.1*m, 0.1*m);
	
	G4LogicalVolume *LogicWorld  = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.*m), LogicWorld, "physWorld", 0, false, 0. , true);

//for Skin box : (Density=1.09 g/cm^3) // Volume = 40 cm^3	//   =======> mase = 43.6 g = 0.0436 kg

	G4Box *solidSkin             = new G4Box("solidSkin", 0.05*m, 0.05*m, 0.002*m);//5*5*0.2 = 5cm^3
	
	G4LogicalVolume *LogicSkin   = new G4LogicalVolume(solidSkin, SkinMat, "LogicalSkin");
	
	physSkin = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.*m), LogicSkin, "physSkin",LogicWorld, false, 0, true);	

//for Adiopos box : (Density=0.95 g/cm^3) // Volume = 140 cm^3 //   =======> mase = 133 g = 0.1330 kg

	G4Box *solidAdipose             = new G4Box("solidAdipose", 0.05*m, 0.05*m, 0.007*m);//5*5*0.7 = 17.5cm^3
	
	G4LogicalVolume *LogicAdipose   = new G4LogicalVolume(solidAdipose, AdiposeMat, "LogicalAdipose");
	
	physAdipose = new G4PVPlacement(0, G4ThreeVector(0, 0., 0.009*m), LogicAdipose, "physAdipose",LogicWorld, false, 0, true);	

//for Muscle box : (Density=1.05 g/cm^3)  // Volume = 140 cm^3 //   =======> mase = 147 g = 0.1470 kg

	G4Box *solidMuscle             = new G4Box("solidMuscle", 0.05*m, 0.05*m, 0.007*m);//5*5*0.7 = 17,5cm^3
	
	G4LogicalVolume *LogicMuscle   = new G4LogicalVolume(solidMuscle, MuscleMat, "LogicalMuscle");
	
	physMuscle = new G4PVPlacement(0, G4ThreeVector(0, 0., 0.023*m), LogicMuscle, "physMuscle",LogicWorld, false, 0, true);	
	
//for Bone box : (Density=1.85 g/cm^3)  // Volume = 100 cm^3 //   =======> mase = 185 g = 0.1850 kg

	G4Box *solidBone             = new G4Box("solidBone", 0.05*m, 0.05*m, 0.005*m);//5*5*0.5 = 12,5cm^3
	
	G4LogicalVolume *LogicBone   = new G4LogicalVolume(solidBone, BoneMat, "LogicalBone");
	
	physBone = new G4PVPlacement(0, G4ThreeVector(0, 0., 0.035*m), LogicBone, "physBone",LogicWorld, false, 0, true);	

//for Lung box : (Density=1.04g/cm^3)	// Volume = 180 cm^3 //   =======> mase = 187.2 g = 0.1872 kg

	G4Box *solidLung             = new G4Box("solidLung", 0.05*m, 0.05*m, 0.009*m); // The volume is 5cm * 5cm * 0.9cm = 22.5cm^3
	
	G4LogicalVolume *LogicLung   = new G4LogicalVolume(solidLung, LungMat, "LogicalLung");
	
	physLung = new G4PVPlacement(0, G4ThreeVector(0, 0., 0.049*m), LogicLung, "physLung",LogicWorld, false, 0, true);
	
	return physWorld;
}
}
