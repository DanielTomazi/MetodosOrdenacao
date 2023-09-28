// Explicações e Exemplos dos 3 Métodos de Ordenação Escolhidos

// Método Selection Sort

// Criador: John Fletcher
// Ano: 1960 
// Finalidade: Ordenar listas e arrays em ordens específicas, como crescente ou decrescente.
// Mercado: O método Selection Sort não é tão utilizado no mercado, pois sua eficiência acaba sendo mediana quando camparada à outros métodos,porém ainda é uma boa alternativa para trabalhar com pequenos conjuntos de dados. 
// Linguagens Compatíveis: Pytho, Java, C++, C#, JavaScript, Ruby...
// Curiosidade: Ele é um algoritmo de ordenação instável, ou seja, se houver elementos iguais em uma lista não ordenada, a posição relativa dos mesmos pode ser alterada.

// Método Radix Sort

// Criador: Foi criado por vários cientistas e matemáticos
// Ano: 1936
// Finalidade: Resolver problemas específicos de ordenação de números inteiros ou de dados alfanuméricos, tendo como pilares de seu funcionamento a ordem em base específica, tamanho fixo de dados e valores de digitos limitados.
// Mercado: O método Radix Sort também não é muito utilizado no mercado, pois possui certas peculiardades em seu funcionamento que faz com que as empresas optem por outros métodos Sort. Alguns exemplos de seu uso são desde as ordenações de números inteiros de tamanho fixo até strings numéricas.
// Linguagens Compatíveis: Pytho, Java, C++, C#, JavaScript, Ruby e demais linguagens consideradas de baixo nível.
// Curiosidade: Ele pode ser usado para ordenação de números negativos e inteiros positivos sem necessitar de conversões ou tratamentos especiais devido a sua ordenação funcionar com base em dígitos individuais, incluindo os sinais positivos e negativos dos mesmos.

// Método Heap Sort

// Criador: J.W.J. Williams
// Ano: 1964
// Finalidade: Resolver problemas de ordenação utilizando a estrutura heap, também conhecida como árvore heap, que busca realizar ordenações de forma eficiente e estável em comparação aos demais métodos.
// Mercado: O método não chega a ser muito utilizado no mercado devido a ter uma certa falta de estabilidade e ineficiência para certos serviços que as empresas comercializam, seus usos podem ser para atividades que não foquem em estabilidade como os sistemas de gerenciamento de bancos de dados (DBMS).
// Linguagens Compatíveis: Pytho, Java, C++, C#, JavaScript, Ruby, Swift, PHP, Go...
// Curiosidade: Ele é muito usado como parte fundamental em algoritmos de prioridade em sistemas operacionais e estruturas de dados por conta de sua eficiência e uabilidade. 

// Código dos 3 métodos juntos em uma aplicação que o usuário eschole o método para ser realizado.

#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int numElements;
    int choice;

    do {
        printf("Digite o número de elementos: ");
        scanf("%d", &numElements);

        int array[numElements];
        printf("Digite os elementos separados por espaço: ");
        for (int i = 0; i < numElements; i++) {
            scanf("%d", &array[i]);
        }

        do {
            printf("Escolha o método de ordenação:\n");
            printf("1. Selection Sort\n");
            printf("2. Radix Sort\n");
            printf("3. Heap Sort\n");
            printf("4. Sair\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    selectionSort(array, numElements);
                    printf("Array ordenado usando Selection Sort: ");
                    break;
                case 2:
                    radixSort(array, numElements);
                    printf("Array ordenado usando Radix Sort: ");
                    break;
                case 3:
                    heapSort(array, numElements);
                    printf("Array ordenado usando Heap Sort: ");
                    break;
                case 4:
                    printf("Saindo do programa.\n");
                    break;
                default:
                    printf("Escolha inválida!\n");
                    break;
            }

            if (choice != 4) {
                printArray(array, numElements);
            }
        } while (choice != 4);

        printf("Deseja ordenar outro conjunto de elementos? (1 para Sim, 0 para Não): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}

// O código mostrado acima é uma junção das funcionalidades dos 3 métodos escolhidos. O objetivo por escolher estes métodos esta na praticidade de ordenação que eles apresentam nas listas que o usuário cria, pois no código é possivel que o usuário escolha os dados a serem ordenados, o método e, após finalizar a ordenação, se quer usar outro método ou se deseja parar. Na hora de sair do programa, é perguntado se o usuário deseja que outros dados sejam informados, como forma de comparar outros númros com os métodos escolhidos, uma funcionalidade foi atribuida com um looping externo no programa.



