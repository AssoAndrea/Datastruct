
MD bin
clang.exe -Iinclude -o bin\data.lib src\*.c -fuse-ld=llvm-lib

clang.exe -Iinclude -Iinclude -o bin\data.exe src\*.c -Lbin -l data