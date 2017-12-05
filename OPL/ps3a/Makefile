OBJ = ps2b

all:
	@echo "Racket has an interpreter. Nothing to build. Perhaps you want, 'make test'?"

test:
	perl test.t

pdf:
	enscript -C --margins=50:50:50:50 -p $(OBJ).rkt.ps $(OBJ).rkt
	ps2pdf $(OBJ).rkt.ps

clean:
	rm -f *~ 

