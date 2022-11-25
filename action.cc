#include "action.hh"
#include "generator.hh"
#include "EventAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"
#include "construction.hh"

using namespace B4;

MyActionInitialization::MyActionInitialization(MyDetectorConstruction* detConstruction) : fDetConstruction(detConstruction)
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::BuildForMaster() const
{
	SetUserAction(new RunAction);
}

void MyActionInitialization::Build() const
{
	MyPrimaryGenerator *generator = new MyPrimaryGenerator();
	SetUserAction(generator);
	SetUserAction(new RunAction);
	auto eventAction = new EventAction;
	SetUserAction(eventAction);
	SetUserAction(new SteppingAction(fDetConstruction,eventAction));
}
