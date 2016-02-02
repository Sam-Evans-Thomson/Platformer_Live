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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/20e7374d/Game.o \
	${OBJECTDIR}/_ext/20e7374d/InputComponent.o \
	${OBJECTDIR}/_ext/417fd003/Player.o \
	${OBJECTDIR}/_ext/417fd003/StateComponent.o \
	${OBJECTDIR}/_ext/ee4cd6a8/Timer.o \
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
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/platformer_live ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/20e7374d/Game.o: /home/sam/NetBeansProjects/Platformer_Live/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/20e7374d
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/Game.o /home/sam/NetBeansProjects/Platformer_Live/Game.cpp

${OBJECTDIR}/_ext/20e7374d/InputComponent.o: /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/20e7374d
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/InputComponent.o /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp

${OBJECTDIR}/_ext/417fd003/Player.o: /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/Player.o /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp

${OBJECTDIR}/_ext/417fd003/StateComponent.o: /home/sam/NetBeansProjects/Platformer_Live/Player/StateComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/StateComponent.o /home/sam/NetBeansProjects/Platformer_Live/Player/StateComponent.cpp

${OBJECTDIR}/_ext/ee4cd6a8/Timer.o: /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/ee4cd6a8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp

${OBJECTDIR}/_ext/4d4d1112/Texture.o: /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Texture.o /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp

${OBJECTDIR}/_ext/4d4d1112/Window.o: /home/sam/NetBeansProjects/Platformer_Live/Window/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Window.o /home/sam/NetBeansProjects/Platformer_Live/Window/Window.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/Game_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Game.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/20e7374d/Game.o ${OBJECTDIR}/_ext/20e7374d/Game_nomain.o;\
	fi

${OBJECTDIR}/_ext/20e7374d/InputComponent_nomain.o: ${OBJECTDIR}/_ext/20e7374d/InputComponent.o /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/20e7374d
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/20e7374d/InputComponent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/20e7374d/InputComponent_nomain.o /home/sam/NetBeansProjects/Platformer_Live/InputComponent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/20e7374d/InputComponent.o ${OBJECTDIR}/_ext/20e7374d/InputComponent_nomain.o;\
	fi

${OBJECTDIR}/_ext/417fd003/Player_nomain.o: ${OBJECTDIR}/_ext/417fd003/Player.o /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/417fd003/Player.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/Player_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/Player.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/417fd003/Player.o ${OBJECTDIR}/_ext/417fd003/Player_nomain.o;\
	fi

${OBJECTDIR}/_ext/417fd003/StateComponent_nomain.o: ${OBJECTDIR}/_ext/417fd003/StateComponent.o /home/sam/NetBeansProjects/Platformer_Live/Player/StateComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/417fd003
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/417fd003/StateComponent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/417fd003/StateComponent_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Player/StateComponent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/417fd003/StateComponent.o ${OBJECTDIR}/_ext/417fd003/StateComponent_nomain.o;\
	fi

${OBJECTDIR}/_ext/ee4cd6a8/Timer_nomain.o: ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/ee4cd6a8
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ee4cd6a8/Timer_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Utilities/Timer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/ee4cd6a8/Timer.o ${OBJECTDIR}/_ext/ee4cd6a8/Timer_nomain.o;\
	fi

${OBJECTDIR}/_ext/4d4d1112/Texture_nomain.o: ${OBJECTDIR}/_ext/4d4d1112/Texture.o /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/4d4d1112
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/4d4d1112/Texture.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Texture_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Window/Texture.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d4d1112/Window_nomain.o /home/sam/NetBeansProjects/Platformer_Live/Window/Window.cpp;\
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
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
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
