# Original PD allocation, partial-free queue and backing reclamation

Planning before diagnostic coding. Whole analysis scope remains report40 OPEN_ITEMS.

## Provenance and fresh state

Reproduce report31 `setup(target, sleepable)` and its caller=False preparation. Compare the newly observed setup and entire before snapshot to the preserved report31 row. This is before original PT allocation, not an allocated PT relabeled as PD.

Add a separate explicitly synthetic pmap zone with two free pmap structures, a valid empty free-PD sentinel/counters, and physical-segment descriptors needed for the existing free backing PG. Validate new storage against captured regions. Original pmap_create allocates and initializes real PD backing through kmem_alloc_wired and pg_exten allocation. Keep executing on the existing root; do not load a newly created PD into CR3.

## Intended sequence

Original create first PD → eligible update with one occupied slot → create second PD → destroy one pmap → eligible update with one occupied slot → destroy remaining pmap → eligible update reclaiming the empty PD backing. Test both destroy orders and both existing execution roots/sleepable zone modes after a successful smoke.

Call preparation and scheduler tick inputs are explicit. No changes to kernel ownership, bitmap/count, map/PTE/descriptor state are permitted between original calls. No patched original instructions or substituted call returns. Synthetic pmap-zone lock initialization, if needed, uses original lock_init and is recorded.

## Required observations

- Original pmap structure allocation/zero/refcount/lock initialization, root KVA and physical CR3 fields.
- Actual fresh PD backing and second hardware-page slot allocation; alloc_count16, bitmap8, queue head/tail and total/free-PD counts.
- Original kernel PDE copy loop, complete source and destination progression, raw write/physical mapping correspondence. Capture automatic backing A/D changes rather than erasing them.
- Original pmap_destroy refcount/locking and pmap-zone zfree, not a fabricated standalone slot-free entry.
- GC keeps partially used pages; full count transitions remove/add free-PD queue membership. Count zero invokes actual zfree and kmem_free, restarts from queue head and preserves last-tick semantics.
- Dirty kernel backing removal can execute 18fcb9 physical lookup and 18fcbe/18fcc5/18fcd4 clean/attribute updates; report34's clean PT assumptions cannot be copied unchanged.
- Original stack/RET, no unexpected panic/blocking/interrupt/error, no new-CR3 execution, full recorded writes and protected state. Instruction/time limit or intermediate stop is not success.

## Review and gates

Independent Codex planning review requested before coding. Root independently checked original 18f40c,18f58c,18f644,18f69c,191144 and dirty removal ASM, plus preserved Darwin pmap source and pg_exten layout. Reviewer conclusions must be reproduced locally.

After initial diagnostic, add a separate original-byte/state auditor, targeted corrupted-record controls and fresh-run reproduction before acceptance. Preserve original binaries/exports/DBs, upstream source and all previous reports. Use Python for every calculation. No reconstructed kernel implementation or GCC 2.7 build claim.

Native frame/RF, scheduler/concurrency, multi-backing-PD queue restart, resource shortage, full ownership and full-kernel semantics remain separately unverified even if this lifecycle succeeds.
