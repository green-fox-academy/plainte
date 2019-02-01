#ifndef BLOG_BLOG_H
#define BLOG_BLOG_H
#include "BlogPost.h"
#include <vector>


class Blog
{
public:
    Blog(std::vector<BlogPost>& _posts);
    void add(BlogPost& post);
    void deletePost(int i);
    void updatePost(int i, BlogPost post);
    void getPost(int i);
private:
    std::vector<BlogPost> posts;
};


#endif //BLOG_BLOG_H
