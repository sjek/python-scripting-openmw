set(EXTENSIONTOOL
  extensiontool.cpp
)
source_group(apps\\extensiontool FILES ${ESMTOOL})

# Main executable
add_executable(extensiontool
  ${EXTENSIONTOOL}
)

target_link_libraries(extensiontool
  components
)
