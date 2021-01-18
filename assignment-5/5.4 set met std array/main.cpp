#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <array>

#include "set.hpp"
#include "catch.hpp"

//int main(){
//}
//

TEST_CASE( "CHARS SET SIZE OF 8" ){
	set< std::array<char,3>, 8 > arraySet;
	
	arraySet.add({'a','a','c'});
	arraySet.add({'c','d','f'});
	//max
	arraySet.add({'x','y','z'});
	
	REQUIRE( arraySet.contains({'c','d','f'}) == true );
	
	std::array<char,3> max = {'x','y','z'};
	
	REQUIRE( arraySet.max() ==  max );
}