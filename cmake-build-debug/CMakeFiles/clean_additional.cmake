# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BrickGame_app_autogen"
  "BrickGame_snake_cli_autogen"
  "CMakeFiles/BrickGame_app_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BrickGame_app_autogen.dir/ParseCache.txt"
  "CMakeFiles/BrickGame_snake_cli_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BrickGame_snake_cli_autogen.dir/ParseCache.txt"
  "CMakeFiles/test_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/test_autogen.dir/ParseCache.txt"
  "models/SnakeCore/CMakeFiles/SnakeLib_autogen.dir/AutogenUsed.txt"
  "models/SnakeCore/CMakeFiles/SnakeLib_autogen.dir/ParseCache.txt"
  "models/SnakeCore/SnakeLib_autogen"
  "models/TetrisCore/CMakeFiles/TetrisLib_autogen.dir/AutogenUsed.txt"
  "models/TetrisCore/CMakeFiles/TetrisLib_autogen.dir/ParseCache.txt"
  "models/TetrisCore/TetrisLib_autogen"
  "models/UnionModule/CMakeFiles/UnionLib_autogen.dir/AutogenUsed.txt"
  "models/UnionModule/CMakeFiles/UnionLib_autogen.dir/ParseCache.txt"
  "models/UnionModule/UnionLib_autogen"
  "test_autogen"
  "view/Desktop/CMakeFiles/DesktopLib_autogen.dir/AutogenUsed.txt"
  "view/Desktop/CMakeFiles/DesktopLib_autogen.dir/ParseCache.txt"
  "view/Desktop/DesktopLib_autogen"
  )
endif()
