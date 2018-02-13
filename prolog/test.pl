schedule(monday, programming).
schedule(tuesday, math).
schedule(wednesday, programming).
schedule(thursday, circuits).
schedule(friday, none).


difficulty(programming, hard).
difficulty(math, hard).
difficulty(english, easy).
difficulty(circuits, hard).

classinformation(Day, Class, Diff) :-
	schedule(Day, Class),
	difficulty(Class, Diff). 