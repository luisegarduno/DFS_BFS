//
// Updated by Luis G. on 07/16/2023.
//

#ifndef SHORTESTPATH_MISSINGFILESEXCEPTION_H
#define SHORTESTPATH_MISSINGFILESEXCEPTION_H

class MissingFilesException{
public:
    static const char * what() {
        return "Missing/invalid number of arguments";
    }
};

#endif // SHORTESTPATH_MISSINGFILESEXCEPTION_H
