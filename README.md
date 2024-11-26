# EMPITWO_LBYARCH

## MP2 Group 7 (LBYARCH S11)
- Laolao, Gian Chill Atienza
- Santos, Emmanuel Gabriel Del Valle

The results show the execution times and average times of the ASM function for varying matrix sizes. For smaller matrices (100x100 to 300x300), the execution time scales linearly with the size of the input, reflecting stable and efficient performance for smaller workloads. The average times within these size groups remain consistent, suggesting that the function handles these data sizes without significant inefficiencies or bottlenecks.

However, as the matrix size grows beyond 300x300, the execution time increases disproportionately, indicating potential scalability issues in the algorithm. Larger matrices such as 400x400 and beyond show a significant jump in average execution time, suggesting inefficiencies in handling large datasets, likely due to increased memory operations or nested loop overhead. Furthermore, runtime errors occur for matrices of size 480x480 above, pointing to possible resource limitations, such as stack overflow or insufficient memory allocation. While the ASM function performs well for smaller matrices, its performance deteriorates with larger inputs, and the runtime errors highlight areas for improvement.