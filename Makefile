all: getip-fcgi

getip-fcgi: getip.cpp
	g++ -std=c++1y -O3 -Wall -o getip-fcgi getip.cpp -lfcgi

install: getip-fcgi
	cp getip-fcgi /usr/bin/

clean:
	rm -rf getip-fcgi
