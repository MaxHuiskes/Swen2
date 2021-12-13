#ifndef BLOCK_H
#define BLOCK_H


class block
{
public:
    block();
    block(int _height, bool _metal);

private:
    int height;
    bool metal;
};

#endif // BLOCK_H
