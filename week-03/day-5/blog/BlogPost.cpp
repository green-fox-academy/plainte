#include "BlogPost.h"

BlogPost::BlogPost(std::string theAuthorName, std::string theTitle, std::string theText, std::string thePubDate) {
    authorName = theAuthorName;
    title = theTitle;
    text = theText;
    publicationDate = thePubDate;
}

std::string BlogPost::getAuthorName()
{
    return authorName;
}

std::string BlogPost::getTitle()
{
    return title;
}

std::string BlogPost::getText()
{
    return text;
}

std::string BlogPost::getPublicationDate()
{
    return publicationDate;
}