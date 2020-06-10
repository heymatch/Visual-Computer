#ifndef EXCEPTIOM
#define EXCEPTION

class Exception{
public:
    Exception(){
        
    }
    const char *what(){
        return "ERROR";
    }
private:
    char *message;
};

#endif