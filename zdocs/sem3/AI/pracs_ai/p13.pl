maxlist([X],X).

maxlist([H | T], M):-
	maxlist(T, MaxTail),
	M is max(H, MaxTail).
