.SILENT:

FILECLASSE=./Classes
FILLEOBJS=./Objets
OBJS=Test2.o Event.o Time.o Timing.o
PROGRAM=Test2

all:	$(PROGRAM)
	$(PROGRAM)

$(PROGRAM):	$(FILLEOBJS)/Test2.o $(FILLEOBJS)/Event.o $(FILLEOBJS)/Time.o $(FILLEOBJS)/Timing.o
	echo "Creation du programme test Test2"
	g++ $(FILLEOBJS)/Test2.o $(FILLEOBJS)/Event.o $(FILLEOBJS)/Time.o $(FILLEOBJS)/Timing.o -o Test2 -D DEBUG

$(FILLEOBJS)/Event.o:	$(FILECLASSE)/Event.cpp	$(FILECLASSE)/Event.h
	echo "Creation de Event.o"
	g++ $(FILECLASSE)/Event.cpp -c -o $(FILLEOBJS)/Event.o -D DEBUG

$(FILLEOBJS)/Test2.o:	$(FILECLASSE)/Test2.cpp 
	echo "Creation du fichier objet Test2.o"
	g++ $(FILECLASSE)/Test2.cpp -c -o $(FILLEOBJS)/Test2.o #-D DEBUG

$(FILLEOBJS)/Timing.o:	$(FILECLASSE)/Timing.cpp	$(FILECLASSE)/Timing.h
	echo "Creation de Timing.o"
	g++ $(FILECLASSE)/Timing.cpp -c -o $(FILLEOBJS)/Timing.o -D DEBUG

$(FILLEOBJS)/Time.o:	$(FILECLASSE)/Time.cpp	$(FILECLASSE)/Time.h
	echo "Creation de Time.o"
	g++ $(FILECLASSE)/Time.cpp -c -o $(FILLEOBJS)/Time.o #-D DEBUG

clean:	
	echo "Suppression de fichiers objets: $(OBJS)"
	rm -f $(FILLEOBJS)/$(OBJS)

clobber:	clean	
	echo "Suppression de tout les programme obtenus apres compilation : $(PROGRAM)"
	rm -f $(PROGRAM)