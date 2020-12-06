//
//  GLTriangleRender.hpp
//  MyOpenGL_1
//
//  Created by licaiyun on 2020/12/6.
//

#ifndef GLTriangleRender_hpp
#define GLTriangleRender_hpp

#include <stdio.h>
#include <iostream>
#include "GLRender.cpp"

namespace GLRender {
class GLTriangleRender: public GLRender {
public:
    
    GLTriangleRender();

    virtual ~GLTriangleRender() override;
    
    virtual void render() override;
    
private:
    
    /// 着色器程序
    GLuint m_shader_program { GL_INVALID_VALUE };
    
    /// 顶点数组对象
    GLuint m_vao { GL_INVALID_VALUE };
    /// 顶点缓冲对象
    GLuint m_vbo { GL_INVALID_VALUE };
    /// 索引缓冲对象
    GLuint m_ebo { GL_INVALID_VALUE };
};
}

#endif /* GLTriangleRender_hpp */
