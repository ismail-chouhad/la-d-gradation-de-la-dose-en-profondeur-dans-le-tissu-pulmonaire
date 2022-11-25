#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
	RegisterPhysics(new G4EmStandardPhysics());
//	RegisterPhysics(new G4OpticalPhysics());
	RegisterPhysics(new G4HadronElasticPhysics());
//	RegisterPhysics(new G4HadronInelasticQBBC()); //probleme ??!!
//	RegisterPhysics(new G4IonPhysics());
}

MyPhysicsList::~MyPhysicsList()
{}

