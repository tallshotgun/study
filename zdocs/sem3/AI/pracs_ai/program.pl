% ==========================================
% FACTS: The basic truths of our family tree
% ==========================================

% Define genders
male(john).
male(bob).
male(jim).
male(tom).

female(mary).
female(lisa).
female(susan).
female(anna).

% Define direct parent relationships: parent(Parent, Child).
parent(john, bob).
parent(john, lisa).
parent(mary, bob).
parent(mary, lisa).

parent(bob, jim).
parent(bob, susan).
parent(lisa, tom).
parent(lisa, anna).

% ==========================================
% RULES: Logic to infer new relationships
% ==========================================

% X is the father of Y IF X is male AND X is a parent of Y.
% (Note: ':-' means IF, and ',' means AND)
father(X, Y) :- male(X), parent(X, Y).

% X is the mother of Y IF X is female AND X is a parent of Y.
mother(X, Y) :- female(X), parent(X, Y).

% X is a child of Y IF Y is a parent of X.
child(X, Y) :- parent(Y, X).

% X is a sibling of Y IF Z is a parent of X AND Z is a parent of Y AND X is not Y.
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% X is the brother of Y IF X is male AND X is a sibling of Y.
brother(X, Y) :- male(X), sibling(X, Y).

% X is the sister of Y IF X is female AND X is a sibling of Y.
sister(X, Y) :- female(X), sibling(X, Y).

% X is a grandparent of Y IF X is a parent of Z AND Z is a parent of Y.
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% X is the grandfather of Y IF X is male AND X is a grandparent of Y.
grandfather(X, Y) :- male(X), grandparent(X, Y).

% X is the grandmother of Y IF X is female AND X is a grandparent of Y.
grandmother(X, Y) :- female(X), grandparent(X, Y).
