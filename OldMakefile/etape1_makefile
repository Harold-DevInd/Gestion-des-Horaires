.SILENT:

CLASSE=./classes
OBJS=Event.o Test1.o
PROGRAM=Test1

all:	$(PROGRAM)
	$(PROGRAM)

$(PROGRAM):	Test1.o Event.o
	echo "Creation du programme test Test1"
	g++ Test1.o Event.o -o Test1 -D DEBUG

Test1.o:	Test1.cpp 
	echo "Creation du fichier objet Test1.o"
	g++ Test1.cpp -c -o Test1.o -D DEBUG

Event.o:	Event.cpp	Event.h
	echo "Creation de Event.o"
	g++ Event.cpp -c -o Event.o -D DEBUG

clean:	
	echo "Suppression de fichiers objets: $(OBJS)"
	rm -f $(OBJS)

clobber:	clean	
	echo "Suppression de tout les programme obtenus apres compilation : $(PROGRAM)"
	rm -f $(PROGRAM)