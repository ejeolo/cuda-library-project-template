#libicmm.so

TARGETS = libicmm.so

all: $(TARGETS)

add.o: gpu/add.cu
	nvcc    -Xcompiler -fPIC -arch=sm_70 -c $<
#-dc
#-rdc=true

add_link.o: add.o
	nvcc   -Xcompiler -fPIC   -arch=sm_70 -dlink   -o $@  $<  -L/usr/local/cuda/lib64 -lcudart -lcudadevrt

ic_add.o: src/ic_add.cpp
	g++ -fPIC -c $<  -L/usr/local/cuda/lib64 -I/usr/local/cuda/include -lcudart -lcudadevrt -I./

$(TARGETS): add.o ic_add.o add_link.o
	g++ -shared -fPIC  $^  -o lib/libicmm.so -I/usr/local/cuda/include -L/usr/local/cuda/lib64 -lcudart -lcudadevrt 
	-rm -f *.o


.PHONY:clean
clean:
	-rm -f *.o lib/*.so test ./bin/test
