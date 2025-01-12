/* Fakta, sebagai basis */
p(0, positif).

/* Aturan */
p(N, positif):- 
    N >= 0,
    !,
    N1 is N - 1, 
    p(N1, positif).
p(N, negatif):-
    !.

/* 
KESIMPULAN:
    a. Masalah terjadi karena dilakukan iterasi N1 is N - 1, yang menyebabkan infinite loop pada kasus N < 0
    b. Mengubah urutan fakta maupun predikat tidak membantu, karena akan tetap terjadi N1 is N - 1 apabila tidak dideklarasi bahwa harus N >= 0 
*/