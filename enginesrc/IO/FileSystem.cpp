#include "FileSystem.h"

#include <boost/filesystem.hpp>

namespace le{
	namespace io{
		bool FileSystem::copyFile( const std::string& path, const std::string& outPath, const bool overwrite )
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
					boost::filesystem::copy_file( path, outPath );
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
				outStr += temp + '\n';
			return true;
		}

		std::string FileSystem::readFile( const std::string& path )
		{
			//Todo: Error Handling
			boost::filesystem::path p{ path };
			boost::filesystem::ifstream ifs{ p };
			std::string temp, a;
			while( getline( ifs, a ) )
				temp += a + '\n';;
			return temp;
		}

		bool FileSystem::readFileRegionF( const std::string & path, std::string & outStr, int begin )
		{
			outStr = readFile( path ).substr( begin );
			//Todo: Error Handling
			return true;
		}

		std::string FileSystem::readFileRegionF( const std::string & path, int begin )
		{

			return readFile( path ).substr( begin );
		}

		bool FileSystem::readFileRegionFT( const std::string & path, std::string & outStr, int begin, int len )
		{

			outStr = readFile( path ).substr( begin, len );
			//Todo: Error Handling
			return true;
		}

		std::string FileSystem::readFileRegionFT( const std::string & path, int begin, int len )
		{
			return readFile( path ).substr( begin, len );
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
		bool FileSystem::overwriteFile( const std::string & path, const std::string & inStr )
		{

			//Todo: Error Handling
			//Todo: Add Overwrite Handling
			boost::filesystem::path p{ path };
			boost::filesystem::ofstream ofs{ p };
			ofs <<inStr;
			return true;
		}
		bool FileSystem::writeFileOffset( const std::string & path, const std::string & inStr, int offset )
		{
			//Todo: Error Handling
			//Todo: Add Overwrite Handling
			boost::filesystem::path p{ path };
			std::string temp = readFileRegionFT( path ,0,offset) + inStr + readFileRegionF(path,offset);
			boost::filesystem::ofstream ofs{ p };
			ofs << temp;
			return true;
		}
	}
}