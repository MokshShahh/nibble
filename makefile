CXX = g++
CXXFLAGS = -Wall -std=c++20

run: nibble
	./nibble

nibble: nibble.cpp
	$(CXX) $(CXXFLAGS) nibble.cpp -o nibble

clean:
	rm -f nibble
