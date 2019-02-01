#include "Blog.h"
#include "BlogPost.h"
#include <iostream>

Blog::Blog(std::vector<BlogPost>& _posts)
{
    posts = _posts;
}

void Blog::add(BlogPost& post)
{
    posts.push_back(post);
}

void Blog::deletePost(int i)
{
    posts.erase(posts.begin() + i);
}

void Blog::updatePost(int i, BlogPost post)
{
    posts.insert(posts.begin() + i, post);
}

void Blog::getPost(int i)
{
    std::cout << "Post(" << i << "): " << posts[i].getAuthorName() << "\n" <<
    posts[i].getTitle() << "\n" << posts[i].getText() << "\n" << posts[i].getPublicationDate() << "\n";
}