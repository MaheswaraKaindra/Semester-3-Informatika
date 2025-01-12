#include "boolean.h"
#include "fraction.h"
#include <stdio.h>
#include <math.h>

int gcd(int N, int R) {
    if (R == 0) return N;
    return gcd(R, N % R);
}

boolean IsFRACTIONValid(int N, int D){
	if (D != 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void CreateFRACTION(FRACTION *F, int N, int R){
	Numerator(*F) = N;
	Denominator(*F) = R;
}

FRACTION SimplifyFRACTION(FRACTION F){
	int fpb;
	fpb = gcd(Numerator(F), Denominator(F));
	Numerator(F) = Numerator(F) / fpb;
	Denominator(F) = Denominator(F) / fpb;
	if ((Numerator(F) > 0 && Denominator(F) < 0) || (Numerator(F) < 0 && Denominator(F) < 0)){
		Numerator(F) *= -1;
		Denominator(F) *= -1;
	}
	return F;
}

void ReadFRACTION(FRACTION *F){
	int N, R;
	boolean temp;
	temp = false;
	do{
		scanf("%d %d", &N, &R);
		Numerator(*F) = N;
		Denominator(*F) = R;
		temp = IsFRACTIONValid(Numerator(*F), Denominator(*F));
		if (temp == true){
			break;
		}
		printf("FRACTION tidak valid\n");
	} while (temp == false);
}

void WriteFRACTION(FRACTION F){
	int N, R;
	F = SimplifyFRACTION(F);
	N = Numerator(F);
	R = Denominator(F);
	printf("%d/%d", N, R);
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2){
	FRACTION F3;
	Numerator(F3) = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
	Denominator(F3) = Denominator(F1) * Denominator(F2);
	return SimplifyFRACTION(F3);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2){
	FRACTION F3;
	Numerator(F3) = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
	Denominator(F3) = Denominator(F1) * Denominator(F2);
	return SimplifyFRACTION(F3);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
	FRACTION F3;
	Numerator(F3) = Numerator(F1) * Numerator(F2);
	Denominator(F3) = Denominator(F1) * Denominator(F2);
	return SimplifyFRACTION(F3);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2){
	FRACTION F3;
	Numerator(F3) = Numerator(F1) * Denominator(F2);
	Denominator(F3) = Denominator(F1) * Numerator(F2);
	return SimplifyFRACTION(F3);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1){
	FRACTION F3;
	int fpb;
	Numerator(F3) = Numerator(F1) * n;
	Denominator(F3) = Denominator(F1);
	return SimplifyFRACTION(F3);
}

float ToDecimal(FRACTION F){
	float result = (float)Numerator(F) / (float)Denominator(F);
	return result;
}