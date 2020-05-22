CC = $(CXX)
CXXFLAGS = -std=gnu++11

CLASSH = ../general/headers/TextViewer.h ../general/headers/Vecteur.h ../general/headers/Clonable.h ../general/headers/Dessinable.h ../general/headers/Systeme.h ../general/headers/SupportADessin.h ../general/headers/Integrable.h ../general/headers/ObjetPhysique.h ../general/headers/Toupie.h ../general/headers/ConeSimple.h ../general/headers/ToupieChinoise.h ../general/headers/Tests/Bille.h ../general/headers/Tests/Oscillateur.h ../general/headers/Integrateur.h ../general/headers/constantes.h

all: ex9a ex9b



ex9a: ../general/source/constantes.o ../general/source/Vecteur.o ../general/source/Matrice3.o ../general/source/Dessinable.o ../general/source/Integrable.o ../general/source/ObjetPhysique.o ../general/source/Toupie.o ../general/source/Tests/Bille.o ../general/source/Tests/Oscillateur.o ../general/source/ConeSimple.o ../general/source/Systeme.o ../general/source/Integrateur.o ../general/source/TextViewer.o ../general/source/ToupieChinoise.o exercice9a.o
	g++ -std=gnu++11 -o ex9a ../general/source/constantes.o ../general/source/Vecteur.o ../general/source/Matrice3.o ../general/source/Dessinable.o ../general/source/Integrable.o ../general/source/ObjetPhysique.o ../general/source/Toupie.o ../general/source/Tests/Bille.o ../general/source/Tests/Oscillateur.o ../general/source/ConeSimple.o ../general/source/Systeme.o ../general/source/Integrateur.o ../general/source/TextViewer.o ../general/source/ToupieChinoise.o exercice9a.o

ex9b: ../general/source/constantes.o ../general/source/Vecteur.o ../general/source/Matrice3.o ../general/source/Dessinable.o ../general/source/Integrable.o ../general/source/ObjetPhysique.o ../general/source/Toupie.o ../general/source/Tests/Bille.o ../general/source/Tests/Oscillateur.o ../general/source/ConeSimple.o ../general/source/Systeme.o ../general/source/Integrateur.o ../general/source/TextViewer.o ../general/source/ToupieChinoise.o exercice9b.o
	g++ -std=gnu++11 -o ex9b ../general/source/constantes.o ../general/source/Vecteur.o ../general/source/Matrice3.o ../general/source/Dessinable.o ../general/source/Integrable.o ../general/source/ObjetPhysique.o ../general/source/Toupie.o ../general/source/Tests/Bille.o ../general/source/Tests/Oscillateur.o ../general/source/ConeSimple.o ../general/source/Systeme.o ../general/source/Integrateur.o ../general/source/TextViewer.o ../general/source/ToupieChinoise.o exercice9b.o


exercice9a.o: exercice9a.cpp $(CLASSH)

exercice9b.o: exercice9b.cpp $(CLASSH)

../general/source/constantes.o: ../general/source/constantes.cpp ../general/headers/constantes.h ../general/headers/Vecteur.h

../general/source/Vecteur.o: ../general/source/Vecteur.cpp ../general/headers/Vecteur.h

../general/source/Matrice3.o: ../general/source/Matrice3.cpp $(CLASSH)

../general/source/Dessinable.o: ../general/source/Dessinable.cpp $(CLASSH)

../general/source/Integrable.o: ../general/source/Integrable.cpp ../general/headers/Integrable.h ../general/headers/Dessinable.h ../general/headers/Vecteur.h ../general/headers/constantes.h ../general/headers/Clonable.h ../general/headers/SupportADessin.h

../general/source/ObjetPhysique.o: ../general/source/ObjetPhysique.cpp ../general/headers/ObjetPhysique.h ../general/headers/Integrable.h ../general/headers/Dessinable.h ../general/headers/Vecteur.h ../general/headers/constantes.h ../general/headers/Clonable.h ../general/headers/SupportADessin.h

../general/source/Toupie.o: ../general/source/Toupie.cpp $(CLASSH)

../general/source/ConeSimple.o: ../general/source/ConeSimple.cpp $(CLASSH)

general/source/Tests/Bille.o: general/source/Tests/Bille.cpp $(CLASSH)

general/source/Tests/Oscillateur.o: general/source/Tests/Oscillateur.cpp $(CLASSH)

../general/source/Systeme.o: ../general/source/Systeme.cpp $(CLASSH)

../general/source/Integrateur.o: ../general/source/Integrateur.cpp $(CLASSH)

../general/source/TextViewer.o: ../general/source/TextViewer.cpp $(CLASSH)

../general/source/ToupieChinoise.o: ../general/source/ToupieChinoise.cpp $(CLASSH)

Codepourrigoler.o: ../Vecteur.cpp



	
