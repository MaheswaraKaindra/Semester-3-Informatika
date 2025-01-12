/* Menghitung ukuran list */
ukuranList([], 0).
ukuranList([_|Tail], Banyak) :-
    ukuranList(Tail, Banyak1),
    Banyak is Banyak1 + 1.

/* Menghitung jumlah dari semua elemen list */
jumlahList([], 0).
jumlahList([Head | Tail], Jumlah) :-
    jumlahList(Tail, Jumlah1),
    Jumlah is Head + Jumlah1.

/* Membuang semua elemen bernilai ganjil dari list */
buangGanjil([], []).
buangGanjil([Head | Tail], [Head | Result]) :-
    Head mod 2 =:= 0,
    buangGanjil(Tail, Result).
buangGanjil([Head | Tail], Result) :-
    Head mod 2 =:= 1,
    buangGanjil(Tail, Result).

/* Membuang semua elemen bernilai negatif pada list */
buangNegatif([], []).
buangNegatif([Head | Tail], [Head | Result]) :-
    Head >= 0,
    buangNegatif(Tail, Result).
buangNegatif([Head | Tail], Result) :-
    Head < 0,
    buangNegatif(Tail, Result).

/* INTERMEZO (tidak ada di soal): Menghapus elemen pertama apabila sama dengan elemen berikutnya */
uas([],[]).
uas([Farhan], [Farhan]).
uas([Farhan, Farhan | Farhans], Razis) :-
    uas([Farhan | Farhans], Razis).
uas([Farhan, Nayaka|Nayakas], [Farhan|Razis]) :-
    Farhan \= Nayaka,
    uas([Nayaka|Nayakas], Razis).