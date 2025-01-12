/* Kode: */
predikat1(L) :- predikat2(L, L).
predikat2([], []).
predikat2([Head | Tail], R) :-
    predikat2(Tail, T1),
    append(T1, [Head], R).

/*
    Hasil Query:
    1.  predikat1([]).
        yes
    2.  predikat1([a]).
        yes
    3.  predikat1([a, b]).
        no
    4.  predikat1([a,b,c]).
        no
    5.  predikat1([a,b,a]).
        yes
    
    Apa yang dilakukan?
    Intinya predikat1 memeriksa apakah sebuah list simetris dengan memanggil predikat 2.
    Predikat 2 akan membalikkan suatu list.
    Apabila hasil pembalikan sama dengan list awal, maka List simetris.
*/