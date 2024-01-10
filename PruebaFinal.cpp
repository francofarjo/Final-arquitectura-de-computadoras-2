#include <stdio.h>
#include "mpi.h"
#include <omp.h>

int main()
{
    
    int world_size, world_rank, name_length;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    int thread_count = 0, thread_number = 1;
    
    #pragma omp parallel default(shared) private(thread_count, thread_number) num_threads(5)
    {
        thread_count = omp_get_num_threads();
        thread_number = omp_get_thread_num();
        
        printf("HOLA DESDE EL HILO %d DE %d DESDE EL PROCESO %d DE %d \n",
           thread_number, thread_count, world_rank, world_size);
    }
    
    MPI_Finalize();
}