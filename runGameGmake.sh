rm ./Makefile

premake5 --file=./premake5.lua gmake

#make clean

if ! bear -- make config=debug; then
    echo "Compilation failed stopping...."
    exit 1
fi

./build/linux-x86_64/Debug/MouseGame

