#ifndef DEVICES_SCANNER_H
#define DEVICES_SCANNER_H


class Scanner
{
public:
    Scanner(int speed);
    void scan();
protected:
    int _speed;
};


#endif //DEVICES_SCANNER_H
