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

Link do relatorio :https://docs.google.com/document/d/1ZWu4LiywHh_9iTz27FrEwu1a1mo9NKk1BUw5xRzGAf4/edit

## Descriçao
Trabalho da disciplina de Estruturas de dados 2 turma E  professora BARBARA DE MELO QUINTELA , relativo ao assunto de manipulação de arquivos .

## Como compilar e Executar
Estar dentro da pasta src e usar o comando:

make run DIR=(endereço dos arquivos csv)
**Para executar no linux, é necessario uma barra (/) após o endereço.

e passar o endereço do diretório onde se encontram os arquivos artistis.csv e tracks.csv (favor tê-los no mesmo diretório)

## Informações importantes

 A escrita das tracks em binário está ignorando 1331 tracks com strings muito grandes, pois estavam deixando o arquivo binario com tamanho maior que 2gb e causando problemas para leittura posteriosmente.
 Na impressao dos Artistas mais frequentes na tabelaHash alguns artistas e nomes de música estâo com problemas (provavelmente devido a algum erro de tratamento na escrita do arquivo binário).
