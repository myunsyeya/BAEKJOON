import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int data = scan.nextInt();
		for (int i = 0; i < data - 1; i++) {
			for (int k = 1; k < data - i; k++) {
				System.out.print(" ");
			}
			for (int j = 1; j <= 2 * i + 1; j++) {
				if (j == 1 || j == 2 * i + 1) {
					System.out.print("*");
				} else {
					System.out.print(" ");
				}
			}
			System.out.println();
		}
		for (int i = 0; i < 2 * data - 1; i++) {
			System.out.print("*");
		}
	}
}
