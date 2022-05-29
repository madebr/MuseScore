
##
## freetype2 >= 2.5.2
##

if (NOT BUILD_THIRDPARTY)
      if (OS_IS_MAC)
            PKGCONFIG1 (freetype2 2.5.2 FREETYPE_INCLUDE_DIRS FREETYPE_LIBDIR FREETYPE_LIBRARIES FREETYPE_CPP)
            if (FREETYPE_INCLUDE_DIRS)
                  STRING(REGEX REPLACE  "\"" "" FREETYPE_INCLUDE_DIRS ${FREETYPE_INCLUDE_DIRS})
                  STRING(REGEX REPLACE  "\"" "" FREETYPE_LIBDIR ${FREETYPE_LIBDIR})
                  message("freetype2 detected ${FREETYPE_INCLUDE_DIRS} ${FREETYPE_LIBDIR} ${FREETYPE_LIBRARIES}")
            else (FREETYPE_INCLUDE_DIRS)
                  message(FATAL_ERROR "freetype >= 2.5.2 is required\n")
            endif (FREETYPE_INCLUDE_DIRS)
      else (OS_IS_MAC)
            find_package(Freetype REQUIRED)
      endif (OS_IS_MAC)
endif (NOT BUILD_THIRDPARTY)


if (NOT BUILD_THIRDPARTY)
      include_directories(${FREETYPE_INCLUDE_DIRS})
else (NOT BUILD_THIRDPARTY)
      include_directories(${PROJECT_SOURCE_DIR}/thirdparty/freetype/include)
endif (NOT BUILD_THIRDPARTY)

if (BUILD_THIRDPARTY)
      add_subdirectory(thirdparty/freetype)
endif (BUILD_THIRDPARTY)
