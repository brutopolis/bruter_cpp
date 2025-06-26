// C++ wrapper for bruter

#ifndef BRUTERCPP_H
#define BRUTERCPP_H 1

extern "C" {
#include "bruter.h"
}

class Bruter 
{
    private:
        BruterList* list;
    public:
        Bruter(int capacity = 8, bool keyless = false, bool typeless = false) 
        {
            list = bruter_new(capacity, keyless, typeless);
        }

        ~Bruter() 
        {
            bruter_free(list);
        }

        BruterValue run() 
        {
            return bruter_run(list);
        }

        BruterInt call(BruterList* list)
        {
            return bruter_call(this->list, list);
        }

        BruterValue get(int i) 
        {
            return bruter_get(list, i);
        }

        void set(int i, BruterValue value) 
        {
            bruter_set(list, i, value);
        }

        #ifndef BRUTER_KEYLESS
        char* get_key(int i) {
            return bruter_get_key(list, i);
        }

        void set_key(int i, const char* key) 
        {
            bruter_set_key(list, i, key);
        }
        #endif

        #ifndef BRUTER_TYPELESS
        int8_t get_type(int i) {
            return bruter_get_type(list, i);
        }

        void set_type(int i, int8_t type) 
        {
            bruter_set_type(list, i, type);
        }
        #endif

        BruterInt size() const 
        {
            return list->size;
        }

        BruterInt capacity() const 
        {
            return list->capacity;
        }

        void swap(int i1, int i2) 
        {
            bruter_swap(list, i1, i2);
        }

        void push(BruterValue value, const char* key = nullptr, int8_t type = 0) 
        {
            bruter_push(list, value, key, type);
        }

        void unshift(BruterValue value, const char* key = nullptr, int8_t type = 0) 
        {
            bruter_unshift(list, value, key, type);
        }

        void insert(BruterInt i, BruterValue value, const char* key = nullptr, int8_t type = 0) 
        {
            bruter_insert(list, i, value, key, type);
        }

        BruterValue pop() 
        {
            return bruter_pop(list);
        }

        BruterValue shift() 
        {
            return bruter_shift(list);
        }

        BruterValue remove(BruterInt i) 
        {
            return bruter_remove(list, i);
        }

        BruterValue fast_remove(BruterInt i) 
        {
            return bruter_fast_remove(list, i);
        }

        void double_capacity() 
        {
            bruter_double(list);
        }

        void half_capacity() 
        {
            bruter_half(list);
        }

        BruterList* get_list() const 
        {
            return list;
        }
};
#endif
