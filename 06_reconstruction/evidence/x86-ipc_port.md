# x86 `ipc/ipc_port.c` (S5-P29, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/ipc/ipc_port.c` with restoration edits incl. a Mach4 block (diff `x86-ipc_port.diff`); headers `ipc_kmsg.h`
(diff `x86-ipc_kmsg_h.diff`) and `ipc_port.h` (diff `x86-ipc_port_h.diff`). Plan 55, 55.0, 55.1, 55.2.

- Original `__text` [0x14c454, 0x14d61a) 4550 B, 29 functions incl. `_ipc_port_lock_mqueue` (0x14c748, Mach4 only);
  `__common` `_ipc_port_multiple_lock_data`/`_timestamp_data`/`_timestamp_lock_data` 4 B each. Gaps: front 0
  (ipc_object ends at 0x14c454), back 2 x `00`.
- Probes (staging only): 1 (one-argument dngrow) 4366 B; 2 (+Mach4 lock_mqueue/set_seqno, +oits=0) 4550 B 26 MATCH;
  3 (+mscount=0, both kmsg fields removed) destroy overshoots (+0x18); 4 (+mscount=0, only `ikm_sender` removed)
  variant OBJECT_MATCH 29/29.
- `struct ipc_kmsg`: `ikm_header` +0x14, `ikm_delta` +0x10 (written by `_ipc_kmsg_get`, cleared by `_ipc_kmsg_put`,
  added to `msgh_size` in mach_msg paths); Darwin `security_id_t ikm_sender` (8 B) absent in the original.
- Final 07_kernel build `s5p29-build-1`: `.i` with and without `-fno-common` identical; `-O3` (`2454e555ec63b3b129b29ac09f5fed499d10edc4cf63615ecdc55e3099e433dc`) and variant
  (`4d5070a91d3b8f5159d80330f421277e892360c3186f0b407918185f548bc599`) equal the probe-4 objects; variant OBJECT_MATCH 29/29, `-fno-common` 0 byte / 0 reference differences;
  101 relocations correspond, bytes outside fields equal; commons 4 B = gaps. `-O2` differs. Grade **A**.
- Regression after the header edits `s5p29-regress-1`: 47/47 identical.
- Callers of the old Darwin API/fields still to adapt when adopted: `ipc_notify.c` (`ikm_sender`), `ipc_kmsg.c`,
  `ipc_right.c` (dngrow one argument).
