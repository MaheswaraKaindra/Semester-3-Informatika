/* Fakta */
ibu(emy, charles).
ibu(emy, david).
ibu(emy, randy).
ibu(maria, farah).

/* Aturan */
saudara_kandung(Anak1, Anak2) :-
    ibu(Ibu, Anak1),
    ibu(Ibu, Anak2),
    Anak1 \= Anak2.