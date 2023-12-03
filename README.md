# CUDA Library Project Template

## How to build
    To build:	 
		$ cd ./cuda-library-project-template/
		$ make
	

## How to test
	To test:
		$ cd testing
		$ make
		$ export LD_LIBRARY_PATH=${PWD}/../lib
		$ ./test

## Compatable GPUs
	Volta
	You can add any arch of nvidia GPU in the Makefile
