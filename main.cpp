#include <GLFW/glfw3.h>
#include <cstdio>

int main() {
    if (!glfwInit()) {
        std::fprintf(stderr, "Failed to initialize GLFW\n");
        return 1;
    }

    GLFWwindow* win = glfwCreateWindow(800, 600, "Lab 1", nullptr, nullptr);
    if (!win) {
        std::fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(win);

    std::printf("GL %s on %s\n",
                glGetString(GL_VERSION),
                glGetString(GL_RENDERER));

    while (!glfwWindowShouldClose(win)) {
        glClearColor(0.55f, 0.10f, 0.30f, 1.0f); // your colour
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}