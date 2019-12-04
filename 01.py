from random import seed
from random import randint
import os
import webbrowser
def limpatela():
    os.system('cls' if os.name == 'nt' else 'clear')
def parada():
    input('Aperte "enter" para continuar.')
    limpatela()
def exite():
    if ((os.path.exists("ListaSinais1.txt")) and (os.path.exists("ListaSinais2.txt"))):
        return 1
    else:
        return 0
def revisao(i,nv):
    j = exite()
    cont = 0
    aux = 0
    if j == 0:
        print("O arquivo não exite.\n")
    else:
        if nv==1:
            f = open("ListaSinais1.txt","r")
        elif nv==2:
            f = open("ListaSinais2.txt","r")
        while cont !=(i-2):
            resp = f.readline()
            cont = cont + 1
        resp = str(f.readline())
        resp = resp.strip()
        link = str(f.readline())
        webbrowser.open_new_tab(link)
        print("Qual o significado do sinal mostrado ?\n\nResposta: ")
        entrada = str(input())        
        while (entrada!=resp):
            print("Errou tente mais uma vez: ")
            entrada = str(input())
            aux = aux + 1
            if(aux >= 4):
                desistir = input("Deseja desistir (Sim/Não) ? ")
                if((desistir == "Sim") or (desistir == "S") or (desistir == "s") or (desistir=="sim")):
                    f.close()
                    return 0
                elif ((desistir == "Não") or (desistir == "N") or (desistir == "n") or (desistir=="Nao") or (desistir == "nao") or (desistir=="não")):
                        aux = 0   
        print("Acertou!")
        f.close()
        return 1
def insere_arquivo():
    limpatela()
    arq = int(input("-x-x-x- ARQUIVOS -x-x-x-\n\n1 - Básico\n2 - Avançado\n0 - Sair\n\nOpção: "))
    while arq!=0:
        if arq ==1:
            f = open("ListaSinais1.txt","a")
            novoSinal = input("Digite o nome do sinal: ")
            novoLink = input("Digite o link do novo sinal: ")
            f.write("\n%s\n%s"%(novoSinal,novoLink))
            input("Sinal cadastrado com sucesso.\n\nAperte 'enter' para continuar.")
            limpatela()
            f.close()
        elif arq == 2:
            f = open("ListaSinais2.txt","a")
            novoSinal = input("Digite o nome do sinal: ")
            novoLink = input("Digite o link do novo sinal: ")
            f.write("\n%s\n%s"%(novoSinal,novoLink))
            input("Sinal cadastrado com sucesso.\n\nAperte 'enter' para continuar.")
            limpatela()
            f.close()
        arq = int(input("-x-x-x- ARQUIVOS -x-x-x-\n\n1 - Básico\n2 - Avançado\n0 - Sair\n\nOpção: ")) 
    limpatela()
def test_arquivo():
    f = open("Teste.txt","r")
    if f == None:
        print("Não foi possível abrir o arquivo.\n")
    else:
        test = str(f.readline())
        test = test.strip()
        print(test)
        resposta = str(input("Digite a resposta: "))
        if resposta == test:
            print("Parabéns, você é foda")
        else:
            print("Essa bagaça não está funcionando.\n")


print("-x-x-x- MENU -x-x-x-\n\n1 - Revisão básica.\n2 - Revisão avançada.\n3 - Teste diário.\n0 - Sair.\n\nOpção: ")
op = int(input())
limpatela()
totalBasica = 0
totalAvan = 0
i = exite()
antSinal1,antSinal2 = 0,0
dnv1,dnv2 = 0,0
f1 = open("ListaSinais1.txt","r")
f2 = open("ListaSinais2.txt","r")
while op !=0:
    if(i==1):
        for line in f1: totalBasica += 1
        for line in f2:  totalAvan += 1
    if op == 1:
        rand = randint(0,totalBasica)
        while ((rand%2!=0) or (rand==antSinal1)):
            rand = randint(0,totalBasica)
        revisao(rand,1)
        antSinal1 = rand
        dnv1 = input("Mais um sinal ? (Sim/Não): ")
        parada()
    elif (op == 2):
        rand = randint(0,totalAvan)
        while ((rand%2!=0) or (rand==antSinal2)):
            rand = randint(0,totalAvan)
        revisao(rand,2)
        antSinal2 = rand
        dnv2 = input("Mais um sinal ? (Sim/Não): ")
        parada()
    elif op==3:
        preparado = input("O Teste diário é composto por 15 sinais, básicos ou avançados, você só sairá do teste após acertar os 15 sinais\nPreparado ? ")
        if((preparado=="s")or(preparado=="sim")or(preparado=="Sim")or(preparado=="S")):
            ok = 1
            while ok<=15:
                if ((ok%3!=0) and (ok<=10)):
                    rand = randint(0,totalBasica)
                    while ((rand%2!=0) or (rand==antSinal1)):
                        rand = randint(0,totalBasica)
                    ok = ok + revisao(rand,1)
                    antSinal1 = rand
                    parada()
                    limpatela()
                elif((ok<=10) and (ok%3==0)):
                    rand = randint(0,totalAvan)
                    while ((rand%2!=0) or (rand==antSinal2)):
                        rand = randint(0,totalAvan)
                    ok = ok + revisao(rand,2)
                    antSinal2 = rand
                    parada()
                    limpatela()
                elif (ok>10 and ok<=15):
                    rand = randint(0,totalAvan)
                    while ((rand%2!=0) or (rand==antSinal2)):
                        rand = randint(0,totalAvan)
                    ok = ok + revisao(rand,2)
                    antSinal2 = rand
                    parada()
                    limpatela()
        print("Parabéns, você concluiu o teste diário. :D \n")
        parada()
    elif op==400:
        senha = input("Digite a senha: ")
        if senha == "3sp4d4":
            insere_arquivo()
    if ((dnv1=="Sim") or (dnv1=="s") or (dnv1=="sim")):
            op = 1
    elif((dnv2=="Sim") or (dnv2=="s") or (dnv2=="sim")):
            op = 2
    else:
        print("-x-x-x- MENU -x-x-x-\n\n1 - Revisão básica.\n2 - Revisão avançada.\n3 - Teste diário.\n0 - Sair.\n\nOpção: ")
        op = int(input())
        limpatela()
limpatela()
f1.close()
f2.close()