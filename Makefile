TEMPLATE 	= Makefile.template
OUTPUT 		= Makefile
CXX 		= g++
CXXFLAGS 	= -std=c++17

run: main.cpp
	$(CXX) $(CFLAGS) -o main main.cpp
	./main
	cat output.txt

solution:
	cp main.cpp solutions/$(problem).cpp
	rm -rf main.cpp
	cp template.cpp main.cpp
	rm -rf input.txt
	rm -rf output.txt
	touch input.txt
	touch output.txt
