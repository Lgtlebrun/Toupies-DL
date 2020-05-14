CC = $(CXX)
CXXFLAGS = -std=gnu++11

CLASSH = ../../headers/TextViewer.h ../../headers/Vecteur.h ../../headers/Clonable.h ../../headers/Dessinable.h ../../headers/Systeme.h ../../headers/SupportADessin.h ../../headers/Integrable.h ../../headers/ObjetPhysique.h ../../headers/Toupie.h ../../headers/ConeSimple.h ../../headers/ToupieChinoise.h ../../headers/Tests/Bille.h ../../headers/Tests/Oscillateur.h ../../headers/Integrateur.h ../../headers/constantes.h

all: TestAll



TestAll: testAll.o Unittest.o TestVecteur.o TestMatrice.o TestSysteme.o TestIntegrateur.o ../constantes.o ../Vecteur.o ../Matrice3.o ../Dessinable.o ../Integrable.o ../ObjetPhysique.o ../Toupie.o Bille.o Oscillateur.o ../ConeSimple.o ../Systeme.o ../Integrateur.o ../TextViewer.o ../ToupieChinoise.o
	g++ -std=gnu++11 -o $@ testAll.o Unittest.o TestVecteur.o TestMatrice.o TestSysteme.o TestIntegrateur.o ../constantes.o ../Vecteur.o ../Matrice3.o ../Dessinable.o ../Integrable.o ../ObjetPhysique.o ../Toupie.o Bille.o Oscillateur.o ../ConeSimple.o ../Systeme.o ../Integrateur.o ../TextViewer.o ../ToupieChinoise.o


	
Unittest.o: Unittest.cpp ../../headers/Tests/Unittest.h

TestVecteur.o: TestVecteur.cpp ../../headers/Tests/TestVecteur.h ../../headers/Vecteur.h ../../headers/Tests/Unittest.h

TestMatrice.o: TestMatrice.cpp ../../headers/Tests/TestMatrice.h ../../headers/Matrice3.h ../../headers/Vecteur.h ../../headers/Tests/Unittest.h

TestSysteme.o: TestSysteme.cpp ../../headers/Tests/TestSysteme.h $(CLASSH)

TestIntegrateur.o: TestIntegrateur.cpp ../../headers/Tests/TestIntegrateur.h $(CLASSH)

testAll.o: testAll.cpp ../../headers/Tests/TestSysteme.h ../../headers/Tests/TestVecteur.h ../../headers/Tests/TestMatrice.h ../../headers/Tests/TestIntegrateur.h $(CLASSH)

../constantes.o: ../constantes.cpp ../../headers/constantes.h ../../headers/Vecteur.h

../Vecteur.o: ../Vecteur.cpp ../../headers/Vecteur.h

../Matrice3.o: ../Matrice3.cpp $(CLASSH)

../Dessinable.o: ../Dessinable.cpp $(CLASSH)

../Integrable.o: ../Integrable.cpp ../../headers/Integrable.h ../../headers/Dessinable.h ../../headers/Vecteur.h ../../headers/constantes.h ../../headers/Clonable.h ../../headers/SupportADessin.h

../ObjetPhysique.o: ../ObjetPhysique.cpp ../../headers/ObjetPhysique.h ../../headers/Integrable.h ../../headers/Dessinable.h ../../headers/Vecteur.h ../../headers/constantes.h ../../headers/Clonable.h ../../headers/SupportADessin.h

../Toupie.o: ../Toupie.cpp $(CLASSH)

../ConeSimple.o: ../ConeSimple.cpp $(CLASSH)

Bille.o: Bille.cpp $(CLASSH)

Oscillateur.o: Oscillateur.cpp $(CLASSH)

../Systeme.o: ../Systeme.cpp $(CLASSH)

../Integrateur.o: ../Integrateur.cpp $(CLASSH)

../TextViewer.o: ../TextViewer.cpp $(CLASSH)

../ToupieChinoise.o: ../ToupieChinoise.cpp $(CLASSH)

Codepourrigoler.o: ../Vecteur.cpp



	
