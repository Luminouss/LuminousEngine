#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define CONFIG_PATH "D:\\Game Engine\\Game\\LuminousEngine\\config.txt"

#define lc_getKey(A)  le::core::Singleton<le::io::Configuration>::get()->getByKey(A)

#define lc_setKey(A,B) le::core::Singleton<le::io::Configuration>::get()->setByKey(A,B)

#define lc_saveConfig() le::core::Singleton<le::io::Configuration>::get()->saveConfig()

#include <unordered_map>

namespace le{
	namespace io{
		class Configuration{
		private:
			std::unordered_map < std::string, std::string > m_configData;/** Map that holds the Configuration Strings */

		public:
			//Load()
			//Get()->bykey/byvalue(?)
			//Set()

			/**
			* Saves the Configuration and does cleanup work 
			* @return void
			*/
			void Finalize( );

			/**
			* Returns the Configuration value of a Key
			* @param key for the value
			* @return the value
			*/
			std::string __inline getByKey( const std::string& key )const;

			/**
			* Initializes Configuration and loads all Key/Value pairs
			* @return void
			*/
			void Initialize( );

			/**
			* Saves the current config 
			* @return void
			*/
			void saveCurrentConfig( );

			/**
			* Sets the value at specified key
			* @param key to be changed
			* @param value to be changed
			* @return void
			*/
			void setByKey( const std::string& key, const std::string& val );

			/**
			* Operator[] Overloading for getting Values
			* @param Key to the value you want to get
			* @return the value
			*/
			std::string operator[](const std::string );

		}; 
	}
}

#endif
