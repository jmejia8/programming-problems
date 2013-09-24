import java.util.Scanner;
import java.util.ArrayList;

/*
	Ejemplo de array list
*/

class Main {
	public static void main(String args[]) {
		ArrayList<Integer> lista = new ArrayList<Integer>(); //crea una lista vacía de enteros
		lista.add(8); //Añade un numero al final de la lista
		lista.add(9);
		lista.add(1);

		for(int i=0;i<lista.size();i++) {
			System.out.println("El elemento en la posicion "+i+" de la lista es "+lista.get(i));
		}

		System.out.println(lista.get(0)); //Imprime la posición 0 de la lista

		lista.remove(1); //remueve el elemento en la posición 1 de la lista

		for(int i=0;i<lista.size();i++) {
			System.out.println("El elemento en la posicion "+i+" de la lista es "+lista.get(i));
		}
	}
}