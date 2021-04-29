CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

PROJECT(LibJPEG)


SET(
    LIBJPEG_SRC
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcapistd.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdpostct.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jidctflt.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcsample.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jutils.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jfdctflt.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdcolor.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jddctmgr.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jaricom.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdmarker.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdapimin.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jquant1.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdmainct.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcparam.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdcoefct.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdinput.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcdctmgr.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jmemnobs.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdapistd.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcomapi.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jidctint.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jquant2.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcmaster.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdtrans.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jfdctint.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jctrans.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jfdctfst.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcinit.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcmarker.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcarith.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcapimin.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jccoefct.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jerror.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcprepct.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdhuff.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jmemmgr.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdatadst.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdmaster.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdarith.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdmerge.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jchuff.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jcmainct.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdatasrc.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jdsample.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jccolor.c
    ${PROJECT_SOURCE_DIR}/LibJPEG/source/jidctfst.c
)


INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/LibJPEG/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/)


SET(
    PROJECT_SRC
    ${PROJECT_SOURCE_DIR}/main.c
    ${PROJECT_SOURCE_DIR}/encode.c
    ${PROJECT_SOURCE_DIR}/jdata_conf.c
)


ADD_LIBRARY(jpeg SHARED ${LIBJPEG_SRC})

ADD_EXECUTABLE(main ${PROJECT_SRC})

TARGET_LINK_LIBRARIES(main jpeg)