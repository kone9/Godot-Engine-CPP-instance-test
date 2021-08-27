#ifndef INSTANCIARCUBOS_H
#define INSTANCIARCUBOS_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Timer.hpp>
#include "RandomNumberGenerator.hpp"
#include "PackedScene.hpp"
#include "Label.hpp"

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
            
            // our initializer called by Godot
            void _init();

            void _ready();

            //funcion process se ejectua 60 veces por segundo
            void _process(const double p_delta);
        
        private:
            godot::Ref<godot::PackedScene> cuboFisico;//asi hago un packetScene tambien uso una referencia a una clase, tengo que identificar cuando se usan referencias a clase y cuando son punteros
            
            int contador = 0;//un contador que se ve en el editor

            godot::Label *FpsText;
            godot::Label *ContadorText;


        private:
            //referencia a la señal TIMEOUT
            void  _on_TimerPrueba_timeout();

            void ManejarFpsEnLabel();
    };

}

#endif