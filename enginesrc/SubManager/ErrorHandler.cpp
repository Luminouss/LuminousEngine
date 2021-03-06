#include "ErrorHandler.h"
namespace le{
	namespace sm{
		void ErrorHandler::Initialize( )
		{
			//Load default Errors
			m_errorMessages.insert( std::make_pair( LERR_UNDEFINED, "Undefined Error Code" ) );
			m_errorMessages.insert( std::make_pair( LERR_NOPRIVILEGE, "No Privilege for the last move" ) );
			m_errorMessages.insert( std::make_pair( LERR_FILENOTFOUND, "Couldn't find File" ) );
			m_errorMessages.insert( std::make_pair( LERR_REGISTERWNDFAILED, "Couldn't register the Window Class" ) );
		}
		void ErrorHandler::Finalize( )
		{ }
		ErrorMessage ErrorHandler::getLastErr( ) const
		{
			return m_lastError;
		}
		ErrorCode ErrorHandler::getLastErrCode( ) const
		{
			return m_lastError.errCode;
		}

		std::string ErrorHandler::getLastErrStr( ) const
		{
			return m_lastError.errMessage;
		}

		void ErrorHandler::setLastErr( const ErrorCode & errCode,const std::string &msg)
		{ 
			m_lastError.errCode = errCode;
			if( msg == "" ){
				m_lastError.errMessage = ( m_errorMessages.find( errCode ) != m_errorMessages.end( ) ) ? m_errorMessages.at( errCode ) : "Unknown Error";
			} else{
				m_lastError.errMessage = msg;
			}
		}
	}
}

