all:
	cmake -G"Visual Studio 17" -B ./build/paradox-svg -S ./
	cmake --build ./build/paradox-svg