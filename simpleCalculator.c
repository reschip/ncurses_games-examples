#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


float suma(float firstNumber,float secondNumber){
    return firstNumber + secondNumber;
}
float resta(float firstNumber,float secondNumber){
    return firstNumber - secondNumber;
}
float dv(float firstNumber,float secondNumber){
    return firstNumber / secondNumber;
}
float mul(float firstNumber,float secondNumber){
    return firstNumber * secondNumber;
}

void setNumbers(float *firstNumber,float *secondNumber){
    printf("\nPrimer Numero:");
    scanf("%f",firstNumber);
    printf("\nSegundo Numero:");
    scanf("%f",secondNumber);
}


int main(){
    char *cadena = malloc(sizeof(char) * 20);
    int i = 1;
    char enter = 0;
    float firstNumber = 0.0, secondNumber=0.0,resultado = 0.0;
    while (i !=0)
    {   
        printf("\n1-Suma\n2-Resta\n3-Division\n4-Multiplicacion\n0-Salir\nSelecciona Una operacion:");
        scanf("%d",&i);
        switch (i){
        case 0: break;
        case 1:
            printf("Suma\n");
            setNumbers(&firstNumber,&secondNumber);
            resultado = suma(firstNumber,secondNumber);
            break;
        case 2:
            printf("Resta\n");
            setNumbers(&firstNumber,&secondNumber);
            resultado = resta(firstNumber,secondNumber);
            break;
        case 3:
            printf("Division\n");
            setNumbers(&firstNumber,&secondNumber);
            resultado = dv(firstNumber,secondNumber);
            break;
        case 4:
            printf("Multiplicacion\n");
            setNumbers(&firstNumber,&secondNumber);
            resultado = mul(firstNumber,secondNumber);
            break;        
        default:
            printf("\n\tSeleccion Un Numero Valido\n");
            break;
        }
        if(i != 0){
        printf("Resultado: %f",resultado);
        printf("\nPresione Enter Para Continuar\n");
        scanf("%c",&enter);
        scanf("%c",&enter);
        while(enter != '\n'){ scanf("%c",&enter); }
        system("clear");
        }
        
    }
    printf("Salio del Programa\n");

    return 0;
}
