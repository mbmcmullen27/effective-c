[ ! -d "./bin" ] && mkdir bin;
./compile.sh
./create-static-library.sh
./link.sh
