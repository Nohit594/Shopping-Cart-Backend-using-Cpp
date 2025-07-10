#include<iostream>
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(2, "guava", 36),
    Product(3, "mango", 46),
    Product(4, "strawberry", 29),
    Product(5, "banana", 16),
    Product(6, "pineapple", 25),
};

Product* chooseProduct(){

    // Display the list of products
    string productList;
    cout << "Available Products : " << endl;

    for(auto product : allProducts){
        productList.append(product.getDisplayName());
    }

    cout << productList;

    cout << "-------------------\n";
    cout << "Enter item short name : ";
    string choice;
    cin >> choice;
    
    for (int i = 0; i < allProducts.size(); i++){
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i];
        }
    }
    
    cout << "Product not found!" << endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    
    int total = cart.getTotal();
    cout << "Pay in Cash : ";
    
    int paid;
    cin >> paid;
    
    if(paid >= total){
        cout << "\nChange " << paid - total << "\n" << endl;
        cout << "Thank you for shopping with us \n";
        cout << "---------------------------------";
        return true;
    }
    
    else {
        cout << "Not Enough Cash !";
        return false;
    }
}

Product* chooseProductToRemove(Cart &cart) {
    if (cart.isEmpty()) {
        cout << "Cart is empty! Nothing to remove.\n";
        return nullptr;
    }
    
    cout << "Items in your cart:\n";
    cout << "-------------------\n";
    
    unordered_map<string, Product*> availableInCart;
    
    for (auto &product : allProducts) {
        if (cart.contains(product)) {
            int quantity = cart.getQuantity(product);
            string info = to_string(quantity) + " x " + product.getName() +
            " Rs. " + to_string(quantity * product.getPrice()) + "\n";
            cout << info;
            
            availableInCart[product.getShortName()] = &product;
        }
    }
    
    cout << "-------------------\n";
    cout << "Enter item short name : ";

    string choice;
    cin >> choice;
    
    if (availableInCart.count(choice)) {
        return availableInCart[choice];
    } else {
        cout << "Invalid choice or product not in cart!\n";
        return NULL;
    }
}


int main(){
    
    char action;
    Cart cart;
    
    while(true){
        cout << "Select an action - (a)dd item, (r)emove item, (v)iew cart, (c)heckout " << endl;
        cin >> action;

        if(action == 'a'){
            // Todo: Add to cart
            // View All Products + Choose Product + Add to cart
            Product *product = chooseProduct();
            if(product != NULL){
                cout << "Added to the Cart : " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        } else if(action == 'v'){
            // view the cart
            cout << "------------------------" << endl;
            cout << cart.viewCart();
            cout << "------------------------" << endl;
        } else if(action == 'r'){
            if(cart.isEmpty()){
                cout << "First add items to your cart \n";
                continue;
            }

            Product *product = chooseProductToRemove(cart);
            if(product != NULL){
                cout << "Removed from the Cart : " << product->getDisplayName() << endl;
                cart.removeProduct(*product);
            }
        } else if(action == 'c') {
            // Checkout
            cout << "------------------------" << endl;
            cout << cart.viewCart() << endl;
            cout << "------------------------" << endl;

            if(checkout(cart)){
                break;
            }
        }
        else {
            cout << "--------------- Please select a valid action to performed -------------" << endl;
        }
    }

    return 0;
}
