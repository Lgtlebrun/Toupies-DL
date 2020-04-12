TEMPLATE = subdirs

SUBDIRS += \
   general \
   Qt_GL \
   text

LIBS += -LD:\Qt\5.5\mingw492_32\lib\libQt5OpenGL.a -lopengl32 -lglu32 -lglut -lmingw32
