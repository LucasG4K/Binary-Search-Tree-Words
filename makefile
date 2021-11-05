output: main.o tree.o
	g++ main.cpp tree.cpp -o run

tree.o: tree.cpp tree.hpp
	g++ -c tree.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./run

clean:
	rm -f *.o *.exe