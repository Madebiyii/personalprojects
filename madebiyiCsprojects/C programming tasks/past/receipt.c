// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: receipt.c
Functions: main, add_cart, check_item_sale, get_promo_price, print_total.
Parameters: Multiple char array, int, float, int.
Returns: struct and str.
Description: Reads in an array of grocery items and outputs the total price of all groceries, promotional price included.
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
float check_item_sale(Cart *cart);
float get_promo_price(Cart *cart);
void print_total(float sum);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 1; // - 1 to exclude the program name.
    int cart_length = (argc - 1) / 4;  // Divide by four to get each cart item.
    Cart carts[cart_length];  // Initialise an array of type Cart.
    int cart_count = 0;  // Keep an account of the cart index.
    float total = 0;

    for(int i = 0; i < length; i += 4)
    {
        // Give the address of carts to the function.
        add_cart(&carts[cart_count], argv[i + 1], atoi(argv[i + 2]), atof(argv[i + 3]), atoi(argv[i + 4]));
        total += check_item_sale(&carts[cart_count]);  // Add the price summed from functions onto total.
        cart_count += 1;
    }

    print_total(total);
    
    return(0);
}   // End of main function.

// Building initialised function(s).
void add_cart(Cart *cart, char *item, unsigned int amount, float price, int promotion)  // Add parameters given to Cart struct.
{
    strcpy(cart->item, item);
    cart->amount = amount;
    cart->price = price;
    cart->promotion = promotion;
}

float check_item_sale(Cart *cart)  // If item is on sale, call the promo function, else return the normal price of item.
{
    if(cart->promotion == 0)  // Just give back the normal price.
    {
        return cart->amount * cart->price;
    }

    else  // promotion will be 1 = there is a sale.
    {
        return get_promo_price(cart);
    }
}

float get_promo_price(Cart *cart)  // Find the promotional price.
{
    int promo_amount = cart->amount - (cart->amount % 3);  // Get the amount that is evenly divided by three.
    int free_items = promo_amount / 3;  // Divide promo_amount by three to get how many free items.
    int items_to_pay_for = promo_amount - free_items;  // This is the amount you actually pay for.
    float promo_price = items_to_pay_for * cart->price;  // The sale price.
    int leftover_items = cart->amount - promo_amount;  // Add together with what's left over.
    float full_price = leftover_items * cart->price;

    return full_price + promo_price;
}

void print_total(float sum)  // Print out the price.
{
    printf("%.2f\n", sum);
}
