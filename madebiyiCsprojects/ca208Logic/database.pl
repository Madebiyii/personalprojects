is_hero(john).
is_hero(alex).
parent(alex, john).
parent(clara, alex).
parent(hugo, alex).

add(X,L,[X|L]).
del(X,[X|Tail],Tail).
del(X,[Y|Tail],[Y|Tail1]):- del(X,Tail,Tail1).
