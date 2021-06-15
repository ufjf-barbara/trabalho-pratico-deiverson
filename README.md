# Trabalho Pratico 

## Equipe

👤 **Deiverson**

* Github:[@DeiversonMAP](https://github.com/DeiversonMAP) 
* Matricula: (201965123AB)


👤 **Deyvison Gregorio Dias**

* Github:[@deyvisongdias](https://github.com/deyvisongdias)
* Matricula: (201835017)

👤 **Gabriel Duque**

* Github:[@gabrielduqueschiffner](https://github.com/gabrielduqueschiffner)
* Matricula:(201965033A)


## Descriçao
Trabalho da disciplina de Estruturas de dados 2 turma E  professora BARBARA DE MELO QUINTELA , relativo ao assunto de manipulação de arquivos .

## Como compilar
g++ main.cpp artists.cpp tracks.cpp functeste.cpp

## Como rodar
all: a.exe

a.exe : main.cpp artists.cpp tracks.cpp functeste.cpp
		g++ main.cpp artists.cpp tracks.cpp functeste.cpp -o main.exe
clean:
	del /S *.class

DIR=""

run:a.exe
	main.exe $(DIR)	
