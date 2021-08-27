#include "CuboFisico.h"

using namespace godot;



void CuboFisico::_init() 
{
    
}


void CuboFisico::_on_TimerCambiarTipo_timeout() 
{
    // Godot::print("cambio a modo statico");
    set_mode( Mode::MODE_STATIC );//se hace estatico
}


void CuboFisico::_register_methods() 
{
    godot::register_method("_on_TimerCambiarTipo_timeout", &CuboFisico::_on_TimerCambiarTipo_timeout);
}


