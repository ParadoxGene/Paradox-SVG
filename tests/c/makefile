mkfile_dir := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

all:
	cmake -S $(mkfile_dir) -B $(mkfile_dir)/../../build/c_unit_tests
	cmake --build $(mkfile_dir)/../../build/c_unit_tests