#include "Log.h"
#include <iostream>
namespace le{
	namespace io{
		void Log::Initialize( )
		{
			m_fstreamin= nullptr;
			m_fstreamout = nullptr;
			if( AllocConsole() ==NULL ){
				return;
			}

			freopen_s( &m_fstreamin, "CONIN$", "r", stdin );
			freopen_s( &m_fstreamout, "CONOUT$", "w", stdout );

			m_hConsoleInput = GetStdHandle( STD_INPUT_HANDLE );
			m_hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
			m_consoleWindow = GetConsoleWindow( );

			if( m_fstreamin == nullptr || m_fstreamout == nullptr || !m_hConsoleInput || !m_hConsoleOutput || !m_consoleWindow ){
				return;
			}

		}
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
