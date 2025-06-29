#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

struct Item{
   double value; // The actual value of the item
   Item* next;   // A pointer to the item beneath
};

struct Stack {
   Item* top = nullptr; // A pointer to the item at the top
   int size = 0;  // How many items are in the stack? 0 if the stack is empty
};

void push(Stack* stack, double num){

    Item* it1 = new Item;
    it1->value = num;
    it1->next = stack->top;
    stack->top = it1;
    stack->size += 1;
}

double top(Stack* stack){
   if (stack->size == 0){
      return HUGE_VAL;
   }else{
      return (stack->top->value);
   }
}

void pop(Stack* stack){
   if (stack->size == 0 || stack->top == nullptr)
      return;

   Item* x = stack->top;
   stack->top = (x->next);
   delete x;
   stack->size -= 1;
}

void print(Stack* stack){
   int width = 10;

   cout << string(width,'-') << endl;
   Item* it2 = stack->top;
    if (it2 == nullptr) {
        cout << setw(width) << right << endl;
    } else {
        while (it2 != nullptr) {
            if (it2 == stack->top)
                cout << setw(width) << right << it2->value << " < TOP" << endl;
            else
                cout << setw(width) << right << it2->value << endl;

            it2 = it2->next;
        }
    }

    cout << string(width, '-') << endl;
    cout << setw(width) << right << stack->size << " ITEMS" << endl;
}


int main(){
   Stack* stack = new Stack;
   push(stack,20.5);
   push(stack,60.004);
   push(stack,10.08);
   push(stack,40.3);
   push(stack,-160.93);
   
   print(stack);

   pop(stack);

   print(stack);
   
   while (stack->size > 0) {
      pop(stack);
   }
   
   print(stack);

   delete stack;
   return 0;

}
