# PocoProjects
test projects for how to using Poco

For how to use Poco from conan, see: https://conan.io/center/recipes/poco?version=1.13.3
pre-requirement:
  1. Has Conan installed. Sample see: 
       https://docs.conan.io/2/tutorial/consuming_packages/build_simple_cmake_project.html
  2. Has CMake installed

Steps to bulid it:
  1. git clone https://github.com/harryyang2099/PocoTest.git
  2. cd PocoTest
  3. conan profile detect --force
  4. conan install . --output-folder=build --build=missing -s compiler.cppstd=17 -r conancenter
     //This would install all depends
  5. Move all files from build\build\generators to build
  6. cd build
  7. cmake .. -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake"
     //This would generate project files such as xxx.sln
  8. cmake --build . --config Release
