#include <iomanip>
#include <iostream>
#include <tgmath.h>

using namespace std;

int main(){
//============= LER VALORES
    int totalFrequencia;
    cout << "Digite o somatório das frequências: ";
    cin >> totalFrequencia;    
    
    int totalClasses;
    cout << "Digite a quantidade de classes: ";
    cin >> totalClasses; 

    int vetor[totalFrequencia];
    
    for(int i = 0; i<totalFrequencia; i++){
        cout << "Digite o item da " << 1+i << "a posiçcão: ";
        cin >> vetor[i];
    }




//============= CALCULAR ALGUNS VALORES
    int menorValor;
    for(int i = 0; i<totalFrequencia; i++){
        if(i == 0 || vetor[i]<menorValor) menorValor = vetor[i];
    }

    int maiorValor;
    for(int i = 0; i<totalFrequencia; i++){
        if(i == 0 || vetor[i]>maiorValor) maiorValor = vetor[i];
    }

    int amplitude = maiorValor - menorValor;

    int larguraClasse = ceil((double)amplitude/totalClasses);

    int minValue = menorValor, maxValue = menorValor+larguraClasse-1, count = 0;


    

    cout << "\n===============================" << endl;
    cout << "Quantidade de casos: " << totalFrequencia << endl;
    cout << "Quantidade de classes: " << totalClasses << endl;
    cout << "Menor valor: " << menorValor << endl;
    cout << "Maior valor: " <<  maiorValor << endl;
    cout << "Amplitude: " <<  amplitude << endl;
    cout << "Largura de classe: " << larguraClasse << endl;
    cout << "===============================" << endl;




//============= IMPRIMIR A TABELA
    for(int i = 0; maiorValor>=minValue; i++){ 
        for(int j = 0; j < totalFrequencia; j++){
            if(vetor[j]>=minValue && vetor[j]<=maxValue){
                count++;
            }
        }
        /*      //DEIXAR A TABELA FORMATADA
        if(maiorValor>=1000){
            if(minValue<1000){
                cout << " ";
                if(minValue<100){
                    cout << " ";
                    if(minValue<10){
                        cout << " ";
                    }
                }
            }
        } else if(maiorValor>=100){
            if(minValue<100){
                cout << " ";
                if(minValue<10){
                    cout << " ";
                }
            }
        } else if(maiorValor>=10){
            if(minValue<10){
                cout << " ";
            }
        }*/
        cout << minValue << " - " << maxValue << " |  " << count << " ocorrências" << endl;

        minValue += larguraClasse;
        maxValue += larguraClasse;
        count = 0;
    }

    cout << "===============================" << endl;




//============= ORDENAR VETOR
    for (int i = 1; i < totalFrequencia; i++) {
        for (int j = 0; j < totalFrequencia - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    cout << "\nVetor ordenado: ";
    for (int i = 0; i < totalFrequencia; i++) {
        cout << vetor[i] << " ";
    }




//============= CALCULAR MÉDIA
    float media = 0;
    for(int i = 0; i<totalFrequencia; i++){
        media +=(float)vetor[i]/totalFrequencia;
    }
    cout << "\n\nMédia: " << media << endl;




//============= CALCULAR MEDIANA
    float mediana = 0;
    if((totalFrequencia%2)==0){
        mediana = (float)(vetor[(totalFrequencia/2)-1]+vetor[totalFrequencia/2])/2;
    } else {
        mediana = (float) vetor[totalFrequencia/2];
    }
    cout << "Mediana: " << mediana << endl;




//============= CALCULAR MODA
    int valor = 0, maiorrep = 0, rep = 0;
    for(int i = 0; i < totalFrequencia; i++){
        rep = 0;
        for(int j = i; j < totalFrequencia; j++){
            if(vetor[i]==vetor[j]){
                rep++;
            }
        }

        if(rep>maiorrep){
            maiorrep = rep;
            valor = vetor[i];
        }
    }
    cout << "Moda: " << valor << " | (" << maiorrep << " rep)" << endl;
}