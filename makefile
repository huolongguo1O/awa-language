TARGET = main
ARGS = -Wall -g
CC = gcc
OUT = fly.exe

main:build/var.o build/main.o build/parse.o build/utils.o build/funcs.o build/float.o build/function.o build/int.o build/string.o build/object.o build/null.o build/types.o
	$(CC) -o $(OUT) build/var.o build/main.o build/parse.o build/utils.o build/funcs.o build/float.o build/function.o build/int.o build/string.o build/object.o build/null.o build/types.o -g

build/var.o:var.c
	$(CC) -c var.c -o build/var.o $(ARGS)

build/main.o:main.c
	$(CC) -c main.c -o build/main.o $(ARGS)

build/parse.o:parse.c
	$(CC) -c parse.c -o build/parse.o $(ARGS)

build/utils.o:utils/utils.c
	$(CC) -c utils/utils.c -o build/utils.o $(ARGS)

build/funcs.o:funcs/funcs.c
	$(CC) -c funcs/funcs.c -o build/funcs.o $(ARGS)

build/float.o:types/float.c
	$(CC) -c types/float.c -o build/float.o $(ARGS)

build/function.o:types/function.c
	$(CC) -c types/function.c -o build/function.o $(ARGS)

build/int.o:types/int.c
	$(CC) -c types/int.c -o build/int.o $(ARGS)

build/string.o:types/string.c
	$(CC) -c types/string.c -o build/string.o $(ARGS)

build/object.o:types/object.c
	$(CC) -c types/object.c -o build/object.o $(ARGS)

build/null.o:types/null.c
	$(CC) -c types/null.c -o build/null.o $(ARGS)

build/types.o:types/types.c
	$(CC) -c types/types.c -o build/types.o $(ARGS)

clean:
	rm -rf build/*
	rm $(OUT)