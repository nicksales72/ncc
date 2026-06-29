main: src/main.c
	gcc	src/main.c -o jlox

clean: 
	rm jlox
