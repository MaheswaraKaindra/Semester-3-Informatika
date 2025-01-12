is_a_horse(cornet).
is_a_horse(prancer).
is_a_horse(dasher).
is_a_horse(thunder).

is_parent_of(dahser, thunder).

is_fast(dasher).
is_fast(thunder).

valuable(Horse) :-
    is_parent_of(Horse, Foal),
    is_fast(Foal).

/*  
    Query :
    | ?- valuable(Horse).

    Result :
    Horse = dasher
    yes
*/