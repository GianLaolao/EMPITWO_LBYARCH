# EMPITWO_LBYARCH

## MP2 Group 7 (LBYARCH S11)
- Laolao, Gian Chill Atienza
- Santos, Emmanuel Gabriel Del Valle

The results show the execution times and average times of the ASM function for varying matrix sizes. For smaller matrices (100x100 to 300x300), the execution time scales linearly with the size of the input, reflecting stable and efficient performance for smaller workloads. The average times within these size groups remain consistent, suggesting that the function handles these data sizes without significant inefficiencies or bottlenecks.

However, as the matrix size grows beyond 300x300, the execution time increases disproportionately, indicating potential scalability issues in the algorithm. Larger matrices such as 400x400 and beyond show a significant jump in average execution time, suggesting inefficiencies in handling large datasets, likely due to increased memory operations or nested loop overhead. Furthermore, runtime errors occur for matrices of size 480x480 and above, pointing to possible resource limitations, such as stack overflow or insufficient memory allocation. While the ASM function performs well for smaller matrices, its performance deteriorates with larger inputs, and the runtime errors highlight areas for improvement.
<br>
![image](https://github.com/user-attachments/assets/ae03f1c7-0f8b-4df2-a0aa-32c8123c4078)

Result of the sample input given in the specs:

...




Results varying in size below:

<h1><b>100 x 100</b></h1>
<b>1st run</b> <br>
Time taken for ASM function: 19.100000 x 10^6 ns <br>
Average Time taken for ASM function: 11.693333 x 10^6 ns <br>
<br>
<b>2nd run</b> <br>
Time taken for ASM function: 17.500000 x 10^6 ns <br>
Average Time taken for ASM function: 17.506667 x 10^6 ns <br>
<br>
<b>3rd run</b> <br> 
Time taken for ASM function: 12.000000 x 10^6 ns <br>
Average Time taken for ASM function: 11.683333 x 10^6 ns <br>
<br>
<b>4th run</b> <br>
Time taken for ASM function: 17.500000 x 10^6 ns <br>
Average Time taken for ASM function: 17.506667 x 10^6 ns <br>
<br>
<b>5th run</b> <br>
Time taken for ASM function: 12.500000 x 10^6 ns <br>
Average Time taken for ASM function: 17.310000 x 10^6 ns <br>
<br>

<h1><b>200 x 200</b></h1>
<br>
<b>1st run</b> <br>
Time taken for ASM function: 48.700000 x 10^6 ns <br>
Average Time taken for ASM function: 53.976667 x 10^6 ns <br>
<br>
<b>2nd run</b> <br>
Time taken for ASM function: 70.000000 x 10^6 ns <br>
Average Time taken for ASM function: 65.856667 x 10^6 ns <br>
<br>
<b>3rd run</b> <br>
Time taken for ASM function: 70.600000 x 10^6 ns <br>
Average Time taken for ASM function: 65.593333 x 10^6 ns <br>
<br>
<b>4th run</b> <br>
Time taken for ASM function: 70.900000 x 10^6 ns <br>
Average Time taken for ASM function: 61.360000 x 10^6 ns <br>
<br>
<b>5th run</b> <br>
Time taken for ASM function: 69.900000 x 10^6 ns <br>
Average Time taken for ASM function: 57.333333 x 10^6 ns <br>
<br>

<h1><b>300 x 300</b></h1>
<br>
<b>1st run</b> <br>
Time taken for ASM function: 156.700000 x 10^6 ns <br>
Average Time taken for ASM function: 105.276667 x 10^6 ns <br>
<br>
Time taken for ASM function: 108.500000 x 10^6 ns <br>
Average Time taken for ASM function: 115.826667 x 10^6 ns <br>
<br>
Time taken for ASM function: 158.300000 x 10^6 ns <br>
Average Time taken for ASM function: 124.816667 x 10^6 ns <br>
<br> 
Time taken for ASM function: 107.400000 x 10^6 ns <br>
Average Time taken for ASM function: 107.080000 x 10^6 ns <br>
<br>
Time taken for ASM function: 158.600000 x 10^6 ns <br>
Average Time taken for ASM function: 105.536667 x 10^6 ns <br>
<br>

<h1><b>400 x 400</b></h1>
<br>
<b>1st run</b> <br>
Time taken for ASM function: 282.700000 x 10^6 ns <br>
Average Time taken for ASM function: 188.130000 x 10^6 ns <br>
<br> 
Time taken for ASM function: 278.900000 x 10^6 ns <br>
Average Time taken for ASM function: 209.820000 x 10^6 ns <br>
<br>
Time taken for ASM function: 283.000000 x 10^6 ns <br>
Average Time taken for ASM function: 188.146667 x 10^6 ns <br>
<br>
Time taken for ASM function: 192.300000 x 10^6 ns <br>
Average Time taken for ASM function: 221.133333 x 10^6 ns <br>
<br>
Time taken for ASM function: 281.100000 x 10^6 ns <br>
Average Time taken for ASM function: 199.163333 x 10^6 ns <br>
<br>

<h1><b>450 x 450</b></h1>
<br>
Time taken for ASM function: 244.000000 x 10^6 ns <br>
Average Time taken for ASM function: 238.606667 x 10^6 ns <br>
<br>

<h1><b>475 x 475</b></h1>
<br>
Time taken for ASM function: 273.700000 x 10^6 ns <br>
Average Time taken for ASM function: 280.170000 x 10^6 ns <br>
<br>

<h1><b>480 x 480</b></h1>
<br>
Run time error. <br>


<h1><b>500 x 500</b></h1>
Run time error. <be>
