# jsonCPP
Lightweight application written in modern C++ to read and write JSON.
This application is still under development and only supports basic rudimentary operations.

## Conceptualization
The main goal of this project is to provide convenient access via object oriented descriptors.
```JsonValue``` represents any value that can be member in a ```JsonArray```. 
Looking at ```JsonObject```, a ```JsonValue``` is connected with a key. 
This key value pair is called ```JsonItem```. A ```JsonValue``` can also be a ```JsonObject``` or ```JsonArray```.
Additionally, primitive types like strings or numeric values can be represented in a ```JsonValue```.
A ```JsonStructure``` is a special kind of ```JsonValu``` as it summarizes ```JsonObject``` and ```JsonArray```.

## How To Use
1. Clone repository
2. Cd into build folder
3. Execute jsoncpp file and add path.