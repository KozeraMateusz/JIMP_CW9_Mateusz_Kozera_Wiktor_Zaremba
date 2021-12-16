all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b > dane/wynik
	diff dane/wynik dane/dobre
test1: all
	bin/gauss dane/A1 dane/b1 > dane/wynik1
	diff dane/wynik1 dane/dobre1
test2: all
	bin/gauss dane/A2 dane/b2 > dane/wynik2
	diff dane/wynik2 dane/dobre2
test3: all
	bin/gauss dane/A3 dane/b3 > dane/wynik3
	diff dane/wynik3 dane/dobre3
test4: all
	bin/gauss dane/A4 dane/b4 > dane/wynik4
	diff dane/wynik4 dane/dobre4
