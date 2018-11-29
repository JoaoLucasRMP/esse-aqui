void GA_process_population( unsigned int pop )
{
   double sum = 0.0;
   double max = 0.0;
   int best;
   int i, child;
 
   best = 0;
   sum = max = population[ pop ][ best ].fitness;
 
   // calcula o total da população topper
   for ( i = 1 ; i < POP_SIZE ; i++ )
   {
      sum += population[ pop ][ i ].fitness;
      if ( population[ pop ][ i ].fitness > max )
      {
         best = i;
         max = population[ pop ][ i ].fitness;
      }
   }
 
   // Eletista, mantendo o melhor cromossomo encontrado.
   recombine( pop, best, best, 0, 0.0, 0.0 );
 
   // Gerando a proxima prole.
   for ( child = 1 ; child < POP_SIZE ; child++ )
   {
      unsigned int parent1 = select_parent( pop, sum );
      unsigned int parent2 = select_parent( pop, sum );
 
      recombine( pop, parent1, parent2, child, MUTATE_PROB, CROSS_PROB );
   }
 
   return;
}
