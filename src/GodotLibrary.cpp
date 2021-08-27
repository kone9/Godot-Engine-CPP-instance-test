#include "gdexample.h"
#include "InstanciarCubos.h"
#include "CuboFisico.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
    godot::Godot::nativescript_init(handle);

    godot::register_class<GDExample>();
    godot::register_class<InstanciarCubos>();
    godot::register_class<CuboFisico>();
    // godot::register_class<InstanciarCubos>();
    // godot::register_class<godot::InstanciarCubos>();
}