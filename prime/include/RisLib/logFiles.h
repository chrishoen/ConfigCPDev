#pragma once

/*==============================================================================
Implements multiple text log files
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
// git test

namespace Log
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initializes the log files facility.

   void reset    ();
   bool openFile       (int aLogNum,const char* aFilePath);
   bool openFileAppend (int aLogNum,const char* aFilePath);

   void closeFile      (int aLogNum);
   void closeAllFiles ();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Write to log file

   void write (int aLogNum, const char* aFormat, ...);

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

