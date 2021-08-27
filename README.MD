# proyecto usar Godot Engine con C++ usando VScode.

## https://docs.godotengine.org/es/stable/tutorials/plugins/gdnative/gdnative-cpp-example.html

## Importante en Vscode se configuro un "TASK" que permite compilar desde el mismo editor llendo a TERMINAL/Run Task/ "Godot_Build_GDnative_C++_DLL_DEBUG" Tambien hay una versión para release "Godot_Build_GDnative_C++_DLL_RELEASE"

## El atajo de teclado para hacer un build debug es ctrl+shif+b


## lo primero que tenes que hacer es actualizar las librerias de godot-cpp. Para eso usas el comando git.

# git submodule update --init --recursive

## lugo vas a terminal/task y ejecutas esto va a crear los binarios en windows que permiten compilar los códigos C++ en la carpeta de proyecto..
# Godot_generate_and_compile_the_bindings_WINDOWS_x64

## igualmente los modulos ya estan en el proyecto, asi que si lo descargas tendria que funcionar igual.

Para iniciar el proyecto necesitas tener 

instalado en tu PC python.

Una ves instalado python tenes que tener instalado pip.

Luego necesitas instalar scons para compilar.

sin esas librerias no vas a poder compilar.

El proyecto trae el compilador y godot dll configurados.

El proyecto pesa 300mb aprox, pero cuando descargas los godot-cpp llega a pesar más de 1 gb.
Para un entorno de desarrollo con C++ es algo correcto, 
en unreal engine para desarrollar con C++ hay que descargar más de 50gb, asi que 1gb no creo que sea para nada pesado


