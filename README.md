# A job runner for API C++ 20   

[![C/C++ CI](https://github.com/Noah-Wilderom/JobRunnerServer/actions/workflows/build.yml/badge.svg?branch=master&event=push)](https://github.com/Noah-Wilderom/JobRunnerServer/actions/workflows/build.yml)

## Requirements   

- [C++ 20](https://en.cppreference.com/w/cpp/20) 
- [cmake 3.24^](https://github.com/Kitware/CMake/releases/)

## Build
### Manual
```console
mkdir -p ./build
cmake -B/build -S . -D CMAKE_BUILD_TYPE=Release
cmake --build /build
./build/RunnerServer
```

### Docker
```console
docker build --rm -f Dockerfile -t runner-server:latest .
docker run --rm -it runner-server:latest
```