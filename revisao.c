#include<stdio.h>
#include<stdbool.h>
#include<string.h>

/*
 N = tamanho do meu vetor(o que eu posso colocar ali dentro)
 pos = o local aonde quero adicionar a sub string
 tam =  tamnho da sub string 
 outra = a sub string q eu quero colocar dentro

 */
    bool vereficaTam(int n, char s[n], int tam){
        
    int tamString = 0;
    for(tamString; s[tamString] != '\0'; tamString++){
    }

    int total = tamString + tam;
    
    if(total > n){
        return false;    
    }
        return true;
    }
    
    void andarDireita(int n, char s[n], int pos, int tam,int ){
        
        
        int i = pos;
        int tamString = 0;
        for(tamString; s[tamString] != '\0'; tamString++){
        }
        
        for(int i ){
        
            
        }
        
    }
    


   bool strsubst(int n, char s[n], int pos, int tam, char *outra){

        bool posso = vereficaTam(n,s,tam);
        if(posso == true){
            printf("Olá");
            
            
        }   
        else{
            printf("Faz algo melhor");
        }
   }


int main(){

 char s[12] = "abacate";
 

 
strsubst(12, s, 5, 2, "te");
}
