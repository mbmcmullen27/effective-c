SET(PROJECT_NAME PrimeDriver)
SET(EXECUTABLE_NAME primetest)

include_directories("${CMAKE_SOURCE_DIR}/include/")

set(${PROJECT_NAME}_SRC
  driver.c
)

add_executable(${EXECUTABLE_NAME} ${${PROJECT_NAME}_SRC})
target_link_libraries(${EXECUTABLE_NAME} libPrimalityUtilities)
