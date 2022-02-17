# cpp_conan_artifactory
This project is a Hello world to create a Cpp Lib and store in Jfrog using Conan 

Define variables 
```
APIKEY"="<yourAPIkeyForArtifactory"
USER="<your@mail.com"
REMOTE_REPO="<yourRemoteArtifactoryRepo> "
REPO_URL="<yourHttps://remoterepo.jfrom.io/artibactory/path>"
ARTIFACT="ProducerLib/0.07"
RECIPE="AlexMx/betaTest"
```

Define in conan our remote repo an user
```
# Add our repository to the remote list
conan remote add $REMOTE_REPO $REPO_URL
conan config set general.revisions_enabled=0
conan user -p $APIKEY -r $REMOTE_REPO $USER
conan remote list
```

Create a new Cpp project using Conan template -s, it means Conan will create a package with embedded sources in "src" folder
```
conan remove *    #<- [optional] Remove all dependencies in cache
conan search "*"  #<- [optional] Verify all dependencies were removed
mkdir producerLib
cd producerLib
conan new $ARTIFACT -s
...
# Modify and|or include your own code in /src/<files> if required.
...
```

Create a package and upload to Artifactory
```
mkdir build
cd build
conan install ..
cmake ../src
make
#if you see a message like follow: "warning:  Clock skew detected.  Your build may be incomplete." use "make clean" to solve it then "make".
#run app: bin/app
cd ..
conan create . $RECIPE
conan upload ${ARTIFACT}@${RECIPE} -r $REMOTE_REPO --all
```
![This is an image](/artifactory.jpg)



Create a consumer of our new lib
```
cd ..
mkdir consumerLib
cd consumerLib

# create a Conan file defining the new artifact (dependency):
printf "[requires]\n${ARTIFACT}@${RECIPE}\n\n[generators]\ncmake\n">conanfile.txt

#create an app to use our new lib:
printf "#include <iostream>\n#include \""producerLib.h\"\nusing namespace std;\nint main(){\n\tcout<<producerLib()<<endl;\n\treturn 0;\n}\n">example.cpp

# create the CMakeLists.txt:
echo '''cmake_minimum_required(VERSION 3.8)
project(consumerLib)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)
add_executable(demo main.cpp)
target_link_libraries(demo producerLib ${CONAN_LIBS})
'''>CMakeLists.txt

conan install .
cmake .
cmake --build .	
#run demo
```