main :-
    open('coba.txt', read, S),
    readHouses(S, Houses),
    close(S),
    write(Houses), nl.

readHouses(S, []) :-
    at_end_of_stream(S), !.

readHouses(S, [Current | Rest]) :-
    \+ at_end_of_stream(S), !,
    read(S, Current),
    readHouses(S, Rest).

main2 :-
    open('coba.txt', read, S),
    readWord(S, W),
    close(S),
    write(W), nl.

readWord(S, W) :-
    get_code(S, C),
    checkCharAndReadRest(C, Chars, S),
    atom_codes(W, Chars).

checkCharAndReadRest(-1, [], _) :- !.
checkCharAndReadRest(end_of_file, [], _) :- !.
checkCharAndReadRest(C, [C | Chars], S) :-
    get_code(S, NextC),
    checkCharAndReadRest(NextC, Chars, S).