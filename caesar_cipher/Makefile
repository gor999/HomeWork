all:remove create_directories main
CC=g++
cpp_src = src/encoder.cpp src/decoder.cpp 
obj_src = obj/encoder.o obj/decoder.o
lib_src = lib/libencoder.so lib/libdecoder.so
obj_stat_src = src/unit_test.cpp
lib_stat = lib/libunit_test.a
stat_src = obj/unit_test.o

create_directories:
	@echo "creating directories..."
	@mkdir -p lib bin
	@mkdir -p obj 
$(obj_src): $(cpp_src)	 
	$(CC) -c -Wall $< -fPIC -I./inc/ -o $@ 
$(lib_src):$(obj_src)
	$(CC) $< -fPIC -shared -o $@
$(stat_src):src/unit_test.cpp
	$(CC) -c  src/unit_test.cpp -fPIC -I./inc/ -o obj/unit_test.o
$(lib_stat):$(stat_src)
	@ar cvq $(lib_stat) $(stat_src)
main:$(lib_src) $(lib_stat)
	@$(CC) src/main.cpp -L./lib -I./inc/ -Wall -ldecoder -lencoder -lunit_test -o bin/main  
	export LD_LIBRARY_PATH=`pwd`/lib/  && ./bin/main
	@echo "Starting Program...."
remove:
	rm -rf obj bin lib
	@echo "cleaning directories"
