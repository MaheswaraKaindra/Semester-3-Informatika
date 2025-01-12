/* Fakta suksesor(X,Y) yang menyatakan bahwa Y adalah suksesor dari X, dengan Y<9 dan 0<=X<=8 */
suksesor(0,1).
suksesor(1,2).
suksesor(2,3).
suksesor(3,4).
suksesor(4,5).
suksesor(5,6).
suksesor(6,7).
suksesor(7,8).

/* Aturan, jumlah(X, Y, Z) benar jika Z adalah hasil jumlah Z dan Y, dan Z kurang dari 10 */
/* Basis */
jumlah(0, Y, Y) :- Y < 10.
/* Rekurens */
jumlah(X, Y, Z) :- suksesor(A, X), jumlah(A, Y, W), suksesor(W, Z).