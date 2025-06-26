#define USE_SHORT_TYPES
#include "bruter.hpp"

int main()
{
    Bruter *list = new Bruter(8, true, true);
    Int i = 42;
    list->push(bruter_value_i(i));
    list->unshift(bruter_value_f(3.14f));
    list->insert(1, bruter_value_p(list));
    list->push(bruter_value_p(strdup("Hello, World!")));
    //list->reverse(); // Reverse the list using the C function
    Value v = list->pop();
    
    // free the list
    printf("List size: %d\n", list->size());
    printf("Popped value: %f\n", v.f);
    free(list->shift().s);
    delete list; // Use delete to free the Bruter object

    return 0;
}