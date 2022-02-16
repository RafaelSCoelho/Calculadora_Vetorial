#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct vtrid
{
    char nvector;
    float x,y,z;
};
typedef struct vtrid Tvtridmen;
struct vbid
{
    char nvector;
    float x,y;
};
typedef struct vbid Tvbidmen;
union dim
{
    Tvtridmen ddd;
    Tvbidmen dd;
};
typedef union dim Tdim;

Tdim* createvector(int);
void destroyvector(Tdim*);
void insert(Tdim*, int);
void print(Tdim,int);
Tdim sum(Tdim,Tdim,int);
Tdim minus(Tdim,Tdim,int);
Tdim multK(Tdim,float,int);
Tdim seek(char,Tdim*);
int parallelvec(Tdim,Tdim,int);;
float norma(Tdim, int);

int main()
{

    int r,s,d,a;
    char m,w;
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\nQuantidade de vetor requerida: ");
    scanf("%d",&r);
    setbuf(stdin,NULL);
    printf("\nDIGITE A DIMENCAO DESEJADA: ");
    scanf("&i",&s);
    setbuf(stdin,NULL);
    Tdim *vetor;
    Tdim res;
    float res2,res3;
    int j;
    vetor=createvector(r);
    for(j=0; j<r; j++)
    {
        insert(vetor+j,s);
    }
    setbuf(stdin,NULL);
    printf("\n");
    for(j=0; j<r; j++)
    {
        print(*(vetor+j),s);
    }
    do
    {
        setbuf(stdin,NULL);
        printf("\n\nESCOLHA UMA OPERACAO: ");
        printf("\n\n1---Soma\n2---Diferenca\n3---Produto por uma escala\n4---norma\n5 vetores paralelos\nopÁao");
        scanf("%d",&d);
        setbuf(stdin,NULL);
        switch(d)
        {
        case 1:
            printf("DIGITE O NOME DO PRIMEIRO VETOR: ");
            scanf("%c",&m);
            setbuf(stdin,NULL);
            printf("DIGITE O NOME DO SEGUNDO VETOR: ");
            scanf("%c",&w);
            setbuf(stdin,NULL);
            res=sum(seek(m,vetor),seek(w,vetor),s);
            print(res,s);
            break;
        case 2:
            printf("DIGITE O NOME DO PRIMEIRO VETOR: ");
            scanf("%c",&m);
            setbuf(stdin,NULL);
            printf("DIGITE O NOME DO SEGUNDO VETOR: ");
            scanf("&c",&w);
            setbuf(stdin,NULL);
            res=minus(seek(m,&*vetor),seek(w,&*vetor),s);
            print(res,s);
            break;

        case 3:

            printf("QUAL E O NOME DO VETOR");
            scanf("%c",&m);
            setbuf(stdin,NULL);
            printf("Digite o nome da constante: ");
            scanf("&f",&a);
            setbuf(stdin,NULL);
            res=multK((seek(m,vetor)),a,s);
            print(res,s);
            setbuf(stdin,NULL);
            break;

        case 4:
            printf("QUAL E O NOME DO VETOR: ");
            scanf("%c",&m);
            setbuf(stdin,NULL);
            res2=norma((seek(m,vetor)),s);
            printf("Norma : %.f \n",res2);
            setbuf(stdin,NULL);
            break;
        case 5:
            printf("\nNome do primeiro vetor: ");
            scanf("%c",&m);
            setbuf(stdin,NULL);
            printf("Nome do segundo vetor: ");
            scanf("%c",w);
            setbuf(stdin,NULL);
            res3=parallelvec((seek(m,vetor)),(seek(w,vetor)),s);
            if(res3==1){
                printf("os vetores sao paralelos.");
                }else{
                printf("os vetores nao sao paralelos.");
            }
break;
        case 0:
            break;
        default:
            printf("digite uma opÁao valida");
        }
    }
    while(d!=0);
    return 0;
}
Tdim seek(char n,Tdim* v)
{
    Tdim *aux=v;
    Tdim ret;
    for(; (n!=aux->dd.nvector)||(n!=aux->ddd.nvector); aux++);
    if((n==aux->dd.nvector)||(n==aux->ddd.nvector))
        ret=*aux;
    return ret;
}
Tdim* createvector(int n)
{
    Tdim* aux=(Tdim*)malloc(sizeof(Tdim)*n);
    return aux;
}
void destroyvector(Tdim* v)
{
    free(v);
}
float norma(Tdim v, int d)
{
    float ret;
    if(d==3)
        ret=sqrt(v.ddd.x*v.ddd.x+v.ddd.y*v.ddd.y+v.ddd.z*v.ddd.z);
    else
        ret=sqrt(v.dd.x*v.dd.x+v.dd.y*v.dd.y);
    return ret;
}
Tdim multK(Tdim v,float k,int d)
{
    Tdim aux;
    if(d==3)
    {
        aux.ddd.x=v.ddd.x*k;
        aux.ddd.y=v.ddd.y*k;
        aux.ddd.z=v.ddd.z*k;
        aux.ddd.nvector='R';
    }
    else
    {
        aux.dd.x=v.dd.x*k;
        aux.dd.y=v.dd.y*k;
        aux.dd.nvector='R';
    }
    return aux;
}
Tdim sum(Tdim v1,Tdim v2,int d)
{
    Tdim aux;
    if(d==3)
    {
        aux.ddd.x=v1.ddd.x+v2.ddd.x;
        aux.ddd.y=v1.ddd.y+v2.ddd.y;
        aux.ddd.z=v1.ddd.z+v2.ddd.z;
        aux.ddd.nvector='R';
    }
    else
    {
        aux.dd.x=v1.dd.x+v2.dd.x;
        aux.dd.y=v1.dd.y+v2.dd.y;
        aux.dd.nvector='R';
    }
    return aux;
}
Tdim minuss(Tdim v1,Tdim v2,int d)
{
    Tdim aux;
    if(d==3)
    {
        aux.ddd.x=v1.ddd.x-v2.ddd.x;
        aux.ddd.y=v1.ddd.y-v2.ddd.y;
        aux.ddd.z=v1.ddd.z-v2.ddd.z;
        aux.ddd.nvector='R';
    }
    else
    {
        aux.dd.x=v1.dd.x-v2.dd.x;
        aux.dd.y=v1.dd.y-v2.dd.y;
        aux.dd.nvector='R';
    }
    return aux;
}

void print(Tdim v, int d)
{
    if(d==3)
        printf("Vetor %c(%.2f,%.2f,%.2f)\n",v.ddd.nvector,v.ddd.x,v.ddd.y,v.ddd.z);
    else
        printf("Vetor %c(%.2f,%.2f)\n",v.dd.nvector,v.dd.x,v.dd.y);
}

void insert(Tdim* v,int d)
{
    Tdim aux;
    printf("DIGITE O NOME DO VETOR : ");
    printf("\n\n\tV----U\n\tN----T\n\tESCOLHA: ");
    if(d==3)
    {
        scanf("%c",&aux.ddd.nvector);
        setbuf(stdin,NULL);
        printf("vetor %c(x,y,z): ",aux.ddd.nvector);
        scanf("%f,%f,%f",&aux.ddd.x,&aux.ddd.y,&aux.ddd.z);
        *v=aux;
        setbuf(stdin,NULL);
    }
    else
    {
        scanf("%c",&aux.dd.nvector);
        setbuf(stdin,NULL);
        printf("vetor %c(x,y): ",aux.dd.nvector);
        scanf("%f,%f",&aux.dd.x,&aux.dd.y);
        *v=aux;
        setbuf(stdin,NULL);
    }
}

int parallelvec(Tdim v,Tdim p, int d)
{
    int ret=0;
    Tdim aux;
    if(d==3)
    {
        if((v.ddd.x!=0)&&(p.ddd.x!=0))
            aux.ddd.x=v.ddd.x/p.ddd.x;
        if((v.ddd.y!=0)&&(p.ddd.y!=0))
            aux.ddd.y=v.ddd.y/p.ddd.y;
        if((v.ddd.z!=0)&&(p.ddd.z!=0))
            aux.ddd.z=v.ddd.z/p.ddd.z;
        if((v.ddd.x==0)&&(p.ddd.x==0))
            aux.ddd.x=0;
        if((v.ddd.y==0)&&(p.ddd.y==0))
            aux.ddd.y=0;
        if((v.ddd.z==0)&&(p.ddd.z==0))
            aux.ddd.z=0;
        if((v.ddd.x!=0)&&(p.ddd.x==0))
            aux.ddd.x=-1;
        if((v.ddd.y!=0)&&(p.ddd.y==0))
            aux.ddd.y=-1;
        if((v.ddd.z!=0)&&(p.ddd.z==0))
            aux.ddd.z=-1;
        //verifica se os vetores s√£o paralelos
        if(((aux.ddd.x==aux.ddd.y)&&(aux.ddd.y==aux.ddd.z))||((aux.ddd.x==0)||(aux.ddd.y==0)||(aux.ddd.z==0)))
            ret=1;

    }
    else
    {
        if((v.dd.x!=0)&&(p.dd.x!=0))
            aux.dd.x=v.dd.x/p.dd.x;
        if((v.dd.y!=0)&&(p.dd.y!=0))
            aux.dd.y=v.dd.y/p.dd.y;
        if((v.dd.x==0)&&(p.dd.x==0))
            aux.dd.x=0;
        if((v.dd.y==0)&&(p.dd.y==0))
            aux.dd.y=0;
        if((v.dd.x!=0)&&(p.dd.x==0))
            aux.dd.x=-1;
        if((v.dd.y!=0)&&(p.dd.y==0))
            aux.dd.y=-1;
        //verifica se os vetores s√£o paralelos
        if(((aux.dd.x==aux.dd.y))||((aux.dd.x==0)||(aux.dd.y==0)))
            ret=1;
    }
    return ret;
}





