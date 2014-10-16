# Dossier pour la compilation

DEST_SRC = SRC
DEST_INC = INC
DEST_OBJ = OBJ

# Flags de compilation

CC = gcc
CFLAGS = -W -Wall



SRC = $(foreach dir, $(DEST_SRC), $(wildcard $(dir)/*.c))
OBJ = $(addsuffix .o, $(basename $(subst ${DEST_SRC}, ${DEST_OBJ}, ${SRC})))

#nom de l'executable
BIN = puissance4

# Make

install: $(BIN)

$(BIN): $(OBJ)
	@$(CC) -o ${BIN} $(OBJ)
	@echo "\n\t"Creation de l\'exectutable : $@"\n"

$(DEST_OBJ)/%.o: $(DEST_SRC)/%.c
	@$(CC) $(CFLAGS) -I$(DEST_INC) -c $< -o $@
	@echo "\n"Creation de $@


# Clean

uninstall:
	@rm -f $(DEST_OBJ)/*.o
	@rm -f $(BIN)
	@find . -name \*~ -exec rm \-fv {} \;
	@echo  "\t"Le pogramme $(BIN) a bien été supprimé