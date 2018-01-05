#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H

#include <string>
#include <vector>

namespace le{
	namespace help{
		class StringManipulator{
		public:
			static std::vector<std::string> splitString( std::string splitString, const char splitter )
			{ 
				//Todo: fix and cleanup
				std::vector<std::string> temp;
				size_t splitpos = splitString.find( splitter );
				while( true ){
					if( splitpos == -1 ){
						temp.push_back( splitString );
						return temp;
					} else{
						temp.push_back( splitString.substr( 0, splitpos ) );
						splitString.erase( splitString.begin( ), splitString.begin( ) + splitpos +1 );
						splitpos = splitString.find( splitter );
					}
				}
			}
		};
	}
}

#endif
