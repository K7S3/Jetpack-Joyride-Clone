#include "main.h"
#ifndef ROOF_H
#define ROOF_H


class Roof
{
public:
    Roof() {}
    Roof(float x, float y, color_t color);
    glm::vec3 position;
    float cord_x;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bounding_box_t bounding_box();
private:
    VAO *object;

};

#endif
// ROOF_H