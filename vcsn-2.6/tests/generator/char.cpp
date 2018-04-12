#include <random>
#include <iostream>
 
/* rm $(ls -I "*.cpp" ) */ 

int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 
 	std::cout << dis(gen) ; 


 	int temp = 5  ; /* le res ne change pas alors que moi je veux 
 	faire des testes sur le res changé, comment on va faire ? 
 	Creer un automate temp  */ 
 	if (temp + 5 < 20 && temp % 2 == 0 ) {
 		std::cout << "ok" ; 
 	}
 	else {
 		std::cout << "Not ok" ;  
 	}
 	
 
}