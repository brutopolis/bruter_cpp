#include "bruter.hpp"

int main()
{
    Bruter *list = new Bruter(8, true, true);
    BruterInt i = 42;
    list->unshift((BruterValue){.f = 3.14}); // Unshift a float value
    list->push((BruterValue){.i = i}); // Push an integer value
    list->insert(0, (BruterValue){.u = 100}); // Insert an unsigned integer value at index 0
    list->insert(1, (BruterValue){.p = (void*)0x1234}); // Insert a pointer value at index 1
    list->insert(2, (BruterValue){.fn = [](BruterList *context, BruterList *args) -> BruterInt {
        // Example function that returns the size of the list
        return context->size;
    }}); // Insert a function pointer at index 2

    
    BruterValue v = list->pop();
    
    // free the list
    printf("List size: %d\n", list->size());
    printf("Popped value: %i\n", v.i);
    delete list; // Use delete to free the Bruter object
    return 0;
}