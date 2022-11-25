#include "generator.hh"
namespace B4
{
MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
	
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName = "proton";
	G4ParticleDefinition *particle = particleTable->FindParticle("proton");
	
	G4ThreeVector pos(0. ,0. ,-0.09*m);
	G4ThreeVector mom(0. ,0. ,1.);
	
	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
//	fParticleGun->SetParticleMomentum(90*MeV); probleme ??!!
	fParticleGun->SetParticleEnergy(90*MeV);
	fParticleGun->SetParticleDefinition(particle);
	
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{

	fParticleGun->GeneratePrimaryVertex(anEvent);
}

}
