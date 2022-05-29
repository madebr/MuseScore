find_path(FLUIDSYNTH_INCLUDE_DIR
    NAMES fluidsynth.h
    )

find_library(FLUIDSYNTH_LIBRARY
    NAMES fluidsynth
    )

set(FLUIDSYNTH_COMPILE_OPTIONS "" CACHE STRING "Compile options of FluidSynth")

set(FLUIDSYNTH_LINK_OPTIONS "" CACHE STRING "Link options of FluidSynth")

include(FindPackageHandleStandardArgs)
findpackage_handle_standard_args(FluidSynth
    REQUIRED_VARS FLUIDSYNTH_LIBRARY FLUIDSYNTH_INCLUDE_DIR
    )

if (FluidSynth_FOUND)
    if (NOT TARGET FluidSynth::FluidSynth)
        add_library(FluidSynth::FluidSynth IMPORTED UNKNOWN)
        set_target_properties(FluidSynth::FluidSynth PROPERTIES
            IMPORTED_LOCATION "${FLUIDSYNTH_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${FLUIDSYNTH_INCLUDE_DIR}"
            INTERFACE_COMPILE_OPTIONS "${FLUIDSYNTH_COMPILE_OPTIONS}"
            INTERFACE_LINK_OPTIONS "${FLUIDSYNTH_LINK_OPTIONS}"
            )
    endif (NOT TARGET FluidSynth::FluidSynth)
endif ()
