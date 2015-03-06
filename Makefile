CC = gcc
CFLAGS = -W -Wall -lGL -lGLU -lglut -lm

#
# DIRositories.
#
OBJ_DIR = OBJ
INC_DIR = INC
SRC_DIR = SRC
BIN_DIR = bin

#
# Sources, objects and binary file name
#
SRC = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ = $(addsuffix .o, $(basename $(subst ${SRC_DIR}, ${OBJ_DIR}, ${SRC})))
BIN = projet

.PHONY: clean mrproper clear dir
.SUFFIXES:


all: dir $(BIN_DIR)/$(BIN)

# creation de l'exécutable.
$(BIN_DIR)/$(BIN): $(OBJ)
	@$(CC) $(OBJ) -o $@ -I $(INC_DIR) $(CFLAGS)

#Création des .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $^ -o $@ -I $(INC_DIR) $(CFLAGS)

#clear
clear:
	clear

#clean
clean:
	rm -f ./$(OBJ_DIR)/*.o;
	rm -f $(BIN_DIR)/$(BIN)
	rmdir $(BIN_DIR)
	rm -f output
	@echo  "\t"Le programme $(BIN) a bien été supprimé

mrproper:
	rm -f ./$(OBJ_DIR)/*.o ./$(BIN_DIR)/$(BIN);
	rm -f output

rebuild: mrproper all clear

#création du répertoire
dir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)