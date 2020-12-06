//
//  GLTriangleRender.cpp
//  MyOpenGL_1
//
//  Created by licaiyun on 2020/12/6.
//

#include "GLTriangleRender.hpp"

namespace GLRender {

/// 顶点数据，x,y,z,
static float vertices[] = {
    -2.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
     0.2f, -0.2f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.2f,  0.2f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.0f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f,
};

/// 索引数据，三个三角形
static GLuint indices[] = {
    0, 1, 2,
    0, 2, 3,
    4, 5, 6,
};

/// 顶点着色器
static const char *vertexShaderSource =
"#version 300 es \n"

"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"

"out vec4 vertexColor;\n"

"uniform float ourRatio;\n"

"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   vertexColor = vec4(aColor.r * ourRatio, aColor.g * ourRatio, aColor.b * ourRatio, 1);\n"
"}\0";

/// 片段着色器
static const char *fragShaderSource =
"#version 300 es \n"
"precision highp float;\n"

"out vec4 fragColor;\n"
"in vec4 vertexColor;\n"

"uniform float ourRatio;\n"

"void main()\n"
"{\n"
"   fragColor = vec4(vertexColor.r * ourRatio, vertexColor.g * ourRatio, vertexColor.b * ourRatio, 1);\n"
"}\0";

GLTriangleRender::GLTriangleRender() {
    // 初始化色器程序
    ///  顶点着色器
    GLuint vsob;
    vsob = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vsob, 1, &vertexShaderSource, NULL);
    glCompileShader(vsob);
    int success;
    char info[512];
    glGetShaderiv(vsob, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vsob, 512, NULL, info);
        std::cout << "error:shader:vertex:compile:" << info << std::endl;
    }
    /// 片段着色器
    GLuint fsob = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fsob, 1, &fragShaderSource, NULL);
    glCompileShader(fsob);
    glGetShaderiv(fsob, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fsob, 512, NULL, info);
        std::cout << "error:shader:frag:compile:" << info << std::endl;
    }
    /// 将所有着色器合成为一个着色器程序，并链接
    m_shader_program = glCreateProgram();
    glAttachShader(m_shader_program, vsob);
    glAttachShader(m_shader_program, fsob);
    glLinkProgram(m_shader_program);
    glGetProgramiv(m_shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_shader_program, 512, NULL, info);
        std::cout << "error:program:link:" << info << std::endl;
    }
    /// 最终的shader program已经产生，vsob和fsob作为中间产物可直接删除。
    glDeleteShader(vsob);
    glDeleteShader(fsob);
    
    // 初始化顶点数组
    /// 顶点数组对象
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    /// 顶点缓冲对象
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    /// 索引缓冲对象
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    /// 设置位置顶点属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    /// 设置颜色顶点属性
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    /// 所有顶点属性值设置完毕，解绑vao
    glBindVertexArray(0);
};

GLTriangleRender::~GLTriangleRender() {
    glDeleteProgram(m_shader_program);
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
    glDeleteVertexArrays(1, &m_vao);
}

static GLuint alpha = 0;

void GLTriangleRender::render() {
    /// 画布颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    /// 使用shader program
    glUseProgram(m_shader_program);
    
    /// 设置ourRatio
    alpha++;
    if (alpha > 100 ) {
        alpha = 0;
    }
    float a = (alpha % 100)/100.0;
    int ourRatio = glGetUniformLocation(m_shader_program, "ourRatio");
    glUniform1f(ourRatio, a);
    
    /// 使用顶点
    glBindVertexArray(m_vao);
    
//    /// 根据七个顶点画三角形
//    glDrawArrays(GL_TRIANGLES, 0, 7);
    /// 根据索引缓存的顺序画三角形
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
}
}
