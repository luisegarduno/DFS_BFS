//
// Created by Luis on 6/7/2020.
//

#ifndef DEPTHFIRSTSEARCH_BREADTHFIRST_MISSINGFILESEXCEPTION_H
#define DEPTHFIRSTSEARCH_BREADTHFIRST_MISSINGFILESEXCEPTION_H

class MissingFilesException{
public:
    static const char * what() {
        return "Missing/invalid number of arguments";
    }
};

#endif //DEPTHFIRSTSEARCH_BREADTHFIRST_MISSINGFILESEXCEPTION_H
