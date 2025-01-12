parent(charles, william).
parent(charles, harry).
parent(phillips, charles).
parent(elizabeth, charles).
parent(victoria, elizabeth).

ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- 
    ancestor(X, Z), 
    !, 
    parent(Z, Y).

/*
    Hasil Query
    1.  ancestor(X, harry).
        X = charles
        no
    2.  ancestor(victoria, Y).
        Y = elizabeth
        Y = charles
        yes
*/