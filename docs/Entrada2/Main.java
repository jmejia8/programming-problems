import java.util.Scanner;
import java.util.StringTokenizer;

class Main {
	public static void main(String args[]) {
		Scanner entrada = new Scanner(System.in);

		int casos = Integer.parseInt(entrada.nextLine());
		for(int i=0;i<casos;i++) {
			StringTokenizer linea = new StringTokenizer(entrada.nextLine(), " ");
			int a = Integer.parseInt(linea.nextToken());
			int b = Integer.parseInt(linea.nextToken());
			System.out.println(a+", "+b);
		}
	}
}