
all:create_directories create_obj lib/decoder/libdecoder.so lib/encoder/libencoder.so main




create_directories:
	@echo "creating directories..."
	@mkdir -p lib
	@mkdir -p bin

create_obj:
	@mkdir -p obj/encoder
	@mkdir -p obj/decoder

#decoder
obj/decoder/decoder.o:obj/decoder
	@echo "creating object file for decoder"
	g++ -I./inc/decoder -c src/decoder/decoder.cpp -o obj/decoder/decoder.o

lib/decoder/libdecoder.so:obj/decoder/decoder.o
	@echo "creating Dinamic Library"
	g++ -fPIC -shared obj/decoder/decoder.o -o lib/libdecoder.so
#encoder
obj/encoder/encoder.o:obj/encoder
	@echo "creating object file for encoder"
	g++ -fPIC -I./inc/encoder -c src/encoder/encoder.cpp -o obj/encoder/encoder.o

lib/encoder/libencoder.so:obj/encoder/encoder.o
	@echo "creating Dinamic Libreary"
	g++ -fPIC -shared  obj/encoder/encoder.o -o lib/libencoder.so

main:
	#g++ -c src/main.cpp -I inc/ -o obj/main.o
	g++ src/main.cpp -L./lib -I./inc/ -Wall -ldecoder -lencoder -o bin/main  #lencoder
	export LD_LIBRARY_PATH=`pwd`/lib  && ./bin/main



remove:
	@echo "cleaning directories"
	@rm -rf obj bin lib
