#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <array>

template< typename T, int N >
class set {
private:
	T set_data [10] = {};
	const int set_size = N;
	int set_pointer = 0;
	
public:
	set()
	{}
	void add( T input_number ){
		if( set_pointer >= set_size ){ // set is vol
			return;
		}
		if( contains( input_number ) == true ){ // input staat al in set
			return;
		}
		else{
			set_data[set_pointer] = input_number;
			set_pointer++;
		}
	}
	
	void remove( T input_number ){ 
		int counter = 0;
		for( int i = 0; i < set_size; i++ ){
			if( set_data[i] == input_number ){
				for ( int i = 0; i < ( set_size - counter ); i++ ){
					set_data[i] = set_data[i+1];
				}
			}
			counter++;
		}
	}
	
	bool contains( T number ){
		for( int i = 0; i < 10; i++ ){
			if( set_data[i] == number ){
				return true;
			}
		}
		return false;
	}
	
	T max(){
		T max_value = set_data[0];
		for( int i = 0; i < set_size; i++ ){
			if( set_data[i] > max_value ){
				max_value = set_data[i];
			} 
		}
		return max_value;
	}
	
	friend std::ostream & operator<<(std::ostream & print, const set & s ){
		// friend = access to private members of set 
		print << "{ ";
		for( int i = 0; i < s.set_size; i++ ){
			print << s.set_data[i];
			print << ", ";
		}
		print << " }";
		return print;
	}
};

#endif