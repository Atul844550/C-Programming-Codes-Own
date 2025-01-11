public class averagewaitingtime {

    public static double averageWaitingTime(int[][] customers) {
        int currentTime = 0;
        double totalWaitingTime = 0.0;
        
        // Iterate through each customer
        for (int[] customer : customers) {
            int arrivalTime = customer[0];
            int timeToPrepare = customer[1];

            // If chef is idle, they start the order as soon as the customer arrives
            // Otherwise, they start when the previous order finishes
            currentTime = Math.max(currentTime, arrivalTime) + timeToPrepare;

            // Calculate waiting time for this customer
            totalWaitingTime += currentTime - arrivalTime;
        }

        // Return the average waiting time
        return totalWaitingTime / customers.length;
    }

    public static void main(String[] args) {
        // Test case
        int[][] customers = {{1, 2}, {2, 5}, {4, 3}};
        double result = averageWaitingTime(customers);
        System.out.printf("%.5f", result);  // Output: 5.00000
    }
}