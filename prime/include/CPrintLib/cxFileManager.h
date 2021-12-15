#pragma once
/*==============================================================================
Session file manager.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include <string>
#include <vector>
#include "json.h"

namespace CX
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class encalsulates a session file manager.

class FileManager
{
public:
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constants.

   static const int cMaxStringSize = 200;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // If true then a print zip is in progress and some file operations will
   // not be executed.
   bool mRunZipInProgress;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Program directory paths.
   std::string mBaseDirPath;
   std::string mZipDirPath;
   std::string mSnipDirPath;
   std::string mWorkDirPath;
   std::string mMetaDirPath;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members. These pertain to the zip dirctory.

   // DirZip variables are set when a DirZip is executed. They are associated
   // with all of the zip files in the zip directory.

   // RunZip variables are set when a RunZip is executed. They are associated
   // with the single zip file in the zip directory that has been selected
   // to run.

   // Zip names.
   std::vector<std::string> mDirZipNameList;
   std::vector<std::string> mDirZipFileNameList;
   std::vector<std::string> mDirZipTimeStampList;

   // Zip names.
   std::string mRunZipName;
   std::string mRunZipFileName;
   std::string mRunZipFilePath;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members. These pertain to the snippet dirctory.

   // DirSnip variables are set when a DirSnip is executed. They are associated
   // with all of the zip files in the zip directory.

   // RunSnip variables are set when a RunSnip is executed. They are associated
   // with the single zip file in the zip directory that has been selected
   // to run.

   // Snip names.
   std::vector<std::string> mDirSnipNameList;
   std::vector<std::string> mDirSnipFileNameList;
   std::vector<std::string> mDirSnipTimeStampList;

   // Snip names.
   std::string mRunSnipName;
   std::string mRunSnipFileName;
   std::string mRunSnipFilePath;

   // Temp snip file.
   std::string mTempSnipFilePath;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members. These pertain to the work dirctory.

   // Gcode name.
   std::string mWorkGCodeFileName;

   // GCode file path.
   std::string mWorkGCodeFilePath;

   // GCode prefix file path.
   std::string mWorkSliceFilePrefixPath;

   // Script file path. File mode1 is zip, file mode2 is gcode.
   std::string mWorkScriptFilePath1;
   std::string mWorkScriptFilePath2;

   // Preview file path.
   std::string mWorkPreviewFilePath;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members. These pertain to the meta dirctory.

   // DirZip variables are set when a DirZip is executed. They are associated
   // with all of the zip files in the zip directory.

   // RunZip variables are set when a RunZip is executed. They are associated
   // with the single zip file in the zip directory that has been selected
   // to run.

   // List of the metadata subdirectory file  paths.
   std::vector<std::string> mDirZipMetaSubDirPathList;

   // Metadata file paths.
   std::string mDirZipMetadataFilePath;
   std::string mDirZipPrologFilePath;

   // Metadata json stores.
   Json::Value mDirZipMetadata;
   Json::Value mDirZipProlog;

   // Metadata file paths.
   std::string mRunZipMetaSubDirPath;
   std::string mRunZipManifestFilePath;
   std::string mRunZipPrologFilePath;
   std::string mRunMetaHistoryFilePath;

   // Metadata json stores.
   Json::Value mDirSnipMetadata;

   // Metadata file paths.
   std::string mDirSnipMetadataFilePath;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members. Status.

   // Last error.
   std::string mError;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   FileManager();
   void initialize();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. These pertain to the zip dirctory.

   // Get the zip name lists from the zip directory.
   void getDirZipFileLists();

   // Show the zip name list.
   void showDirZipNameList();
   void showDirZipFileNameList();

   // Select a zip name from the zip name list. Return true if successful.
   bool setRunZipName(int aZipNum);

   // Set the zip name. Return true if successful.
   bool setRunZipName(const char* aZipName);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. These pertain to the zip dirctory.

   // Get the zip name lists from the zip directory and update
   // the metadata.
   bool doDirZip();

   // Unzip a zip file from the zip directory into the work directory.
   // Return true if successful.
   bool doLoadZip();
   bool doLoadZip(int aZipNum);
   bool doLoadZip(const char* aZipName);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. These pertain to the snippet dirctory.

   // Get the snippet file lists from the snippet directory.
   void getDirSnipFileLists();

   // Show the snippet name list.
   void showDirSnipNameList();
   void showDirSnipFileNameList();

   // Select a snippet name from the name list. Return true if successful.
   bool setRunSnipName(int aSnipNum);

   // Set the snittet name. Return true if successful.
   bool setRunSnipName(const char* aSnipFileName);

   // Get the snippet name lists from the snippet directory and update
   // the metadata.
   bool doDirSnip();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. These pertain to the snippet dirctory.

   // Copy the snippet file from the snippet directory into the work directory.
   // Return true if successful.
   bool doLoadSnip();
   bool doLoadSnip(int aSnipNum);
   bool doLoadSnip(const char* aSnipName);

   // Write a string to the temp snippet file.
   // Return true if successful.
   bool doWriteTempSnip(const char* aSnipFileContents);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. These pertain to the work dirctory.

   // Find the name of the gcode file in the work directory.
   bool doFindWorkGCodeFileName();

   // Return the file path to the gcode file.
   std::string getWorkGCodeFilePath();

   // Return the file path to a slice file.
   std::string getWorkSliceFilePath(int aSliceNumber);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. These pertain to the meta dirctory.

   // Create the meta directory and meta subdirectories.
   bool doCreateMetaDirs();

   // Extract metadata files from the zip files into the corresponding meta
   // subdirectories and fill in the json records.
   bool doFillMetaDirs();

   // Extract metadata files from the zip file into the corresponding meta
   // subdirectory. Fill in the corresponding json records.
   bool doFillMetaDir(
      int aListIndex,                 // Input
      Json::Value& aMetadataRecord,   // Output
      Json::Value& aPrologRecord);    // Output

   // Update a meta subdirectory history file and record print time
   // with the current time. Add the updated history file to the
   // associated zip file.
   bool doUpdateRunZipHistoryWithPrintTime();

   // Fill in the snippet metadata json store.
   bool doFillSnipMetadata();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Show.
   void show1();
   void show2();

   // Return true if the file exists,
   bool exists(std::string aFilePath);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global instance.

#ifdef _CXFILEMANAGER_CPP_
FileManager gFileManager;
#else
extern FileManager gFileManager;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace




