#include <iostream>
#include "encoder/encoder.h"
#include "decoder/decoder.h"


int main(){
std::string before_encoder = "Hello world I am from American";
std::string after_encoder = encoder(before_encoder, 7);
std::cout<<after_encoder<<std::endl;
std::string after_decoder = decoder(after_encoder, 7);
std::cout<<after_decoder<<std::endl;

if(before_encoder == after_decoder){
	std::cout<<"Test_case_1: "<<"True"<<std::endl;
}

//std::cout<<decoder("Hello world From Armenia",  10000)<<std::endl;



return 0;
}
