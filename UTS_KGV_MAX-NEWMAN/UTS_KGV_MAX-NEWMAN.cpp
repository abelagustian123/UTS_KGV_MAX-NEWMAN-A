
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "util.h"

float color1[] = { 0.2f, 1.0f, 1.0f, 1.0f }; //BIRU MUDA
float color2[] = { 1.0f, 0.0f, 0.0f, 1.0f }; //MERAH
float color3[] = { 0.0f, 1.0f, 0.0f, 1.0f }; //HIJAU
float color4[] = { 0.0f, 0.0f, 1.0f, 1.0f }; //BIRU
float color5[] = { 1.0f, 1.0f, 0.0f, 1.0f }; //kUNING
float color6[] = { 1.0f, 0.0f, 1.0f, 1.0f }; //UNGU
float color7[] = { 1.0f, 0.6f, 1.0f, 1.0f }; 
float color8[] = { 0.5f, 0.5f, 1.0f, 1.0f }; 


float last_time = 0;
float current_time = 0;
float deltatime = 0;
float scaleAnimate = 1;
float currentSpeed = -100.0f;
float minScale = 0.5f, maxScale = 1.0f;


unsigned int program;
GLint color1Loc, color2Loc, color3Loc, color4Loc, color5Loc, color6Loc, color7Loc, color8Loc;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_C && action == GLFW_PRESS)
    {
        for (int i = 0; i < 4; i++)
        {
            color1[i] = (rand() * 1.0f) / RAND_MAX;
            color2[i] = (rand() * 1.0f) / RAND_MAX;
            color3[i] = (rand() * 1.0f) / RAND_MAX;
            color4[i] = (rand() * 1.0f) / RAND_MAX;
            color5[i] = (rand() * 1.0f) / RAND_MAX;
            color6[i] = (rand() * 1.0f) / RAND_MAX;
            color7[i] = (rand() * 1.0f) / RAND_MAX;
            color8[i] = (rand() * 1.0f) / RAND_MAX;
        }

        std::cout << color1[0] << " " << color1[1] << color1[2] << " " << color1[3] << std::endl;
        std::cout << color2[0] << " " << color2[1] << color2[2] << " " << color2[3] << std::endl;
        std::cout << color3[0] << " " << color3[1] << color3[2] << " " << color3[3] << std::endl;
        std::cout << color4[0] << " " << color4[1] << color4[2] << " " << color4[3] << std::endl;
        std::cout << color5[0] << " " << color5[1] << color5[2] << " " << color5[3] << std::endl;
        std::cout << color6[0] << " " << color6[1] << color6[2] << " " << color6[3] << std::endl;
        std::cout << color7[0] << " " << color7[1] << color7[2] << " " << color7[3] << std::endl;
        std::cout << color8[0] << " " << color8[1] << color8[2] << " " << color8[3] << std::endl;



        glUniform4f(color1Loc, color1[0], color1[1], color1[2], color1[3]);
        glUniform4f(color2Loc, color2[0], color2[1], color2[2], color2[3]);
        glUniform4f(color3Loc, color3[0], color3[1], color3[2], color3[3]);
        glUniform4f(color4Loc, color4[0], color4[1], color4[2], color4[3]);
        glUniform4f(color5Loc, color5[0], color5[1], color5[2], color5[3]);
        glUniform4f(color6Loc, color6[0], color6[1], color6[2], color6[3]);
        glUniform4f(color7Loc, color7[0], color7[1], color7[2], color7[3]);
        glUniform4f(color8Loc, color8[0], color8[1], color8[2], color8[3]);
    }
    else if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
        scaleAnimate = 1;
    }
    else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
        scaleAnimate = 0.5f;
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /*
        Dari kode diatas berfungsi membuat windows dengan kuran 640*480 dengan tulisan hellow world
    */


    /* Make the window's context current */
    glfwMakeContextCurrent(window); //disini membuat contextnya yang artinya menjalankan windowsnya

    glfwSetKeyCallback(window, keyCallback);

    GLenum err = glewInit();

    //1
    float vertices[] = {
        0, 0,       //v0
        -1.0, 0,    //v1
        -0.7, 0.7,  //v2
        0, 1.0,     //v3
        0.7, 0.7,   //v4
        1.0, 0,     //v5
        0.7, -0.7,  //v6
        0, -1.0,    //v7
        -0.7, -0.7  //v8
    };

    //1
    unsigned int indexArr[] = {
        0,1,2,
        0,2,3,
        0,3,4,
        0,4,5,
        0,5,6,
        0,6,7,
        0,7,8,
        0,8,1 //BERJUMALH 24
    };

    // VERTICES
    unsigned int vertexBuffer = 0;
    glGenBuffers(1, &vertexBuffer); //proses pengiriman data dari cpu ke gpu

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 18, vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


    //Index ARRAY
    unsigned int indexBuffer = 0;
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 24, indexArr, GL_STATIC_DRAW);



    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    //UNIFORM
    glUseProgram(program);
    GLint scaleLoc = glGetUniformLocation(program, "scale");
    glUniform1f(scaleLoc, 0.5f);

    color1Loc = glGetUniformLocation(program, "color1");
    glUniform4f(color1Loc, color1[0], color1[1], color1[2], color1[3]);

    color2Loc = glGetUniformLocation(program, "color2");
    glUniform4f(color2Loc, color2[0], color2[1], color2[2], color2[3]);

    color3Loc = glGetUniformLocation(program, "color3");
    glUniform4f(color3Loc, color3[0], color3[1], color3[2], color3[3]);

    color4Loc = glGetUniformLocation(program, "color4");
    glUniform4f(color4Loc, color4[0], color4[1], color4[2], color4[3]);

    color5Loc = glGetUniformLocation(program, "color5");
    glUniform4f(color5Loc, color5[0], color5[1], color5[2], color5[3]);

    color6Loc = glGetUniformLocation(program, "color6");
    glUniform4f(color6Loc, color6[0], color6[1], color6[2], color6[3]);

    color7Loc = glGetUniformLocation(program, "color7");
    glUniform4f(color7Loc, color7[0], color7[1], color7[2], color7[3]);

    color8Loc = glGetUniformLocation(program, "color8");
    glUniform4f(color8Loc, color8[0], color8[1], color8[2], color8[3]);

    /* Dibawah ini adalah loop penggambaran object */
    while (!glfwWindowShouldClose(window))
    {
        //scale
        current_time = glfwGetTime() / 0.55f;
        deltatime = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        scaleAnimate = scaleAnimate + (deltatime * currentSpeed);

        //check min max scale
        if (scaleAnimate >= maxScale) {
            currentSpeed = -currentSpeed;
        }
        else if (scaleAnimate <= minScale) {
            currentSpeed = -currentSpeed;
        }
        glUniform1f(scaleLoc, scaleAnimate);


        //2. animasi di mana warna setiap segitiga akan berubah
        float a, b;
        a = (float)sin(current_time) * (RAND_MAX);
        b = (float)cos(current_time) * (RAND_MAX);
        glUniform4f(color1Loc, color1[0] * a, color1[1] * b, color1[2], color1[3] * a);
        glUniform4f(color2Loc, color2[0] * a, color2[1] * a, color2[2], color2[3] * b);
        glUniform4f(color3Loc, color3[0] * a, color3[1] * b, color3[2], color3[3] * a);

        glUniform4f(color4Loc, color4[0] * b, color4[1] * a, color4[2], color4[3] * b);
        glUniform4f(color5Loc, color5[0] * b, color5[1] * b, color5[2], color5[3] * a);
        glUniform4f(color6Loc, color6[0] * b, color6[1] * a, color6[2], color6[3] * b);

        glUniform4f(color7Loc, color7[0] * a, color7[1] * b, color7[2], color7[3] * a);
        glUniform4f(color8Loc, color8[0] * b, color8[1] * a, color8[2], color8[3] * b);


         /* Render here */

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.7f, 1.0f); 
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}