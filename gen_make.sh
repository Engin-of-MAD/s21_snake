rm -rf build
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/.local/lib
echo $LD_LIBRARY_PATH
mkdir build
cd build
cmake ..
cmake -G "Unix Makefiles"

