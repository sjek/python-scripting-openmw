set(EXTENSIONTOOL extensiontool.cpp)
source_group(apps\\extensiontool FILES ${EXTENSIONTOOL})

# Main executable
add_executable(extensiontool ${EXTENSIONTOOL})

target_link_libraries(extensiontool components)
