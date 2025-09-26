#include <chrono>
#include <print>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <thread>

using namespace std::chrono_literals;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::println("resize to: {} {}", width, height);
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
    if ((glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS
            || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    std::println("Hello, world!");

    if (glfwInit() < 0) {
        std::println("Failed to initialize glfw!");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_POSITION_X, 600);
    glfwWindowHint(GLFW_POSITION_Y, 300);
    GLFWwindow* window = glfwCreateWindow(800, 600, "opengl", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (gladLoadGL(glfwGetProcAddress) < 0) {
        std::println("Failed to load GL!");
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    constexpr auto period = 1000000us / 60.f;
    std::chrono::high_resolution_clock clk {};

    while (!glfwWindowShouldClose(window)) {
        auto t0 = clk.now();
        process_input(window);

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();

        std::this_thread::sleep_until(t0 + period);
        auto dt = clk.now() - t0;
        std::println("dt: {:.2f} ms  {:.2f} Hz", dt.count() / 1000000., 1000000000. / dt.count());
        std::println("t0: {}   t0+period: {}", t0.time_since_epoch(), (t0+period).time_since_epoch());
    }

    glfwTerminate();
    return 0;
}
