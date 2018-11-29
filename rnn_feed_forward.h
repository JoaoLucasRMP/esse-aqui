#include "math.h"
void RNN_feed_forward( void )
{ 
   int i, j, k;
   int HIDDEN_NEURONS, hidden, INPUT_NEURONS, w_h_i, inputs, w_h_c1, context1, w_h_c2, context2, OUTPUT_NEURONS, outputs, w_o_h, population, POP_SIZE, MUTATE_PROB, CROSS_PROB;
 
   // primeiro: calcula-se as saidas das camadas ocultas.
   for ( i = 0 ; i < HIDDEN_NEURONS ; i++ )
   {
      hidden [ i ] = 0.0;
 
      // Adciona ao algoritmo a entrada.
      for ( j = 0 ; j < INPUT_NEURONS+1 ; j++ )
      {
         hidden [ i ] += w_h_i [ i ][ j ] * inputs[ j ];
      }
 
      // Adciona a entrada oculta.
      hidden [ i ] += w_h_c1 [ i ] * context1[ i ];
      hidden [ i ] += w_h_c2 [ i ] * context2[ i ];
 
      // adciona a tangente hiperbolica de ativação da função.
      hidden [ i ] = tanh( hidden[ i ] );
   }
 
   // segundo: calcular a camada de saida de dados de saida
   for ( i = 0 ; i < OUTPUT_NEURONS ; i++ )
   {
      outputs [ i ] = 0.0;
 
      for ( j = 0 ; j < HIDDEN_NEURONS+1 ; j++ )
      {
         outputs [ i ] += ( w_o_h [ i ][ j ] * hidden[ j ] );
      }
 
      // ativa a função de ativação sigmoid.
      outputs [ i ] = sigmoid( outputs[ i ] );
   }
 
   // terceiro: memorizar o contexto do valor oculto.
   for ( k = 0 ; k < HIDDEN_NEURONS+1 ; k++ )
   {
      context2 [ k ] = context1[ k ];
      context1 [ k ] = hidden[ k ];
   }
 
   return;
}
