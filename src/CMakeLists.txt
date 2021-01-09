# Add Headers to load image library so they can show up in Header Files in IDEs
set(LoadImage_HEADER_DIR ${PROJECT_SOURCE_DIR}/include)
add_library(LoadImage
  loadimage.cpp ${LoadImage_HEADER_DIR}/loadimage.hpp
)
target_link_libraries(LoadImage ${OpenCV_LIBS})

add_executable(ShowImage main.cpp)
target_link_libraries(ShowImage LoadImage)

# Add command to build process to copy over the images folder.
add_custom_command(TARGET ShowImage POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/images" "$<TARGET_FILE_DIR:ShowImage>/images"
)

