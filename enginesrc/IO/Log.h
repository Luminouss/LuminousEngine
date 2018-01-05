#ifndef LOG_H
#define LOG_H

#include <string>
#include <windows.h>
#include <fstream>
#include <iostream>

#ifdef _DEBUG
#define ll_log(A) le::core::Singleton<le::io::Log>::get()->log(A)
#define ll_log_if(A,B) le::core::Singleton<le::io::Log>::get()->log_if(A,B)

//Todo: ;^)
#define ll_err(A) le::core::Singleton<le::io::Log>::get()->log(A)
#define ll_err_if(A,B) le::core::Singleton<le::io::Log>::get()->log_if(A,B)
#else
#define ll_log(A) 
#define ll_log_if(A,B)
#endif

namespace le{
	namespace io{
		class Log{
		public:
			/**
			* Initializes the Console Window and loads the Handles
			* @return void
			*/
			void Initialize( );

			/**
			* Logs the specified String 
			* @param String to be logged
			* @return void
			*/
			void inline log( const std::string str );
			/**
			* Logs the specified String if a certain Expression evaluates to true
			* @param String to be logged
			* @param Expression to be checked
			* @return void
			*/
			void log_if( const std::string str, const bool expr );
		private:
			FILE* m_fstreamin;
			FILE* m_fstreamout;
			HANDLE m_hConsoleInput, m_hConsoleOutput;
			HWND m_consoleWindow;
		};
	}
}



#endif