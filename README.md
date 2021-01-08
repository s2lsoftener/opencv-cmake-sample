# opencv-cmake-sample

Setting up a cross-platform OpenCV project using CMake

## Setting up OpenCV

When CMake looks for packages using `find_package()`, one of the variables it looks at is `PROJECTNAME_DIR`. For OpenCV, this variable is `OpenCV_DIR`, and it should resolve to a directory containing an `OpenCVConfig.cmake` file.

### Windows

Pre-built libraries: https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html

Git Bash:
```bash
export OpenCV_DIR="C:\opencv\build\x64\vc15\lib"
```

## CMake Custom Command: copy_directory

CMakeLists.txt files can define post-build commands, such as copying over an image directory from `src` that the app depends on.

```cmake
# Add command to build process to copy over the images folder.
add_custom_command(TARGET ShowImage POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/images" "$<TARGET_FILE_DIR:ShowImage>/images"
)
```
