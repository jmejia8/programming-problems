import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		Scanner entrada = new Scanner(System.in);
		while(true) {
			int numero = Integer.parseInt(entrada.nextLine());
			System.out.println(numero);
			if(numero < 0)
				break;
		}
	}
}