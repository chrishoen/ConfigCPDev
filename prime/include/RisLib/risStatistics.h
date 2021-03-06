#pragma once
/*==============================================================================
mean, stdev,min,max
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Ris
{
//******************************************************************************
//******************************************************************************
//******************************************************************************
// This filter characterizes an input signal by calculating expectations and
// uncertainties of the signal. It does this on a periodic basis, given a fixed
// window size. For example, given a fixed window size of 1000, and an update
// rate of 1000 khz, this will produce new statisics once a second.

class PeriodicStatistics
{
public:
   // Initialize
   void initialize(int aSize, double aPeriod);
   void show();

   // Put input value
   void put(double aX);

   // Members
   int mSize;
   double mPeriod;
   bool mFirstFlag;

   // Output values
   bool    mEndOfPeriod;  // True at the end of a period
   double  mX;            // Input value
   double  mEX;           // expectation (mean)
   double  mUX;           // uncertainty (standard deviation)
   double  mMinX;         // minimum 
   double  mMaxX;         // maximum
   double  mMean;         // expectation (mean)
   double  mStdDev;       // uncertainty (standard deviation)

   double  mMaxError;     // maximum error.

   double  mEXSquare;     // expectation of X squared
   double  mVariance;     // variance

   // Sums for expectation and uncertainty
   double  mXSum;         // Sum of X
   double  mXSquareSum;   // Sum of X squared
   int     mPutCount;     // Put count

   // Current min and max
   double  mCurrentMinX;      // minimum
   double  mCurrentMaxX;      // maximum
   double  mCurrentMaxError;  // maximum error

   // Members
   int mK;
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This filter characterizes an input signal by calculating expectations and
// uncertainties of the signal. It does this for a trial experiment, for an
// arbitrary number of samples.

class TrialStatistics
{
public:
   TrialStatistics();

   // Initialize
   void startTrial(double aXLimit=0.0);
   void finishTrial();
   void show();
   void show2();
   void showEUMM(int aPF, char* aLabel);

   // Put input value
   void put(double aX);

   // Members
   unsigned long long mPutCount;    // Number of samples

   // Input values
   double   mX;            // Input value
   double   mXLimit;       // Input limit
   bool     mXLimitFlag;   // Input limit
   // Output values
   double   mEX;           // expectation (mean)
   double   mUX;           // uncertainty (standard deviation)
   double   mMinX;         // minimum 
   double   mMaxX;         // maximum
   double   mMaxMaxX;      // maximum for all times
   double   mMean;         // expectation (mean)
   double   mStdDev;       // uncertainty (standard deviation)
   double   mVariance;     // variance


   double   mOLMean;       // Online algorithm
   double   mOLM2;         // Online algorithm
   double   mOLDelta;      // Online algorithm

   double   mXSum;         // Sum of X
   double   mXMean;        // expectation (mean)
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace


