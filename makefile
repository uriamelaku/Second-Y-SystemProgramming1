CC=gcc
FLAG=-Wall -g


all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so mains maindloop maindrec


mains: main.o libclassrec.a
	$(CC) $(FLAG) -o mains main.o libclassrec.a
maindloop: main.o libclassloops.so
	$(CC) $(FLAG) -o maindloop main.o ./libclassloops.so
maindrec: main.o libclassrec.so
	$(CC) $(FLAG) -o maindrec main.o ./libclassrec.so

loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

main.o: main.c NumClass.h
	${CC} ${FLAG} -c main.c -o main.o


libclassloops.a: libclassloops.o basicClassification.o
	ar -rcs libclassloops.a libclassloops.o basicClassification.o
libclassrec.a: libclassrec.o basicClassification.o
	ar -rcs libclassrec.a libclassrec.o basicClassification.o


libclassloops.so: libclassloops.o basicClassification.o
	$(CC) -fPIC -shared -o libclassloops.so libclassloops.o basicClassification.o
libclassrec.so: libclassrec.o basicClassification.o
	$(CC) -fPIC -shared -o libclassrec.so libclassrec.o basicClassification.o



libclassloops.o: advancedClassificationLoop.c NumClass.h
	${CC} ${FLAG} -c advancedClassificationLoop.c -o libclassloops.o
libclassrec.o: advancedClassificationRecursion.c NumClass.h
	${CC} ${FLAG} -c advancedClassificationRecursion.c -o libclassrec.o
basicClassification.o: basicClassification.c NumClass.h
	${CC} ${FLAG} -c basicClassification.c -o basicClassification.o


.PHONY: clean all
clean:
	rm -f *.o *.a *.so mains maindloop maindrec