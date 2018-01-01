#ifndef LOG_H
#define LOG_H

#include <string>

#ifdef _DEBUG
#define ll_log(A) le::core::Singleton<le::io::Log>::get()->log(A)
#define ll_log_if(A,B)le::core::Singleton<le::io::Log>::get()->log_if(A,B)
#else
#define ll_log(A) 
#define ll_log_if(A,B)
#endif

namespace le{
	namespace io{
		class Log{
		public:
			/**
			* Logs the specified String 
			* @param String to be logged
			* @return void
			*/
			void log( std::string str );
			/**
			* Logs the specified String if a certain Expression evaluates to true
			* @param String to be logged
			* @param Expression to be checked
			* @return void
			*/
			void log_if( std::string str, bool expr );
		};
	}
}

typedef le::io::Log LuminousLog;


#endif