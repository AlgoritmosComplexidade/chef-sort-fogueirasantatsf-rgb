#include <stdio.h>
#include <string.h>

/* Versão comentada do Bubble Sort para strings.
 */

void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
    /* arr como um array 2D de strings,
     * cada string pode ter até 49 caracteres + '\\0'.
     *
     * comparacoes e trocas são ponteiros porque quero que a
     * função atualize esses números e o main veja o resultado.
     */

    int i, j;
    char temp[50];

    /* Acho que é melhor zerar os contadores aqui, caso
     * quem chamar não tenha inicializado.
     */
    if (comparacoes) *comparacoes = 0;
    if (trocas) *trocas = 0;

    /* Loop externo: faço passagens até n-1 (parece que é o padrão) */
    for (i = 0; i < n - 1; i++) {
        int trocou = 0; /* flag pra saber se a passagem fez alguma troca */

        /* Loop interno: comparo pares adjacentes */
        for (j = 0; j < n - i - 1; j++) {
            /* conto cada comparação que eu faço */
            if (comparacoes) (*comparacoes)++;

            /* strcmp > 0 significa arr[j] vem depois alfabeticamente que arr[j+1] */
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                /* preciso trocar as strings; uso uma temporária com strcpy */
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);

                /* conto a troca realizada */
                if (trocas) (*trocas)++;
                trocou = 1;
            }
        }

        /* Se não trocou nada nessa passagem, já tá ordenado -> posso parar */
        if (!trocou) break;
    }
}

int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------
    /* Aqui eu criei um array com 6 ingredientes. Cada string tem espaço para 50 chars.*/
    char ingredientes[6][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata", "Massa"};
    int num_ingredientes = 6;

    /* Vou usar variáveis pra guardar quantas comparações e trocas aconteceram.
     * Inicializo com zero só pra garantir.
     */
    int comparacoes = 0;
    int trocas = 0;
    int i;

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    /* Imprimo cada ingrediente antes de ordenar */
    for (i = 0; i < num_ingredientes; i++) {
        printf("%s\n", ingredientes[i]);
    }

    /* Chamo a função de ordenação. Atualiza comparacoes e trocas. */
    bubbleSortStrings(ingredientes, num_ingredientes, &comparacoes, &trocas);

    printf("\nLista depois da ordenação:\n");
    /* Imprimo o resultado pra ver se deu certo */
    for (i = 0; i < num_ingredientes; i++) {
        printf("%s\n", ingredientes[i]);
    }

    /* Aqui mostro as métricas — achei interessante ver quantas operações o algoritmo fez */
    printf("\nTotais: Comparacões: %d | Trocas: %d\n", comparacoes, trocas);

    return 0;
}
