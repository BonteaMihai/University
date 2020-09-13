import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;

public class Graph {
	
	private boolean directed;
	private int nrEdges;
	private int nrVertices;
	private HashMap<Integer, ArrayList<Integer> > dictEdges;
	private ArrayList<Graph> subgraphs;
	
	public Graph(int nrVertices, boolean directed) {
		this.directed = directed;
		this.nrVertices = nrVertices;
		dictEdges = new HashMap<Integer, ArrayList<Integer> >(nrVertices);
		nrEdges = 0;
		
		for (int i = 1; i <= nrVertices; ++i)
			dictEdges.put(i, new ArrayList<Integer>());
		
		subgraphs = new ArrayList<Graph>();
	}
	
	public void addEdge(int x, int y) throws Exception{
		// Checking if node x and y exist
		var searchResultX = dictEdges.get(x);
		var searchResultY = dictEdges.get(y);
		if (searchResultX == null || searchResultY == null)
			throw new Exception("Given nodes do not simultaneously exist!");
			
		// Checking whether (x, y) is already an edge in the graph
		for (int node: dictEdges.get(x))
			if (node == y)
				throw new Exception("Edge (x, y) already exists within the graph!");
		
		nrEdges++;
		dictEdges.get(x).add(y);
		if (!directed)
			dictEdges.get(y).add(x);
	}
	
	public void addVertex(int x) throws Exception{
		var searchResult = dictEdges.get(x);
		if (searchResult == null)
			dictEdges.put(x, new ArrayList<Integer>());
		else
			throw new Exception("Vertex " + x + " already exists!");
	}
	
	public boolean isEdge(int x, int y) throws Exception{
		// Checking if node x and y exist
		var searchResultX = dictEdges.get(x);
		var searchResultY = dictEdges.get(y);
		if (searchResultX == null || searchResultY == null)
			throw new Exception("Given nodes do not simultaneously exist!");
		
		for (int node: dictEdges.get(x))
			if (node == y)
				return true;
		return false;
	}
	
	public boolean isDirected() {
		return directed;
	}
	
	public int nrEdges() {
		return nrEdges;
	}
	
	public int nrVertices() {
		return nrVertices;
	}
	
	public ArrayList<Integer> parseNeighbors(int x) throws Exception {
		var searchResult = dictEdges.get(x);
		if (searchResult != null)
			return new ArrayList<Integer>(searchResult);
		else
			throw new Exception("Vertex " + x + " does not exist!");
	}
	
	public ArrayList<Integer> parseKeys(){
		return new ArrayList<Integer>(dictEdges.keySet());
	}

	/* Connected Components */
	
	private void storeAsSubgraph(ArrayList<Integer> connectedComponent){
		Graph temp = new Graph(0, directed);
				
		// Adding the vertices to the subgraph
		for (int vertex : connectedComponent)
			try {
				temp.addVertex(vertex);
			}
			catch(Exception e) {}
		
		//System.out.println(temp.dictEdges.keySet().toString());
		
		// Adding the edges to the subgraph
		for (int vertex : connectedComponent)
			for (int neighbor : dictEdges.get(vertex))
				try {
					temp.addEdge(vertex, neighbor);
				}
				catch(Exception e) {}
		// Append the subgraph to the list
		subgraphs.add(temp);
	}
	
	public void connectedComponents() {
		// Making sure the subgraph list is empty
		subgraphs.removeAll(subgraphs);
		// Set which contains the visited elements
		Set<Integer> visited = new HashSet<Integer>();
		
		//if vertex i is not visited, we go over the connected component containing it
		for (int vertex : dictEdges.keySet())
			if (!visited.contains(vertex)) {
				ArrayList<Integer> connectedComponent = bfs(vertex);
				
				storeAsSubgraph(connectedComponent);
				for (int subVertex : connectedComponent) 
					visited.add(subVertex);
			}
	}
	
	public ArrayList<Integer> bfs(int startNode){
		// Initialize the queue q and visited set with the initial node
		Queue<Integer> q = new LinkedList<>();
		q.add(startNode);
		ArrayList<Integer> explored = new ArrayList<Integer>();
		
		Set<Integer> visited = new HashSet<Integer>();
		visited.add(startNode);
		
		//while queue is not empty, pop the front of the queue and add its unvisited neighbours to the back
		while (!q.isEmpty()) {
			int currentNode = q.remove();
			explored.add(currentNode);
			
			for (int neighbour : dictEdges.get(currentNode)) {
				if (!visited.contains(neighbour)) {
					q.add(neighbour);
					visited.add(neighbour);
				}
			}
		}
		return explored;
	}
	
	public ArrayList<Integer> dfs(int startNode){
		// Initialize the stack st and the visited list with the initial node
		Stack<Integer> st = new Stack<Integer>();
		st.add(startNode);
		ArrayList<Integer> explored = new ArrayList<Integer>();
		Set<Integer> visited = new HashSet<Integer>();
		visited.add(startNode);
		
		while (!st.isEmpty()) {
			int currentNode = st.pop();
			explored.add(currentNode);
			
			for (int neighbour : dictEdges.get(currentNode)) {
				if (!visited.contains(neighbour)) {
					st.add(neighbour);
					visited.add(neighbour);
				}
			}
		}
		return explored;
	}
	
	public String toString() {
		String str = "Vertices: ";
		str += dictEdges.keySet().toString() + '\n';
		
		str += "Edges: ";
		for (int vertex : dictEdges.keySet()) {
			for (int neighbour : dictEdges.get(vertex)) {
				if (directed || vertex < neighbour)
				str += "(" + vertex + ", " + neighbour + ") "; 
			}
		}
		return str;
	}
	
	public void printSubgraphs() {
		int counter = 1;
		for (Graph graph : subgraphs) {
			System.out.println("Connected component " + counter++ + ": ");
			System.out.println(graph.toString());
		}
	}
	
	
}

