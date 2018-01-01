#include "Log.h"
#include <iostream>
namespace le{
	namespace io{
		void Log::log_if( std::string str, bool expr )
		{
			if( expr )
				std::cout << str << std::endl;
		}
		void Log::log( std::string str )
		{
			std::cout << str << std::endl;
		}
	}
}
