% Gender
male(john).
male(bob).
male(tom).
male(peter).

female(mary).
female(lisa).
female(anna).
female(susan).

% Parent relation: parent(Parent, Children)
parent(john, bob).
parent(john, lisa).
parent(mary, bob).
parent(mary, lisa).

parent(bob, tom).
parent(bob, anna).
parent(susan, tom).
parent(susan, anna).

parent(lisa, peter).

% A father is a parent who is male
father(F, C) :-
	parent(F, C),
	male(F).

% A mother is a parent who is female
mother(M, C) :-
	parent(M, C),
	female(M).

% Both share same parent but are not the same person
sibling(A, B) :-
	parent(P, A),
	parent(P, B),
	A \= B.

% A brother is a male sibling
brother(B, S) :-
	sibling(B, S),
	male(B).

% A sister is a female sibling
sister(S, B) :-
	sibling(S, B),
	female(S).

% A grandparent is a parent of the parent of a child
grandparent(GP, GC) :-
	parent(GP, P),
	parent(P, GC).

% A grandfather is a male grandparent
grandfather(GF, GC) :-
	grandparent(GF, GC),
	male(GF).

% A grandmother is a female grandparent
grandmother(GM, GC) :-
	grandparent(GM, GC),
	female(GM).

% An uncle is a brother of a parent of a child
uncle(U, N) :-
	parent(P, N),
	brother(U, P).

% An aunt is a sister of a parent of a child
aunt(A, N) :-
	parent(P, N),
	sister(A, P).
