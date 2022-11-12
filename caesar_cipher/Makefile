
all:create_directories create_obj lib/decoder/libdecoder.so lib/encoder/libencoder.so lib/libunit_test.a main


create_directories:
	@echo "creating directories..."
	@mkdir -p lib
	@mkdir -p bin

create_obj:
	@mkdir -p obj/encoder
	@mkdir -p obj/decoder
	@mkdir -p obj/unit_test
#decoder
obj/decoder/decoder.o:obj/decoder
	@echo "creating object file for decoder"
	@g++ -I./inc/decoder -c src/decoder/decoder.cpp -o obj/decoder/decoder.o

lib/decoder/libdecoder.so:obj/decoder/decoder.o
	@echo "creating Dinamic Library for decoder..."
	@g++ -fPIC -shared obj/decoder/decoder.o -o lib/libdecoder.so
#encoder
obj/encoder/encoder.o:obj/encoder
	@echo "creating object file for encoder"
	@g++ -fPIC -I./inc/encoder -c src/encoder/encoder.cpp -o obj/encoder/encoder.o

lib/encoder/libencoder.so:obj/encoder/encoder.o
	@echo "creating Dinamic Libreary for encoder..."
	@g++ -fPIC -shared  obj/encoder/encoder.o -o lib/libencoder.so

#unit_test

lib/libunit_test.a:obj/unit_test/unit_test.o
	@echo "unit_test static library declareded.."
	@ar cvq lib/libunit_test.a obj/unit_test/unit_test.o


obj/unit_test/unit_test.o:
	@echo "created obj link..."
	@g++ -c  src/unit_test/unit_test.cpp -I inc -o obj/unit_test/unit_test.o



main:
	@echo "Starting Program...."
	@g++ src/main.cpp -L./lib -I./inc/ -Wall -ldecoder -lencoder -lunit_test -o bin/main  
	@export LD_LIBRARY_PATH=`pwd`/lib  && ./bin/main

remove:
	@echo "cleaning directories"
	@rm -rf obj bin lib
