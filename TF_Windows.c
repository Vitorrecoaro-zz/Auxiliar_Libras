/* 

Programa feito para o trabalho final da disciplina de Libras da UNIFEI, no ano de 2019 segundo semestre.
Feito por: Bruno Medri, Daniel Henrique, Caio Mello, Thiago Roberto, Ulisses Mira, Vitor Recoaro e Yerro Candido
Data: 30/10/2019
Objetivo: Programa que trará sinais em libras que o usuário deverá responder qual o significado do sinal mostrado.
Edição: V1.2_Windows.
Adições: Modos de revisões e níveis de frases em libras.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<locale.h>



typedef struct sinais{
    char nome[100],link[10000];
}no;

void revisaoSinal(int n,int rev);
void addFILE(no *n1,int rev);
int qtdSinais(int rev);
void revisaodiaria();

int main(){
    setlocale(LC_ALL,"UTF-8");
    int op,test=0;
    char continuar,ok = 's';
    FILE *arq;
    arq = fopen("ListasSinais.txt","a+");
    
    printf("-x-x-x- Menu -x-x-x-\n\n1- Revisao basica.\n2- Revisao avancada.\n3- Teste diario\n0- Sair\n\n");
    scanf(" %d",&op);
    system("cls");
    while(op!=0){
        if(op==1){
            srand(time(NULL));
            int sinais=(qtdSinais(1)),n;
            sinais++;
            n = (rand() % sinais);
            while((n%2)!=0 || n==0){
                n = (rand()%sinais);
            }
            revisaoSinal(n,1);
            printf("Mais um sinal [s/n]? ");
            scanf(" %c",&continuar);
            system("cls");
            if(continuar=='s'){
                test = 1;
             }
            else{
                test = 0;
            }
        }
        else if(op==2){
            srand(time(NULL));
            int sinais=(qtdSinais(2)),n;
            sinais++;
            n = (rand() % sinais);
            while((n%2)!=0 || n==0){
                n = (rand()%sinais);
            }
            revisaoSinal(n,2);
            printf("Mais um sinal [s/n]? ");
            scanf(" %c",&continuar);
            system("cls");
            if(continuar=='s'){
                test = 1;
             }
            else{
                test = 0;
            }            
        }
        else if(op == 3){
        }
        else if(op==400){
            no n1;
            int tipo;

            printf("-x-x-x- Menu Arquivos -x-x-x-\n\n1- Sinais Basicos\n2- Sinais avancados\n\n");
            scanf(" %d",&tipo);
            printf("Digite o nome do novo sinal e um link do video do sinal.\n");
            scanf(" %[^\n] %[^\n]",n1.nome,n1.link);
            addFILE(&n1,tipo);
            printf("Voce aprendera o novo sinal.\n");
            printf("Aperte \"y\" para continuar\n");
            scanf(" %c",&ok);
            while(ok!='y'){
                scanf(" %c",&ok);
            }
            system("cls");
        }
        if(test==0){
            printf("-x-x-x- Menu -x-x-x-\n\n1- Revisao basica.\n2- Revisao avancada.\n3- Teste diario\n0- Sair\n\n");
            scanf(" %d",&op);
            system("cls");          
        }
        else{
            op = op;
        }
    }
}

void revisaoSinal(int n,int rev){
    setlocale(LC_ALL,"UTF-8");
    int cont=0,lresp=n-2,p=0,erros; 
    char resp[100],frase[100],teste,link[10000],lose;
    FILE *arq;
    if(rev == 1){
        arq = fopen("ListasSinais.txt","r");
    }
    else if(rev == 2){
        arq = fopen("ListasSinais2.txt","r");
    }
    for(p=0;p<100;p++){
        frase[p]='\0';
    }
    while(cont!=lresp){
        teste = fgetc(arq);
        if(teste=='\n'){
            cont++;
        }
    }    
    teste = fgetc(arq);
    p = 0;
    while(teste!='\n'){
        frase[p]=teste;
        p++;
        teste = fgetc(arq);
    }
    fgets(link,10000,arq);
    printf("O link para o sinal: %s\n\nO que significa esse sinal?\nResposta: ",link);
    scanf(" %[^\n]",resp);
    while(strcmp(resp,frase)!=0){
        if(erros<5){
        erros++;
        printf("Tente mais uma vez.\nResposta: ");
        scanf(" %[^\n]",resp);
        }
        else{
            printf("Deseja desistir [s/n] ?\n");
            scanf(" %c",&lose);
            if(lose=='s'){
                system("cls");
                erros = 10;
                break;
            }
            else if(lose=='n'){
                erros = 0;
            }
        }
    }
    if(erros==10){
        printf("Precisa treinar mais!\n");
    }
    else{
    printf("Acertou!\n");
    }
    fclose(arq);
    for(p=0;p<100;p++){
        frase[p]='\0';
    }
}

void addFILE(no *n1,int rev){
    setlocale(LC_ALL,"UTF-8");
    FILE *arq;
    if(rev == 1){
        arq = fopen("ListasSinais.txt","a");
    }
    else if (rev == 2){
        arq = fopen("ListasSinais2.txt","a");
    }
    fprintf(arq,"%s\n%s\n",n1->nome,n1->link);
    fclose(arq);
    return;
}

int qtdSinais(int rev){
    setlocale(LC_ALL,"UTF-8");
    int cont=0;
    char test;
    FILE *arq;
    if(rev == 1){
        arq = fopen("ListasSinais.txt","r");
    }
    else if(rev == 2){
        arq = fopen("ListasSinais2.txt","r");
    }
    test = getc(arq);
    while(test!=EOF){
        if(test=='\n'){
             cont++;
        }
        test = getc(arq);
    }
    fclose(arq);
    return cont;
}

void revisaodiaria(){
    int canetaAzul = 0;
}

