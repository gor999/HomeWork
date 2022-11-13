all:create_directories main
CC=g++
CPPFLAGS=-c -Wall
SHARED = -fPIC -shared 
DECODE = obj/decoder/decoder.o  
ENCODE = obj/encoder/encoder.o  
LIB_DEC = lib/libdecoder.so
LIB_ENC = lib/libencoder.so:

UNIT_TEST = /unit_test/unit_test
SRC_ENCODER = src/encoder/encoder.cpp
SRC_DECODER = src/decoder/decoder.cpp

create_directories:
	@echo "creating directories..."
	@mkdir -p lib bin
	@mkdir -p obj/encoder
	@mkdir -p obj/decoder
	@mkdir -p obj/unit_test


#decoder
$(DECODE):
	$(ENCODE): @$(CC) -fPIC -I./inc/encoder $(CPPFLAGS) $(SRC_ENCODER) -o $@ 
	@$(CC) -fPIC -I./inc/decoder $(CPPFLAGS) $(SRC_DECODER) -o $@

$(ENCODE):
	@$(CC) -fPIC -I./inc/encoder $(CPPFLAGS) $(SRC_ENCODER) -o $@ 
	

$(LIB_DEC) : $(DECODE)
	@echo "decoder..."
	@$(CC) $(SHARED) $^ -o $@

lib/libencoder.so : $(ENCODE)
	@echo "encoder..."
	@$(CC) $(SHARED) $^ -o $@


#unit_test

lib/%.a: obj/unit_test/unit_test.o
	@echo "unit_test static library declareded.."
	@ar cvq lib/libunit_test.a obj/$(UNIT_TEST).o



obj/unit_test/unit_test.o:
	@echo "created obj link..."
	@$(CC) $(CPPFLAGS)  src/$(UNIT_TEST).cpp -I inc -o obj/$(UNIT_TEST).o



main:lib/libdecoder.so lib/libencoder.so lib/libunit_test.a
	@echo "Starting Program...."
	@$(CC) src/main.cpp -L./lib -I./inc/ -Wall -ldecoder -lencoder -lunit_test -o bin/main  
	@export LD_LIBRARY_PATH=`pwd`/lib  && ./bin/main

remove:
	@echo "cleaning directories"
	@rm -rf obj bin lib
