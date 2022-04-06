# C++ executable using CMake + vcpkg

Cross-platform, cross-toolchain C++ project using CMake as meta-build system and vcpkg as package manager.
Useful as seed to germinate further projects from.

# Tools

Make sure the following tools are installed:

* C++ compiler toolchain
  - **Windows**: VC++ (Visual Studio 2017+), [MinGW][] (Minimal GCC on Windows), Clang
  - **Linux**: GCC, Clang
  - **Mac**: Clang (Xcode), GCC
* [CMake][]
* [vcpkg][]

**`cmake` should be in `$PATH` / `%PATH%`.**

# Build

Fix `vcpkg`’s path in the `cmake` command below to where it’s installed on your machine.

``` shell
git clone https://github.com/legends2k/cpp-vcpkg-seed

cd cpp-vcpkg-seed

cmake -B build -DCMAKE_TOOLCHAIN_FILE=D:\libs\vcpkg\scripts\buildsystems\vcpkg.cmake

cmake --build build
```

This should build the `seed` executable under `//build`.

# Dependencies

Project dependencies are listed in `vcpkg.json` manifest.  Add/Remove libraries as needed.
Available libraries are listed at [vcpkg packages][].
By default [fltk][] and [spdlog][] are listed as dependencies for GUI programming and logging.

``` shell
  "dependencies": [
    "spdlog",
    "fltk"
  ]
```

Refer [vcpkg manifest documentation][] for details.


# References

* [CMake Documentation][cmake-doc]
* [vcpkg Manifest Mode: CMake Example][vcpkg cmake example]


[CMake]: https://cmake.org/
[vcpkg]: https://vcpkg.io/en/getting-started.html
[mingw]: https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/
[fltk]: https://www.fltk.org/
[spdlog]: https://github.com/gabime/spdlog
[vcpkg manifest documentation]: https://vcpkg.io/en/docs/users/manifests.html
[vcpkg cmake example]: https://vcpkg.io/en/docs/examples/manifest-mode-cmake.html
[cmake-doc]: https://cmake.org/cmake/help/latest/index.html
[vcpkg packages]: https://vcpkg.io/en/packages.html
