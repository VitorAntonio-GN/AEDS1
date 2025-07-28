#include <stdio.h>

int main(void)
{
    float catetus_1 = 0.0;
    printf("Catetus 1: ");
    scanf("%f", &catetus_1);

    float catetus_2 = 0.0;
    printf("Catetus 2: ");
    scanf("%f", &catetus_2);

    //pega hipotenusa
    float hypotenuse =  (catetus_1 * catetus_1) + (catetus_2 * catetus_2);
 
    float num_for_bases = hypotenuse;
    int num_bases = 0;

    //verifica a quantidade de casas decimais
    while(num_for_bases > 1 || num_for_bases == 1)
    {
        num_for_bases /= 10;
        num_bases++;
    }

    float base_10_root = 1;

    //pela quantidade de "casas" ele as transforma em bases, se 2 casas, é uma base 10, 
    //o -1 é por que começa na casa 1, que já foi contada automaticamente
    for(int j = 0; j < num_bases - 1; j++)
    {
        base_10_root *= 10;
    }

    float test_root = 0;
    float root = 0;
    //define quantas casas irá rodar
    int add_bases_root = 0;
    int decimal_count = num_bases + 10;

    //vai descendo com o contador junto com a quantidade de casas decimais (se o numero * numero for maior que a hipotenusa, ele desce)
    //quando fica maior, ele soma a raiz o anterior
    while(((root * root) != hypotenuse) && (decimal_count != 0))
    {      
        //base =  contador * casa em que está
        //o valor vai sendo adicionado e testado com ele mesmo
        //base original usada com a de teste ()
        test_root += add_bases_root * base_10_root;

        //se root + test root ao quadrado é maior que a hipotenusa (ao quadrado é maior, logo a raiz é maior)
        if(((root + test_root) * (root + test_root)) > hypotenuse)
        {
            //caso a base seja maior que a hipotenusa na multiplicação, será adicionada ela com o contador menos 1 a raiz, ex: 100 * 100 > hipotenusa, 
            //logo será adicionado 000 a raiz, caso seja 9 * 9 > hipotenusa, será adicionado 8 a raiz (contador 8 - 1)
            root += (add_bases_root - 1) * base_10_root;

            //caso adicionar, abaixa a casa decimal e reseta o contador
            base_10_root /= 10;
            add_bases_root = 0;

            //reduz o contador de casas decimais para parar o loop while
            decimal_count--;
        }
        else
        {
            //aumenta o contador
            //aumentar a test root, que depós na soma leva a raiz "original" (adicionada caso true e vai seguindo)
            add_bases_root++;
        }

        //reseta a base de teste, a original fica guardada
        test_root = 0;
    }

    hypotenuse = root;

    printf("Hypotenuse: %.5f", hypotenuse);
}