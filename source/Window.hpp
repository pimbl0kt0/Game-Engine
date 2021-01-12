#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>
#include <string>
#include <functional>

#include "Renderer.hpp"
#include "Scene.hpp"

namespace Engine {
    class Window
        {
        public:
            Window();
            Window(const std::string& title, const int& width, const int& height);

            Window& operator=(const Window& window);

            void setContext();
            void setViewport(int width, int height);
            void update();
            void render();
            void open();
            void close();

            void setScene(Scene& currentScene);

            //Events
            
            void registerEvents();

            void onClose(const std::function<void()>& callback);
            void onResize(const std::function<void(int, int)>& callback);
            void onFocus(const std::function<void(bool)>& callback);

        private:
            GLFWwindow* glfwWindow;

            int width, height;
            std::string title;

            Renderer renderer; 
            Scene* currentScene;

            std::function<void()> onCloseCallback;
            std::function<void(int, int)> onResizeCallback;
            std::function<void(bool)> onFocusCallback;

            static void onClose(GLFWwindow* window);
            static void onResize(GLFWwindow* window, int width, int height);
            static void onFocus(GLFWwindow* window, int focused);
        };
}