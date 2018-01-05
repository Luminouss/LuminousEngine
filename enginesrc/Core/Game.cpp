#include "Game.h"
namespace le{
	namespace core{
		Game::Game( )
		{ 
			m_window = nullptr;
		}

		void Game::setWindow( wnd::Window * wnd)
		{
			m_window = wnd;
		}

		Game::~Game( )
		{ 
			delete m_window;
		}
	}
}

