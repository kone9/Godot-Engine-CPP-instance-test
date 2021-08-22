#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Spatial.hpp>

namespace godot {

class GDExample : public Spatial {
    GODOT_CLASS(GDExample, Spatial)

private:
    float time_passed;

public:
    static void _register_methods();

    GDExample();
    ~GDExample();

    void _init(); // our initializer called by Godot

    void _process(float delta);
};

}

#endif