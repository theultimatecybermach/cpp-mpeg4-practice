#include <stdio.h>
#include <GLFW/glfw3.h>

int main(int argv, const char** argc){
    GLFWwindow* window;
    unsigned char* data = new unsigned char[200*200*3];
    if (!glfwInit()){
        printf("GLFW could not be intiailized.");
        return 1;
    }
    window = glfwCreateWindow(2440,1440,"Hello World!", NULL,NULL);
    if(!window){
        printf("Could not open the window.\n");
        return 1;
    }
    
    for(int y=0; y<200; ++y){
        for (int x=0; x<200; ++x){ 
            data[y * 200 * 3 + x * 3 ] = 00xff;
            data[y * 200 * 3 + x * 3 + 1 ] = 00x00;
            data[y * 200 * 3 + x *3 + 2] = 00x00;

        }
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawPixels(200,200,GL_RGB, GL_UNSIGNED_BYTE,data);
        glfwSwapBuffers(window);
        glfwWaitEvents();

    }
    
    return 0;
}
