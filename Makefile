# ---------------------------------------------------------
# ---------------------------------------------------------
#	Note to keep as reference.
# ---------------------------------------------------------
# ---------------------------------------------------------
#
#setup:
#	creates a directory `build`
#	`moves` the directory `build` to the stack
#	sets up the project with cmake
#	`removes` the directory `build` from the stack
#
#project:
#	builds the project found in the `build` directory
#
#clean:
#	removes the directory `build`
#
setup:
	mkdir -p build/ &&\
	pushd build/ &&\
	cmake .. -G "Unix Makefiles" &&\
	popd
project:
	pushd build/ && make && popd
clean:
	rm -rf build/