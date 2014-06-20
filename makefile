TARGET		= fakeled

INCPATH		= -I ./

OBJECTS		= main.o \
		  fakeled.o \
		  fifoserver.o \
		  fakeledparser.o
		  
LIBS		= -L/.

$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) -o $(TARGET) $(LIBS)

main.o: main.cpp
	$(CXX) -c $(INCPATH) -o main.o main.cpp

fakeled.o: fakeled.cpp fakeled.h
	$(CXX) -c $(INCPATH) -o fakeled.o fakeled.cpp

fifoserver.o: fifoserver.cpp fifoserver.h
	$(CXX) -c $(INCPATH) -o fifoserver.o fifoserver.cpp
	
fakeledparser.o: fakeledparser.cpp fakeledparser.h fakeled.h
	$(CXX) -c $(INCPATH) -o fakeledparser.o fakeledparser.cpp

clean:
	rm -fv *.o
	rm -f *.fakeled
	rm -f *~ core *.core
 
