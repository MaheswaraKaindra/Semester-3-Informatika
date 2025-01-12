/* RULE: Append - Menggabungkan 2 list */
append([], X, X).
append([H|T], X, [H|Y]) :- append(T, X, Y).