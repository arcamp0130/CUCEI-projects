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
- Create a vector to store all 10 products IDs as `int`.
- Create a vector to store products price as `float`.
- Create a $10 \times 3$ matrix to store the following:
  - Every row represents a product.
  - Each column represents a store.
  - It contains products stock on every store.

### Validations
- Unique IDs.
- Prices must be positive values (`float`).
- Stock must be integer and positive (`unsigned int`).

### Navigation
You must create a menu with the following options:

1. Set products data (`id`, `price`, `stock`).
2. Show full inventory (IDs, prices and stock by store).
3. Show full inventory in budget/price by using $price \times stock$
   - To a specific store.
   - To all stores.
4. Find product(s) with less and more total stock.
5. Update a product stock on a specific store.
6. Exit program