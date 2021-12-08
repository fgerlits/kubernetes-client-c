INCLUDE:=-I../../kubernetes/
LIBS:=-L../../kubernetes/build -L../../install/lib -lyaml -lwebsockets -lkubernetes -L/usr/local/lib
CFLAGS:=-g
BIN:=list_pod_bin

all:
	gcc main.c $(CFLAGS) $(INCLUDE) $(LIBS) -o $(BIN)
clean:
	rm ./$(BIN)
test:
	./$(BIN)
