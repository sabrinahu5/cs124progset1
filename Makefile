CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

SRC = mst.cpp
HDR = binary_heap.hpp
OBJ = $(SRC:.cpp=.o)

TARGET = mst

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)