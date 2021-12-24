#pragma once

/*==============================================================================
Dsp namespace: 
Parameters class whose values are read from a command file. 
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Dsp
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This is a class that contains parameter member variables. The values of
// the parameters are set by reading a text file that contains command lines.
// Each command line is of the form "command argument1 argument2 ...".
// 

class SlowThresholderParms
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Fuzzy alpha filter sampling period and step response time, seconds.
   float mAlphaFilterTs;
   float mAlphaFilterStepTime;

   // Fuzzy to crisp threshold.
   float mFuzzyToCrispThresh;

   // Signal thresholds.
   float mThresh;
   float mThreshDelta;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor,
   SlowThresholderParms();
   void reset();
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace