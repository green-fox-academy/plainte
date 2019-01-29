#include "BlogPost.h"

BlogPost::BlogPost(std::string theAuthorName, std::string theTitle, std::string theText, std::string thePubDate) {
    authorName = theAuthorName;
    title = theTitle;
    text = theText;
    publicationDate = thePubDate;
}
