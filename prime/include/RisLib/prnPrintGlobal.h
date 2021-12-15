#pragma once
/*==============================================================================

This file contains a global variable that has a constructor that is called
at program load time. It is used to manually reset other global objects
that do not have constructors because they live in shared memory.

==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Prn
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// A variable that has a constructor that is called at load time.
// It initialiizes the global print filter table, which does not have
// a constructor, because it might live in share memory.

class PrintGlobal
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   PrintGlobal();
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global instance

#ifdef _PRNPRINTGLOBAL_CPP_
        PrintGlobal gPrintGlobal;
#else
        extern PrintGlobal gPrintGlobal;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

