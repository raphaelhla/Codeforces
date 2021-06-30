
import java.util.Scanner;

public class A {

	public static int divisor(int n) {
		int i = 2;
		int maior = 0;
		while (i * i <= n) {
			if (n % i == 0) {
				int a = Math.max(i, n / i);
				maior = Math.max(maior, a);
			}
			i++;
		}
		return maior;
	}
	
	public static int resp(int n) {
		
		if(n < 4) {
			return n -1;
			
		}else {
			
			if (n % 2 == 0) {
				return 2;
			}else {
				return 3;
			}
		}
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(sc.nextLine());
			System.out.println(resp(n));
		}
	}
}

