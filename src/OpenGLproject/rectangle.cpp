#include <glad/glad.h>
#include <glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource ="#version 330 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "layout (location = 1) in vec3 aColor;\n"
                                "out vec3 ourColor;\n"
                                "void main()\n"
                                "{\n"
                                "   gl_Position = vec4(aPos, 1.0);\n"
                                "   ourColor = aColor;\n"
                                "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "in vec3 ourColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(ourColor, 1.0f);\n"
                                   "}\n\0";

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();//初始化glfw库
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//设置openGL的主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//设置openGL的次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//profile设置openGL的配置文件

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);//创建一个窗口
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//将当前上下文设置为窗口上下文
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//设置窗口大小回调函数

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);//创建顶点着色器
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);//将顶点着色器附加到着色器对象上
    glCompileShader(vertexShader);//编译顶点着色器
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//检查顶点着色器是否编译成功
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);//创建片段着色器
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);//添加对象
    glCompileShader(fragmentShader);//编译片段着色器
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//检查编译是否成功
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);//检查着色器链接是否错误
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);//删除顶点着色器
    glDeleteShader(fragmentShader);//删除片段着色器

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
            0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top

    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);//生成1个VAO
    glGenBuffers(1, &VBO);//生成一个VBO
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);//绑定VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//将顶点数据传递到VBO

    // position attribute 位置属性和颜色属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);//将当前顶点属性与VBO关联
    glEnableVertexAttribArray(0);//启动顶点属性
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);

    // as we only have a single shader, we could also just activate our shader once beforehand if we want to
    glUseProgram(shaderProgram);//使用着色程序

    // render loop 主任务渲染循环
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);//处理用户输入

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//清空颜色
        glClear(GL_COLOR_BUFFER_BIT);//清空颜色缓冲区

        // render the triangle
        glBindVertexArray(VAO);//绑定VAO并绘制三角形
        glDrawArrays(GL_TRIANGLES, 0, 3);//绘制三角形

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);//交换前后缓冲区
        glfwPollEvents();//处理窗口事件
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();//关闭glfw程序
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}