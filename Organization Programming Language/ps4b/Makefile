OBJ = ps

all:
	@echo "Racket has an interpreter. Nothing to build. Perhaps you want, 'make test'?"

test:
	perl test.t

pdf:
	enscript -C --margins=50:50:50:50 -p $(OBJ).rkt.ps $(OBJ).rkt
	ps2pdf $(OBJ).rkt.ps
	pdftk $(OBJ).rkt.pdf output $(OBJ).rkt.pw.pdf encrypt_128bit owner_pw q3WrFxrh user_pw ZrqTV6pY

clean:
	rm -f *~ *.pdf *.ps

