#ifndef LOG_H
#define LOG_H

#include <string>

#ifdef _DEBUG
#define ll_log(A) le::core::Singleton<le::io::Log>::get()->log(A)
#define ll_log_if(A,B)le::core::Singleton<le::io::Log>::get()->log_if(A,B)
#else
#define ll_log(A) 
#endif

namespace le{
	namespace io{
		class Log{
		public:
			void log( std::string str );
			void log_if( std::string str, bool expr );
		};
	}
}

typedef le::io::Log LuminousLog;


#endif