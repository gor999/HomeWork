#include <iostream>
#include "unit_test/unit_test.h"
#include "encoder/encoder.h"
#include "decoder/decoder.h"


int main(){
		int key;

		
	while(true){
		std::string before_encoder;
		
		std::cout<<"Press word for stop put break"<<std::endl;	
		std::getline(std::cin,before_encoder);
		if(before_encoder == "break"){
			break;
		}
		std::cout<<"Press key"<<std::endl;
		std::cin>>key;
		
		std::string after_encoder = encoder(before_encoder, key);
		std::cout<<after_encoder<<std::endl;
		std::string after_decoder = decoder(after_encoder, key);
		unit_test(before_encoder,after_decoder);
		
		std::cin.ignore(10000, '\n');	
	}
return 0;
}
