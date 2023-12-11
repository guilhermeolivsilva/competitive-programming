import java.util.Scanner;


public class exercise {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        scanner.close();

        try {
            double radius = Double.parseDouble(input);
            double area = Math.PI * radius * radius;
            System.out.printf("A=%.4f\n", area);
        } catch (NumberFormatException e) {
            System.out.println("Error: Not a valid number");
        }        
    }
}
