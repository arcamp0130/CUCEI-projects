# Inventory
This is a C program to manage products stock of several stores of a chain.

Stakeholders need a client to manage all their products, stock, and other elements, satisfying their requirements.

> [!NOTE]
> This is just a simple university work, so its purpose is to only apply and reforce some kind of basic knowledge.

## Topics
1. Definition and value of C arrays
2. Declaration of vectors (unidimential) and matrices (bidimentional).
3. Array writting and reading.
4. Operations with arrays

## Requirements
### Data storage
- [X] Create a vector to store all 10 products IDs as `int`.
- [X] Create a vector to store products price as `float`.
- [X] Create a $10 \times 3$ matrix to store the following:
  - Every row represents a product.
  - Each column represents a store.
  - It contains products stock on every store.

### Validations
- [X] Unique IDs.
- [X] Prices must be positive values (`float`).
- [X] Stock must be integer and positive (`unsigned int`).

### Navigation
You must create a menu with the following options:

1. [X] Set products data (`id`, `price`, `stock`).
2. [X] Show full inventory (IDs, prices and stock by store) only when there is setted data.
3. [X] Show full inventory in budget/price by using $price \times stock$
   - [X] To a specific store.
   - [X] To all stores.
4. [X] Find product(s) with less and more stock across all stores.
5. [X] Update a product stock on a specific store.
6. [X] Exit program