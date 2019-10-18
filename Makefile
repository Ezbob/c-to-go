BUILD_DIR=build
BUILD_FILE=build/Makefile

all: _build

${BUILD_FILE}: 
	mkdir -p ${BUILD_DIR}
	cd ${BUILD_DIR} && cmake -G"Unix Makefiles" ..

_build: ${BUILD_FILE}
	${MAKE} ${MAKEFLAGS} -C ${BUILD_DIR}

clean:
	${RM} -rf ${BUILD_DIR}
