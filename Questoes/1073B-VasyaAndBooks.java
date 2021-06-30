import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Teste {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String n = sc.nextLine();
		String a = sc.nextLine();
		String b = sc.nextLine();
		sc.close();
		String[] livros = a.split(" ");
		String[] ordem = b.split(" ");
		ArrayList<String> resp = new ArrayList<>();
		Map<String, Integer> passados = new HashMap<>();
		int i = 0, cont = 0;
		
		for (int j = 0; j < livros.length; j++) {
			while (passados.containsKey(ordem[i])) {
				resp.add(Integer.toString(cont));
				i += 1;
			}
			cont += 1;
			;
			if (livros[j].equals(ordem[i])){
				resp.add(Integer.toString(cont));
				cont = 0;
				i += 1;
			}
			else {
				passados.put(livros[j], 0);
			}
		}
		while (resp.size() < livros.length) {
			resp.add("0");
		}
		System.out.println(String.join(" ", resp));
	}

}
