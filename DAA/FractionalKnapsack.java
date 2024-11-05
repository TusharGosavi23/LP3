import java.util.Arrays;
import java.util.Scanner;

class Item {
    int weight;
    int value;

    // Constructor to initialize item with weight and value
    public Item(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }
}

public class FractionalKnapsack {

    // Method to calculate the maximum value we can carry in the knapsack
    public static double getMaxValue(Item[] items, int capacity) {
        // Sort items by value-to-weight ratio in descending order
        Arrays.sort(items, (item1, item2) -> {
            double ratio1 = (double) item1.value / item1.weight;
            double ratio2 = (double) item2.value / item2.weight;
            return Double.compare(ratio2, ratio1);
        });

        double totalValue = 0; // Total value in the knapsack
        int currentWeight = 0; // Current weight of items in the knapsack

        // Go through each item in sorted order
        for (Item item : items) {
            if (currentWeight + item.weight <= capacity) {
                // If the whole item can fit, take it all
                currentWeight += item.weight;
                totalValue += item.value;
            } else {
                // If the whole item can't fit, take a fraction of it
                int remainingCapacity = capacity - currentWeight;
                totalValue += ((double) item.value / item.weight) * remainingCapacity;
                break; // Knapsack is now full
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user for the number of items
        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();

        // Create an array to hold the items
        Item[] items = new Item[n];

        // Input items (weight and value)
        for (int i = 0; i < n; i++) {
            System.out.print("Enter weight and value for item " + (i + 1) + " (format: weight value): ");
            int weight = scanner.nextInt();
            int value = scanner.nextInt();
            items[i] = new Item(weight, value);
        }

        // Ask the user for the capacity of the knapsack
        System.out.print("Enter the capacity of the knapsack: ");
        int capacity = scanner.nextInt();

        // Calculate and display the maximum value that can be carried
        double maxValue = getMaxValue(items, capacity);
        System.out.printf("Maximum value in Knapsack = %.2f%n", maxValue);

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}
