#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Timer.hpp>
#include "RandomNumberGenerator.hpp"
#include "PackedScene.hpp"

namespace godot {
    class InstanciarCubos : public Spatial 
    {
            GODOT_CLASS(InstanciarCubos, Spatial)

        public:
            //para registrar metodos como el update importantisimo
            static void _register_methods();
            //metodo contructor
            InstanciarCubos();
            //metodo destructor
            ~InstanciarCubos();
            
            void _init(); // our initializer called by Godot

            //funcion process se ejectua 60 veces por segundo
            void _process(float delta);

        private:
            godot::Ref<godot::RandomNumberGenerator> _random;//asi hago la referencia a la clase, exactamente igual que en unreal engine cuando necesitas acceder a objetos que no estan en la escena
            godot::Ref<godot::PackedScene> cuboFisico;//asi hago un packetScene tambien uso una referencia a una clase, tengo que identificar cuando se usan referencias a clase y cuando son punteros

            //timer para ser usado como delay en el código
            Timer* timerAwait;
            //espera un tiempo y ejecuta la función que tiene ese nombre
            void Await(float timeAwait, String nameFunction);
            //funcion para ser ejecutada luego de un tiempo
            void ContinuarFlujo();

            void luegoDeInstanciar();
        
        private:
            float time_passed;
            //puntero al timer de la escena
            godot::Timer* NuevoTimer;

        public:
            //referencia a la señal TIMEOUT
            void _on_TimerInstanciar_timeout();
    };

}

#endif