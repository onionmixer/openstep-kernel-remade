# Independent planning review and input correction

Before coding, `/root/vm_contract_review27` independently reviewed the planned original PD lifecycle. Root separately read the original allocation/create/destroy/update listings and the preserved Darwin pmap/pg_exten source.

Accepted planning constraints: a genuinely newly allocated PD backing, a separate pmap zone, partial slot occupancy in free-PD queue, full-count queue removal/reinsertion, no activation of new PD roots, and actual dirty kernel-backing lookup/attribute path in final GC. The existing report34 clean PT outcome is not an oracle for dirty PD backing.

## Initial smoke failure

The first smoke stopped at the original zone growth path `16b3df` during the second create. The malformed synthetic zone had `+0xc=PM0` and `+0x10=PM1`, so allocation consumed PM1 first and exhausted the reachable chain. The recorded failure is retained in `failed-create-slot1-zone-seed.json`; `zone-seed-failure-identity.json` pins the pre-correction runner hash and exact input distinction.

Root checked `16b3b7..16b3ce`, `16b8b3..16b8d7` and Darwin zalloc.h/c. Before applying the correction, the independent reviewer confirmed:

- `+0xc` is last_insert hint, not tail; `+0x10` is free_elements head.
- With `PM0→PM1→0`, initial `last_insert=PM1, free_elements=PM0` is valid. Both pointers become zero after the second allocation.
- On returning PM1 before PM0, the final last_insert is PM0, not PM1. The hint follows the most recent insertion, not the largest address.

The seed was corrected and the emulator is restarted fresh. No original code, allocation failure branch, returned value or live ownership was patched. This is a fixture error, not an OPENSTEP kernel bug.

## Flag naming boundary

The inherited Python parameter `sleepable` writes bit0 at zone+0x2c. Original code uses that bit for the complex-lock branch; preserved Darwin zalloc.h calls it `pageable`, with `sleepable` in bit1. This report retains the legacy parameter key for reference equality but does not claim it tests the actual sleep-if-empty flag. Earlier reports are preserved unchanged.

## Lifetime model and coherent stale-mapping counterexample

Before lifetime-model coding, the reviewer confirmed the planned slot/count/bitmap/queue model, complete kernel-PDE copy checks, stale free-zone fields and dirty backing path. Root independently enumerated the original writes and observed three physical PG lookups in final GC, including two from dirty-PTE processing.

Post-coding review found a substantive hole: changing the final two `18fcd8` zero stores into present writable PTEs, and coherently updating following raw PTE/walk snapshots, still passed the initial audit. Root reproduced this exact accepted record corruption. This was an auditor defect, not an observed original-kernel stale mapping.

The corrected audit checks the complete inverse-overlap write policy for both backing PTEs, their exact zero stores and ESI addresses, descriptor owner/backlink removal, correct physical mappings while allocated, and zero/NP mappings after GC. The coherent mutation is now a negative control. The reviewer read-only rechecked all normal cases and rejection of the reported mapping/address mutations, without finding another mandatory issue in this stated narrow scope.

Common wired-allocation endpoint fields are compared with the preserved independently audited report31 path. This comparison is explicitly distinguished from a newly written full CPU semantics model. Native PD activation, concurrency and allocator exhaustion are not established here.
