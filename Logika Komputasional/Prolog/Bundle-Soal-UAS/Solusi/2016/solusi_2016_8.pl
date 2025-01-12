male(arif).
male(pandu).
female(dyah).
female(arini).
parents(pandu, arif, dyah).
parents(arini, arif, dyah).

/* Kode awal */
sister_of(X, Y):-
    female(X),
    parents(X, M, F),
    parents(Y, M, F).

/*
    a.  Hasil query sister_of(arini, Y).
        Y = pandu
        Y = arini
        yes
    b.  Program seharusnya juga mencakup X \= Y untuk memastikan arini tidak dicek dengan dirinya sendiri.
*/

/* Kode Revisi */
fixed_sister_of(X, Y):-
    female(X),
    parents(X, M, F),
    parents(Y, M, F),
    X \= Y.