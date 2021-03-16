#ifndef TRAB1_ED2_2021_LEARQUIVO_H
    #define TRAB1_ED2_2021_LEARQUIVO_H

    #include "pilha.h"
    #include "planoR.h"

    /**
     * Le o arquivo de entrada e aloca os pontos lidos
     * @param {char*}FILENAME nome do arquivo a ser lido
     * @param {PlanoR*}p 
     * @return Estrutura planoR preenchida
     * @pre FILENAME e PlanoR existem
     * @post PlanoR modificado
     **/
    // PlanoR* leArquivo(char* FILENAME, PlanoR* p);

Pilha *leArquivo(char* FILENAMEINPUT, Pilha *p);
#endif
