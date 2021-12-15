#pragma once

/*==============================================================================
Pulse Descriptor Word
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Dsp
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class encapsulates a pulse descriptor word. It contains members that
// describe an individual pulse.

class Pdw
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   int    mSeqNum;
   int    mIndex;
   double mToa;
   double mAmplitude;
   double mPulseWidth;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods..

   Pdw();
   void reset();
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

