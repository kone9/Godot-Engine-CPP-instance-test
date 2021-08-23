#include "gdexample.h"

using namespace godot;

void GDExample::_register_methods()
{
    register_method("_process", &GDExample::_process);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() 
{
    // initialize any variables here
    time_passed = 0.0;
    Godot::print("hola mundo desde C++");
       
}

void GDExample::_process(float delta)
{
}