#include "Counter.h"


Counter::Counter()
{
    field = 0;
    temp = field;
}
Counter::Counter(int f)
{
    field = f;
    temp = f;
}
void Counter::add(int number)
{
    field += number;
}

void Counter::add()
{
    field++;
}
void Counter::reset()
{
    field = temp;
}
int Counter::get()
{
    return field;
}