all:remove create_directories main
CC=g++
src_main_cpp = src/main/*.cpp 
src_test_cpp = $(wildcard src/test/*.cpp)
obj_test_src = $(patsubst src/test/%.cpp,obj/test/%.o,$(src_test_cpp))
lib_stat = $(patsubst obj/test/%.o,lib/test/lib%.a,$(obj_test_src)) 
cpp_src = $(wildcard src/*.cpp)
obj_src = $(patsubst src/%.cpp,obj/%.o,$(cpp_src))						
lib_din = $(patsubst obj/%.o,lib/lib%.so,$(obj_src)) 

create_directories:
	@echo "creating directories..."
	@mkdir -p lib/test
	@mkdir -p bin 
	@mkdir -p obj/test/

$(obj_src): $(cpp_src)	 
	$(CC) -c -Wall $< -fPIC -I./inc/ -o $@ 
$(lib_din):$(obj_src)
	$(CC) $< -fPIC -shared -o $@	

$(obj_test_src):$(src_test_cpp)
	$(CC) -c $(src_test_cpp) -fPIC -I./inc/ -o $@

$(lib_stat):$(obj_test_src)
	@ar cvq $(lib_stat) $(obj_test_src)

main:$(lib_din) $(lib_stat)
	@$(CC) $(src_main_cpp) -L./lib -I./inc/ && -I./inc/test -Wall -ldecoder -lencoder -lunit_test -o bin/main  
	export LD_LIBRARY_PATH=`pwd`/lib/  && ./bin/main
	@echo "Starting Program...."
remove:
	rm -rf obj bin lib
	@echo "cleaning directories"
