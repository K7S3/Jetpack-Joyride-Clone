#include "boomerang.h"

#include "main.h"
#include "math.h"

Boomerang::Boomerang(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    radius = 0.20;
    speed = 3.0;
    xspeed = 0.04;
    yspeed = -0.015;

    const int n = 6;
    const int reqd = n;
    GLfloat vertex_buffer_data[] = {
        0.4f, 0.2f,0.0f,
        0.05f, 0.15f,0.0f,
        -0.0f, -0.0f, 0.0f,

        0.4f, -0.2f, 0.0f,
        0.05f, -0.15f, 0.0f,
        -0.0f, -0.0f, 0.0f
    };
    this->object = create3DObject(GL_TRIANGLES, 6,vertex_buffer_data, color, GL_FILL);
}

void Boomerang::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);

    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Boomerang::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}


void Boomerang::tick1() {
     this->rotation += speed;
    this->position.x -= xspeed;
    if(this->position.y <= -0.4)
        yspeed = 0;
     this->position.y += yspeed;
}
