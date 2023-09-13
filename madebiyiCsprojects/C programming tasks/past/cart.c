// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: cart.c
Functions: main, add_cart, check_item_sale.
Parameters: Multiple char array, int, float, int.
Returns: struct and str.
Description: Reads in an array of grocery items and outputs their information given alongside whether or not they're on sale.
Author: Patricija Shalkauskaite
Date: 11-11-2021
*/

typedef struct Cart Cart; // Define Cart as a type name.

struct Cart //Structure type definition.
{
  char item[20];
  unsigned int amount;
  float price;
  int promotion;  // 0 if there's no promotion, 1 if item is on sale.
};

void add_cart(Cart *cart, char *item, unsigned int amount, float price, int promotion);
void check_item_sale(Cart *cart);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 1; // - 1 to exclude the program name.
    int cart_length = (argc - 1) / 4;  // Divide by four to get each cart item.
    Cart carts[cart_length];  // Initialise an array of type Cart.
    int cart_count = 0;  // Keep an account of the cart index.

    for(int i = 0; i < length; i += 4)
    {
        // Give the address of carts to the function.
        add_cart(&carts[cart_count], argv[i + 1], atoi(argv[i + 2]), atof(argv[i + 3]), atoi(argv[i + 4]));
        check_item_sale(&carts[cart_count]);
        cart_count += 1;
    }

    return(0);
}

// Building initialised function(s).
void add_cart(Cart *cart, char *item, unsigned int amount, float price, int promotion)  // Add parameters given to Cart struct.
{
    strcpy(cart->item, item);
    cart->amount = amount;
    cart->price = price;
    cart->promotion = promotion;
}

void check_item_sale(Cart *cart)  // Output grocery information and if they're on sale.
{
    if(cart->promotion == 0)
    {
        printf("%s,%d,%.2f,No Sale\n", cart->item, cart->amount, cart->price);
    }
    else  // promotion will be 1 = there is a sale.
    {
        printf("%s,%d,%.2f,On Sale\n", cart->item, cart->amount, cart->price);
    }
}
