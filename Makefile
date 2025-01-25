all:
	g++ -I src/include -L src/lib -o main main.cpp renderer.cpp types.cpp -lmingw32 -lSDL3
