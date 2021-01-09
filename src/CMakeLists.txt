# Add Headers to load image library so they can show up in Header Files in IDEs
set(LoadImage_HEADER_DIR ${PROJECT_SOURCE_DIR}/include)
add_library(LoadImage
  loadimage.cpp ${LoadImage_HEADER_DIR}/loadimage.hpp
)
# target_include_directories(LoadImage ${OpenCV_INCLUDE_DIRS}) # Might not be needed since I'm using OpenCV 4
target_link_libraries(LoadImage ${OpenCV_LIBS})

add_executable(ShowImage main.cpp)
target_link_libraries(ShowImage LoadImage)

# Add command to build process to copy over the images folder.
add_custom_command(TARGET ShowImage POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/images" "$<TARGET_FILE_DIR:ShowImage>/images"
)

if (WIN32)
  set(OPENCV_DLLS 
    "${OpenCV_DIR}/../bin/opencv_world${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH}.dll"
    "${OpenCV_DIR}/../bin/opencv_videoio_ffmpeg${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH}_64.dll"
    "${OpenCV_DIR}/../bin/opencv_videoio_msmf${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH}_64.dll"
  )
  add_custom_command(TARGET ShowImage POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "** Copying over OpenCV Windows DLLs"
    COMMAND ${CMAKE_COMMAND} -E copy ${OPENCV_DLLS} $<TARGET_FILE_DIR:ShowImage>
  )
endif()