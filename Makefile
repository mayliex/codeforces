TEMPLATE 	 = Makefile.template
OUTPUT 		 = Makefile
CXX 		 = g++
CXXFLAGS 	 = -std=c++17 -g

run: main.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp
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

debug:
	clang++ $(CXXFLAGS) -o main main.cpp
	lldb main

