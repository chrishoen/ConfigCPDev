#pragma once
/*==============================================================================
cprint json meta file utilities.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include <string>
#include "json.h"

namespace CX
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Methods.

// Create a new history record.
void doCreateNewHistoryRecord(
   Json::Value&       aHistoryRecord);      // Output

// Update a record print time wth the current time.
void doUpdateHistoryRecordPrintTime(
   Json::Value&       aHistoryRecord);      // Output

// Read a history json record from a file.
// Update the record with the current time.
// Write the updated record to the file.
void doUpdateHistoryRecordFromFileWithCurrentTime(
   const std::string& aHistoryFilePath,     // Input
   Json::Value&       aHistoryRecord);      // Output

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace




