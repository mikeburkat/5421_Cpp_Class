CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		wordListDriver.o

LIBS =

TARGET =	wordListDriver

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
