#include "Log.h"
#include <iostream>
namespace le{
	namespace io{
		void Log::log_if( const std::string str, const bool expr )
		{
			if( expr )
				log( str );
		}
		void inline Log::log( const std::string str )
		{
			std::cout << str << std::endl;
			//Todo : Write to LogFile
		}
	}
}
