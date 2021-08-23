#include "instanciar.h"


namespace godot
{

    
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
        Godot::print("termino el timer");
    }

    void Instanciar::_register_methods() 
    {
        register_method("Instanciar", &Instanciar::_process);
        register_method("_on_TimerInstanciar_timeout", &Instanciar::_on_TimerInstanciar_timeout);
    }


}