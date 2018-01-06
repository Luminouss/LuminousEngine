#include "Window.h"

#include "Core/Singleton.h"
#include "IO/Log.h"

#include "Helpers/Defines.h"

namespace le{
	namespace core{
		namespace wnd{

			LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
			{
				switch( msg ){
					// Check if the window is being destroyed.
				case WM_DESTROY:
				{
					PostQuitMessage( 0 );
					return 0;
				}

				// Check if the window is being closed.
				case WM_CLOSE:
				{
					PostQuitMessage( 0 );
					return 0;
				}

				// All other messages pass to the message handler in the system class.
				default:
				{
					return DefWindowProc( hwnd, msg, wparam, lparam );
				}
				}
			}

			bool Window::finalizeWindow( )
			{
				if( !ShowWindow( m_wndInfo.window, SW_SHOWDEFAULT ) ){
					ll_err( "Window was already Visible before");
				}
				if( !UpdateWindow( m_wndInfo.window ) ){
					ll_err( "Error in Window::finalizeWindow() - could not update Window with Errorcode" + WindowsErrorStr( ) );
					return false;
				}
				return true;
			}
			WindowInformation Window::getWindowInformation( )
			{
				return m_wndInfo;
			}
			void Window::setWindowInformation( WindowInformation & wndinfo )
			{
				m_wndInfo = wndinfo;
			}
			Window::Window( )
			{

			}
			Window::~Window( )
			{

			}
			bool Window::createWindow( )
			{
				m_wndInfo.window = CreateWindowEx(
					WS_EX_APPWINDOW,
					m_wndInfo.className,
					m_wndInfo.name,
					WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
					400, 400,
					m_wndInfo.size.width, m_wndInfo.size.height,
					NULL, NULL,
					m_wndInfo.hInstance,
					NULL
				);
				if( m_wndInfo.window == NULL ){
					ll_err( "Error in Window::createWindow() - could not Create Window with error Code" + WindowsErrorStr( ) );
					return false;
				}
				return true;
			}
			bool Window::registerWndClass( )
			{
				//Todo: make this customizable
				WNDCLASSEX wndex{ 0 };
				wndex.cbSize = sizeof( WNDCLASSEX );
				wndex.hIcon = wndex.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
				wndex.hCursor = LoadCursor( NULL, IDC_ARROW );
				wndex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
				wndex.cbClsExtra = 0;
				wndex.cbWndExtra = 0;
				wndex.hInstance = m_wndInfo.hInstance;
				wndex.lpfnWndProc = ( WNDPROC ) WndProc;
				wndex.lpszClassName = m_wndInfo.className;
				wndex.lpszMenuName = NULL;
				wndex.hbrBackground = ( HBRUSH ) GetStockObject( BLACK_BRUSH );
				if( !RegisterClassEx( &wndex ) ){
					ll_err( "Error in Window::registerWndClass() - could not register WNDCLASS with error Code" + WindowsErrorStr( ) );
					return false;
				}
				return true;
			}
		}
	}
}