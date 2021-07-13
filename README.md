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

## Como compilar e Executar
Estar dentro da pasta src e usar o comando:

make run DIR=(endereço)

e passar o endereço do diretório onde se encontram os arquivos artistis.csv e tracks.csv (favor tê-los no mesmo diretório)

## Informações importantes

 A escrita das tracks em binário está ignorando 1331 tracks com strings muito grandes, pois estavam deixando o arquivo binario com tamanho maior que 2gb e causando problemas para leittura posteriosmente.
 Na impressao dos Artistas mais frequentes na tabelaHash alguns artistas e nomes de música estâo com problemas (provavelmente devido a algum erro de tratamento na escrita do arquivo binário).