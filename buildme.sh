

rm -rf build
rm -rf CMakeFiles
rm -rf CMakeCache.txt
rm -rf cmake_install.cmake
rm -rf Makefile
rm -rf src/CMakeFiles
rm -rf src/CMakeCache.txt
rm -rf src/cmake_install.cmake
rm -rf src/Makefile

if [ -d "build" ]; then
    cmake .
    make
fi
