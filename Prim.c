#include <stdio.h>
#include <stdlib.h>
//Fazer MST(arvore geradora de custo minimo)
//Ordenar as arestas q sobraram
//Retirar a q tiver maior valor

typedef struct vertice {
  int v; /* Vértice */
  double custo;
  struct vertice* prox;
} Vertice;

typedef struct grafo {
  int n;      /* Número de nós */
  Vertice** lista;
} Grafo;

void cria_grafo(Grafo* g, int n)  { 
  g->lista = calloc(n, sizeof(Vertice*));
  g->n = n;
}

/*void iniciar(Grafo *list, int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    list->lista->v = 0;
    list->lista->custo = 0;
    list->lista->prox = NULL;
  }
}*/

/*void heapfy(Grafo *elements, int n, int i){
    int menor = i,temp;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if(esquerda < n && elements[esquerda] < elements[menor] ){
         menor = esquerda;
    }
    if(direita < n && elements[direita] < elements[menor]){
        menor = direita;
    }
    if(menor != i)
    {
        temp = elements[i];
        elements[i] = elements[menor];
        elements[menor] = temp;

        heapfy(elements,n,maior);
    }

   
}*/

void Prim(Grafo *gr, int orig, int *pai){
	int i, j, dest, primeiro, nVert = gr->n;
	double menorPeso;
	for(i = 0; i < nVert; i++){
		//mst->lista->v = 0;
		//mst->lista->custo = 0;
		//mst->lista->prox = NULL;
		pai[i] = -1;
	}
	printf("A\n");
	pai[orig] = orig;
	while(1){
		primeiro = 1;
		for(i = 0; i < nVert; i++){
			if(pai[i] != -1){
				/*for(j = nVert/2-1; i >= 0; i--){
					heapfy(gr, nVert, i);
				}*/
				for(j = 0; j < nVert; j++){
					if(pai[gr->lista[j]->v] == -1){
						if(primeiro){
							menorPeso = gr->lista[j]->custo;
							orig = i;
							dest = gr->lista[j]->v;
							primeiro = 0;
						}else{
							if(menorPeso > gr->lista[j]->custo){
								menorPeso = gr->lista[j]->custo;
								orig = i;
								dest = gr->lista[j]->v;						
							}
						}
					}
				}
			}
		}
		if(primeiro = 1){
			break;
		}
		pai[dest] = orig;
	}
	printf("Foi");
}

void imprimir(Grafo *g, int n)
{
  int i;
  Vertice *aux;
  int a;
  for(i=1 ; i<=n; i++){
    aux = g->lista[i];
    printf("(%d)-> ",i);
    printf("\n");
    while(aux!=NULL){
      	printf("[%i] ",aux->v);
      	aux = aux->prox;
      	//system ("pause");
    }
    printf("\n");
  }
}

void adiciona_aresta(Grafo *g, int v1, int v2,double c) {
 	Vertice **ve = &g->lista[v1];
 	while (*ve != NULL && (*ve)->v > v1){
        ve = &(*ve)->prox;
	}
 	if (*ve == NULL || (*ve)->v != v2){
       Vertice* n = malloc(sizeof(Vertice));
       n->v = v2;
       n->custo = c;
       n->prox = *ve;
       *ve = n;
  	}
  
}

int existe_aresta(Grafo *g, int v1, int v2) {
 	Vertice *l = g->lista[v1];
 	while (l != NULL && l->v < v2)
    	l = l->prox;
 	if (l != NULL && l->v == v2)
    	return 1;
 	return 0;
}

void remove_aresta(Grafo *g, int v1, int v2){
 	Vertice **ve = &g->lista[v1];
 	while (*ve != NULL &&
	 (*ve)->v < v2)
    ve = &(*ve)->prox;
 	if (*ve != NULL && (*ve)->v == v2) {
    Vertice* r = *ve;
    *ve = (*ve)->prox;
    free(r);
 	}
}

int main(){
	Grafo g;
	cria_grafo(&g,10);
	//iniciar(&g);
	int *v;
	int mst[10];
	v = (int*)malloc(7*sizeof(int));
 	FILE *file;
 	file = fopen("dado.txt","r");
 	int n=0,a=1,b=0,i;
 	double c=0;
 	/*for(i=0;i<150;i++)
 	{
    v[i]=1;//Armazena os valores de cada vértice.No começo todos tem 1
    //printf("%i\n",v[i]);
 	}*/

 	if(file == NULL){
    	printf("Erro ao abrir o arquivo.");
    	return 0;
 	}
 	while((fscanf(file,"%i %i %lf\n",&a ,&b,&c)) != EOF){
    	//printf("%i %i %.15lf\n",a,b,c);
    	//Removendo origem = destino
    	//fazendo com q tenham o mesmo peso
    	if(a<b){
     	adiciona_aresta(&g,a,b,c);
      	adiciona_aresta(&g,b,a,c);
    	}
 	}
 	imprimir(&g, 10);
 	Prim(&g, 1, &mst);
  
 	fclose(file);
 	imprimir(&g, 10);

 	return 0;
}
