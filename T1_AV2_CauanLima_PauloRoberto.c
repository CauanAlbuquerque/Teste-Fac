// Cauan Albuquerque de Lima
// Paulo Roberto da Rocha Faria
#include <stdio.h>
#define N 5

void exibe_produtos(int vCod[], int vEstoque[], int tamanhoExibe){
    int i;
    for (i = 0; i < tamanhoExibe; i++){
        printf("código: %d / estoque %d\n",vCod[i], vEstoque[i]);
    }
}


void ler_percentuais(float percentuais[], int tamanhoPer, float minimo, float maximo){
    int contador = 0;
   
    while (contador <= tamanhoPer) {
        printf("digite o percentual %d: ",contador);
        scanf("%f", &percentuais[contador]);
        if (percentuais[contador] >= minimo && percentuais[contador] <= maximo){
            contador ++;
        }
        else{
            printf("Percentual inválido! ");
        }
    }
}
void calcular_limites_dinamicos(int vCod, float *min, float *max){
    int margem;
    margem = 0.1 + (vCod % 100) * 0.2;
    *min= 0.01 - margem;
    *max= 0.01+ margem;
}

int calcular_alteracao(int codigo, float *quantidade, float percentuais){
    int minimo, maximo; 
    calcular_limites_dinamicos(codigo, &minimo, &maximo);
    if(codigo>=minimo && codigo<=maximo){
        *quantidade = *quantidade * percentuais;
        return 1;
    }
    return 0;
}
int main(){
    int percentuais[10];
    float min = 0.1,max = 0.5; 
    int i, tamanho = 10;
    int vCod[N] = {2374, 1259, 9860, 4123, 3051};
    int vEstoque[N] = {100, 150, 200, 80, 50};
    exibe_produtos(&vCod, &vEstoque, 5);
    calcular_limites_dinamicos(vCod[N], &min, &max);
    ler_percentuais(&percentuais, tamanho,min,max);
    for(i = 0; i < N; i++){
        calcular_alteracao(vCod[i], vEstoque[i], percentuais[i]);
    }
    
    return 0;
}