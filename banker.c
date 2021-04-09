// Banker's Algorithm
#include <stdio.h>
int main()
{
	// P0, P1, P2, P3,  are the Process names here

	int n, m, i, j, k;
	n = 4; // Number of processes
	m = 4; // Number of resources
	int alloc[4][4] = { { 2,0,1,1 }, // P0 // Allocation Matrix
						{ 1,1,0,0 }, // P1
						{ 1,0,1,0 }, // P2
						{ 0,1,0,1 }}; // P3

	int max[4][4] = {{3,2,1,1},{1,2,0,2},{3,2,1,0},{2,1,0,1}};

	int avail[4] = {6,4,4,2}; // Available Resources

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 4; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
    printf("---------------------------------------------------\n");
    printf("Process   Max   \tAllocation\t Need \n");
    for(int i=0;i<4;i++){
        printf("P%d\t",i);
        for(int j=0;j<4;j++){
            printf("%d ",max[i][j]);
        }
        printf("\t");
        for(int j=0;j<4;j++){
            printf("%d ",alloc[i][j]);
        }
         printf("\t");
        for(int j=0;j<4;j++){
             printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------------------------\n\n");
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	printf("\n\n");

	return (0);
}

