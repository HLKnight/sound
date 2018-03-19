OBJ = main.o sound.o screen.o
APPNAME = sound.a
TAR = sound.tar

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)

archive :
	tar cf $(TAR) *
