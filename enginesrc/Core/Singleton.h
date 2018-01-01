#ifndef SINGLETON_H
#define SINGLETON_H

#include <assert.h>


namespace le{
	namespace core{

		template <typename T>
		class Singleton{
		public:

			static bool create( )
			{
				if( Singleton::m_instance != nullptr )
					return false;

				Singleton::m_instance = new T( );
			}

			static T* create( T* in )
			{

				if( Singleton::m_instance != nullptr )
					return false;

				Singleton::m_instance = in;
			}

			static T* get( )
			{
				assert( Singleton::m_instance != nullptr );
				return Singleton::m_instance;
			}


			static bool destroy( )
			{
				if( Singleton::m_instance == nullptr )
					return false;

				delete Singleton::m_instance;
				return true;
			}

		private:
			static T* m_instance;
#pragma region Constructors
			Singleton( ) { }
			~Singleton( ) { }
			Singleton( Singleton const& ) = delete;
			Singleton& operator=( Singleton const& ) = delete;
			Singleton( Singleton const&& ) = delete;
			Singleton& operator=( Singleton const&& ) = delete;
#pragma endregion
		};

		template <typename T>
		T* Singleton<T>::m_instance = nullptr;

	}
}

#endif