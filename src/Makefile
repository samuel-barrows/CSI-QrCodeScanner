CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include
LIB := lib
LIBRARIES   := -lQrCode -lBarcodeReaderDemo

EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) -I$(INCLUDE) $^ -o $@ -L$(LIB) $(LIBRARIES)

clean:
	-rm $(BIN)/*
