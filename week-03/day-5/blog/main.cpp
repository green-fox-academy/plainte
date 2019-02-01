#include <iostream>
#include "BlogPost.h"
#include <vector>
#include "Blog.h"


int main(int argc, char * argv[])
{
    BlogPost object1("John Doe",
                     "\"Lorem Ipsum\"",
                     "Lorem ipsum dolor sit amet.",
                     "2000.05.04.");
    BlogPost object2("Tim Urban",
                     "\"Wait but why\"",
                     "A popular long-form, stick-figure-illustrated blog about almost everything.",
                     "2010.10.10.");
    BlogPost object3("William Turton",
                     "\"One Engineer Is Trying to Get IBM to Reckon With Trump\"",
                     "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. "
                     "When I asked to take his picture outside one of IBM’s New York City offices, "
                     "he told me thathe wasn’t really into the whole organizer profile thing.",
                     "2017.03.28.");

    std::vector<BlogPost> posts;

    posts.push_back(object1);
    posts.push_back(object2);
    posts.push_back(object3);

    Blog blog(posts);

    blog.add(object1);
    blog.getPost(0);
    blog.deletePost(2);
    blog.getPost(1);
    blog.updatePost(5, object2);
    blog.getPost(5);


    return 0;
}