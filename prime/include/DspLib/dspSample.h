#pragma once


/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Dsp
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class encapsulates a sample.

class Sample
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Sample time and amplitude.
   double  mTime;
   double  mVolts;
   double  mAmplitude;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Constructor.
   Sample();

   // Convert and store.
   void put(double aTime,double aVolts);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

