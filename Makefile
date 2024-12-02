CXX = g++
CXXFLAGS = -I/usr/include/libxml2
LDFLAGS = -L/usr/lib64 -lxml2


all: parseXML

parseXML: parseXML.cpp
	$(CXX) $(CXXFLAGS) parseXML.cpp -o parseXML $(LDFLAGS)

clean:
	rm -f parseXML

