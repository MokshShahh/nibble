CXX = g++
CXXFLAGS = -Wall -std=c++20

run: nibble
	cd bin && ./nibble

nibble: nibble.cpp
	$(CXX) $(CXXFLAGS) nibble.cpp -o bin/nibble

clean:
	rm -f nibble
