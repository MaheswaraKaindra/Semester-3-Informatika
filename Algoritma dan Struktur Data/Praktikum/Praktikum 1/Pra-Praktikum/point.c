#include "boolean.h"
#include "point.h"
#include <math.h>
#include <stdio.h>

void CreatePoint (POINT * P, float X, float Y){
    Absis(* P) = X;
    Ordinat(* P) = Y;
}
                                               
void BacaPOINT (POINT * P){
    float X, Y;
    scanf("%f %f", &X, &Y);
	 Absis(*P) = X;
	 Ordinat(*P) = Y;
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
    return((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P){
    return((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
    return(Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return(Absis(P) == 0);
}

int Kuadran (POINT P){
    int result = 0;
    if (Absis(P) > 0 && Ordinat(P) > 0){
        result = 1;
    }
    if (Absis(P) < 0 && Ordinat(P) > 0){
        result = 2;
    }
    if (Absis(P) < 0 && Ordinat(P) < 0){
        result = 3;
    }
    if (Absis(P)>0 && Ordinat(P)<0){
		  result = 4;
	 }
    return result;   
}
                         
POINT NextX (POINT P){
    Absis(P) += 1;
    return P;
}
             
POINT NextY (POINT P){
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if (SbX){
        Ordinat(P) *= -1; 
    }
    else{
		  Absis(P) *= -1;
	 }
    return P; 
}

float Jarak0 (POINT P){
    float q = ((Absis(P)*Absis(P))) + (Ordinat(P)*Ordinat(P));
    return(sqrt(q));
}

float Panjang (POINT P1, POINT P2){
    float q = ((Absis(P2) - Absis(P1))*(Absis(P2) - Absis(P1))) + ((Ordinat(P2) - Ordinat(P1))*(Ordinat(P2) - Ordinat(P1)));
    return(sqrt(q));
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
    if (SbX){
        Ordinat(*P) *= -1; 
    }
    else{
	  	  Absis(*P) *= -1;
	 }
}

void Putar (POINT *P, float Sudut){
    POINT temp;
	 float pi = 3.14159265358979323846;
    Absis(temp) = Absis(*P);
    Ordinat(temp) = Ordinat(*P);
    Absis(*P) = Absis(temp)*cos(Sudut*pi/180) + Ordinat(temp)*sin(Sudut*M_PI/180);
    Ordinat(*P) = -Absis(temp)*sin(Sudut*pi/180) + Ordinat(temp)*cos(Sudut*M_PI/180);
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    int a = (Ordinat(P2) - Ordinat(P1))/(Absis(P2) - Absis(P1));
    int b = (Ordinat(P1) - a * Absis(P1));
    printf("(%d,%d)", a, b);
}