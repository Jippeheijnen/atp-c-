#! /usr/bin/bash

sudo ls -la > /dev/null

cd /home/jippe/development/atp-cplusplus/

echo "Compiling C++"
cd cpp/build
cmake .. &>/dev/null
make
sudo make install

echo ""
echo ""
echo "Compiling C++ tests"
cd ../tests/build
cmake .. &>/dev/null
make

echo ""
echo ""
echo "Compiling PyBind11"
cd ../../../build
cmake .. &>/dev/null
make
sudo make install

echo ""
echo ""
echo "renaming atp_cplusplus.cpython-310-x86_64-linux-gnu.so to atp_cplusplus.co"
sudo mv /home/jippe/.local/lib/python3.10/site-packages/atp_cplusplus.cpython-310-x86_64-linux-gnu.so /home/jippe/.local/lib/python3.10/site-packages/atp_cplusplus.so
echo "Done!"
