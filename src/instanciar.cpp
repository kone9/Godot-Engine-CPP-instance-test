#ifndef __INSTANCIAR_H__
#define __INSTANCIAR_H__

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
    timerAwait = Timer()._new();//creo el timer desde el inicio
    get_node<godot::Node>("root");
    add_child(timerAwait);//agrego el timer await dinamicamente
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
    Await(3,"ContinuarFlujo");
    Godot::print("espero un segundo");
    // godot::Object::cast_to<godot::RigidBody>(cuboInstanciado)->set_can_sleep(true);
}

void Instanciar::ContinuarFlujo()
{

}


void Instanciar::Await(float timeAwait, String nameFunction) 
{
    timerAwait->set_wait_time(timeAwait);
    timerAwait->connect(timeAwait, this, nameFunction);
    timerAwait->set_one_shot(true);
    timerAwait->start();
}



void Instanciar::_register_methods() 
{
    register_method("Instanciar", &Instanciar::_process);
    register_method("_on_TimerInstanciar_timeout", &Instanciar::_on_TimerInstanciar_timeout);
    register_method("Await", &Instanciar::Await);
    register_method("ContinuarFlujo", &Instanciar::ContinuarFlujo);
}



#endif // __INSTANCIAR_H__