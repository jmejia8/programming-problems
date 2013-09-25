import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static BigInteger exponente_dos(int exp) {
		if(exp == 0)
			return new BigInteger("1");
		if(exp == 1)
			return new BigInteger("2");
		if(exp%2 == 0) // exponente par
			return exponente_dos(exp/2).multiply(exponente_dos(exp/2));
		else
			return exponente_dos(exp/2).multiply(exponente_dos(exp/2+1));
	}

	public static void main(String args[]) {
		Scanner entrada = new Scanner(System.in);

		int potencia = Integer.parseInt(entrada.nextLine());
		System.out.println(exponente_dos(potencia));
	}
}