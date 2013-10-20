ELEMENT_OBJECTS:=block.o spike.o lock.o check_point.o exit.o
ELEMENT_HEADERS:=block.h spike.h lock.h check_point.h exit.h
ELEMENT_SOURCE:=block.cpp spike.cpp lock.cpp check_point.cpp exit.cpp
PLAYER:=player.h player.cpp
BLOCK:=block.h block.cpp
SPIKE:=spike.h spike.cpp
LOCK:=lock.h lock.cpp
CHECK_POINT:=check_point.h check_point.cpp
EXIT:=exit.h exit.cpp
LEVEL:=level.h level.cpp
ELEMENT_FILES=BLOCK SPIKE LOCK CHECK_POINT EXIT
TAGS:=-lallegro-4.4.2-md -lstdc++
CONSTANTS:=global_constants.h global_macros.h
all:engine.exe editor.exe
engine.exe:engine.o collision.o init.o player.o level.o color.o string.o $(ELEMENT_OBJECTS)
	g++ engine.o collision.o init.o player.o level.o color.o string.o $(ELEMENT_OBJECTS) -o engine.exe $(TAGS)
editor.exe:editor.o collision.o init.o player.o level.o button.o color.o level_editor.o $(ELEMENT_OBJECTS)
	g++ editor.o collision.o init.o player.o level.o string.o color.o button.o level_editor.o $(ELEMENT_OBJECTS) -o editor.exe $(TAGS)
engine.o:engine.cpp declarations.h global_macros.h $(LEVEL)
	g++ engine.cpp -c
editor.o:editor.cpp button_element.h button_element.cpp declarations.h global_macros.h level_editor.h level_editor.cpp $(LEVEL)
	g++ editor.cpp -c
block.o:$(CONSTANTS) $(BLOCK)
	g++ block.cpp -c
spike.o:$(CONSTANTS.h) $(SPIKE)
	g++ spike.cpp -c
lock.o:$(CONSTANTS) $(LOCK)
	g++ lock.cpp -c
check_point.o:$(CONSTANTS) $(CHECK_POINT)
	g++ check_point.cpp -c
exit.o:$(CONSTANTS) $(EXIT)
	g++ exit.cpp -c
level.o:$(CONSTANTS) player.h $(LEVEL) $(ELEMENT_HEADERS)
	g++ level.cpp -c
player.o:$(CONSTANTS) $(PLAYER)
	g++ player.cpp -c
collision.o:collision.cpp $(CONSTANTS)
	g++ collision.cpp -c
init.o:init.cpp $(CONSTANTS)
	g++ init.cpp -c
button.o:button.cpp button.h
	g++ button.cpp -c
color.o:color.cpp color.h
	g++ color.cpp -c
string.o:string.cpp string.h
	g++ string.cpp -c
level_editor.o:level_editor.cpp level_editor.h button_element.h button_element.cpp $(CONSTANTS)
	g++ level_editor.cpp -c