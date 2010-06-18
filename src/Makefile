all: test_hdf4object

test_hdf4object: test.o hdf4object.o
	g++ test.o hdf4object.o -o test_hdf4object -lmfhdf -ldf -ljpeg

test.o: test.cpp
	g++ -c test.cpp -I /usr/include/hdf

hdf4object.o: hdf4object.cpp
	g++ -c hdf4object.cpp -I /usr/include/hdf

clean:
	rm -f *.o test_hdf4object

