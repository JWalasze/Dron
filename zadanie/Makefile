CPPFLAGS= -c -g -Wall -Iinc -pedantic -std=c++17 

__start__: DronPodwodny
	./DronPodwodny

DronPodwodny: obj/Dr3D_gnuplot_api.o obj/main.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/LZespolona.o obj/InterfejsRysowania.o obj/Bryla.o obj/Graniastoslup.o obj/Prostopadloscian.o obj/Dron.o obj/Sruba.o
	g++ -o DronPodwodny  obj/main.o obj/Dr3D_gnuplot_api.o -lpthread\
						obj/Wektor.o\
						obj/Macierz.o\
						obj/LZespolona.o\
						obj/MacierzOb.o\
						obj/InterfejsRysowania.o\
						obj/Bryla.o\
						obj/Graniastoslup.o\
						obj/Prostopadloscian.o\
						obj/Dron.o\
						obj/Sruba.o
						
						
obj/main.o: src/main.cpp 	inc/Dr3D_gnuplot_api.hh inc/Macierz.hh inc/Wektor.hh\
        					 inc/LZespolona.hh inc/MacierzOb.hh inc/InterfejsRysowania.hh inc/Bryla.hh inc/Prostopadloscian.hh inc/Graniastoslup.hh inc/Dron.hh inc/Sruba.hh
	g++ ${CPPFLAGS} -o  obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh 
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/MacierzOb.o: src/MacierzOb.cpp inc/MacierzOb.hh 
	g++ ${CPPFLAGS} -o obj/MacierzOb.o src/MacierzOb.cpp

obj/InterfejsRysowania.o: src/InterfejsRysowania.cpp inc/InterfejsRysowania.hh
	g++ ${CPPFLAGS} -o obj/InterfejsRysowania.o src/InterfejsRysowania.cpp

obj/Bryla.o: src/Bryla.cpp inc/Bryla.hh
	g++ ${CPPFLAGS} -o obj/Bryla.o src/Bryla.cpp

obj/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh 
	g++ ${CPPFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp	

obj/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Sruba.o: src/Sruba.cpp inc/Sruba.hh
	g++ ${CPPFLAGS} -o obj/Sruba.o src/Sruba.cpp

clear:
	rm obj/*.o DronPodwodny
