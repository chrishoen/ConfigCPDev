#pragma once
/*==============================================================================
Command line string class.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risCmdLineExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Ris
{
//******************************************************************************
//******************************************************************************
//******************************************************************************
// This utility class encapsulates a function that executes an command line
// executive for a single command line string.

class  CmdLineString
{
public:

   CmdLineString();

   // Parse a command line string into a command line command and pass
   // the command to a command line executive to execute.
   void execute (BaseCmdLineExec* aExec, char* aCmdLineString);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

