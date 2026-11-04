multi(_,0,0).

multi(N1,N2,R):-
	N2>0,
	N2_prev is N2 - 1,
	multi(N1,N2_prev, TempR),
	R is N1+TempR.
