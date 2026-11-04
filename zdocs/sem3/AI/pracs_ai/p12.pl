evenlength([]).

evenlength([_ | T]):-
	oddlength(T).

oddlength([_ | T]):-
	evenlength(T).
