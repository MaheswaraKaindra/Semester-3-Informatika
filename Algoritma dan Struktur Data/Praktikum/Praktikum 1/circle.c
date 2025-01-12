#include "point.h"
#include "boolean.h"
#include "circle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCIRCLEValid(float X, float Y, float R){
    if (R > 0) {
        return 1;
    }
}
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    Center(*C).X = X;
    Center(*C).Y = Y;
    Radius(*C) = R;
}
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C){
    float X, Y, R;
    boolean valid = false;
    do {
        scanf("%f %f %f", &X, &Y, &R);
        valid = IsCIRCLEValid(X,Y,R); 
        if (valid == false){
            printf("CIRCLE tidak valid");
        }
    } while (valid == false);
    
    Center(*C).X = X;
    Center(*C).Y = Y;
    Radius(*C) = R;
}
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", Center(C).X, Center(C).Y, Radius(C));
}
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C){
    float pi = 3.14;
    float K = 2 * pi * Radius(C);
    return K;
}
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */

float Area(CIRCLE C){
    float pi = 3.14;
    float A = pi * Radius(C) * Radius(C);
}
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
    float jarak = (Absis(P) - Center(C).X) * (Absis(P) - Center(C).X) + (Ordinat(P) - Center(C).Y) * (Ordinat(P) - Center(C).Y);
    return (sqrt(jarak) < Radius(C));
}
/* Mengirim true jika titik P berada di dalam lingkaran C */

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
    float jarak = (Absis(P) - Center(C).X) * (Absis(P) - Center(C).X) + (Ordinat(P) - Center(C).Y) * (Ordinat(P) - Center(C).Y);
    return (sqrt(jarak) == Radius(C));
}
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){\
    float jarak = sqrt((Center(C2).X - Center(C1).X) * (Center(C2).X - Center(C1).X) + (Center(C2).Y - Center(C1).Y) * (Center(C2).Y - Center(C1).Y));
    float selisih = abs(Radius(C2) - Radius(C1));
    return(jarak < selisih);
}   
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
    float jarak = sqrt((Center(C2).X - Center(C1).X) * (Center(C2).X - Center(C1).X) + (Center(C2).Y - Center(C1).Y) * (Center(C2).Y - Center(C1).Y));
    float selisih = abs(Radius(C2) - Radius(C1));
    float selisih2 = Radius(C2) + Radius(C1);
    return((jarak == selisih) || (jarak == selisih2));
}
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**

 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
    float jarak = sqrt((Center(C2).X - Center(C1).X) * (Center(C2).X - Center(C1).X) + (Center(C2).Y - Center(C1).Y) * (Center(C2).Y - Center(C1).Y));
    float selisih = abs(Radius(C2) - Radius(C1));
    float selisih2 = Radius(C2) + Radius(C1);
    return((selisih < jarak) && (jarak < selisih2));
}
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */

/* ***************************************************************** */