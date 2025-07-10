#include<iostream>
#include<unordered_map>
using namespace std;

// Products, Item, Cart

// Forward Declaration
class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;
public:
    Product(){}
    Product(int u_id, string name, int price){
        id = u_id;
        this->name = name;
        this->price = price;
    }

    string getName() {
        return name;
    }

    int getPrice() {
        return price;
    }

    string getDisplayName(){
        return name + " : Rs " + to_string(price) + "\n";
    }
    
    string getShortName(){
        return name.substr(0, 1);
    }
    

    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int quantity;

public:
    // Constructor using a Init list
    Item(){}
    Item(Product p, int q):product(p), quantity(q){}

    int getItemPrice(){
        return quantity * product.price;
    }

    string getItemInfo(){
        return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity * product.price) + "\n";
    }

    friend class Cart;
};

class Cart{
    // ToDo
    // Collection
    unordered_map<int, Item> items;
public:
    void addProduct(Product product){
        if(items.count(product.id) == 0){
            Item newItem(product, 1);
            items[product.id] = newItem;
        } else {
            items[product.id].quantity += 1;
        }
    }

    void removeProduct(Product product){
        if(items.count(product.id) == 0){
            cout << "first add some "<< product.name << " in the cart" << endl;
        } else {
            if(items[product.id].quantity > 1){
                items[product.id].quantity -= 1;
            } else {
                items.erase(product.id);
            }
        }
    }

    int getTotal(){
        // Todo
        int total = 0;
        for(auto itemPair : items){
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }


    string viewCart(){
        if(items.empty()){
            return "Cart is empty !!!\n";
        }

        string itemList;
        int cart_total = getTotal();

        for (auto itemPair : items){
            auto item = itemPair.second;
            itemList.append(item.getItemInfo());
        }

        return itemList + "\nTotal Amount : Rs. " + to_string(cart_total) + '\n';
    }

    bool contains(Product product) {
        return items.count(product.id) > 0;
    }


    int getQuantity(Product product) {
        if (contains(product)) {
            return items[product.id].quantity;
        }
    }

    bool isEmpty(){
        return items.empty();
    }

};