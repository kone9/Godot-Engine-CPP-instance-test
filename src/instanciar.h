#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Timer.hpp>
#include "RandomNumberGenerator.hpp"
#include "PackedScene.hpp"

namespace godot {

class Instanciar : public Spatial {
    GODOT_CLASS(Instanciar, Spatial)

private:
    float time_passed;
    //puntero al timer de la escena
    godot::Timer* NuevoTimer;

public:
    //para registrar metodos como el update importantisimo
    static void _register_methods();

    //metodo contructor
    Instanciar();

    //metodo destructor
    ~Instanciar();

    void _init(); // our initializer called by Godot

    //funcion process se ejectua 60 veces por segundo
    void _process(float delta);

private:
    godot::Ref<godot::RandomNumberGenerator> _random;//asi hago la referencia a la clase, exactamente igual que en unreal engine cuando necesitas acceder a objetos que no estan en la escena
    godot::Ref<godot::PackedScene> cuboFisico;//asi hago un packetScene tambien uso una referencia a una clase, tengo que identificar cuando se usan referencias a clase y cuando son punteros


public:
    //referencia a la señal TIMEOUT
    void _on_TimerInstanciar_timeout();
    
};

}

#endif