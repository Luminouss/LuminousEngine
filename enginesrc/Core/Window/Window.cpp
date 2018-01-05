#include "Window.h"

#include "Core/Singleton.h"
#include "IO/Log.h"

namespace le{
	namespace core{
		namespace wnd{

			LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
			{
				switch( msg ){
				case WM_CLOSE:
				{
					DestroyWindow( hwnd );
					break;
				}
				case WM_DESTROY:
				{
					PostQuitMessage( 0 );
					break;
				}
				case WM_DISPLAYCHANGE:
				{
					InvalidateRect( hwnd, NULL, FALSE );
				}
				default:
				{
					return DefWindowProc( hwnd, msg, wParam, lParam );
				}
				}
			}
			bool Window::finalizeWindow( )
			{
				if( !ShowWindow( m_wndInfo.window, SW_SHOWDEFAULT ) ){
					ll_err( "Error in Window::finalizeWindow() - could not show Window with Errorcode" + GetLastError( ) );
					return false;
				}
				if( !UpdateWindow( m_wndInfo.window ) ){
					ll_err( "Error in Window::finalizeWindow() - could not update Window with Errorcode" + GetLastError( ) );
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
					0,
					m_wndInfo.className,
					m_wndInfo.title,
					WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL | WS_MINIMIZEBOX,
					CW_USEDEFAULT, CW_USEDEFAULT,
					m_wndInfo.size.width, m_wndInfo.size.height,
					NULL, NULL,
					m_wndInfo.hInstance,
					NULL
				);
				if( m_wndInfo.window == NULL ){
					ll_err( "Error in Window::createWindow() - could not Create Window with error Code" + std::to_string( GetLastError( ) ) );
					return false;
				}
				return true;
			}
			bool Window::registerWndClass( )
			{
				//Todo: make this customizable
				WNDCLASSEX wndex{ 0 };
				wndex.cbSize = sizeof( WNDCLASSEX );
				wndex.hIcon = LoadIcon( NULL, IDI_APPLICATION );
				wndex.hCursor = LoadCursor( NULL, IDC_ARROW );
				wndex.style = CS_HREDRAW | CS_VREDRAW;
				wndex.hInstance = m_wndInfo.hInstance;
				wndex.lpfnWndProc = ( WNDPROC ) WndProc;
				wndex.lpszClassName = m_wndInfo.className;
				wndex.hbrBackground = ( HBRUSH ) GetStockObject( WHITE_BRUSH );
				if( !RegisterClassEx( &wndex ) ){
					ll_err( "Error in Window::registerWndClass() - could not register WNDCLASS with error Code" + GetLastError( ) );
					return false;
				}
				return true;
			}
		}
	}
}