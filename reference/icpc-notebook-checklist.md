# ICPC Team Reference Document — Checklist (25 หน้า)

หน้า 1 = ข้อมูลทีม/มหาวิทยาลัย (บังคับ) → เหลือ **24 หน้า**
ติ๊ก `[x]` อันที่จะเอา แล้วค่อยมาคุยกันเรื่องจัดหน้า

ตัวเลขในวงเล็บ = จำนวนหน้าโดยประมาณ

## A. ของที่ต้องมี (พื้นฐานทีมเรา — มีของอยู่แล้วใน repo)

- [ ] Template C++ + pre-submit checklist (overflow, edge case, bounds, trace ตัวอย่างมือ) (1)
- [X] ตาราง constraints → complexity (n เท่าไหร่ ใช้ algo แบบไหน) (0.5)
- [X] STL cheat sheet — sort/comparator/tie, set/map, multiset, priority_queue (min-heap), lower/upper_bound (1–1.5)
- [X] Binary search + binary search on answer (0.5–1)
- [X] Two pointers + prefix sums + prefix+map (subarray sums) (1)
- [X] Greedy patterns — interval scheduling (sort by end), event sweep ±1, exchange argument (1)
- [X] DP — 5-question recipe, counting vs optimisation, loop-order (Coin Comb I vs II), 2D DP (1.5–2)
- [X] String/parsing — getline trap, stringstream, substr/find/stoll, freq array (1)
- [X] Math — gcd/lcm, modpow, modular inverse, sieve, nCr mod p, ตาราง overflow (1–1.5)

## B. ควรมี (มาตรฐาน ICPC — ยังไม่ได้เรียนแต่เพื่อนร่วมทีมอาจใช้)

- [X] Graph พื้นฐาน — adjacency list, BFS, DFS, connected components (1)
- [X] Shortest path — Dijkstra, Bellman-Ford, Floyd-Warshall (1)
- [X] DSU (Union-Find) + Kruskal MST (1)
- [X] Topological sort + DAG DP (0.5)
- [X] Tree พื้นฐาน — traversal, subtree size, LCA (binary lifting) (1)
- [X] DP เพิ่มเติม — 0/1 knapsack (loop ถอยหลัง), LCS, LIS (n log n) (1)
- [X] Segment tree / Fenwick (BIT) — point update, range query (1–1.5)
- [X] Number theory เพิ่ม — prime factorization, divisors, Euler phi (0.5–1)

## C. เผื่อเหลือหน้า (โจทย์เจอไม่บ่อย แต่เจอแล้วเขียนสดยาก)

- [ ] String algorithms — hashing, KMP/Z, trie (1–1.5)
- [ ] Geometry พื้นฐาน — cross product, CCW, distance, convex hull (1–1.5)
- [ ] Combinatorics/สูตร — Catalan, inclusion-exclusion, pigeonhole (0.5)
- [ ] Matrix exponentiation (0.5)
- [ ] Bitmask DP + bit tricks (`__builtin_popcount` ฯลฯ) (0.5–1)
- [ ] Game theory — Nim, Grundy (0.5)
- [ ] Coordinate compression + sweep line (0.5)
- [ ] Fast I/O + จุดพลาดบ่อย (endl vs "\n", cin.tie) (0.25)

## D. หน้าพิเศษ (ไม่ใช่ algo แต่มีประโยชน์จริงตอนแข่ง)

- [ ] "Wrong answer แล้วทำไง" debug checklist — misread gate (restate + คิด sample มือ), bug family ประจำตัว (n-vs-x, inequality direction, INF sign, > vs >=) (0.5–1)
- [ ] กลยุทธ์ทีม — อ่านโจทย์ทุกข้อก่อน, คนอ่าน ≠ คนโค้ดคนแรก, ใครถือเครื่องเมื่อไหร่ (0.5)


## style
ต้องการ ref function ที่มีประโยชน์ จาก obj ออกมาเป็น code snipt ที่จะทำเช่น 

สร้าง set ที่มี เลข 1-n ยกเว้น condition -> code
เป็นต้น 

เอาง่ายๆ tools อีกตัวอย่างเช่น
หา idx แรกที่เจอ -> upper() 
ถ้าไม่เจอ คืน v.end();

## ปล เลหือที่ให้เขียน 4 หน้า ดังนั้นมี 20 หน้าให้ใช้
