#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#define lerr_setErr(A,B) le::core::Singleton<le::sm::ErrorHandler>::get()->setLastErr(A,B)
#define lerr_setErr(A) le::core::Singleton<le::sm::ErrorHandler>::get()->setLastErr(A)

#define lerr_getErr() le::core::Singleton<le::sm::ErrorHandler>::get()->getLastErr()
#define lerr_getErrStr() le::core::Singleton<le::sm::ErrorHandler>::get()->getLastErrStr()
#define lerr_getErrCode() le::core::Singleton<le::sm::ErrorHandler>::get()->getLastErrCode()

#include <string>
#include <unordered_map>
namespace le{
	namespace sm{
		/**
		* Error Codes
		*/
		enum ErrorCode{ 
			/**Undefined error errorcode*/
			LERR_UNDEFINED = 0,
			/**No privilege errorcode*/
			LERR_NOPRIVILEGE,
			/**File not found errorcode*/
			LERR_FILENOTFOUND,
			/**Window Class could not be registered*/
			LERR_REGISTERWNDFAILED
		};
		/**
		* ErrorMessage to store the last ErrorMessage
		*/
		struct ErrorMessage{
		public:
			/**error code of the last error*/
			ErrorCode errCode;
			/**error message of the last error*/
			std::string errMessage; 
		};

		class ErrorHandler{
		public:
			/**
			* Finalizes the ErrorHandler class, currently does nothing
			* @return void
			*/
			void Finalize( );
			/**
			* Get last saved error code
			* @return The last saved errorcode
			*/
			ErrorCode getLastErrCode( )const;
			/**
			* Get last saved error message
			* @return The last saved error message
			*/
			ErrorMessage getLastErr( )const ;
			/**
			* Get the last saved error string
			* @return last saved error string
			*/
			std::string getLastErrStr( )const;
			/**
			* Initializes the default error message
			* @return void
			*/
			void Initialize( );
			/**
			* Set the last error
			* @param errorcode of the error
			* @param optional error message of the error
			*/
			void setLastErr( const ErrorCode& ,const std::string &message = "");
		private:
			/**Map that holds the default error messages, retrieved with an specified errorcode*/
			std::unordered_map<ErrorCode, std::string>m_errorMessages;
			/**last errormessage*/
			ErrorMessage m_lastError; 
		};
	}
}
#endif