#define GLFW_INCLUDE_NONE
#include<iostream>
#include<GLFW/glfw3.h>
#include "glad.h"

void vertices(float valor, float a, float b, float c){
    glBegin(GL_QUADS);
        glColor3f(a,b,c);                                              
        glVertex3f(-valor, valor, 0.0f);                          // Top Left
        glVertex3f( valor, valor, 0.3f);                          // Top Right
        glVertex3f( valor,-valor, 0.0f);                          // Bottom Right
        glVertex3f(-valor,-valor, 0.0f);                          // Bottom Left
    glEnd(); 
}

int main(int, char**){
    GLFWwindow* window;
    
    if (!glfwInit()){
        return -1;
    }

    window = glfwCreateWindow(640,480,"Tela", NULL,NULL);
    glfwMakeContextCurrent(window);

    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Couldn't load opengl" << std::endl;
        glfwTerminate();
        return -1;
    }

   glClearColor(0.0f,0.0f, 0.0f, 9.0f);

    while (!glfwWindowShouldClose(window)){
        
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

       for(int i=10;i>=1;i--){
           float newi = i;
           if(i%3 == 0){
               vertices(newi/10, 1.0,1.0,1.0);
           }
           else if(i%3==1){
               vertices(newi/10, 0.5,0.5,0.5);   
           }
           else{
               vertices(newi/10, 0.0,0.0,0.0);    
           }
       }

        glfwSwapBuffers(window);    
    }

    glfwTerminate();
    return 0;
}
