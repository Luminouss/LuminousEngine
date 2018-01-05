#include "FileSystem.h"

#include <boost/filesystem.hpp>

#include "Core/Singleton.h"
#include "SubManager/ErrorHandler.h"

namespace le{
	namespace io{
		bool FileSystem::copyFile( const std::string& path, const std::string& outPath, const bool overwrite )
		{
			if( fileExist( path ) && fileExist( outPath ) ){
				if( overwrite ){
					boost::filesystem::copy_file( path, outPath, boost::filesystem::copy_option::overwrite_if_exists );
					return true;
				} else{
					lerr_setErr( sm::LERR_NOPRIVILEGE );
					return false;
				}
			} else if( fileExist( path ) && !fileExist( outPath ) ){
				boost::filesystem::copy_file( path, outPath );
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return false;
			}
		}

		bool FileSystem::deleteFile( const std::string& path )
		{
			if( fileExist( path ) ){
				std::remove( path.c_str( ) );
				return true;
			}
			lerr_setErr( sm::LERR_FILENOTFOUND );
			return false;
		}

		bool inline FileSystem::fileExist( const std::string& path )
		{
			return boost::filesystem::exists( path );
		}

		bool FileSystem::readFile( const std::string& path, std::string& outStr )
		{
			if( fileExist( path ) ){
				//Todo: what if File is already opened?(dont know if thats a problem while reading)
				boost::filesystem::path p{ path };
				boost::filesystem::ifstream ifs{ p };
				std::string temp;
				while( getline( ifs, temp ) )
					outStr += temp + '\n';
				return true;
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return false;
			}
		}

		std::string FileSystem::readFile( const std::string& path )
		{
			if( fileExist( path ) ){
				boost::filesystem::path p{ path };
				boost::filesystem::ifstream ifs{ p };
				std::string temp, a;
				while( getline( ifs, a ) )
					temp += a + '\n';;
				return temp;
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return "";
			}
		}

		bool FileSystem::readFileRegionF( const std::string & path, std::string & outStr, int begin )
		{
			if( fileExist( path ) ){
				outStr = readFile( path ).substr( begin );
				return true;
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return false;
			}
		}

		std::string FileSystem::readFileRegionF( const std::string & path, int begin )
		{
			if( fileExist( path ) ){
				return readFile( path ).substr( begin );
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return "";
			}
		}

		bool FileSystem::readFileRegionFT( const std::string & path, std::string & outStr, int begin, int len )
		{
			if( fileExist( path ) ){
				outStr = readFile( path ).substr( begin, len );
				return true;
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return false;
			}
		}

		std::string FileSystem::readFileRegionFT( const std::string & path, int begin, int len )
		{
			if( fileExist( path ) ){
				return readFile( path ).substr( begin, len );
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return "";
			}
		}

		bool FileSystem::writeFile( const std::string& path, const std::string& inStr )
		{
			if( fileExist( path ) ){
				//Todo: Add Overwrite Handling
				//Todo: what if file is already opened?
				boost::filesystem::path p{ path };
				std::string temp = readFile( path );
				boost::filesystem::ofstream ofs{ p };
				ofs << temp << inStr;
				return true;
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return false;
			}
		}
		bool FileSystem::overwriteFile( const std::string & path, const std::string & inStr )
		{
			if( fileExist( path ) ){
				//Todo: Add Overwrite Handling
				//Todo: what if file is already opened?
				boost::filesystem::path p{ path };
				boost::filesystem::ofstream ofs{ p };
				ofs << inStr;
				return true;
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return false;
			}
		}
		bool FileSystem::writeFileOffset( const std::string & path, const std::string & inStr, int offset )
		{
			if( fileExist( path ) ){
				//Todo: Add Overwrite Handling
				boost::filesystem::path p{ path };
				std::string temp = readFileRegionFT( path, 0, offset ) + inStr + readFileRegionF( path, offset );
				boost::filesystem::ofstream ofs{ p };
				ofs << temp;
				return true;
			} else{
				lerr_setErr( sm::LERR_FILENOTFOUND );
				return false;
			}
		}
	}
}