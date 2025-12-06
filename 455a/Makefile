CXX      = g++
CXXFLAGS = -std=c++17
problem  = 455a


run: $(problem).cpp
	$(CXX) $(CFLAGS) -o ${problem} ${problem}.cpp
	./$(problem)
	cat output.txt

clean:
	rm -rf $(problem)