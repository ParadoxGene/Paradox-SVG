mkfile_dir := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

all:
	cmake -S $(mkfile_dir) -B $(mkfile_dir)/../../build/c++_unit_tests
	cmake --build $(mkfile_dir)/../../build/c++_unit_tests