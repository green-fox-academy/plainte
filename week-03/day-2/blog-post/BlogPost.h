#include <string>

#ifndef BLOG_POST_BLOGPOST_H
#define BLOG_POST_BLOGPOST_H

class BlogPost {
public:
    BlogPost(std::string theAuthorName, std::string theTitle, std::string theText, std::string thePubDate);

    std::string authorName, title, text , publicationDate;

};

#endif //BLOG_POST_BLOGPOST_H
