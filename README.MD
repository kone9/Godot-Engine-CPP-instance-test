# proyecto usar Godot Engine con C++ usando VScode.

## https://docs.godotengine.org/es/stable/tutorials/plugins/gdnative/gdnative-cpp-example.html

## Importante en Vscode se configuro un "TASK" que permite compilar desde el mismo editor llendo a TERMINAL/Run Task/ "construir los modulos con scons DEBUG WINDOWS configuracion Ariel" Tambien hay una versión para release

## Por alguna razón en windows 10 no se genera en la carpeta bin/win64 dentro del proyecto de godot el archivo que permite ejecutar los modulos C++ "libgdexample.dll"


Este es el error
E 0:00:00.925   open_dynamic_library: Can't open dynamic library: D:/PROYECTOS GODOT ENGINE C++/InstanceTestGDNative_CPP/InstanceTestGDNative_CPP/bin/win64/libgdexample.dll, error: Error 126: No se puede encontrar el mￃﾳdulo especificado.
.
  <Error de C++>Condition "!p_library_handle" is true. Returned: ERR_CANT_OPEN
  <Fuente C++>  platform/windows/os_windows.cpp:2425 @ open_dynamic_library()


## no funciona el launch.


Para iniciar el proyecto necesitas tener 

instalado en tu PC python.

Una ves instalado python tenes que tener instalado pip.

Luego necesitas instalar scons para compilar.

sin esas librerias no vas a poder compilar.

Podes compilar directo desde el editor de VScode o con los comandos.

Next compile the godot-cpp bindings:



- cd "en la carpeta"
- cd godot-cpp
- scons platform=windows generate_bindings=yes -j4 bits=64

- agregar más modulos:
- scons platform=windows


