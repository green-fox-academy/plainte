#include <string>
#ifndef POST_IT_POSTIT_H
#define POST_IT_POSTIT_H

class PostIt
{
public:
    PostIt(std::string backGroundColor, std::string text, std::string textColor);

    std::string backGroundColor;
    std::string text;
    std::string textColor;
};


#endif
