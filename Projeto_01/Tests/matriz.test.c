#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Libs/matriz/matriz.h"
#include "../Libs/minUnit/minUnit.h"

int tests_run = 0;

static char* SOMA_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/soma.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'+');
    mu_assert("ERROR: FALHA NA SOMA DO ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(&m,&res));
    clearMatriz(&m) ; clearMatriz(&res);
    return 0;
}

static char* SUBTRACAO_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/subtr.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'-');
    mu_assert("ERROR: FALHA NA SUBTRACAO DO ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(&m,&res));
    clearMatriz(&m) ; clearMatriz(&res);
    return 0;
}


static char* MULTIPLICACAO_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/mult.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'*');
    mu_assert("ERROR: FALHA NA MULTIPLICACAO DO ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(&m,&res));
    clearMatriz(&m) ; clearMatriz(&res);
    return 0;
}

static char* DIVISAO_ESCALAR_MATRIZ(){
    Matriz m = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz res = prepMatriz("./src/Resultados/divs.csv");
    float num = 2.0F;
    opEscalarMatriz(&m,&num,'/');
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(&m,&res));
    clearMatriz(&m) ; clearMatriz(&res);
    return 0;
}

static char* MULTIPLICACAO_MATRIZES(){
    Matriz m1 = prepMatriz("./src/Matrizes/matriz_01.csv");
    Matriz m2 = prepMatriz("./src/Matrizes/matriz_02.csv");
    Matriz m3; m3.matriz = buildMatriz();
    Matriz res = prepMatriz("./src/Resultados/multM.csv");
    multMatrizes(&m1,&m2,&m3);
    mu_assert("ERROR: FALHA NA DIVISAO DO ESCALAR NOS ELEMENTOS DA MATRIZ",eqMatriz(&m3,&res));
    clearMatriz(&m1) ; clearMatriz(&m2) ; clearMatriz(&m3) ;clearMatriz(&res);
    return 0;
}

static char* all_tests(){
    mu_run_test(SOMA_ESCALAR_MATRIZ);
    mu_run_test(SUBTRACAO_ESCALAR_MATRIZ);
    mu_run_test(MULTIPLICACAO_ESCALAR_MATRIZ);
    mu_run_test(DIVISAO_ESCALAR_MATRIZ);
    mu_run_test(MULTIPLICACAO_MATRIZES);
    return 0;
}

int main(int argc, char **argv){
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}