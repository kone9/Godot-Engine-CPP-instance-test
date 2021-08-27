#ifndef CUBOFISICO_H
#define CUBOFISICO_H

#include <Godot.hpp>
#include <RigidBody.hpp>

namespace godot {

class CuboFisico : public RigidBody {
    GODOT_CLASS(CuboFisico, RigidBody)

private:
    void _on_TimerCambiarTipo_timeout();

public:
    static void _register_methods();

    void _init(); // our initializer called by Godot

};

}

#endif