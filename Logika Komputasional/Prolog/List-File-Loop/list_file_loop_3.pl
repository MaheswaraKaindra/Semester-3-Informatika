command_loop :-
    write('Find the password: '), nl,
    repeat,
    write('password> '),
    read(X),
    end_condition(X).

end_condition(end).
end_condition(X) :-
    have(X), !,
    write('You have found the password!'), nl.

have(X) :-
    X=='secret', !.