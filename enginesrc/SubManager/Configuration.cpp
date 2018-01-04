#include "Configuration.h"

#include <vector>

#include "Core/Singleton.h"
#include "Helpers/StringManipulator.h"
#include "FileSystem.h"

namespace le{
	namespace sm{
		void Configuration::Initialize( )
		{
			std::string filecontent = lfs_readFile( CONFIG_PATH );
			std::vector<std::string> pairs = help::StringManipulator::splitString(filecontent,'\n');
			for( auto it = pairs.begin( ); it != pairs.end( ) - 1; it++ ){
				std::vector<std::string> temp = help::StringManipulator::splitString( *it, '=' );
				setByKey( temp[0], temp[1] );
			}
		}
		void Configuration::Finalize( )
		{ 
			saveCurrentConfig( );
		}
		std::string __inline Configuration::getByKey( const std::string & key ) const
		{
			return m_configData.at(key);
		}
		void  Configuration::setByKey( const std::string & key, const std::string & val )
		{
			if( m_configData.find( key ) == m_configData.end( ) ){
				m_configData.insert( std::pair<std::string, std::string>( key, val ) );
			} else{
				m_configData[key] = val;
			}
		}
		void Configuration::saveCurrentConfig( )
		{
			std::string savedConfig;
			for( auto it = m_configData.begin( ); it != m_configData.end( ); it++ ){
				savedConfig += ( *it ).first + '=' + ( *it ).second + '\n';
			}

			lfs_overwriteFile( CONFIG_PATH, savedConfig );
		}
		std::string Configuration::operator[]( const std::string key)
		{
			return getByKey( key );
		}
	}
}
