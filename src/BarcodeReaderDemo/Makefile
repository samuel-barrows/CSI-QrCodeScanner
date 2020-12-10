CC=g++
CCFLAGS=-fPIC -c -Wall

DBRLIB_PATH=../../lib/
#DBRLIB_PATH=../../Lib/ARM32
LDFLAGS=-L $(DBRLIB_PATH) -Wl,-rpath=$(DBRLIB_PATH) -Wl,-rpath=./
DBRLIB=-lDynamsoftBarcodeReader

STDLIB=-lstdc++

TARGET=BarcodeReaderDemo
OBJECT=BarcodeReaderDemo.o
SOURCE=BarcodeReaderDemo.cpp

# build rule for target.
$(TARGET): $(OBJECT)
	$(CC) -o $(OBJECT) $(STDLIB) $(DBRLIB) $(LDFLAGS)

# target to build an object file
$(OBJECT): $(SOURCE)
	$(CC) $(CCFLAGS) $(SOURCE)

# the clean target
.PHONY : clean
clean: 
	rm -f $(OBJECT) $(TARGET)

