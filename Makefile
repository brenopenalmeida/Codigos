#Elaborado com monitoria
#Compilador
CC = g++

#Flags
FLAG = -g -std=c++17 -Wall -Wextra -Werror -Wshadow -Wconversion -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused

# Variavel .o
O = *.o

EXE = a

# Comando para dar clean ( Linux )

RM = rm -rf

# Comando para pegar todos os .cpp da pasta do diretório
TODOSCPP = $(wildcard *.cpp)

# Compila e execulta o programa e depois apaga todos os arquivos .o e .exe
all: run clean


run:
	$(CC) $(FLAG) -c $(TODOSCPP)
	$(CC) $(FLAG) -o $(EXE) $(O)
	./$(EXE)

clean:
#Caso o Sistema Operacional for Windows, descomente as linhas seguintes(30 e 31), e comente as proximas(32 e 33).
	del *.o
	del *.exe
#	$(RM) $(O)
#	$(RM) $(EXE)