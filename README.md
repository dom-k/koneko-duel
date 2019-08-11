# koneko-duel

A cute little terminal game against boredom 😸.

**Note**: This is my first C++ project, which I made for learning purpose.

![AppVeyor](https://img.shields.io/appveyor/ci/domkh/koneko-duel.svg)

## Requirements

- libsqlite3-dev
- cmake
- g++

```sh 
sudo apt install \
    libsqlite3-dev \
    g++ \
    cmake
```

## How to build and run

### Create a build directory

```sh
cd koneko-duel
mkdir -p build
```

### Run cmake from inside the build directory

```sh
cd build
cmake ..
```

### Run make to build the project

```sh
make
```

### Run koneko-duel and profit!

```sh
./koneko-duel
```
