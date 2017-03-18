all :
	g++ -std=c++11 -g -I google-breakpad/src/ -o app app.cpp google-breakpad/src/client/linux/libbreakpad_client.a -lpthread
run : 
	./app
del :
	rm -f app