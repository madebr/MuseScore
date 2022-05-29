
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
            add_library(FreeType::FreeType INTERFACE IMPORTED)
            set_target_properties(FreeType::FreeType PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${FREETYPE_INCLUDE_DIRS}"
                INTERFACE_LINK_DIRECTORIES "${FREETYPE_LIBDIR}"
                INTERFACE_LIBRARIES "${FREETYPE_LIBRARIES}"
                INTERFACE_COMPILE_OPTIONS "${FREETYPE_CPP}"
                )
      else (OS_IS_MAC)
            find_package(Freetype REQUIRED)
      endif (OS_IS_MAC)
endif (NOT BUILD_THIRDPARTY)

if (BUILD_THIRDPARTY)
      add_subdirectory(thirdparty/freetype)
else (BUILD_THIRDPARTY)
      add_library(mscore_freetype INTERFACE)
      target_link_libraries(mscore_freetype INTERFACE Freetype::Freetype)
endif (BUILD_THIRDPARTY)
