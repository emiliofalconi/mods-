#include <stdio.h>
#include <string.h>
#include <stdlib.h>





typedef struct cruces{
    char Cruce[4];
    struct cruces *next;    
}Cruces;

typedef struct c_incompatible{
    char Par1[4];
    char Par2[4];
    struct c_incompatible *next;        
}C_incompatible;

typedef struct turnos{
    char cruce[4];
    char turno;
    struct turnos *next;
}Turnos;


//Funcion que reserva el espacio de memoria para la estructura Cruce
Cruces *CrearCruce(char *cruce){
    Cruces *newp;
    if((newp=(Cruces*)malloc(sizeof(Cruces)))==NULL)
        return NULL;
    strcpy(newp->Cruce,cruce);
}


//Reserva el espacio de memoria para la estructura de Cruces incompatibles
C_incompatible *CrearC_incompatible(char *par1, char *par2){
    C_incompatible *newp;
    if((newp=(C_incompatible*)malloc(sizeof(C_incompatible)))==NULL)
        return NULL;
    strcpy(newp->Par1,par1);
    strcpy(newp->Par2,par2);
    return newp;
}

//Reserva el espacio de memoria para la estructura de los turnos
Turnos *CrearTurno(char *cruce, char *turno){
    Turnos *newp;
    if((newp=(Turnos*)malloc(sizeof(Turnos)))==NULL)
        return NULL;
    strcpy(newp->cruce,cruce);
    newp->turno=*turno;
    return newp;
}

//Funcion que anade al final de la lista de tipo Cruces un nuevo Nodo
Cruces *FinalCruces(Cruces* lista, Cruces *newp){
    if(lista==NULL)
        return newp;
    Cruces *p=lista;
    while(p->next!=NULL){
    p=p->next;
    }
    p->next=newp;
    return lista;
}

//Funccion que anade al final de una lista de giros incompatibles un nuevo Nodo
C_incompatible *Final_incompatible(C_incompatible *lista, C_incompatible *newp){
    if(lista==NULL)
        return newp;
    C_incompatible *p=lista;
    while(p->next!=NULL){
    p=p->next;
    }
    p->next=newp;
    return lista;
}

//Funcion que anade al final de una lista de turnos un nuevo Nodo
Turnos *FinalTurnos(Turnos *lista, Turnos *newp){
    if(lista==NULL)
        return newp;
    Turnos *p=lista;
    while(p->next==NULL){
    p=p->next;
    }
    p->next=newp;
    return lista;
}


//Se verifica que el par de cruces C1 y C2 sea un par que pueden cruzar al mismo tiempo
int Posible(Cruces *C1, Cruces *C2,C_incompatible *L){
//Si la lista de Cruces incompatibles es vacia entonces todos los pares de cruces son permitidos
    if(L==NULL)
        return 1;
//Si el segundo par de cruce es nulo entonces no quedan mas cruces que comparar
    if(C2==NULL)
        return 1;
//Se compara el primer par de cruces con ambos pares de lla lista de incompatibles
    if(!strcmp(C1->Cruce,L->Par1) || !strcmp(C1->Cruce,L->Par2))
//Si el primer par se encuentra, se verifica eque el segundo tambien lo este en alguno de los dos pares
//en caso de estar ambos significa que el cruce es invalido, se retorna falso.
        if(!strcmp(C2->Cruce,L->Par1) || !strcmp(C2->Cruce,L->Par2))
            return 0;
//Para mayor eficiencia se hace recursion de cola pero con el siguiente giro incompatible
//de esta forma se verifica toda la lista de giros incompatibles
    return (Posible(C1,C2,L->next));
}

Turnos *asigna(Cruces *L1, C_incompatible *L2){
    Cruces *p=L1;
    Cruces *q = NULL;
    Turnos *L3 = NULL;
    char turno = 'A';
    //if(!L3)
    L3 = FinalTurnos(L3,CrearTurno(p->Cruce,&turno));
    printf("HOLA\n");
    
    while (p){
        q=p->next;
        
        while(q){
        printf("HOLA 2\n");
            if(Posible(p,q,L2)) {
            	printf("HOLA 3\n");
                L3=FinalTurnos(L3,CrearTurno(q->Cruce,&turno));
            
            }
            
        }
        
    }
    return L3;
}

void imprime(Turnos *turnos){
while(turnos){
printf("%s - ", turnos->cruce);
printf("%c \n", turnos->turno);
turnos=turnos->next;
}
}




C_incompatible *listI;
Cruces *listc;
Turnos *list;
char cruce[4];
char par[4];


void main(){
while(1){
printf("Introduzca vertrices");
scanf("%s",&cruce);
if(!(strcmp(cruce,"--")))
	break;
listc=FinalCruces(listc,CrearCruce(cruce));

}
while(1){
printf("Ingrese par uno");
scanf("%s", cruce);
printf("Ingrese par dos");
scanf("%s", par);
if(!strcmp(cruce,par))
	break;
listI=Final_incompatible(listI,CrearC_incompatible(cruce,par));
}


list=asigna(listc,listI);

imprime(list);

}



