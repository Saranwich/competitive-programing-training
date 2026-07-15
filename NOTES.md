# Teaching Notes

## User profile
- Thai student, prepping solo for ICPC Asia Pacific (Thailand) regional, ~2026-07-18
- **End of first-year CS. CF rating ~1000. Beginner. Knew basics (b_search) but ~4 months ago — RUSTY.**
- First ~2 days = reactivation, not new material. Verify retention with quiz/timed solves, not self-report.
- C++ only. Repo: mostly 800-rated As, few Bs, one C. ~27 problems.
- Time budget: 6 full-time days + 4 days of 4–6h, user picks which day is which.

## Preferences / working notes
- Repo layout: codeforces/problemset/*.cpp, atcoder/. Commits titled "YYYY-MM-DD, solved: <id>".
- Book: Competitive Programmer's Handbook at resources/books/book.pdf (draft July 2018).
- Full-time day = 2 lessons + ~6 problems + review. Partial day = 1 lesson + 3–4 problems.
- Keep lessons short; the real training volume comes from CSES/CF problems, not reading.

## Plan state
- Day 1 (2026-07-08): Lessons 0001 (constraints→complexity) + 0002 (template/STL/checklist) done. Solved CSES 1068, 1083 (committed c538a7a). Strong transfer: applied overflow-check proactively on 1083. See LR-0002.
- Day 2: Lesson 0003 (binary search on the answer). SOLVED CSES 1621 (hit unordered_map anti-hash TLE → switched to set), 1620 Factory Machines, 1085 Array Division. All AC after fixing detail bugs (see LR-0003). Binary search reactivated.
- Recurring weakness to drill: edge cases → the pre-submit checklist (cpp-stl-cheatsheet #checklist). Make him run it every problem.
- Day 3 (2026-07-09, 4h partial): Lesson 0004 (two pointers & prefix sums) + two-pointers-cheatsheet.html. SOLVED CSES 1640 (both hash AND sort+two-pointer versions) + 1141 Playlist (stretch, took 4 review rounds). See LR-0004.
- TASK-NUMBER FIX (Day 4): Lesson 0004 originally MISLABELED the subarray reps — the real CSES tasks are 1660 Subarray Sums I (positive), 1661 Subarray Sums II (negatives→prefix+map). 2183 is "Missing Coin Sum" (a GREEDY problem), NOT a subarray problem. 2216/2217 are "Collecting Numbers". All lesson links now corrected.
- Prefix+map (seen[0]=1, map-not-unordered, negative keys OK) landed well via Q&A — he now gets it "finds subarrays, not two pointers". Good conceptual anchor.
- Day 4 (2026-07-10/11): Lesson 0005 (greedy & exchange arguments) + greedy-cheatsheet.html authored. Scoped to ONE skill: recognise a greedy problem, pick the correct sort key, justify via exchange argument. Patterns A (interval scheduling, sort by END) + B (event sweep, ±1).
- SOLVED CSES 2183 Missing Coin Sum (greedy, sort asc + track reach, reach as ll). Clean solve, he wrote the reach>coin gap logic himself. This surfaced the task-number mislabel above — he caught it. Took heavy scaffolding (Thai + ASCII number-line visual) before the greedy invariant clicked; the visual (reach = gapless bar, oversized coin = permanent hole) is what landed it.
- Still owed (Day 3 reps): 1660 Subarray Sums I, 1661 Subarray Sums II (prefix+map). Greedy set: 1629 Movie Festival, 1630 Tasks&Deadlines, 1619 Restaurant Customers, 1084 Apartments, stretch 1164 Room Allocation.
- Watch: hash bias (LR-0004) — greedy set is sorting-based, good for balancing toolbox. Push him to say the sort key + why out loud before coding.
- Owed reps CLOSED (2026-07-11): SOLVED 1660 Subarray Sums I (sliding window), 1661 Subarray Sums II (prefix+map), 2183 Missing Coin Sum (greedy). All committed. Greedy set 1629/1630/1619/1084/1164 still NOT committed — the greedy *skill* was exercised via 2183, so moving on; circle back to those as warm-up reps if time.
- Day 5 (2026-07-13): Lesson 0006 (DP I — state/transition/order) + dp-cheatsheet.html authored. Scoped to ONE skill: the 5-question recipe (state, transition, base, order, answer) on 1D DP. Two shapes taught: counting (SUM + mod 1e9+7) and optimisation (MIN + INF guard). Grounded as greedy's fallback (the {1,3,4}→6 coin case from Lesson 5). Pre-empted his recurring bugs in DP form: overflow→mod, INF-sentinel guard, s-c>=0 bounds. Included the loop-order twist (Coin Comb I vs II).
- DP problem set assigned: 1633 Dice Combinations, 1634 Minimizing Coins, 1635 Coin Comb I, 1636 Coin Comb II (loop-order), 1637 Removing Digits, stretch 1746 Array Description.
- NEXT SESSION: verify DP solves via /check — KEY CHECK: did he write the 5 recipe answers as a comment BEFORE coding, and can he state dp[i] in one sentence? Watch the mod-inside-loop and INF-guard bugs specifically. Watch loop-order confusion on 1636. THEN Day 6 = DP II (2D: grids/knapsack/LCS).
- 10-day schedule lives in reference/training-plan.html.
- Day 6+ (2026-07-15): DETOURED from DP set to Movie Festival greedy reps. Heavy STL Q&A session (sort/comparator/tie, lower/upper_bound, iterator-not-index, multiset vs stack, structured bindings) — good, he's shoring up STL mechanics that the DP set doesn't drill. Taught 1632 Movie Festival II in full (end-time sort + multiset of k free-times + "assign to largest free ≤ start" via upper_bound+step-back; exchange-argument justification tying back to Lesson 5).
- FILE-NAMING CONFUSION to watch: 1629=Festival I, 1632=Festival II. His file `1632_Movie_Festival.cpp` actually holds Festival I code (comment correctly says task/1629); `1632_Movie_Festival_II.cpp` still has the OLD wrong single-timeline code (to be rewritten with multiset).
- /check on his Festival I (1629): greedy reasoning SOLID (right sort key end-then-start, right boundary `time>s`, fixed last time's double-fill via movies[i]={a,b}). ONE bug: `time += e` should be `time = e` (treated absolute end-time as duration). Gave him a 3-back-to-back-interval trace to self-spot it; passed CSES sample by luck. NOT-yet, mechanical fix. Next: fix+submit 1629, THEN write 1632 II with multiset (Festival I = k=1 special case framing landed).
- Still owed: DP set (1633-1637, stretch 1746) not yet checked — circle back after Movie Festival reps.
- MASTERED 1632 Movie Festival II (2026-07-16): built from the idea (end-sort + multiset of k free-times + upper_bound-then-step-back). Self-fixed two bug classes once pointed — dangling `if(...);` semicolon, and leftover debug cout (judge hygiene). Verified correct via 4 hand-checked tests (k=1 reduces to Festival I, boundary-touch chain, k-cap). Complexity O(n log n + n log k). STRONG conceptual round: he asked & now understands why-multiset-not-vector (O(k) shift vs O(log k) tree), why-not-stack (search-by-value not LIFO), and upper_bound return on [0,0,0]/duplicates. STL mechanics now solid, not incantation.
- SOLVED greedy warm-up reps (2026-07-16): 1630 Tasks&Deadlines (key insight: Σd fixed → minimize Σ finish times → SPT sort by duration; deadlines irrelevant to order), 1619 Restaurant Customers (event sweep ±1 on a map), 1084 Apartments (sort both + two-pointer within k). All AC, all committed.
- MASTERED 1164 Room Allocation (2026-07-16): min-heap of {departure, room_id}, sort customers by ARRIVAL, reuse earliest-freeing room when `top.first < arrival` else open new. First time using priority_queue — spent a full session on heap mechanics from zero ("no idea what a heap is"). Two bugs I caught via brute-force validator: (1) sorted by departure not arrival → inflated count; (2) printed room ids in sorted order not input order → overlapping guests same room. Fixed by carrying original index in array<ll,3> and writing ans[idx]. Understood CSES special-judge: any minimal-count conflict-free assignment accepted, labels needn't match sample.
- STL TRICKS learned this session (heap/sort/tie) — drill-ready reference:
  - `priority_queue<T, vector<T>, greater<>>` = MIN-heap (default `less<>` = max-heap). Must restate `vector<T>` because template args are positional — can't skip to the 3rd (Compare) slot. Only interface: push/top/pop/empty; NO indexing/iteration (adaptor hides the underlying vector — the 2i+1 child math only applies if you build on a raw vector with make_heap/push_heap/pop_heap).
  - `pair`/`array` compare lexicographically (first, then second...) → put the heap/sort key FIRST. Storing `{departure, id}` makes top = earliest-departing automatically.
  - `pop()` returns void — read `top()` first, then `pop()`. Always guard `!empty()` before top/pop (UB otherwise).
  - `sort`'s 3rd arg is a comparator (functor/lambda returning strict `<`). `tie(x.b, x.a) < tie(y.b, y.a)` = sort by b then a without writing a struct — `tie` makes a tuple of references, tuples compare lexicographically. `greater<>` is just the functor `a > b`.
  - To keep input order after sorting: carry the original index alongside the data, write results into `ans[idx]`, print `ans`.
- NEXT: back to owed DP set (1633 Dice Comb, 1634 Min Coins, 1635/1636 Coin Comb loop-order, 1637, stretch 1746) — verify the 5-question recipe-as-comment-before-coding habit + watch mod-in-loop / INF-guard / loop-order bugs. Then Day 6 = DP II (2D grids/knapsack/LCS).
