#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>

#include "set.hpp"
#include "catch.hpp"

//int main(){
//}

TEST_CASE( "ADDING (MAX 10) UNIQUE ELEMENTS TO SET" ){
	set set1;
	set1.add(1);
	set1.add(2);
	set1.add(3);
	set1.add(4);
	set1.add(5);
	set1.add(5);
	set1.add(6);
	set1.add(7);
	set1.add(8);
	set1.add(9);
	set1.add(10);
	set1.add(11);
	set1.add(12);
	REQUIRE( set1.contains(1) == true );
	REQUIRE( set1.contains(5) == true );
	REQUIRE( set1.contains(10) == true );
	REQUIRE( set1.contains(12) == false );
}

TEST_CASE( "ADDING AND REMOVING ELEMENTS" ){
	set set1;
	set1.add(1);
	set1.add(2);

	REQUIRE( set1.contains(1) == true );
	REQUIRE( set1.contains(2) == true );
	
	set1.remove(1);
	set1.remove(2);

	REQUIRE( set1.contains(1) == false );
	REQUIRE( set1.contains(2) == false );
}