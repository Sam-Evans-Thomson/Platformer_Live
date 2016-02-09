#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/20e7374d/Game.o \
	${OBJECTDIR}/_ext/8e7b6eb9/Actor.o \
	${OBJECTDIR}/_ext/7e1371f3/GameObject.o \
	${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox.o \
	${OBJECTDIR}/_ext/e1d0c8c2/Hitbox.o \
	${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox.o \
	${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox.o \
	${OBJECTDIR}/_ext/7e1371f3/Vec2.o \
	${OBJECTDIR}/_ext/76c91f2d/Graphic.o \
	${OBJECTDIR}/_ext/20e7374d/InputComponent.o \
	${OBJECTDIR}/_ext/4c343a22/LevelManager.o \
	${OBJECTDIR}/_ext/2499d7dd/BasicPlatform.o \
	${OBJECTDIR}/_ext/4c343a22/LevelSegment.o \
	${OBJECTDIR}/_ext/417fd003/GraphicsComponent.o \
	${OBJECTDIR}/_ext/417fd003/PhysicsComponent.o \
	${OBJECTDIR}/_ext/417fd003/Player.o \
	${OBJECTDIR}/_ext/314faef/JumpingState.o \
	${OBJECTDIR}/_ext/314faef/PrimaryState.o \
	${OBJECTDIR}/_ext/314faef/RunningState.o \
	${OBJECTDIR}/_ext/314faef/SecondaryState.o \
	${OBJECTDIR}/_ext/ee4cd6a8/Timer.o \
	${OBJECTDIR}/_ext/4d4d1112/Camera.o \
	${OBJECTDIR}/_ext/4d4d1112/Canvas.o \
	${OBJECTDIR}/_ext/4d4d1112/Texture.o \
	${OBJECTDIR}/_ext/4d4d1112/Window.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES=

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer_live

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer_live: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer_live ${OBJECTFILES} ${LDLIBSOPTIONS} -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

${OBJECTDIR}/_ext/20e7374d/Game.o: /home/sam/NetBeansProjects/Platformer_Live/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/20e7374d
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/Game.o /home/sam/NetBeansProjects/Platformer_Live/Game.cpp

${OBJECTDIR}/_ext/8e7b6eb9/Actor.o: /home/sam/NetBeansProjects/Platformer_Live/GameObject/Actor/Actor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/8e7b6eb9
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8e7b6eb9/Actor.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Actor/Actor.cpp

${OBJECTDIR}/_ext/7e1371f3/GameObject.o: /home/sam/NetBeansProjects/Platformer_Live/GameObject/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e1371f3
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e1371f3/GameObject.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/GameObject.cpp

${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox.o: /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/CircleHitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/CircleHitbox.cpp

${OBJECTDIR}/_ext/e1d0c8c2/Hitbox.o: /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/Hitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/Hitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/Hitbox.cpp

${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox.o: /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/LineHitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/LineHitbox.cpp

${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox.o: /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/RectHitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/RectHitbox.cpp

${OBJECTDIR}/_ext/7e1371f3/Vec2.o: /home/sam/NetBeansProjects/Platformer_Live/GameObject/Vec2.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e1371f3
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e1371f3/Vec2.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Vec2.cpp

${OBJECTDIR}/_ext/76c91f2d/Graphic.o: /home/sam/NetBeansProjects/Platformer_Live/Graphics/Graphic.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/76c91f2d
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/76c91f2d/Graphic.o /home/sam/NetBeansProjects/Platformer_Live/Graphics/Graphic.cpp

${OBJECTDIR}/_ext/20e7374d/InputComponent.o: /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/20e7374d
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/InputComponent.o /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp

${OBJECTDIR}/_ext/4c343a22/LevelManager.o: /home/sam/NetBeansProjects/Platformer_Live/Level/LevelManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4c343a22
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4c343a22/LevelManager.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelManager.cpp

${OBJECTDIR}/_ext/2499d7dd/BasicPlatform.o: /home/sam/NetBeansProjects/Platformer_Live/Level/LevelObjects/BasicPlatform.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2499d7dd
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2499d7dd/BasicPlatform.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelObjects/BasicPlatform.cpp

${OBJECTDIR}/_ext/4c343a22/LevelSegment.o: /home/sam/NetBeansProjects/Platformer_Live/Level/LevelSegment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4c343a22
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4c343a22/LevelSegment.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelSegment.cpp

${OBJECTDIR}/_ext/417fd003/GraphicsComponent.o: /home/sam/NetBeansProjects/Platformer_Live/Player/GraphicsComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/GraphicsComponent.o /home/sam/NetBeansProjects/Platformer_Live/Player/GraphicsComponent.cpp

${OBJECTDIR}/_ext/417fd003/PhysicsComponent.o: /home/sam/NetBeansProjects/Platformer_Live/Player/PhysicsComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/PhysicsComponent.o /home/sam/NetBeansProjects/Platformer_Live/Player/PhysicsComponent.cpp

${OBJECTDIR}/_ext/417fd003/Player.o: /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/Player.o /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp

${OBJECTDIR}/_ext/314faef/JumpingState.o: /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/JumpingState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/JumpingState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/JumpingState.cpp

${OBJECTDIR}/_ext/314faef/PrimaryState.o: /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/PrimaryState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/PrimaryState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/PrimaryState.cpp

${OBJECTDIR}/_ext/314faef/RunningState.o: /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/RunningState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/RunningState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/RunningState.cpp

${OBJECTDIR}/_ext/314faef/SecondaryState.o: /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/SecondaryState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/SecondaryState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/SecondaryState.cpp

${OBJECTDIR}/_ext/ee4cd6a8/Timer.o: /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/ee4cd6a8
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp

${OBJECTDIR}/_ext/4d4d1112/Camera.o: /home/sam/NetBeansProjects/Platformer_Live/Window/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Camera.o /home/sam/NetBeansProjects/Platformer_Live/Window/Camera.cpp

${OBJECTDIR}/_ext/4d4d1112/Canvas.o: /home/sam/NetBeansProjects/Platformer_Live/Window/Canvas.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Canvas.o /home/sam/NetBeansProjects/Platformer_Live/Window/Canvas.cpp

${OBJECTDIR}/_ext/4d4d1112/Texture.o: /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Texture.o /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp

${OBJECTDIR}/_ext/4d4d1112/Window.o: /home/sam/NetBeansProjects/Platformer_Live/Window/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Window.o /home/sam/NetBeansProjects/Platformer_Live/Window/Window.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${OBJECTDIR}/_ext/20e7374d/Game_nomain.o: ${OBJECTDIR}/_ext/20e7374d/Game.o /home/sam/NetBeansProjects/Platformer_Live/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/20e7374d
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/20e7374d/Game.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/Game_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Game.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/20e7374d/Game.o ${OBJECTDIR}/_ext/20e7374d/Game_nomain.o;\
	fi

${OBJECTDIR}/_ext/8e7b6eb9/Actor_nomain.o: ${OBJECTDIR}/_ext/8e7b6eb9/Actor.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Actor/Actor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/8e7b6eb9
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/8e7b6eb9/Actor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8e7b6eb9/Actor_nomain.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Actor/Actor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/8e7b6eb9/Actor.o ${OBJECTDIR}/_ext/8e7b6eb9/Actor_nomain.o;\
	fi

${OBJECTDIR}/_ext/7e1371f3/GameObject_nomain.o: ${OBJECTDIR}/_ext/7e1371f3/GameObject.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e1371f3
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/7e1371f3/GameObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e1371f3/GameObject_nomain.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/GameObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/7e1371f3/GameObject.o ${OBJECTDIR}/_ext/7e1371f3/GameObject_nomain.o;\
	fi

${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox_nomain.o: ${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/CircleHitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox_nomain.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/CircleHitbox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox.o ${OBJECTDIR}/_ext/e1d0c8c2/CircleHitbox_nomain.o;\
	fi

${OBJECTDIR}/_ext/e1d0c8c2/Hitbox_nomain.o: ${OBJECTDIR}/_ext/e1d0c8c2/Hitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/Hitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/e1d0c8c2/Hitbox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/Hitbox_nomain.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/Hitbox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/e1d0c8c2/Hitbox.o ${OBJECTDIR}/_ext/e1d0c8c2/Hitbox_nomain.o;\
	fi

${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox_nomain.o: ${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/LineHitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox_nomain.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/LineHitbox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox.o ${OBJECTDIR}/_ext/e1d0c8c2/LineHitbox_nomain.o;\
	fi

${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox_nomain.o: ${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/RectHitbox.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/e1d0c8c2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox_nomain.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Hitboxes/RectHitbox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox.o ${OBJECTDIR}/_ext/e1d0c8c2/RectHitbox_nomain.o;\
	fi

${OBJECTDIR}/_ext/7e1371f3/Vec2_nomain.o: ${OBJECTDIR}/_ext/7e1371f3/Vec2.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Vec2.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e1371f3
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/7e1371f3/Vec2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e1371f3/Vec2_nomain.o /home/sam/NetBeansProjects/Platformer_Live/GameObject/Vec2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/7e1371f3/Vec2.o ${OBJECTDIR}/_ext/7e1371f3/Vec2_nomain.o;\
	fi

${OBJECTDIR}/_ext/76c91f2d/Graphic_nomain.o: ${OBJECTDIR}/_ext/76c91f2d/Graphic.o /home/sam/NetBeansProjects/Platformer_Live/Graphics/Graphic.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/76c91f2d
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/76c91f2d/Graphic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/76c91f2d/Graphic_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Graphics/Graphic.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/76c91f2d/Graphic.o ${OBJECTDIR}/_ext/76c91f2d/Graphic_nomain.o;\
	fi

${OBJECTDIR}/_ext/20e7374d/InputComponent_nomain.o: ${OBJECTDIR}/_ext/20e7374d/InputComponent.o /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/20e7374d
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/20e7374d/InputComponent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/InputComponent_nomain.o /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/20e7374d/InputComponent.o ${OBJECTDIR}/_ext/20e7374d/InputComponent_nomain.o;\
	fi

${OBJECTDIR}/_ext/4c343a22/LevelManager_nomain.o: ${OBJECTDIR}/_ext/4c343a22/LevelManager.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4c343a22
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/4c343a22/LevelManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4c343a22/LevelManager_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/4c343a22/LevelManager.o ${OBJECTDIR}/_ext/4c343a22/LevelManager_nomain.o;\
	fi

${OBJECTDIR}/_ext/2499d7dd/BasicPlatform_nomain.o: ${OBJECTDIR}/_ext/2499d7dd/BasicPlatform.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelObjects/BasicPlatform.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2499d7dd
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2499d7dd/BasicPlatform.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2499d7dd/BasicPlatform_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelObjects/BasicPlatform.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2499d7dd/BasicPlatform.o ${OBJECTDIR}/_ext/2499d7dd/BasicPlatform_nomain.o;\
	fi

${OBJECTDIR}/_ext/4c343a22/LevelSegment_nomain.o: ${OBJECTDIR}/_ext/4c343a22/LevelSegment.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelSegment.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4c343a22
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/4c343a22/LevelSegment.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4c343a22/LevelSegment_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Level/LevelSegment.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/4c343a22/LevelSegment.o ${OBJECTDIR}/_ext/4c343a22/LevelSegment_nomain.o;\
	fi

${OBJECTDIR}/_ext/417fd003/GraphicsComponent_nomain.o: ${OBJECTDIR}/_ext/417fd003/GraphicsComponent.o /home/sam/NetBeansProjects/Platformer_Live/Player/GraphicsComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/417fd003/GraphicsComponent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/GraphicsComponent_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/GraphicsComponent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/417fd003/GraphicsComponent.o ${OBJECTDIR}/_ext/417fd003/GraphicsComponent_nomain.o;\
	fi

${OBJECTDIR}/_ext/417fd003/PhysicsComponent_nomain.o: ${OBJECTDIR}/_ext/417fd003/PhysicsComponent.o /home/sam/NetBeansProjects/Platformer_Live/Player/PhysicsComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/417fd003/PhysicsComponent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/PhysicsComponent_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/PhysicsComponent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/417fd003/PhysicsComponent.o ${OBJECTDIR}/_ext/417fd003/PhysicsComponent_nomain.o;\
	fi

${OBJECTDIR}/_ext/417fd003/Player_nomain.o: ${OBJECTDIR}/_ext/417fd003/Player.o /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/417fd003/Player.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/Player_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/417fd003/Player.o ${OBJECTDIR}/_ext/417fd003/Player_nomain.o;\
	fi

${OBJECTDIR}/_ext/314faef/JumpingState_nomain.o: ${OBJECTDIR}/_ext/314faef/JumpingState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/JumpingState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/314faef/JumpingState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/JumpingState_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/JumpingState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/314faef/JumpingState.o ${OBJECTDIR}/_ext/314faef/JumpingState_nomain.o;\
	fi

${OBJECTDIR}/_ext/314faef/PrimaryState_nomain.o: ${OBJECTDIR}/_ext/314faef/PrimaryState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/PrimaryState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/314faef/PrimaryState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/PrimaryState_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/PrimaryState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/314faef/PrimaryState.o ${OBJECTDIR}/_ext/314faef/PrimaryState_nomain.o;\
	fi

${OBJECTDIR}/_ext/314faef/RunningState_nomain.o: ${OBJECTDIR}/_ext/314faef/RunningState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/RunningState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/314faef/RunningState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/RunningState_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/RunningState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/314faef/RunningState.o ${OBJECTDIR}/_ext/314faef/RunningState_nomain.o;\
	fi

${OBJECTDIR}/_ext/314faef/SecondaryState_nomain.o: ${OBJECTDIR}/_ext/314faef/SecondaryState.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/SecondaryState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/314faef
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/314faef/SecondaryState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/314faef/SecondaryState_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/PlayerStates/SecondaryState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/314faef/SecondaryState.o ${OBJECTDIR}/_ext/314faef/SecondaryState_nomain.o;\
	fi

${OBJECTDIR}/_ext/ee4cd6a8/Timer_nomain.o: ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/ee4cd6a8
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ee4cd6a8/Timer_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o ${OBJECTDIR}/_ext/ee4cd6a8/Timer_nomain.o;\
	fi

${OBJECTDIR}/_ext/4d4d1112/Camera_nomain.o: ${OBJECTDIR}/_ext/4d4d1112/Camera.o /home/sam/NetBeansProjects/Platformer_Live/Window/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/4d4d1112/Camera.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Camera_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Window/Camera.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/4d4d1112/Camera.o ${OBJECTDIR}/_ext/4d4d1112/Camera_nomain.o;\
	fi

${OBJECTDIR}/_ext/4d4d1112/Canvas_nomain.o: ${OBJECTDIR}/_ext/4d4d1112/Canvas.o /home/sam/NetBeansProjects/Platformer_Live/Window/Canvas.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/4d4d1112/Canvas.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Canvas_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Window/Canvas.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/4d4d1112/Canvas.o ${OBJECTDIR}/_ext/4d4d1112/Canvas_nomain.o;\
	fi

${OBJECTDIR}/_ext/4d4d1112/Texture_nomain.o: ${OBJECTDIR}/_ext/4d4d1112/Texture.o /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/4d4d1112/Texture.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Texture_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/4d4d1112/Texture.o ${OBJECTDIR}/_ext/4d4d1112/Texture_nomain.o;\
	fi

${OBJECTDIR}/_ext/4d4d1112/Window_nomain.o: ${OBJECTDIR}/_ext/4d4d1112/Window.o /home/sam/NetBeansProjects/Platformer_Live/Window/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/4d4d1112/Window.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Window_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Window/Window.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/4d4d1112/Window.o ${OBJECTDIR}/_ext/4d4d1112/Window_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/SDL2 -I/usr/include/c++/5.2.1 -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer_live

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
