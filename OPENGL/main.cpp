#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

const char* vertexShaderSource = "#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"  FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);  \n"
"}\0";

int main()
{
    glfwInit();

    //version of opengl is this case 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //core profile for modern compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //triangle vertices
    GLfloat vertices[] = {
        -0.5, -0.5, 0,
        0.5, -0.5, 0,
        0, 0.5, 0
    };



    //window creation parameters
    GLFWwindow* window = glfwCreateWindow(800, 800, "Hello Window", NULL, NULL);
    if (!(window)) {
        std::cout << "Failed to initialize window";
        glfwTerminate();
        return -1;
    }

    //actually create the window in the context
    glfwMakeContextCurrent(window);
    gladLoadGL();

    //creates the window from x = 0 and y = 0, to x = 800 and y = 800
    glViewport(0, 0, 800, 800);

    //creating the vertex and fragment shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    //delete the shaders since we already used it
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    //color of the buffer
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    //clean the back buffer and assign color
    glClear(GL_COLOR_BUFFER_BIT);
    //swaps the front and back buffer
    glfwSwapBuffers(window);

    //while loop to keep window open
    while (!glfwWindowShouldClose(window)) {
        //the events that happen inside the window
        glfwPollEvents();
    }

    //kill window
    glfwDestroyWindow(window);



    glfwTerminate();

    return 0;
}