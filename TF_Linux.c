/* 

Programa feito para o trabalho final da disciplina de Libras da UNIFEI, no ano de 2019 segundo semestre.
Feito por: Bruno Medri, Daniel Henrique, Caio Mello, Thiago Roberto, Ulisses Mira, Vitor Recoaro e Yerro Candido
Data: 30/10/2019
Objetivo: Programa que trará sinais em libras que o usuário deverá responder qual o significado do sinal mostrado.
Edição: V1_Linux.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<locale.h>



typedef struct sinais{
    char nome[100],link[10000];
}no;

void revisaoSinal(int n);
void addFILE(no *n1);
int qtdSinais();

int main(){
    setlocale(LC_ALL,"UTF-8");
    int op,test=0,vazio;
    char continuar,ok = 's';
    FILE *arq;
    arq = fopen("ListasSinais.txt","a+");
    
    printf("-x-x-x- Menu -x-x-x-\n\n1- Revisao.\n2- Aprender novos sinais.\n0- Sair\n\n");
    scanf(" %d",&op);
    system("clear");
    while(op!=0){
        if(op==1){
            srand(time(NULL));
            int sinais=(qtdSinais()),n;
            sinais++;
            n = (rand() % sinais);
            while((n%2)!=0 || n==0){
                n = (rand()%sinais);
            }
            fseek(arq,0,SEEK_END);
            vazio = ftell(arq);
            if(vazio == 0){
                fclose(arq);
            }
            else{
                revisaoSinal(n);
                printf("Mais um sinal [s/n]? ");
                while(getchar()!='\n');
                scanf(" %c",&continuar);
                system("clear");
                if(continuar=='s'){
                    test = 1;
                }
                else{
                    test = 0;
                }
            }
        }
        else if(op==2){
            no n1;
            printf("Digite o nome do novo sinal e um link do video do sinal.\n");
            scanf(" %[^\n] %[^\n]",n1.nome,n1.link);
            addFILE(&n1);
            printf("Voce aprendera o novo sinal.\n");
            printf("Digite \"y\" para continuar\n");
            scanf(" %c",&ok);
            while(ok!='y'){
                scanf(" %c",&ok);
            }
            system("clear");
        }
        if(test==0){
            printf("-x-x-x- Menu -x-x-x-\n\n1- Revisao.\n2- Aprender novos sinais.\n0- Sair\n\n");
            scanf(" %d",&op);
            system("clear");          
        }
        else{
            op = 1;
        }
    }
}

void revisaoSinal(int n){
    setlocale(LC_ALL,"UTF-8");
    int cont=0,lresp=n-2,p=0,erros; 
    char resp[100],frase[100],teste,link[10000],lose;
    FILE *arq;
    arq = fopen("ListasSinais.txt","r");
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
                system("clear");
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
    return;
}

void addFILE(no *n1){
    setlocale(LC_ALL,"UTF-8");
    FILE *arq;
    arq = fopen("ListasSinais.txt","a");
    fprintf(arq,"%s\n%s\n",n1->nome,n1->link);
    fclose(arq);
    return;
}

int qtdSinais(){
    setlocale(LC_ALL,"UTF-8");
    int cont=0;
    char test;
    FILE *arq;
    arq = fopen("ListasSinais.txt","r");
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


