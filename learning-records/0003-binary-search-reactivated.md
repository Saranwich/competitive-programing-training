# Binary search reactivated — technique understood, details are the shaky part

Evidence (2026-07-08, CSES 1620 + 1085): user can now frame binary-search-on-the-answer independently — correctly identified the monotonic `check` for both problems and got the overall structure (template + check, right `hi=mid` direction) on the first attempt. Also showed good judgment questioning whether 1621 even needed BS (it didn't).

**Where the bugs clustered — all details, not concepts:**
- Direction of a division inside `check` (1620: computed `k/x` instead of `x/k`).
- `hi` bound too small to reach the answer (1620: used 2e9, needed 2e18).
- Off-by-one / infinite loop from `lo = mid` instead of `lo = mid + 1`.
- Greedy `check` implementation slips: double-add of an element, cutting after exceeding instead of at/-before, inverted `pieces >= k` vs `<= k`.

**Implications:**
- The concept is landing fast; do NOT re-teach binary search theory. Keep giving BS-on-answer problems but let the user implement `check` solo — the reps fix the detail bugs.
- These detail bugs map exactly to the pre-submit checklist (overflow, bounds, off-by-one). Reinforce running it.
- Also learned this session: on CF/CSES prefer ordered `set`/`map` over `unordered_*` (anti-hash TLE). Candidate for a permanent glossary/checklist note. See [[0002-overflow-instinct-and-edgecase-gap]].
- Ready to move at full pace to two-pointers & prefix sums next session.
