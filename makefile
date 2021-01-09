CC=g++
CFLAGS=-std=c++11

all:Bin BinPacker testBinPacker
	$(CC) $(CFLAGS) Bin.o BinPacker.o testBinPacker.o -o out
Bin:Bin.cpp
	$(CC) $(CFLAGS) -c Bin.cpp
BinPacker:BinPacker.cpp
	$(CC) $(CFLAGS) -c BinPacker.cpp
testBinPacker:testBinPacker.cpp
	$(CC) $(CFLAGS) -c testBinPacker.cpp
clean:
	rm *.o out *.txt
