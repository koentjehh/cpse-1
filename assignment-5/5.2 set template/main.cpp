#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>

#include "set.hpp"
#include "catch.hpp"

//int main(){
//}
//

TEST_CASE( "FLOAT NUMBERS SET SIZE OF 4" ){
	set< float, 4 > floatSet;
	floatSet.add(1.0);
	floatSet.add(2.0);
	floatSet.add(3.0);
	floatSet.add(4.0);
	//max
	floatSet.add(5.0);
	
	REQUIRE( floatSet.contains(1.0) == true );
	REQUIRE( floatSet.contains(4.0) == true );
	REQUIRE( floatSet.contains(5.0) == false );
}


TEST_CASE( "CHARS SET SIZE OF 8" ){
	set< char, 8 > charSet;
	charSet.add('a');
	charSet.add('b');
	charSet.add('c');
	charSet.add('d');
	charSet.add('e');
	charSet.add('f');
	charSet.add('g');
	charSet.add('h');
	//max
	charSet.add('i');
	
	REQUIRE( charSet.contains('a') == true );
	REQUIRE( charSet.contains('e') == true );
	REQUIRE( charSet.contains('h') == true );
	REQUIRE( charSet.contains('i') == false );
}