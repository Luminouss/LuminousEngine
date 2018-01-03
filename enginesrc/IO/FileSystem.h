#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#define lfs_copyFile(A,B) le::core::Singleton<le::io::FileSystem>::get()->copyFile(A,B,false)
#define lfs_copyFileO(A,B) le::core::Singleton<le::io::FileSystem>::get()->copyFile(A,B,true)

#define lfs_deleteFile(A) le::core::Singleton<le::io::FileSystem>::get()->deleteFile(A)

#define lfs_fileExist(A) le::core::Singleton<le::io::FileSystem>::get()->fileExist(A)

#define lfs_readFile(A,B) le::core::Singleton<le::io::FileSystem>::get()->readFile(A,B)
#define lfs_readFile(A) le::core::Singleton<le::io::FileSystem>::get()->readFile(A)
#define lfs_readFileF(A,B,C) le::core::Singleton<le::io::FileSystem>::get()->readFileRegionF(A,B,C)
#define lfs_readFileF(A,B) le::core::Singleton<le::io::FileSystem>::get()->readFileRegionF(A,B)
#define lfs_readFileFT(A,B,C,D) le::core::Singleton<le::io::FileSystem>::get()->readFileRegionFT(A,B,C,D)
#define lfs_readFileFT(A,B,C) le::core::Singleton<le::io::FileSystem>::get()->readFileRegionFT(A,B,C)

#define lfs_writeFile(A,B) le::core::Singleton<le::io::FileSystem>::get()->writeFile(A,B)
#define lfs_overwriteFile(A,B) le::core::Singleton<le::io::FileSystem>::get()->overwriteFile(A,B)
#define lfs_writeFileOff(A,B,C) le::core::Singleton<le::io::FileSystem>::get()->writeFileOffset(A,B,C)

namespace le{
	namespace io{

		class FileSystem{
			//read (from-to)	(X)
			//write (offset)	(X)
			//copy				(X)
			//delete			(X)
			//check if exists	(X)

		public:

			/**
			* Copies a File from one path to another
			* @param Path to the File which should be read from
			* @param Path to where the File should be copied to
			* @param Whether it should overwrite any already existing file or not
			* @return true if File got copied, false if a Error occured
			*/
			bool copyFile( const std::string& path, const std::string& outPath , const bool overwrite);

			/**
			* Deletes a File at a given Path
			* @param Path to the File which should be deleted
			* @return true if File got deleted, false if errors occured
			*/
			bool deleteFile( const std::string& path );

			/**
			* Checks if a File exists
			* @param Path to the File which should be checked
			* @return true if File exists false otherwise
			*/
			bool inline fileExist( const std::string& path );

			/**
			* Read the entire content of a specified File
			* @param Path to the File which should be read from
			* @param Reference to the String which will contain the content of the File
			* @return true if File was read correctly, false if a Error occured
			*/
			bool readFile( const std::string& path, std::string& outStr );

			/**
			* Read the entire content of a specified File
			* @param Path to the File which should be read from
			* @return The String that has been read
			*/
			std::string readFile( const std::string& path );

			/**
			* Read a specific Region of the File
			* @param Path to the File which should be read from
			* @param Reference to the String which will contain the content of the File
			* @param Beginning Offset of the Region to be read
			* @return true if File was read correctly, false if a Error occured
			*/
			bool readFileRegionF( const std::string& path, std::string& outStr, int begin);

			/**
			* Read a specific Region of the File
			* @param Path to the File which should be read from
			* @param Beginning Offset of the Region to be read
			* @return The String that has been read
			*/
			std::string readFileRegionF( const std::string& path, int begin);

			/**
			* Read a specific Region of the File
			* @param Path to the File which should be read from
			* @param Reference to the String which will contain the content of the File
			* @param Beginning Offset of the Region to be read
			* @param Amount of Characters to be read
			* @return true if File was read correctly, false if a Error occured
			*/
			bool readFileRegionFT( const std::string& path, std::string& outStr,int begin,int len );

			/**
			* Read a specific Region of the File
			* @param Path to the File which should be read from
			* @param Beginning Offset of the Region to be read
			* @param Amount of Characters to be read
			* @return The String that has been read
			*/
			std::string readFileRegionFT( const std::string& path ,int begin, int len);

			/**
			* Writes a Message into a specified File
			* @param Path to the File which should be written to
			* @param String to be written
			* @return true if File was written correctly, false if a Error occured
			*/
			bool writeFile( const std::string& path, const std::string& inStr );

			/**
			* Overwrites a specified File
			* @param Path to the File which should be written to
			* @param String to be written
			* @return true if File was written correctly, false if a Error occured
			*/
			bool overwriteFile( const std::string& path, const std::string& inStr );
			
			/**
			* Writes a Message into a specified File with an offset from the start
			* @param Path to the File which should be written to
			* @param String to be written
			* @param Offset for the written stuff
			* @return true if File was written correctly, false if a Error occured
			*/
			bool writeFileOffset( const std::string& path, const std::string& inStr ,int offset);
		};
	}
}

#endif