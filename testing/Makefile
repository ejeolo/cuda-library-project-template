#test

TARGET = test

all: $(TARGET)

CXX_FLAGS = -I/usr/local/cuda/include -L/usr/local/cuda/lib64 -lcudart -lcudadevrt  -I../include -L../

test.o: test.cpp
	g++  -c $< $(CXX_FLAGS)

$(TARGET):test.o
	g++ $< -o $@ -L/usr/local/cuda/lib64 -lcudart -lcudadevrt  -L../lib  -licmm
	@echo "to execute: export LD_LIBRARY_PATH=${PWD}/../lib"

.PHONY:clean
clean:
	-rm -f *.o $(TARGET)
