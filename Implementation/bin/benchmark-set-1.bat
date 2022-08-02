:: Execute a set of different benchmarks for size 1

@ECHO off
SET DIR_PATH=../out/build/msvc-x64-release

:: Insert
START /WAIT /B %DIR_PATH%/Benchmark.exe -b insert -s 1 -i 100 -d --seed 1
ECHO.
START /WAIT /B %DIR_PATH%/Benchmark.exe -b insert -s 1 -i 100 --seed 15000
ECHO.

:: Search
START /WAIT /B %DIR_PATH%/Benchmark.exe -b search -s 1 -i 100 -d --seed 30000
ECHO.
START /WAIT /B %DIR_PATH%/Benchmark.exe -b search -s 1 -i 100 --seed 45000
ECHO.

:: Range Search
START /WAIT /B %DIR_PATH%/Benchmark.exe -b range_search -s 1 -i 50 -d --seed 60000
ECHO.
START /WAIT /B %DIR_PATH%/Benchmark.exe -b range_search -s 1 -i 50 --seed 75000