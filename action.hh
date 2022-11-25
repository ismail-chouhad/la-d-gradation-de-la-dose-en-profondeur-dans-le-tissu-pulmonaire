#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "generator.hh"
#include "EventAction.hh"

namespace B4
{
	class MyDetectorConstruction;
}

class MyActionInitialization : public G4VUserActionInitialization
{
public :
	MyActionInitialization(B4::MyDetectorConstruction*);
	~MyActionInitialization();
	
	void BuildForMaster() const override;
	void Build() const override;
private : 
	B4::MyDetectorConstruction* fDetConstruction = nullptr;
};

#endif
