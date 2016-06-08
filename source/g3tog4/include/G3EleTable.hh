#ifndef _G4ELETABLE_
#define _G4ELETABLE_ 1
// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G3EleTable.hh,v 1.1 1999/05/06 04:19:58 lockman Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
#include <rw/ctoken.h>
#include <rw/tpordvec.h>
#include "globals.hh"
#include "G4Element.hh"

class G3EleTable{

public:
  G3EleTable();
  virtual ~G3EleTable();
  G4Element* GetEle(G4double Z);

private:
  void LoadUp();
  int parse(G4double& Z, char* name, char* sym, G4double& A); 

private:
  char** _EleNames;
  G4Element** _Ele;
  int _MaxEle;

};

extern G3EleTable G3Ele;
#endif