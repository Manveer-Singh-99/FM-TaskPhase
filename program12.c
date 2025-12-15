#include <stdio.h> // Include standard I/O.
#include <stdlib.h> // Include standard lib for malloc/free.

// Define product structure.
typedef struct {
    int id; // Product ID.
    char name[50]; // Product Name.
    int quantity; // Quantity in stock.
    float price; // Price per unit.
} Product;

// Function definition: Analyzes inventory.
void inventory_management(int n, Product product_details[]) {
    // Print report header.
    printf("\n--- Inventory Report ---\n");
    // Init total value.
    float total_value = 0.0;
    
    // Loop through products.
    for (int i = 0; i < n; i++) {
        // Print product details row.
        printf("ID: %d | %-15s | Qty: %d | Price: $%.2f\n",
               product_details[i].id, product_details[i].name, 
               product_details[i].quantity, product_details[i].price);
        // Add to total value.
        total_value += product_details[i].quantity * product_details[i].price;
    }
    // Print total value.
    printf("Total Value: $%.2f\n", total_value);

    // Init indices for max tracking.
    int max_qty_idx = 0;
    int max_price_idx = 0;
    
    // Loop from second item.
    for (int i = 1; i < n; i++) {
        // Check max quantity.
        if (product_details[i].quantity > product_details[max_qty_idx].quantity) max_qty_idx = i;
        // Check max price.
        if (product_details[i].price > product_details[max_price_idx].price) max_price_idx = i;
    }

    // Print item with highest quantity.
    printf("Highest Quantity: %s (%d)\n", product_details[max_qty_idx].name, product_details[max_qty_idx].quantity);
    // Print item with highest price.
    printf("Highest Price: %s ($%.2f)\n", product_details[max_price_idx].name, product_details[max_price_idx].price);
}

// Main function: Entry point.
int main() {
    // Variable for count.
    int n;
    // Print header.
    printf("--- Task 12 Input ---\n");
    // Prompt count.
    printf("Enter number of products: ");
    // Read count and validate.
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    // Allocate memory for products.
    Product *inventory = malloc(n * sizeof(Product));

    // Loop to read product data.
    for (int i = 0; i < n; i++) {
        // Print prompt for specific product.
        printf("\nProduct %d:\n", i + 1);
        // Prompt ID.
        printf("ID: ");
        // Read ID.
        scanf("%d", &inventory[i].id);
        
        // Prompt Name.
        printf("Name (no spaces): ");
        // Read Name.
        scanf("%s", inventory[i].name); 
        
        // Prompt Quantity.
        printf("Quantity: ");
        // Read Quantity.
        scanf("%d", &inventory[i].quantity);
        
        // Prompt Price.
        printf("Price: ");
        // Read Price.
        scanf("%f", &inventory[i].price);
    }

    // Call management function.
    inventory_management(n, inventory);
    // Free memory.
    free(inventory);
    // Return success code.
    return 0;
}