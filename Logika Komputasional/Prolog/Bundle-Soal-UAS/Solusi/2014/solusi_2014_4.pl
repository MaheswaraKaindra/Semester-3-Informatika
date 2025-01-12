/* Kode (sudah diperbaiki): */
big_mac(a).
big_mac(c).
big_kahuna_burger(b).
whopper(d).

enjoys(pete, X) :- big_kahuna_burger(X), !, fail.
enjoys(pete, X) :- burger(X), !.

burger(X) :- big_mac(X).
burger(X) :- big_kahuna_burger(X).
burger(X) :- whopper(X).

/*
    Hasil query:
    1.  enjoys(pete, a).
        true?;
        no
    2.  enjoys(pete, b).
        true?;
        no
    3.  enjoys(pete, c).
        true?;
        no
    4.  enjoys(pete, d).
        true?;
        no
    
    Program masih salah,
    1. Fakta harus berada di atas rules. 
    2. Fakta yang sejenis, misalnya big_mac harus berurutan.
    3. Perlu ditambahkan cut sebelum fail, sehingga program tidak akan backtracking ke kasus kedua.
    4. Perlu ditambahkan cut di akhir kasus kedua untuk mengunci jawaban.
*/