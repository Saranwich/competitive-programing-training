# Sliding window: concept fine, but state-bookkeeping is the failure mode — and a hash bias to manage

Evidence (2026-07-09, Day 3, CSES 1640 + 1141). Two clear signals:

**1. Prefers hash/map, reaches for it by default.** Self-reported "I'm just comfortable with hash — is that bad?" Solved 1640 with a hashmap first (correct idea, but the intended sorted+two-pointer drill). Coached that hash is a great primary hammer but he needs a second tool: sorted + two-pointers for pair problems, and to know when hash *can't* work (needs ordering / "next greater" / closest-pair). He then wrote the sort+two-pointer version cleanly on the second ask. Keep occasionally forcing the non-hash tool so the toolbox stays balanced.

**2. The real weakness: incremental window-state bookkeeping.** On 1141 (longest distinct window) he kept trying to maintain the window *length* incrementally with `ans += 1` / `ans -= (l - last)` — the delta sign flipped when the duplicate was interior, and he never took a max. Took ~4 review rounds. The fix that finally worked: **stop juggling deltas; compute `r - l + 1` fresh each iteration and `ans = max(ans, ...)`.** This is the general lesson — for sliding windows, recompute the invariant from the pointers, don't try to patch it incrementally.

**Recurring detail bugs (same family as LR-0003):**
- Confused `map.count(key)` (returns 0/1) with `map[key]` (returns the value/position) — did this *twice* in the guard `last[k[r]] >= l`. Flag whenever he needs a stored position.
- `0` as a falsy sentinel again: `if (seen[x])` misses index-0 entries (also bit him in 1640). Store 1-based, or use `.count()`/explicit compare.
- The `>= l` window guard (is the duplicate still *inside* the window?) was non-obvious to him — needed a full walkthrough. Now understood.

**Implications for next sessions:**
- Prefix+map concept is solid (he articulated "it finds subarrays, not two pointers" himself). Don't re-teach; just give reps (2183, 1662 still pending).
- For window problems, steer him to the recompute-invariant pattern early, before he builds delta bookkeeping.
- The map `[]`-vs-`.count()` and 0-falsy bugs are now a *pattern* across two sessions — worth a permanent line on the pre-submit checklist / STL cheat sheet. See [[0003-binary-search-reactivated]].
- He iterates well and doesn't give up (4 rounds on a stretch problem) — can handle being pushed. But watch for him patching a broken approach instead of replacing it; nudge toward the clean rewrite sooner.
