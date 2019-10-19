BUILD_DIR=build
BUILD_FILE=build/Makefile
BUILD_MODE="Unix Makefiles"

all: _build

${BUILD_FILE}: 
	mkdir -p ${BUILD_DIR}
	cd ${BUILD_DIR} && cmake -G${BUILD_MODE} ..

_build: ${BUILD_FILE}
	cd ${BUILD_DIR} && ${MAKE} ${MAKEFLAGS}

clean:
	${RM} -rf ${BUILD_DIR}
