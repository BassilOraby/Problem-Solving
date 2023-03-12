#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <iostream>
#include <omp.h>

double Matrix_One[30][30], Matrix_Two[30][30], Matrix_Three[30][30];
int P = 30;

MPI_Status status;

void main(int argc, char **argv)
{
	int numberOfTasks, taskid, numworkers, source, dest, rows, offset, i, j, k;

	omp_set_num_threads(8);

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
	MPI_Comm_size(MPI_COMM_WORLD, &numberOfTasks);

	numworkers = numberOfTasks - 1;

	srand(time(NULL));
	if (taskid == 0) {
		for (i = 0; i < P; i++) {
			for (j = 0; j < P; j++) {
				Matrix_One[i][j] = i * j;
				Matrix_Two[i][j] = i * j;
				Matrix_Three[i][j] = 0.0;
			}
		}

		rows = P / numworkers;
		offset = 0;

		for (dest = 1; dest <= numworkers; dest++)
		{
			MPI_Send(&offset, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
			MPI_Send(&rows, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
			MPI_Send(&Matrix_One[offset][0], rows*P, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
			MPI_Send(&Matrix_Two, P*P, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
			offset = offset + rows;
		}

		for (i = 1; i <= numworkers; i++)
		{
			source = i;
			MPI_Recv(&offset, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
			MPI_Recv(&rows, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
			MPI_Recv(&Matrix_Three[offset][0], rows*P, MPI_DOUBLE, source, 2, MPI_COMM_WORLD, &status);
		}
		finish = clock();
		double processing_time;
		processing_time = (double(finish - start) / CLOCKS_PER_SEC);
		cout << "Time taken =" << processing_time << "\n";

		printf("Here is the result matrix:\n");
		for (i = 0; i < P; i++) {
			for (j = 0; j < P; j++)
				printf("%6.2f   ", Matrix_Three[i][j]);
			printf("\n");;
		}
	}
	if (taskid > 0) {
		source = 0;
		MPI_Recv(&offset, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
		MPI_Recv(&rows, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
		MPI_Recv(&Matrix_One, rows*P, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);
		MPI_Recv(&Matrix_Two, P*P, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);

#pragma omp parallel 
		{
#pragma omp for private(i,j,k)
			for (k = 0; k < P; k++) {
				for (i = 0; i < rows; i++) {
					for (j = 0; j < P; j++) {
						Matrix_Three[i][k] = Matrix_Three[i][k] + Matrix_One[i][j] * Matrix_Two[j][k];
					}
				}
			}
		}

		MPI_Send(&offset, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
		MPI_Send(&rows, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
		MPI_Send(&Matrix_Three, rows*P, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
	}

	MPI_Finalize();
}