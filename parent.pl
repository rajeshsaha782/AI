parent(john,mike).
parent(john,ann).
parent(mary,mike).
parent(mike,pat).
parent(mike,bob).
parent(pat,ben).
parent(ann,efti).

female(mary). 
female(ann). 
female(pat).
male(john).
male(mike).
male(bob).
male(ben). 
male(efti).

mother(X,Y) :- parent(X, Y), female(X).
father(X,Y) :- parent(X, Y), male(X). 

brother(X,Y) :- parent(P,X),parent(P,Y),male(X),X\=Y.
sister(X,Y) :- parent(P,X),parent(P,Y),female(X),X\=Y.

grandfather(X,Y) :- parent(P,Y),parent(X,P),male(X).
grandmother(X,Y) :- parent(P,Y),parent(X,P),female(X).

uncle(X,Y) :- parent(P,Y),brother(P,X).
aunty(X,Y) :- parent(P,Y),sister(P,X).

grandgrandfather(X,Y) :- grandfather(P,Y),parent(X,P),male(X).
grandgrandmother(X,Y) :- grandmother(P,Y),parent(X,P),female(X).

cousin(X,Y):- parent(P,X),parent(Q,Y),(brother(P,Q);sister(P,Q)).

husband(X,Y):- parent(X,C),parent(Y,C),male(X),female(Y).
wife(Y,X):- parent(X,C),parent(Y,C),male(X),female(Y).