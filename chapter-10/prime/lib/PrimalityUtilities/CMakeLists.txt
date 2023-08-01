SET(PROJECT_NAME PrimalityUtilities)
SET(LIBRARY_NAME libPrimalityUtilities)

set(PUBLIC_HEADERS
  ${CMAKE_SOURCE_DIR}/include/PrimalityUtilities/isprime.h
)

include_directories("${CMAKE_SOURCE_DIR}/include/PrimalityUtilities/")

set(${PROJECT_NAME}_SRC
  isprime.c
)

add_library(${LIBRARY_NAME} STATIC ${${PROJECT_NAME}_SRC})
