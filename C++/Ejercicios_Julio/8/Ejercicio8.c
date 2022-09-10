#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int resolver(double a, double b, double c, double* px1, double* px2);

int main(){
    //Lectura de imputs
    double a,b,c;
    double p1,p2;


    printf("Esta función encuientra la/s solucion/es de una ecuación cuadrática con los parámetros introducidos\n");
    printf("Primer valor (x²): ");
    scanf("%lf", &a);
    printf("Segundo valor (x): ");
    scanf("%lf", &b);
    printf("Último valor (N): ");
    scanf("%lf", &c);
    
    //Asignamos direcciones de salida a px1 y px2

    double* px1=&p1;
    double* px2=&p2;

    int x = resolver(a,b,c,px1,px2) > 0;
    if(x>0){
    printf("Compleja\n");
    printf("Parte real: %lf \n",*px1);
    printf("Parte Imaginaria: %lf i \n",*px2);
    }

    else{
    printf("No-Compleja\n");
    printf("Solución 1: %lf \n",*px1);
    printf("Solución 2: %lf \n",*px2);
    }
    return 0;
}


int resolver(double a, double b, double c, double* px1, double* px2){
    //Imput -> Ec 2o grado
    // -b +- (b² -4ac)/2a ;; Condiciones: a!=0, b!=0
    //Out: St en px1 y px2 <-> sol € R o NAN si no existe la solución
    //Si solo tiene 1 solución se guarda en px1
    //-----------return 0
    //Imaginario: 
    //-----------return 1

    //Control de parámetros
    if(a==0 && b==0){
        *px1 = NAN;
        *px2 = NAN;
        return 0;
    }

    // Usando el discriminante podemos saber cómo será el output de la raíz
    double D = pow(b,2) - (4*a*c);

    if(D < 0 ){
        //Solución no real
        *px1 = -(1*b)/(2*a); //Parte real
        *px2 = sqrt(-D)/(2*a); //Parte imaginaria
        return 1;
    }

    else if (D==0) //1 SOLUCIÓN
    {
        *px1 = -1*b/2*a;
        *px2 = NAN;
        return 0;
    }
    else //2 SOLUCIONES
    {
        *px1 = ((-1*b)+ sqrt(D))/2*a;
        *px2 = ((-1*b)-sqrt(D))/2*a;
        return 0;
    }
   
}

