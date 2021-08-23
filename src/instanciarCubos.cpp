#ifndef __INSTANCIAR_H__
#define __INSTANCIAR_H__

#include "instanciarCubos.h"
#include <SceneTree.hpp>
#include "RigidBody.hpp"

using namespace godot;//sino uso esto no funciona

InstanciarCubos::InstanciarCubos() 
{
    
}

InstanciarCubos::~InstanciarCubos() 
{
    
}

void InstanciarCubos::_init() 
{
    get_node<Timer>("TimerInstanciar");
    timerAwait = Timer()._new();//creo el timer desde el inicio
    get_node<Node>("root");
    add_child(timerAwait);//agrego el timer await dinamicamente
}

void InstanciarCubos::_process(float delta) 
{
    
}

void InstanciarCubos::_on_TimerInstanciar_timeout() 
{
    Godot::print("instancio cubo");
    
    Node *cuboInstanciado = cuboFisico->instance();
    if(cuboInstanciado == nullptr) return;//Siempre verifico los punteros para no romper el programa
    add_child(cuboInstanciado);
    Await(3,"ContinuarFlujo");
    
    // godot::Object::cast_to<godot::RigidBody>(cuboInstanciado)->set_can_sleep(true);
    // cast_to<RigidBody>(cuboInstanciado)->set_can_sleep(true);
}


void InstanciarCubos::ContinuarFlujo()
{
    Godot::print("pasaron 3 segundos");
}

void InstanciarCubos::Await(float timeAwait, String nameFunction) 
{
    timerAwait->set_wait_time(timeAwait);
    timerAwait->connect(timeAwait, this, nameFunction);
    timerAwait->set_one_shot(true);
    timerAwait->start();
}

void InstanciarCubos::_register_methods() 
{
    register_method("Instanciar", &InstanciarCubos::_process);
    register_method("_on_TimerInstanciar_timeout", &InstanciarCubos::_on_TimerInstanciar_timeout);
    register_method("Await", &InstanciarCubos::Await);
    register_method("ContinuarFlujo", &InstanciarCubos::ContinuarFlujo);
    // register_property("cuboFisico",InstanciarCubos::cuboFisico,PackedScene);
    godot::register_property("cuboFisico", &InstanciarCubos::cuboFisico, (Ref<PackedScene>)nullptr);//hace que se vea el packet scene en el editor
}


#endif // __INSTANCIAR_H__