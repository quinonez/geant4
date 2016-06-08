// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VGlobalFastSimulationManager.hh,v 1.1 1999/04/15 15:43:14 mora Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
// 
// Abstract interface for GEANT4 Global Fast Simulation Manager.
// P. Mora de Freitas & M. Verderi 14/April/1999.
//
// G4GlobalFastSimulationManager is a "Singleton", i.e., only one instance 
// of it may exist. This is ensured by making the constructor private.
//
// G4VGlobalFastSimulationManager is an abstract interface for the
// G4GlobalFastSimulationManager one. It has the public access function
// GetConcreteInstance(), which is used to obtain a pointer to the concrete 
// G4GlobalFastSimulationManager, should it exist. After
//
// G4VGlobalFastSimulationManager* pVFSMan =  
//     G4VGlobalFastSimulationManager::GetConcreteInstance ();
//
// pVFSMan points to the real (concrete) G4GlobalFastSimulationManager if
// at least a parameterisation envelope exists, otherwise is zero.  
//
// Thus all code must be protected, for example by:
//   if (pVFSMan) 
//    G4FlavoredParallelWorld* =
//      pVFSMan -> GetFlavoredWorldForThis(p);
//

#ifndef G4VGLOBALFASTSIMULATIONMANAGER_HH
#define G4VGLOBALFASTSIMULATIONMANAGER_HH

class G4VFlavoredParallelWorld;
class G4ParticleDefinition;

class G4VGlobalFastSimulationManager {

public:
  // Returns pointer to actual Global Fast Simulation manager if
  // at least a parameterisation envelope exists. Always check value.
  static G4VGlobalFastSimulationManager* GetConcreteInstance ();

  virtual ~G4VGlobalFastSimulationManager () {}

  // VGlobalFastSimulationManager Interface for visualisation.

  virtual
  G4VFlavoredParallelWorld* GetFlavoredWorldForThis(G4ParticleDefinition*)=0;

protected:
  // Pointer to real G4GlobalFastSimulationManager.
  static G4VGlobalFastSimulationManager* fpConcreteInstance;  

};

inline 
G4VGlobalFastSimulationManager* 
G4VGlobalFastSimulationManager::GetConcreteInstance () {
  return fpConcreteInstance;
}
#endif