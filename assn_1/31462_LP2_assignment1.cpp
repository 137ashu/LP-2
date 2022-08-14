/*Problem Statement:-Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected 
graph and develop a recursive algorithm for searching all the vertices of a graph or tree data 
structure.*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class graph{
protected:
	int n;
	int v[10];
	int adj[10][10];
	queue <int> q;

public:
	void input(){
		cout<<"Enter the no. of vertices :";
		cin>>n;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				adj[i][j]=0;
			}
		}
		q.push(0);
	}
	void visit(){
		for(int i=0;i<n;i++){
			v[i]=0;
		}
	}
	void edges(){
		int p,q;
		cout<<"Vertex 1:";
		cin>> p;p=p-1;
		cout<<"Vertex 2:";
		cin>> q;q=q-1;
		adj[p][q]=1;
		adj[q][p]=1;
	}
	void display(){
		cout<<"\n |";
		for(int i=0;i<n;i++){
			cout<<i+1<<" ";
		}
		cout<<"\n";
		for(int i=0;i<n+1;i++){
			cout<<"--";
		}
		for (int i=0;i<n;i++){
			cout<<"\n"<<i+1<<"|";
			for (int j=0;j<n;j++){
				cout<<adj[i][j]<<" ";
			}
		}
	}
	void dfs(int z){
		v[z]=1;
		cout<<" "<<z+1;
		for(int i=0;i<n;i++){
			if (adj[z][i]==1 && !v[i])
				dfs(i);
		}

	}

	void bfs(int z){
		int j;
		if (v[z]==0)
        {
		v[z] = 1;
		z = q.front();
		cout << z +1<< " ";
		q.pop();
	    for(j=0;j<n;j++){
	    	if(!v[j] && adj[z][j] == 1){
				q.push(j);
			}
		}
        }
        else{
            q.pop();
        }
		if (!q.empty()){
			bfs(q.front());
		}
	}

	void bfs_it(int z){
		int j;
		queue <int> q1;
		v[z] = 1;
		q1.push(z);

		while(!q1.empty()){
            z = q1.front();
			cout << z +1<< " ";
			q1.pop();
			for(j=0;j<n;j++){
				if(!v[j] && adj[z][j] == 1){
					q1.push(j);
					v[j]=1;
                }
            }
        }
	}

	void dfs_it(int z)
	{
		stack<int> s;
		s.push(z);

		while (!s.empty())
		{
			z=s.top();
			s.pop();
			if(v[z]==1)
			{
				continue;
			}
			else{
				v[z]=1;
				cout<< z+1 <<" ";

				for(int j=n-1;j>-1;j--)
				{
					if (!v[j] && adj[z][j] == 1)
					{
						s.push(j);
					}
				}
			}
		}
	}

};
int main() {
	graph g;
	g.input();
	int t,ch=0;
	cout<<"\nEnter no of edges:";
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"\nEnter vertex for Edge "<<i+1<<endl;
		g.edges();
	}
	cout<<"\n\nAdjacency Matrix of Graph"<<endl;
	g.display();
	do{
		cout<<"\n\n1.BFS_RE \n2.DFS_RE \n3.BFS_IT \n4.DFS_IT \n5.exit"<<endl;
		cout<<"\nEnter choice :";
		cin>>ch;
		switch(ch){
		case 1:
			g.visit();
			cout<<"\nBFS traversing using Recursion :";
			g.bfs(0);
			break;
		case 2:
			g.visit();
			cout<<"\nDFS traversing using Recursion :";
			g.dfs(0);
			break;
		case 3:
			g.visit();
			cout<<"\nBFS traversing using Iteration :";
			g.bfs_it(0);
			break;
		case 4:
			g.visit();
			cout<<"\nDFS traversing using Iteration :";
			g.dfs_it(0);
			break;
		case 5:
			cout<<"\nTerminated"<<endl;
			exit(0);
			break;
		default:
			cout<<"\nInvalid choice"<<endl;
			break;
		}
	}while(ch!=5);
	return 0;
}
