CXX = g++
CFLAG = -Wall -std=c++14
TARGET = main.exe
OBJECTS = print.o main.o

run: all
	main.exe

all: $(TARGET)

main.exe: $(OBJECTS)
	$(CXX) $(CFLAG) -o $@ $^

clean:
	del $(OBJECTS) $(TARGET)