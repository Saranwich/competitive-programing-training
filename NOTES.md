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
- Day 3 (2026-07-09, 4h partial): Lesson 0004 (two pointers & prefix sums) + two-pointers-cheatsheet.html. SOLVED CSES 1640 (both hash AND sort+two-pointer versions) + 1141 Playlist (stretch, took 4 review rounds). 2183 + 1662 NOT started — blank/stub, do them first next session (they're the core window + prefix-map reps he still needs). See LR-0004.
- Prefix+map (seen[0]=1, map-not-unordered, negative keys OK) landed well via Q&A — he now gets it "finds subarrays, not two pointers". Good conceptual anchor.
- NEXT SESSION: finish 2183 + 1662 (15 min each), THEN sorting/greedy/events (Day 4).
- 10-day schedule lives in reference/training-plan.html.
