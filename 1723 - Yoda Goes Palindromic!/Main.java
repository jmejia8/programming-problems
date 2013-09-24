import java.util.Scanner;
import java.util.ArrayList;
import java.math.BigInteger;

public class Main {
	public static String limpiar(String cad) {
		cad = cad.toLowerCase();
		ArrayList<Character> chars = new ArrayList<Character>();
		for(char c: cad.toCharArray()) {
			if(c >= 'a' && c <= 'z') {
				chars.add(c);
			}
		}
		char[] arr = new char[chars.size()];
		for(int i=0;i<chars.size();i++){
			arr[i] = chars.get(i);
		}
		return new String(arr);
	}

	public static int apariciones(char a, String cad) {
		int contador = 0;
		for(char p: cad.toCharArray()) {
			if(p==a)
				contador += 1;
		}
		return contador;
	}

	public static boolean cumple_par(String cad) {
		// verifica que en cad cada caracter aparezca un numero par de veces
		for(char a: cad.toCharArray()) {
			if(apariciones(a, cad)%2 == 1)
				return false;
		}
		return true;
	}

	public static boolean cumple_impar(String cad) {
		// verifica que en cad cada caracter aparezca un numero par de veces
		int num_impares = 0;
		char impar = '0';
		for(char a: cad.toCharArray()) {
			int ap = apariciones(a, cad);
			if(ap%2 == 1) {
				if(num_impares == 0) {
					impar = a;
					num_impares += 1;
				} else {
					if(num_impares == 1) {
						if(impar != a) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}

	public static BigInteger factorial(int n) {
		if(n==0 || n==1){
			return BigInteger.ONE;
		} else {
			return (new BigInteger(Integer.toString(n))).multiply(factorial(n-1));
		}
	}

	public static ArrayList<Integer> valores_distintos(String cad) {
		ArrayList<Integer> cuenta = new ArrayList<Integer>();
		ArrayList<Character> chars = new ArrayList<Character>();
		for(char a: cad.toCharArray()) {
			if(chars.contains(a)) //ese caracter ya lo medimos
				continue;
			int repeticiones = apariciones(a, cad);
			cuenta.add(repeticiones/2);
			chars.add(a);
		}
		return cuenta;
	}

	public static int suma(ArrayList<Integer> arr) {
		int s = 0;
		for(int i=0;i<arr.size();i++)
			s += arr.get(i);
		return s;
	}

	public static void main(String args[]) {
		Scanner entrada = new Scanner(System.in);
		int num_casos = Integer.parseInt(entrada.nextLine());

		for(int i=0;i<num_casos;i++) {
			String cadena = limpiar(entrada.nextLine());

			if(cadena.length() == 0 || cadena.length() == 1)
				System.out.println(1);
			else {
				if(cadena.length()%2 == 0) {
					// la cadena tiene longitud par
					// cada letra debe aparecer un numero par de veces
					if(cumple_par(cadena)) {
						ArrayList<Integer> distintos = valores_distintos(cadena);
						BigInteger res = factorial(suma(distintos));
						for(int j=0;j<distintos.size();j++) {
							res = res.divide(factorial(distintos.get(j)));
						}
						System.out.println(res);
					} else {
						System.out.println(0);
					}
				} else {
					// longitud impar
					// una letra puede aparecer un numero impar de veces
					if(cumple_impar(cadena)) {
						ArrayList<Integer> distintos = valores_distintos(cadena);
						BigInteger res = factorial(suma(distintos));
						for(int j=0;j<distintos.size();j++) {
							res = res.divide(factorial(distintos.get(j)));
						}
						System.out.println(res);
					} else {
						System.out.println(0);
					}
				}
			}
		}
	}
}
