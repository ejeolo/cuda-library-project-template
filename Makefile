#libicmm.so

TARGETS = libicmm.so
GPU_ARCH= -arch=sm_70


all: $(TARGETS)



sub.o: gpu/sub.cu
	nvcc    -Xcompiler -fPIC $(GPU_ARCH) -c $<

add.o: gpu/add.cu
	nvcc    -Xcompiler -fPIC $(GPU_ARCH) -c $<
#-dc
#-rdc=true

add_link.o: add.o
	nvcc   -Xcompiler -fPIC  $(GPU_ARCH) -dlink   -o $@  $<  -L/usr/local/cuda/lib64 -lcudart -lcudadevrt

ic_add.o: src/ic_add.cpp
	g++ -fPIC -c $<  -L/usr/local/cuda/lib64 -I/usr/local/cuda/include -lcudart -lcudadevrt -I./

ic_sub.o: src/ic_sub.cpp
	g++ -fPIC -c $<  -L/usr/local/cuda/lib64 -I/usr/local/cuda/include -lcudart -lcudadevrt -I./

$(TARGETS): sub.o ic_sub.o add.o ic_add.o add_link.o
	mkdir -p lib
	g++ -shared -fPIC  $^  -o lib/libicmm.so -I/usr/local/cuda/include -L/usr/local/cuda/lib64 -lcudart -lcudadevrt 
	-rm -f *.o


.PHONY:clean
clean:
	-rm -f *.o lib/*.so test ./bin/test
	-rm -rf lib bin
