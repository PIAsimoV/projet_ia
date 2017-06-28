minim:
	g++ -std=c++11 -o minimale src/cam/minimale.cpp `pkg-config opencv --cflags --libs`

alexnet:
	g++ -std=c++11 -o alexnet src/cam/alexnet.cpp `pkg-config opencv --cflags --libs`

usb:
	g++ -std=c++11 -o usb_alexnet src/cam/usb_alexnet.cpp `pkg-config opencv --cflags --libs`

googlenet:
	g++ -std=c++11 -o googlenet src/cam/googlenet.cpp `pkg-config opencv --cflags --libs`

save:
	g++ -std=c++11 -o save src/cam/save.cpp `pkg-config opencv --cflags --libs`

clean:
	rm save
	rm minimale
	rm alexnet
	rm googlenet
	rm usb_alexnet
