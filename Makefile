build:
	g++ -std=c++17 ./src/*.cpp -o Allegro -I include -L lib -l SDL2-2.0.0

run:
	./Allegro

clean:
	rm Allegro
