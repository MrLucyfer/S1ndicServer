SRCS = src/main.cpp src/Path.cpp src/Socket.cpp src/Server.cpp src/Logger.cpp src/DataBuffer.cpp src/Petition.cpp src/PetitionData.cpp src/RequestParser.cpp

OBJS = $(SRCS:.cpp=.o) # Here you get the .o of every .cpp

TARGET = bin/sw # The executable name

CC = g++

CXXFLAGS = -std=c++17 -g -Wall -lstdc++fs

all: $(TARGET)

clean:
	rm src/*.o

.PHONY: all

$(TARGET): $(OBJS) # This line will compile to .o every .cpp which need to be (which have been modified)
	$(CC) -o $(TARGET) $(OBJS) $(CXXFLAGS)