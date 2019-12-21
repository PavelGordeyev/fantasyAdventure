CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = main.o Die.o Menu.o checkInput.o Space.o MathSpace.o DuelSpace.o PrizeSpace.o DoorSpace.o Game.o

SRCS = main.cpp Die.cpp Menu.cpp checkInput.cpp Space.cpp MathSpace.cpp DuelSpace.cpp PrizeSpace.cpp DoorSpace.cpp Game.cpp

HEADERS = 

projectFinal: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o projectFinal

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	-rm ${OBJS} projectFinal