#include "instanciar.h"
#include <SceneTree.hpp>
#include "RigidBody.hpp"

using namespace godot;//sino uso esto no funciona

Instanciar::Instanciar() 
{
    
}

Instanciar::~Instanciar() 
{
    
}

void Instanciar::_init() 
{
    get_node<godot::Timer>("TimerInstanciar");
}

void Instanciar::_process(float delta) 
{
    
}

void Instanciar::_on_TimerInstanciar_timeout() 
{
    Godot::print("instancio cubo");
    
    godot::Node *cuboInstanciado = cuboFisico->instance();
    if(cuboInstanciado == nullptr) return;//Siempre verifico los punteros para no romper el programa
    add_child(cuboInstanciado);
    
    Godot::print("espero un segundo");
    
    godot::Object::cast_to<godot::RigidBody>(cuboInstanciado)->set_can_sleep(true);
     
}

void Instanciar::_register_methods() 
{
    register_method("Instanciar", &Instanciar::_process);
    register_method("_on_TimerInstanciar_timeout", &Instanciar::_on_TimerInstanciar_timeout);
}


