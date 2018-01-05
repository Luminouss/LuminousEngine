#ifndef GAME_H
#define GAME_H

#include "Window\Window.h"

namespace le{
	namespace core{
		class Game{
		public:
			Game( );
			//Todo: what if we need more than 1 window
			/**
			* Sets the main window 
			* @param pointer to the Window
			* @return void
			*/
			void setWindow(wnd::Window* );


			virtual ~Game( );
			Game( const Game& rhs ) = delete;
			Game& operator=( const Game& rhs ) = delete;
			Game( const Game&& rhs ) = delete;
			Game& operator=( const Game&& rhs ) = delete;
		private:
			/**Pointer to the main window*/
			wnd::Window* m_window;
		};
	}
}
#endif