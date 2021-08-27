#include "InstanciarCubos.h"
#include "SceneTree.hpp"
#include "RigidBody.hpp"
#include "Engine.hpp"

using namespace godot;//sino uso esto no funciona

InstanciarCubos::InstanciarCubos() 
{
    
}

InstanciarCubos::~InstanciarCubos() 
{
    
}

void InstanciarCubos::_init() 
{
}

void InstanciarCubos::_ready() 
{
    Godot::print("inicio el juego");
    FpsText = (godot::Label*)get_tree()->get_nodes_in_group("FpsText")[0];
    ContadorText = (godot::Label*)get_tree()->get_nodes_in_group("ContadorText")[0];
}

void InstanciarCubos::_on_TimerPrueba_timeout() 
{
    contador ++;
    ContadorText->set_text( String::num_int64(contador) );

    Node *cuboInstanciado = cuboFisico->instance();
    if(cuboInstanciado == nullptr) return;//Siempre verifico los punteros para no romper el programa
    add_child(cuboInstanciado);
}


void InstanciarCubos::_process(const double p_delta) 
{
    ManejarFpsEnLabel();
}

void InstanciarCubos::ManejarFpsEnLabel() 
{
    if(FpsText == nullptr) return;
    FpsText->set_text("FPS= " + String::num_real( Engine::get_singleton()->get_frames_per_second() ) );
    Godot::print( String::num_real( Engine::get_singleton()->get_frames_per_second() ) );
    if(Engine::get_singleton()->get_frames_per_second() > (real_t)50)
    {
        FpsText->set("custom_colors/font_color",godot::Color(0,0,1 ) );
        
    } 

    if(Engine::get_singleton()->get_frames_per_second() <= (real_t)50)
    {
        FpsText->set("custom_colors/font_color",godot::Color(0.011763, 0.860352, 0) );
       
    }
    if(Engine::get_singleton()->get_frames_per_second() < (real_t)40)
    {
        FpsText->set("custom_colors/font_color",godot::Color(0.974609, 1, 0) );
        
    }
    if(Engine::get_singleton()->get_frames_per_second() < (real_t)30)
    {
        FpsText->set("custom_colors/font_color",godot::Color(0.96582, 0.288614, 0) );
        
    }
    if(Engine::get_singleton()->get_frames_per_second() < (real_t)20)
    {
        FpsText->set("custom_colors/font_color",godot::Color(0.96582, 0, 0.345205) );
        
    }
    if(Engine::get_singleton()->get_frames_per_second() < (real_t)10)
    {
        FpsText->set("custom_colors/font_color",godot::Color(1, 0, 0) );
         
    }
}



void InstanciarCubos::_register_methods() 
{
    godot::register_method("_ready", &InstanciarCubos::_ready);
    godot::register_method("_process",&InstanciarCubos::_process);
    godot::register_method("_on_TimerPrueba_timeout", &InstanciarCubos::_on_TimerPrueba_timeout);
    godot::register_method("Instanciar", &InstanciarCubos::_process);
    godot::register_property("contador", &InstanciarCubos::contador, (int)1);
    godot::register_property("cuboFisico", &InstanciarCubos::cuboFisico, (Ref<PackedScene>)nullptr);//hace que se vea el packet scene en el editor
    godot::register_method("ManejarFpsEnLabel",&InstanciarCubos::ManejarFpsEnLabel);
}
