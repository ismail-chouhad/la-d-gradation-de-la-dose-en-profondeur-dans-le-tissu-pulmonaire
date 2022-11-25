#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "RunAction.hh"

int main(int argc, char** argv)
{
	G4UIExecutive *ui = nullptr;
  	if ( argc == 1 ) { ui = new G4UIExecutive(argc, argv); }
	G4RunManager *runManager = new G4RunManager();
	
	auto detConstruction = new B4::MyDetectorConstruction();
	runManager->SetUserInitialization(detConstruction);
	
	//runManager->SetUserInitialization(new B4::MyDetectorConstruction());
	runManager->SetUserInitialization(new MyPhysicsList());
	//runManager->SetUserInitialization(new MyActionInitialization());
	
	auto actionInitialization = new MyActionInitialization(detConstruction);
	runManager->SetUserInitialization(actionInitialization);
	
	runManager->Initialize();
	
//	G4UIExecutive *ui = new G4UIExecutive(argc, argv);
	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();
	
	G4UImanager *UImanager = G4UImanager::GetUIpointer();
	
if ( ! ui ) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
else {
    // interactive mode
    UImanager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
    delete ui;
  }
return 0;
}
