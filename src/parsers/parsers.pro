#-*- mode: makefile; tab-width: 4; -*-
#
include(../../qmake.inc)
#
TEMPLATE = lib
#
SOURCES	 =  IOSCfgLexer.cpp  \
			IOSCfgParser.cpp \
			IPTCfgLexer.cpp  \
			IPTCfgParser.cpp

HEADERS	 = ../../config.h    \
			IOSCfgLexer.hpp  \
			IOSCfgParser.hpp \
			IOSCfgParserTokenTypes.hpp \
			IPTCfgLexer.hpp  \
			IPTCfgParser.hpp \
			IPTCfgParserTokenTypes.hpp \


CONFIG += staticlib

INCLUDEPATH += $$ANTLR_INCLUDEPATH ../libfwbuilder/src/

LIBS += $$ANTLR_LIBS
DEFINES += $$ANTLR_DEFINES

TARGET   = fwbparser

INSTALLS -= target
