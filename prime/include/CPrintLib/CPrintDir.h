#pragma once

/*==============================================================================
This unit provides a set of functions that provide management of a
relocatable cprint directory to be used by programs that use cprint.
==============================================================================*/
//******************************************************************************
//******************************************************************************
//******************************************************************************
//
#include <string>
#include <vector>

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace CPrint
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// cprint directory management functions.
//

// Return the cprint directory path.
const char* getBaseDirectory();

// Set the program working directory to the cprint directory path.
void setProgramDir();

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Return directory paths.

std::string getBaseDirPath();
std::string getZipDirPath();
std::string getSnipDirPath();
std::string getWorkDirPath();
std::string getSpecialDirPath();
std::string getMetaDirPath();
std::string getImageDirPath();
std::string getMetaSubDirPath(std::string& aSubDirName);

//******************************************************************************
//******************************************************************************
//******************************************************************************
// cprint directory management functions.

// Clean the cprint work directory.
void doCleanWork();
void doCleanMeta();

// Get a directory listing of the cprint zip directory and return a list of
// filenames of zip files. The filenames do not include the filepath.
void getZipFileNameList(
   std::string& aZipDirPath, 
   std::vector<std::string >& aZipFileNameList,
   std::vector<std::string >& aZipNameList,
   std::vector<std::string >& aZipTimeStampList);

// Get a directory listing of the cprint snippet directory and return a list
// of filenames of gcode files. The filenames do not include the filepath.
void getSnipFileNameList(
   std::string& aSnipDirPath, 
   std::vector<std::string >& aSnipFileNameList,
   std::vector<std::string >& aSnipNameList,
   std::vector<std::string >& aSnipTimeStampList);

// Find the gcode file in the work directory and return its filename.
void doFindWorkGCodeFileName(
   std::string& aGCodeFileName);

// Find the gcode file in a directory and return its path.
void doFindGCodeFilePath(std::string& aDirPath, std::string& aGCodeFilePath);

// Unzip a zip file from the zip directory to the work directory.
void doUnzipToWork(
   std::string& aZipFilePath);

// Zip a zip file from the work directory to the zip directory.
void doZipFromWork(
   std::string& aZipFilePath);

// Copy a file to the work directory..
void doCopyToWork(
   std::string& aFilePath);

// Touch a file.
void doTouch(
   std::string& aFilePath);

// Create a directory.
void doCreateDir(
   std::string& aDirPath);

// Unzip a zip file, extracting a single target file, into
// a destination directory.
bool doUnzipFileToDir(
   std::string& aZipFilePath,
   std::string& aTargetFileName,
   std::string& aDestinDirPath);

// Add or update a file to an existing zip file.
bool doAddFileToZipFile(
   std::string& aSourceFilePath,
   std::string& aDestinZipFilePath);

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
