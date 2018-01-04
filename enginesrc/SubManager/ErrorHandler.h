#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#define lerr_setErr(A) le::core::Singleton<le::sm::ErrorHandler>::get()->setLastErr(A)
#define lerr_setErr(A,B) le::core::Singleton<le::sm::ErrorHandler>::get()->setLastErr(A,B)

#define lerr_getErr() le::core::Singleton<le::sm::ErrorHandler>::get()->getLastErr()
#define lerr_getErrStr() le::core::Singleton<le::sm::ErrorHandler>::get()->getLastErrStr()
#define lerr_getErrCode() le::core::Singleton<le::sm::ErrorHandler>::get()->getLastErrCode()

#include <string>
#include <unordered_map>
namespace le{
	namespace sm{
		enum ErrorCode{
			LERR_UNDEFINED = 0
		};

		struct ErrorMessage{
		public:
			ErrorCode errCode;
			std::string errMessage;
		};

		class ErrorHandler{
		public:
			void Initialize( );
			void Finalize( );
			ErrorMessage getLastErr( )const ;
			ErrorCode getLastErrCode( )const;
			std::string getLastErrorStr( )const;
			void setLastErr( const ErrorCode& ,const std::string &message = "");
		private:
			std::unordered_map<ErrorCode, std::string>m_errorMessages;
			ErrorMessage m_lastError;
		};
	}
}
#endif