# LeetCode-cpp

Do some leetcode in cpp

## How to run tests

[Catch2](https://github.com/catchorg/Catch2) test framework is used, basically I followed this [guide](https://github.com/catchorg/Catch2/blob/devel/docs/slow-compiles.md#top) on how to speed up compilation. As a summary:

```zsh
# compile catch2 to obj file
$ clang++ catch.cpp -c -o obj/catch.o
$ clang++ tests-main -c -o obj/tests-main.o

# link them in the test you want
$ cd 20201028_Example
$ clang++ ../obj/* *.cpp -o test && test
===============================================================================
All tests passed (4 assertions in 1 test case)
```

I'm using vscode, so the following `tasks.json` file can simplify the above build and test tasks:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "C/C++: clang++ build current dir tests",
            "command": "/usr/local/opt/llvm/bin/clang++",
            "args": [
                "-std=c++2a",
                "${workspaceFolder}/obj/*",
                "${fileDirname}/*.cpp",
                "-o",
                "${fileDirname}/test"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "type": "shell",
            "label": "C/C++: run current dir tests",
            "command": "${fileDirname}/test",
            "group": {
                "kind": "test",
                "isDefault": true
            }
        }
    ]
}
```
