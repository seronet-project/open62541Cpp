### Introduction

The AbstractionLayer should be used to seperate Dependency from other sdks.Currently only the implementation for the open62541 project is available. With this the open62541 project can be used with C++ classes.

### Preinstallation
- open62541 ( >0.3)

### Installation Windows

````
> git clone https://github.com/seronet-project/open62541AbstractionLayer.git
> pushd open62541AbstractionLayer
> mkdir cmake-build-debug
> cd cmake-build-debug
> cmake -DUA_ARCHITECTURE:STRING=win32 ..
> cmake --build . --target install -- -j 2
> popd
````

### Installation Linux

````
> git clone https://github.com/seronet-project/open62541AbstractionLayer.git
> pushd open62541AbstractionLayer
> mkdir cmake-build-debug
> cd cmake-build-debug
> cmake UA_ARCHITECTURE:STRING=posix ..
> cmake --build . --target install -- -j 2
> popd
````

