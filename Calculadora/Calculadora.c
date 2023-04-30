#include<stdio.h>

float suma(int num1, int num2);
float resta(int num1, int num2);
float multipli(int num1, int num2);
void division(float num1, float num2);
void menu();

float num1, num2;

int main(){

  menu();

  return 0;
}

void menu(){

  char operador;
  float num1, num2;
  float resp;

  do{
    printf("\n\nBienvenido a la calculadora, elija una de las siguientes opciones:\n\n - 1. Suma\n - 2. Resta\n - 3. Multiplicacion\n - 4. Division\n\n");
    scanf("\t%c", &operador);

    printf("Ingrese los numeros que va a operar: \n\n");
    scanf("\t%f %f", &num1, &num2);

    switch (operador){
    case '1':
      resp = suma(num1,num2);
      printf("El resultado de la suma es: %.2f\n", suma(num1,num2));
      break;

    case '2':
      resp = resta(num1,num2);
      printf("El resultado de la resta es: %.2f\n", resta(num1,num2));
      break;

    case '3':
      resp = multipli(num1,num2);
      printf("El resultado de la multiplicacion es: %.2f\n", multipli(num1,num2));
      break;

    case '4':
      division(num1,num2);
      break;

    default:
      printf("\n\n ERROR ¡La operacion es Invalida! ");
      break;
    }
  }while((operador != 'A') && (operador != 'B') && (operador != 'C') && (operador != 'D'));
}

float suma(int num1, int num2){

  int sum;

  sum = num1 + num2;

  return sum;
}

float resta(int num1, int num2){

  int rest;

  rest = num1 - num2;

  return rest;
}

float multipli(int num1, int num2){

  int multi;

  multi = num1 * num2;

  return multi;
}

void division(float num1, float num2){

  float div;

  if(num2 != 0){
    div = num1 / num2;
    printf("El resultado de la division es %.2f",div);
  }else{
    printf("No se puede dividir entre 0\n");
  }

}
