mkdir build
cd build
cmake ..
make all
mkdir report
mkdir coverage
mkdir gcov
./BrickGame_tests

mv CMakeFiles/BrickGame_tests.dir/tests/*.gcno coverage
mv models/SnakeCore/CMakeFiles/SnakeLib.dir/src/*.gcno coverage
mv models/TetrisCore/CMakeFiles/TetrisLib.dir/src/*.gcno coverage
mv models/UnionModule/CMakeFiles/UnionLib.dir/src/*.gcno coverage

mv CMakeFiles/BrickGame_tests.dir/tests/*.gcda coverage
mv models/SnakeCore/CMakeFiles/SnakeLib.dir/src/*.gcda coverage
mv models/TetrisCore/CMakeFiles/TetrisLib.dir/src/*.gcda coverage
mv models/UnionModule/CMakeFiles/UnionLib.dir/src/*.gcda coverage

#mv CMakeFiles/BrickGame_tests.dir/tests/*.d coverage
#mv models/SnakeCore/CMakeFiles/SnakeLib.dir/src/*.d coverage
#mv models/TetrisCore/CMakeFiles/TetrisLib.dir/src/*.d coverage
#mv models/UnionModule/CMakeFiles/UnionLib.dir/src/*.d coverage
cd coverage

gcov *.gcno

lcov --capture --directory . --output-file coverage.info


echo pwd
genhtml coverage.info --output-directory ../report
rm *.gcno *.gcda
cmake --build .

