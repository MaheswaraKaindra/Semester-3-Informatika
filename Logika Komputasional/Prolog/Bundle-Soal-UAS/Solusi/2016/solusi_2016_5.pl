main :-
    open('mahasiswa.txt', read, S),
    readMhs(S, Mahasiswa),
    close(S),
    write(Mahasiswa), nl.

readMhs(S, []) :- at_end_of_stream(S), !.
readMhs(S, [Head | Tail]) :-
    read(S, Head),
    readMhs(S, Tail).