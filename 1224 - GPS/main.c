#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _nodo{
	int x;
	int y;
	int item;

	struct _nodo *up;
	struct _nodo *down;
	struct _nodo *left;
	struct _nodo *right;

	struct _nodo *next;
}t_nodo;

typedef struct _list
{
	char recorrido[100];
	int len;
	int peso;
}ge_list;

ge_list lista;

typedef t_nodo *nodo;
int n_nodos=0;

nodo new_nodo(int x, int y){
	nodo temp;
	temp =(struct _nodo *) malloc(sizeof(struct _nodo));
	if (temp==NULL)	{
		exit(1);
	}
	temp->x=x;	temp->y=y; temp->item =n_nodos;
	temp->up = NULL;	temp->down = NULL;
	temp->left = NULL;	temp->right = NULL;
	temp->next=NULL;
	n_nodos++;
	return temp;
}

nodo existe_punto(nodo primero, int x, int y){
	nodo nulo=NULL, temp = primero;
	while(temp!= NULL){
		if (temp->x==x && temp->y==y){
			return temp;
		}
		temp = temp->next;
	}
	return nulo;
}

void generar_mapa(nodo primero, int n, char *dir_v, char *dir_h){
	int i, j;
	nodo aux, temp = primero;
	while(temp!= NULL){
		j=((temp->x)/2)-1;
		// norte -------------------------------------
		if (dir_v[j]=='n' && temp->y <=2*n){
			for ( i = temp->y+2; i <= 2*n; i+=2){
				aux = existe_punto(primero, temp->x,i);
				if (aux!=NULL){
					// printf("(%i, %i)-->(%i, %i)\n",temp->x,temp->y, aux->x, aux->y );
					temp->up = aux;
					break;
				}
			}
		}
		// sur -------------------------------------
		if (dir_v[j]=='s' && temp->y >1){
			for ( i = temp->y; i > 1; i-=2){
				aux = existe_punto(primero,temp->x, i);
				if (aux!=NULL){
					temp->down = aux;
					break;
				}
			}
		}
		// derecha -------------------------------------
		j=(temp->y - 1)/2;
		// printf("(%i %i) %c - %i\n", temp->x, temp->y, dir_h[j], j );
		if (dir_h[j]=='e' && temp->x <=2*n){
			for ( i = temp->x+2; i <= 2*n; i+=2){
				aux = existe_punto(primero, i,temp->y);
				if (aux!=NULL){
					temp->right = aux;
					break;
				}
			}
		}
		// izquierda -------------------------------------
		if (dir_h[j]=='w' && temp->x >2){
			for ( i = temp->x-2; i > 1; i-=2){
				aux = existe_punto(primero, i,temp->y);
				if (aux!=NULL){
					temp->left = aux;
					break;
				}
			}
		}
		temp = temp->next;
	}
	return;
}
int nodo_repetido(int *visitados,  int a, int v){
	int i;
	for (i = 0; i < v; ++i){
		if (a==visitados[i]) return 1;
	}
	return 0;
}
int obtener_peso(nodo actual, int *visitados, int v){
	int i=0,p_x=0, p_y=0;
	nodo temp ;
	for (i = 0; i < v; ++i){
		temp=actual;
		while(temp!=NULL){
			if (temp->item==visitados[i]){
				p_x+=(-1^(i+1))*(temp->x);
				p_y+=(-1^(i+1))*(temp->y);
				break;
			}
			temp = temp->next;
		}
	}
	return abs(p_y)+abs(p_x);
}
void registrar_recorrido(nodo actual, int *visitados, int v){
	int pes = obtener_peso(actual, visitados, v);
	if ( lista.len==-1 || lista.len>v || (lista.len==v && lista.peso > pes)){
		for (int i = 0; i < v; ++i){
			lista.recorrido[i]=visitados[i];
			lista.peso=pes;
			lista.len=v-2;
		}
	}
}
void recorre_mapa(nodo path, int v, int *visitados, int n, nodo primero){
	if (path == NULL) return ;
	if (nodo_repetido(visitados, path->item, v)) return;
	visitados[v]=path->item;
	v++;
	if (path->x == 2*n && path->y==2*n-1){registrar_recorrido(primero, visitados, v);}
	printf("(%i, %i)--%i\n", path->x, path->y,v );
	recorre_mapa(path->up, v, visitados, n, primero);
	recorre_mapa(path->down, v, visitados, n, primero);
	recorre_mapa(path->left, v, visitados, n, primero);
	recorre_mapa(path->right, v, visitados, n, primero);
}

void recorre(nodo actual){
	if (actual ==NULL){
		return;
	}
	printf("%i %i\n", actual->x, actual->y);
	recorre(actual->next);
}
int main(int argc, char const *argv[]){
	int n,i,j,k,l,c;
	lista.peso = -1; lista.len=-1;
	char dir_temp[6];
	nodo temp, temp2, primero =new_nodo(2,1);
	temp2 = primero;
	scanf("%i", &n);
	//printf("%i\n", n);

	char dir_h[n];
	char dir_v[n];
	for (i = 0; i < n; ++i){
		scanf("%s", dir_temp);
		dir_v[i]=dir_temp[0];
	}

	temp=new_nodo(2*n,2*n-1);
	temp2->next = temp;
	for ( i = 0; i < n; ++i){
		scanf("%i", &j);
		scanf("%s", dir_temp);
		dir_h[i]=dir_temp[0];
		scanf("%i", &k);
		for ( l = 0; l < k; ++l){
			scanf("%i", &c);
			if (c==2 && j==1){continue;}
			else if(c==2*n && j==2*n-1){continue;}
			temp->x=c;   temp->y=j;
			temp2=new_nodo(2*n,2*n-1);
			temp->next = temp2;
			temp = temp2;
		}
	}
	generar_mapa(primero, n,dir_v, dir_h);
	int visitados[n];
	//recorre(primero);
	recorre_mapa(primero, 0, visitados, n, primero);
	printf("%i - %i\n", lista.peso, lista.len);
	return 0;
}

////////////////    revisar repetidos en el recorrido