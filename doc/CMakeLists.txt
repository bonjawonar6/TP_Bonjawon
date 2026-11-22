find_package(Doxygen REQUIRED)

configure_file(doxyfilerc ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

add_custom_target(doc
  COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Génération de la documentation avec Doxygen")