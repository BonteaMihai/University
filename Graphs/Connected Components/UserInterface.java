import java.io.File;
import java.util.Scanner;

public class UserInterface {
	
	private String filename;
	private Graph graph;
	private Scanner consoleReader;
	
	public UserInterface(String filename) {
		this.filename = filename;
		consoleReader = new Scanner(System.in);
	}
	
	private void printMenu() {
		String str = "Options:\n";
		str += "1) Load graph.\n";
		str += "2) Print the connected components using breadth first search.\n";
		str += "3) Add edge.\n";
		str += "4) Add vertex.\n";
		str += "0) Quit.\n";
		System.out.print(str);
	}
	
	private void loadGraph() {
		try {
			File inFile = new File(filename);
			Scanner reader = new Scanner(inFile);

			
			int n, m, x, y;
			boolean directed;
			
			n = reader.nextInt();
			directed = reader.nextBoolean();
			m = reader.nextInt();
			graph = new Graph(n, directed);
			
			for (int i = 1; i <= m; ++i) {
				x = reader.nextInt();
				y = reader.nextInt();
				
				graph.addEdge(x, y);
			}
			reader.close();
		}
		catch(Exception e) {
			System.out.println(e.getMessage());
		}
		System.out.println("Graph loaded successfully!");
	}
	
	private void printConnected() {
		graph.connectedComponents();
		graph.printSubgraphs();
	}
	
	private void addEdge() {
		boolean isCorrect = false;
		System.out.print("\nInsert the two vertices between which the edge will be created: ");
		int x, y;
		
		while (!isCorrect) {
			try {
				x = consoleReader.nextInt();
				y = consoleReader.nextInt();
				graph.addEdge(x, y);
				isCorrect = true;
			}
			catch(Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
	
	private void addVertex(){
		boolean isCorrect = false;
		System.out.print("\nInsert the new vertex: ");
		int x;
		
		while (!isCorrect) {
			try {
				x = consoleReader.nextInt();
				graph.addVertex(x);
				isCorrect = true;
			}
			catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
	
	public void menu() {
		printMenu();
		int choice;
		boolean loop = true;
		
		while (loop) {
			choice = consoleReader.nextInt();
			
			switch(choice) {
			case 1:
				loadGraph();
				break;
			case 2:
				printConnected();
				break;
			case 3:
				addEdge();
				break;
			case 4:
				addVertex();
				break;
			case 0:
				loop = false;
				break;
			default:
				System.out.println(choice + " is not a recognized command.\n");
				break;
			}
		}
		consoleReader.close();
	}
}
