all: a

a : main.cpp artists.cpp tracks.cpp functeste.cpp
	g++ main.cpp artists.cpp tracks.cpp functeste.cpp -o main.exe
clean:
	del /S *.exe

DIR=""

run:a
	.\main.exe $(DIR)