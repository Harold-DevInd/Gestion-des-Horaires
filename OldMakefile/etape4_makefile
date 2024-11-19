.SILENT:

FILECLASSE=./Classes
FILLEOBJS=./Objets
OBJS=Test4.o Group.o Professor.o Classroom.o Schedulable.o
PROGRAM=Test4

all:	$(PROGRAM)
	$(PROGRAM)

$(PROGRAM):	$(FILLEOBJS)/Test4.o $(FILLEOBJS)/Group.o $(FILLEOBJS)/Professor.o $(FILLEOBJS)/Classroom.o $(FILLEOBJS)/Schedulable.o
	echo "Creation du programme test Test4"
	g++ $(FILLEOBJS)/Test4.o $(FILLEOBJS)/Group.o $(FILLEOBJS)/Professor.o $(FILLEOBJS)/Classroom.o $(FILLEOBJS)/Schedulable.o -o Test4 #-D DEBUG

$(FILLEOBJS)/Test4.o:	$(FILECLASSE)/Test4.cpp 
	echo "Creation du fichier objet Test4.o"
	g++ $(FILECLASSE)/Test4.cpp -c -o $(FILLEOBJS)/Test4.o #-D DEBUG

$(FILLEOBJS)/Group.o:	$(FILECLASSE)/Group.cpp	$(FILECLASSE)/Group.h $(FILLEOBJS)/Schedulable.o
	echo "Creation de Group.o"
	g++ $(FILECLASSE)/Group.cpp -c -o $(FILLEOBJS)/Group.o -D DEBUG

$(FILLEOBJS)/Professor.o:	$(FILECLASSE)/Professor.cpp	$(FILECLASSE)/Professor.h $(FILLEOBJS)/Schedulable.o
	echo "Creation de Professor.o"
	g++ $(FILECLASSE)/Professor.cpp -c -o $(FILLEOBJS)/Professor.o -D DEBUG

$(FILLEOBJS)/Classroom.o:	$(FILECLASSE)/Classroom.cpp	$(FILECLASSE)/Classroom.h $(FILLEOBJS)/Schedulable.o
	echo "Creation de Classroom.o"
	g++ $(FILECLASSE)/Classroom.cpp -c -o $(FILLEOBJS)/Classroom.o -D DEBUG

$(FILLEOBJS)/Schedulable.o:	$(FILECLASSE)/Schedulable.cpp	$(FILECLASSE)/Schedulable.h
	echo "Creation de Schedulable.o"
	g++ $(FILECLASSE)/Schedulable.cpp -c -o $(FILLEOBJS)/Schedulable.o #-D DEBUG

clean:	
	echo "Suppression de fichiers objets: $(OBJS)"
	rm -f $(FILLEOBJS)/*

clobber:	clean	
	echo "Suppression de tout les programme obtenus apres compilation : $(PROGRAM)"
	rm -f $(PROGRAM)