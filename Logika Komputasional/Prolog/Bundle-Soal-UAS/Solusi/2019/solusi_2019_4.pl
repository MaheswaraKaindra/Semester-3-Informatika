isMember(Val, [Val|_]) :- !.
isMember(Val, [_ | Tail]) :-
    isMember(Val, Tail).

intersectList([], _, []).
intersectList(_, [], []).

intersectList([Head1 | Tail1], List2, [Head1 | Result]) :-
    isMember(Head1, List2),
    intersectList(Tail1, List2, Result).
intersectList([_ | Tail1], List2, Result) :-
    intersectList(Tail1, List2, Result).