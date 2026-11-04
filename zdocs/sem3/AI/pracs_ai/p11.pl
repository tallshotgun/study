sumlist([],0).

sumlist([H | T], S):-
	sumlist(T, SumTail),
	S is H + SumTail.
