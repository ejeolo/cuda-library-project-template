# CUDA Library Project Template

## How to build
  To build:
		$ cd ./cuda-library-project-template/
		$ make clean
		$ make
	

## How to test
  To test:
		$ cd testing
		$ make clean
		$ make
		$ export LD_LIBRARY_PATH=${PWD}/../lib
		$ ./test
## Build bin/test without shared library
  To directly test:
	$ cd ./cuda-library-project-template/
	$ make clean
	$ make -f makefile_bin

## Compatable GPUs
  Volta
  You can add any arch of nvidia GPU in the Makefile
