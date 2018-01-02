#include "FileSystem.h"

#include <boost/filesystem.hpp>

namespace le{
	namespace io{
		bool FileSystem::copyFile( const std::string& path, const std::string& outPath , const bool overwrite)
		{
			//Todo: Error handling
			if( fileExist( path ) ){
				if( fileExist( outPath ) ){
					if( overwrite ){
						boost::filesystem::copy_file( path, outPath, boost::filesystem::copy_option::overwrite_if_exists );
						return true;
					} else{
						return false;
					}
				} else{
					boost::filesystem::copy_file( path, outPath);
					return true;
				}
			} else{
				return false;
			}
		}

		bool FileSystem::deleteFile( const std::string& path )
		{
			if( fileExist( path ) ){
				std::remove( path.c_str( ) );
				return true;
			}
			//Todo: Error Handling
			return false;
		}

		bool inline FileSystem::fileExist( const std::string& path )
		{
			return boost::filesystem::exists( path );
		}

		bool FileSystem::readFile( const std::string& path, std::string& outStr )
		{
			//Todo: Error Handling
			boost::filesystem::path p{ path };
			boost::filesystem::ifstream ifs{ p };
			std::string temp;
			while( getline( ifs, temp ) )
				outStr += temp;
			return true;
		}

		std::string FileSystem::readFile( const std::string& path)
		{
			//Todo: Error Handling
			boost::filesystem::path p{ path };
			boost::filesystem::ifstream ifs{ p };
			std::string temp,a;
			while( getline( ifs, a ) )
				temp += a;
			return temp;
		}

		bool FileSystem::writeFile( const std::string& path, const std::string& inStr )
		{
			//Todo: Error Handling
			//Todo: Add Overwrite Handling
			boost::filesystem::path p{ path };
			std::string temp = readFile( path );
			boost::filesystem::ofstream ofs{ p };
			ofs << temp << inStr;
			return true;
		}
	}
}