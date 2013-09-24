import java.math.BigInteger;

class Main{
	public static BigInteger factorial(int n) {
		if(n==0 || n==1){
			return BigInteger.ONE; //Devolvemos 1 (versión entero grande)
		} else {
			return (new BigInteger(Integer.toString(n))).multiply(factorial(n-1)); //Quizá haya una mejor forma de hacer esto
			// La multiplicación entre enteros grandes se hace con multiply en vez de *
			// así mismo el resto de las operaciones básicas
		}
	}
	public static void main(String args[]) {
		System.out.println(factorial(50));
	}
}