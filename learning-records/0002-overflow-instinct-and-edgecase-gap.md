# Lesson 1 transferring: overflow-check instinct forming; edge-cases are a *process* gap

Evidence (2026-07-08, CSES 1068 + 1083, day 1):

**Win — constraint→type habit is transferring.** On 1083 the user independently abandoned an `iota`/vector approach for the O(n) sum-formula (Σ1..n − Σgiven), *and verified the worst-case sum fits in `long long` before trusting it* — unprompted, one day after Lesson 1. This is the intended transfer: reading constraints → deciding types.

**Gap — edge-case misses are a process problem, not a knowledge problem.** User missed the overflow on 1068 despite *knowing* overflow exists ("I still missed edge case"). Self-identifies this as a recurring habit. The issue is the absence of a pre-submit ritual, not missing knowledge.

**Rust confirmed & shaking out fast:** forgot `iota` lives in `<numeric>` and had to web-search filling a sequence. Exactly the reactivation LR-0001 predicted; resolved by typing under pressure.

**Implications for next sessions:**
- Introduce a fixed **pre-submit checklist** (overflow / empty or n=1 / off-by-one / reset between test cases) and make the user run it every problem until automatic. This targets the process gap directly.
- Lesson 2 should hand over `<bits/stdc++.h>` template so "which header is `iota` in?" never costs time again.
- Push pace: day-1 transfer this strong means Day 2 (sorting/binary search) can move at full speed.
