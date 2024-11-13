.SILENT:

FILECLASSE=./Classes
FILLEOBJS=./Objets
OBJS=Test3.o Event.o Time.o Timing.o
PROGRAM=Test3

all:	$(PROGRAM)
	$(PROGRAM)

$(PROGRAM):	$(FILLEOBJS)/Test3.o $(FILLEOBJS)/Event.o 
	echo "Creation du programme test Test3"
	g++ $(FILLEOBJS)/Test3.o $(FILLEOBJS)/Event.o $(FILLEOBJS)/Time.o $(FILLEOBJS)/Timing.o -o Test3 #-D DEBUG

$(FILLEOBJS)/Event.o:	$(FILECLASSE)/Event.cpp	$(FILECLASSE)/Event.h $(FILLEOBJS)/Timing.o
	echo "Creation de Event.o"
	g++ $(FILECLASSE)/Event.cpp -c -o $(FILLEOBJS)/Event.o #-D DEBUG

$(FILLEOBJS)/Test3.o:	$(FILECLASSE)/Test3.cpp 
	echo "Creation du fichier objet Test3.o"
	g++ $(FILECLASSE)/Test3.cpp -c -o $(FILLEOBJS)/Test3.o #-D DEBUG

$(FILLEOBJS)/Timing.o:	$(FILECLASSE)/Timing.cpp	$(FILECLASSE)/Timing.h $(FILLEOBJS)/Time.o
	echo "Creation de Timing.o"
	g++ $(FILECLASSE)/Timing.cpp -c -o $(FILLEOBJS)/Timing.o #-D DEBUG

$(FILLEOBJS)/Time.o:	$(FILECLASSE)/Time.cpp	$(FILECLASSE)/Time.h
	echo "Creation de Time.o"
	g++ $(FILECLASSE)/Time.cpp -c -o $(FILLEOBJS)/Time.o #-D DEBUG

clean:	
	echo "Suppression de fichiers objets: $(OBJS)"
	rm -f $(FILLEOBJS)/*

clobber:	clean	
	echo "Suppression de tout les programme obtenus apres compilation : $(PROGRAM)"
	rm -f $(PROGRAM)