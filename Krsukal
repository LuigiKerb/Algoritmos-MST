#include <stdio.h>
#include <stdlib.h>
//Quantidade de vertice
#define MaxV 6
//Quantidade de arestas
#define MaxA 36
//ordenar as arestas usando insertion_sort 
//pega o menor peso e armazena na estrutura aresta
//vai para o prÃ³ximo  e verifica se esse vertice ja n esta na estrutura

//uma struct para armazenar a origem,destino e custo
typedef struct aresta
{
  int o,d,r;
  float peso;

}Aresta;

//criando o vetor global para controle de rotulo
int vetorRotulos[MaxV];

void insertion_sort(Aresta *v)
{

  int i,j,l,origem,destino;
  float peso;

  for(i=1;i<MaxA;i++)
  {
    j=i-1;
    origem = v[i].o;
    destino = v[i].d;
    peso = v[i].peso;
    //trocando os valores de posiÃ§Ã£o
    while(peso < v[j].peso && j >= 0)
    {
      v[j+1].peso = v[j].peso;
      v[j+1].o = v[j].o;
      v[j+1].d = v[j].d;
      v[j].peso = peso;
      v[j].o = origem;
      v[j].d = destino;
      j--;
    }
   
  }
}


//considera cada vÃ©rtice como se fosse uma Ãºnica arvore
void makeset()
{
  int i;
  for(i=1;i<=MaxV;i++)
  {
    vetorRotulos[i] = i;
  }

}
void imprimir_rotulos(int a,int aux2)
{
  int l;
  printf("Na %i interacao possui %i grupos.\n",a ,aux2);
  for(l=1;l<=MaxV;l++)
  {
    printf("%d ",vetorRotulos[l]);
  }
  printf("\n");
}
//Junto com o vetor de rotulos,unimos as menores arestas conforme a quantidade de grupo q o usuario deseja
void kruskal(Aresta *arestas,int k){
  int i,j,aux,aux2=MaxV,l,a=1;
  makeset();
  if(k == aux2)
    {
      imprimir_rotulos(a,aux2);
      return;
    }

  for(i=0;i<MaxA;i++){
    if(vetorRotulos[arestas[i].o]!=vetorRotulos[arestas[i].d]){
      imprimir_rotulos(a,aux2);
       printf("\n");
      a++;
      arestas[i].r = arestas[i].o;
      if(k==aux2)
      {
        break;
      }
      aux2--;
      aux=arestas[i].d;
      vetorRotulos[arestas[i].d] =vetorRotulos[arestas[i].o];
      for(j=1;j<=MaxV;j++){
        if(vetorRotulos[j]==aux){
          vetorRotulos[j]=vetorRotulos[arestas[i].o];
          
        }
      }
    }
  }
  
}

int main() 
{
  FILE *file;
  file = fopen("dado.txt","r");

  Aresta *v;
  v = (Aresta*)malloc(MaxA* sizeof(Aresta));
 
  int a=0,j=0;

  if(file == NULL)
  {
    printf("Erro ao abrir o arquivo.");
    return 0;
  }

  while(!feof(file))
  {
    fscanf(file,"%d %d %f\n",&v[j].o ,&v[j].d,&v[j].peso);
    v[j].r = 0;
      j++;
  }
 //o usuÃ¡rio digita a quantidade de agrupamento q deseja,faz um do while p aceitar valores de 1 a Max
  do
  {
     printf("Digite a quantidade de grupo que deseja: ");
     scanf("%i",&a);
  }while(!(a>=1 && a<=MaxV));
  
    
  insertion_sort(v);
  kruskal(v,a);
  
  fclose(file);
  free(v);

  return 0;
}
