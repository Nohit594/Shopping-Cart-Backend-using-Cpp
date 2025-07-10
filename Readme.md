# 🛒 Console Shopping Cart (C++)

A simple terminal-based shopping cart system built in C++. This project demonstrates object-oriented programming (OOP) principles including classes, encapsulation, and composition.

## 🚀 Features

- View available products
- Add products to the cart
- Remove products from the cart
- View cart summary with item quantity and total cost
- Checkout with simulated payment and change calculation

---

## 📁 Project Structure

```
.
├── cart_main.cpp       # Main application logic (menu, user interaction)
├── datamodel.h         # Contains Product, Item, and Cart class definitions
├── README.md           # Project documentation
```

---

## 💡 How It Works

### ✅ Classes Used:

- **Product**: Stores product details (id, name, price)
- **Item**: Represents an entry in the cart (product + quantity)
- **Cart**: Holds a map of product IDs to `Item` objects and provides operations to manipulate the cart

### 🢾 Menu Options:

- `(a)` Add item to cart
- `(r)` Remove item from cart
- `(v)` View cart contents
- `(c)` Checkout and pay

---

## 🛠️ How to Compile and Run

### Compile:

```bash
g++ cart_main.cpp -o cart_main
```

### Run:

```bash
./cart_main
```

---

## 📌 Sample Run

```
Select an action - (a)dd item, (r)emove item, (v)iew cart, (c)heckout
a
Available Products :    
apple : Rs 26
guava : Rs 36
mango : Rs 46
strawberry : Rs 29      
banana : Rs 16
pineapple : Rs 25       
-------------------     
Enter item short name : a
Added to the Cart : apple : Rs 26

Select an action - (a)dd item, (r)emove item, (v)iew cart, (c)heckout 
a
Available Products :    
apple : Rs 26
guava : Rs 36
mango : Rs 46
strawberry : Rs 29      
banana : Rs 16
pineapple : Rs 25       
-------------------     
Enter item short name : a
Added to the Cart : apple : Rs 26

Select an action - (a)dd item, (r)emove item, (v)iew cart, (c)heckout 
a
Available Products : 
apple : Rs 26        
guava : Rs 36        
mango : Rs 46        
strawberry : Rs 29
banana : Rs 16
pineapple : Rs 25
-------------------
Enter item short name : m
Added to the Cart : mango : Rs 46

Select an action - (a)dd item, (r)emove item, (v)iew cart, (c)heckout
r
Items in your cart:
-------------------
2 x apple Rs. 52
1 x mango Rs. 46
-------------------
Enter item short name : a
Removed from the Cart : apple : Rs 26

Select an action - (a)dd item, (r)emove item, (v)iew cart, (c)heckout
v
------------------------
1 x mango Rs. 46
1 x apple Rs. 26

Total Amount : Rs. 72
------------------------
Select an action - (a)dd item, (r)emove item, (v)iew cart, (c)heckout
c
------------------------
1 x mango Rs. 46
1 x apple Rs. 26

Total Amount : Rs. 72

------------------------
Pay in Cash : 80

Change 8

Thank you for shopping with us
---------------------------------
```

---

## 🎓 What You’ll Learn

- Using `unordered_map` for data storage
- Designing an interactive menu loop
- Object-oriented C++ design
- Basic string manipulation and formatted output

---

## 📄 License

This project is open-source and free to use under the [MIT License](LICENSE).

---

## 🙌 Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you'd like to change.

---

## ✨ Author

**Nohit Singh Chouhan**

Connect with me on [LinkedIn](https://www.linkedin.com/in/nohit594) or check out my [GitHub](https://github.com/Nohit594)!

