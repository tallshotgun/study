conc([], L2, L2).

conc([H | T1], L2, [H | T3]) :-
	conc(T1, L2, T3).
