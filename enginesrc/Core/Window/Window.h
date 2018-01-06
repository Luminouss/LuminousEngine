#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <Windows.h>

#include "Helpers/Size.h"

namespace le{
	namespace core{
		namespace wnd{
			struct WindowInformation{
				//Todo: make everything private and add getters-setters
			public:
				/**Name of the Window*/
				LPCSTR name;
				/**Name of the Window Class*/
				LPCSTR className;
				/**Title of the Window*/
				LPCSTR title;
				/**Window Handle*/
				HWND window;
				/**Main programs Instance Handle*/
				HINSTANCE hInstance;

				/**Window Size*/
				SIZE2D32 size;

				WindowInformation( ) :
					name( "" ),
					className( "" ),
					window( NULL ),
					hInstance( NULL )
				{ }
			};

			class Window{
			public:
				/**
				* Creates the Window
				* @return true if Window was created successfully, false otherwise check log for more info
				*/
				bool createWindow( );
				/**
				* Registers the Windowclass
				* @return true if WindowClass was registered successfully, false otherwise check log for more info
				*/
				bool registerWndClass( );

				/**
				* Finalizes and shows the Window
				* @return true if everything succeeded, false if not, check log for more info
				*/
				bool finalizeWindow( );

				/**
				* Returns the WindowInformations
				* @return the WindowInformation object
				*/
				WindowInformation getWindowInformation( );
				/**
				* Set the WindowInformation
				* @param WindowInformation to be set
				* @return void
				*/
				void setWindowInformation( WindowInformation& );

				Window( );
				~Window( );
				Window( const Window& rhs ) = delete;
				Window( const Window&& rhs ) = delete;
				Window& operator=( const Window& rhs ) = delete;
				Window& operator=( const Window&& rhs ) = delete;
			private:
				/**Private WindowInformation Object, stores all the Informations about the Window*/
				WindowInformation m_wndInfo;
			};
		}
	}
}
#endif