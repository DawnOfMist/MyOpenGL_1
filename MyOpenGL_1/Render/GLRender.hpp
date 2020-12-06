//
//  GLRender.hpp
//  MyOpenGL_1
//
//  Created by licaiyun on 2020/12/6.
//

#ifndef GLRender_hpp
#define GLRender_hpp

#include <stdio.h>
#include <OpenGLES/ES3/gl.h>

namespace GLRender {
class GLRender {
public:
    virtual ~GLRender(){};
    
    virtual void render() = 0;
};
}

#endif /* GLRender_hpp */
