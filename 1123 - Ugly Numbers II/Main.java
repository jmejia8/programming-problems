import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	public static boolean es_feo(int num) {
		int divisor = 2;
		while(true) {
			if(num == 1)
				return true;
			if(num%divisor == 0) {
				num = num/divisor;
			} else {
				if(divisor == 2)
					divisor = 3;
				else if (divisor == 3)
					divisor = 5;
				else
					return false;
			}
		}
	}

	public static void main(String args[]) {
		Scanner entrada = new Scanner(System.in);
		ArrayList<Integer> numeros_feos = new ArrayList<Integer>();

		numeros_feos.add(1);
		numeros_feos.add(2);
		numeros_feos.add(3);
		numeros_feos.add(4);
		numeros_feos.add(5);
		numeros_feos.add(6);
		numeros_feos.add(8);
		numeros_feos.add(9);
		numeros_feos.add(10);
		numeros_feos.add(12);

		while(entrada.hasNext()) {
			String num = entrada.nextLine();
			int numero = Integer.parseInt(num);

			if (numero == 0) {
				break;
			} else {
				int ultimo_feo = numeros_feos.get(numeros_feos.size()-1);
				while(numeros_feos.size() < numero) {
					ultimo_feo += 1;
					if(es_feo(ultimo_feo)) {
						numeros_feos.add(ultimo_feo);
					}
				}
				System.out.println(numeros_feos.get(numero-1));
			}
		}
	}
}
