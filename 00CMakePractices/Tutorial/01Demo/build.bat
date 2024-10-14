@echo of 
mkdir build
cd build 
cmake -G "MinGW Makefiles" ..
cmake --build . --config Release -j 
cmake --install .