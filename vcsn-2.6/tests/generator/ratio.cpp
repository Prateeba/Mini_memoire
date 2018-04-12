// ratio example
#include <iostream>
#include <ratio>

int main (){
	const int max  = 1000 ; 
    int count = 63 ; 
	typedef std::ratio<(const int*) count,max> ratio_aut;

	std::cout << "Ratio = " << ratio_aut::num << "/" << ratio_aut::den << " (which is : " << ( double(ratio_aut::num) / ratio_aut::den ) << ")" << std::endl;


	return 0;
}