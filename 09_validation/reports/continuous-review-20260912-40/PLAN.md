# Original aging → removal integration: bounded plan

Status: planning; no completion claim. This does not replace remaining whole-kernel analysis.

## Evidence and explicit boundary

- Read preserved original `00191144.asm`, `0018f7f8.asm`, `00190f90.asm` and the finalized report32/33/34/35 consumers before coding.
- Reuse report34 `dirty_prefix.prefix` read-only. Compare every field in report33's fixed `PREFIX_KEYS` against a freshly executed prefix and canonical report32. Report32 `points` and `zero_chunks` are **not newly collected** by this helper; do not call this full report32-row equality.
- Original-created EXT has section offset zero. The actual section size is `0x800000`; do not reduce it to the copied data's VM page. The selected PDE is the first PDE; copied DATA uses the neighboring PDE.
- Prefix still relies on explicit CPU-frame injection and synthetic bootstrap/map/object/zone prerequisites. Native RF, hardware interrupt delivery, boot ownership and concurrency remain unverified.

## Proposed cases and inputs

Fresh emulator for each case. Record physical-segment input exactly as report33, empty free-PD queue controls, last/tick, one-byte EXT age, and optional selected-PDE Accessed input. Do not change original instruction bytes, PT content, PDE neighbor, section offset/size, or queue ownership after prefix.

Default: last=1, tick=3, age=7, original selected PDE retained. Supplement with age=6 threshold equality and a selected-PDE Accessed case. Cover both existing roots; expand normal removal over the existing copy-function/destination/flags/sleepable prefix matrix only after smoke success.

## Verification gates

1. Independent Codex planning review before diagnostic coding; root reproduce each substantive finding. Keep review scope and disagreements explicit.
2. Original `pmap_update` through actual internal removal and RET, with all original instruction heads and memory writes. No call mocks, forced successful branches, patched opcodes, or synthetic replacement return.
3. Capture actual helper args, entire PT scan progression, age decision, selected/neighbor PDE effects, dirty lookup and PV unlink, active→free PT queue transition, saved-next traversal, counters, stack/callee-saved state, original backing and DATA preservation.
4. Independently replay captured writes and verify original-byte store cardinality and stack CALL/RET flow using preserved report34/35 read-only consumers. Add an explicit semantic model for this new path; do not equate write replay with full instruction semantics.
5. Existing run time/instruction limits remain; non-RET or exception is a recorded failed diagnostic, not success. Any required input or budget adjustment must be explained.
6. Corrupted-record negative controls, fresh-run reproducibility, input/original/prior-report hashes and bounded report checkpoint before any completion statement.

Calculations and aggregation use Python only. Changes belong only in this report directory. No `07_kernel` implementation; GCC 2.7 build requirements unchanged.
