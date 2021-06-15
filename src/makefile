all: a.exe

a.exe : main.cpp artists.cpp tracks.cpp functeste.cpp
		g++ main.cpp artists.cpp tracks.cpp functeste.cpp -o main.exe
clean:
	del /S *.exe

DIR=""

run:a.exe
	main.exe $(DIR)