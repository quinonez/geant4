//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
#ifndef LXeTrajectory_h
#define LXeTrajectory_h 1

#include "G4Trajectory.hh"
#include "G4Allocator.hh"
#include "G4ios.hh" 
#include "globals.hh" 
#include "G4ParticleDefinition.hh" 
#include "G4TrajectoryPoint.hh"
#include "G4Track.hh"
#include "G4Step.hh"

class G4Polyline;                   // Forward declaration.

class LXeTrajectory : public G4Trajectory
{
public:
  LXeTrajectory();
  LXeTrajectory(const G4Track* aTrack);
  LXeTrajectory(LXeTrajectory &);
  virtual ~LXeTrajectory();
  
  virtual void DrawTrajectory(G4int i_mode=0) const;
  
  inline void* operator new(size_t);
  inline void  operator delete(void*);

  void SetDrawTrajectory(G4bool b){drawit=b;}
  void WLS(){wls=true;}
  void SetForceDrawTrajectory(G4bool b){forceDraw=b;}
  void SetForceNoDrawTrajectory(G4bool b){forceNoDraw=b;}
private:
  G4bool wls;
  G4bool drawit;
  G4bool forceNoDraw;
  G4bool forceDraw;
  G4ParticleDefinition* particleDefinition;
};

extern G4Allocator<LXeTrajectory> LXeTrajectoryAllocator;

inline void* LXeTrajectory::operator new(size_t)
{
  void* aTrajectory;
  aTrajectory = (void*)LXeTrajectoryAllocator.MallocSingle();
  return aTrajectory;
}

inline void LXeTrajectory::operator delete(void* aTrajectory)
{
  LXeTrajectoryAllocator.FreeSingle((LXeTrajectory*)aTrajectory);
}

#endif