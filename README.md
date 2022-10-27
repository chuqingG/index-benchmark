# The Adaptive Radix Tree (ART)
The Adaptive Radix Tree: ARTful Indexing for Main-Memory Databases

#### Usage
```bash
# build target
mkdir build && cd build
cmake .. && make
# run benchmark: ./Benchmark -b [search/insert/range_search] -s [1/2/3] -i 100 [...]
./Benchmark -b search -s 1 -i 100
```

```bash
Finished 'search' benchmark with size '1' (65000 keys), '100' iterations and 'sparse' keys in 1.9 minutes.

=================================================================================================================
                                        PERFORMANCE BENCHMARK RESULTS
=================================================================================================================
Index Structure |      Min      |      Max      |      Avg      |      Med      | M Ops/s (Avg) | M Ops/s (Med) |
-----------------------------------------------------------------------------------------------------------------
ART             |      0.0033s  |      0.0048s  |      0.0035s  |      0.0035s  |     18.4532   |     18.4765   |
ART (Virt)      |      0.0032s  |      0.0044s  |      0.0033s  |      0.0033s  |     19.9564   |     19.9963   |
ART (CRTP)      |      0.0031s  |      0.0045s  |      0.0032s  |      0.0032s  |     20.1255   |     20.1551   |
ART (Leis)      |      0.0032s  |      0.0046s  |      0.0033s  |      0.0032s  |     19.9269   |     20.0927   |
Trie            |      0.0109s  |      0.0134s  |      0.0112s  |      0.0112s  |      5.7855   |      5.8063   |
M-Trie          |      0.0806s  |      0.1135s  |      0.0817s  |      0.0813s  |      0.7956   |      0.7991   |
H-Trie          |      0.1153s  |      0.1285s  |      0.1192s  |      0.1192s  |      0.5451   |      0.5452   |
Sorted List     |      0.0471s  |      0.0487s  |      0.0476s  |      0.0475s  |      1.3657   |      1.3672   |
Hash-Table      |      0.0077s  |      0.0088s  |      0.0080s  |      0.0080s  |      8.1324   |      8.1341   |
RB-Tree         |      0.0288s  |      0.0306s  |      0.0296s  |      0.0296s  |      2.1952   |      2.1960   |
```