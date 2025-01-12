main :-
    open('mahasiswa.txt', read, S),
    readmhs(S, Mahasiswa),
    close(S),
    write(Mahasiswa), nl.

readmhs(S, []) :- at_end_of_stream(S), !.
readmhs(S, [Head|Tail]) :-
    \+ at_end_of_stream, !,
    read(S, Head),
    readmhs(S, Tail).