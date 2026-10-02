# x86 `ipc/ipc_notify.c` (Mach4) and `mach/notify.h` (S5-P30, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Mach4
(https://github.com/openmach/mach4.git 69fa77870f20d854c875135e116ebc80b118e7ff) `kernel/ipc/ipc_notify.c` verbatim; `mach/notify.h` = Darwin header with Mach4 typedefs
(diff `x86-notify_h.diff`). Plan 56, 56.1, 56.2.

- Original `__text` [0x14af44, 0x14b842) 2302 B, 16 functions — same names and order as Mach4 (Darwin has a different
  set); `__data` 346 B at 0x1de754 (nine drop-diagnostic strings); `__common` templates 0x1f6270.. (32 B x 5, 24 B).
  Gaps: front 2 x `00` (after `_ipc_mqueue_receive` 0x14af42), back 2 x `00` (next `_ipc_object_reference` 0x14b844).
- Old (typed) notification format in the original: `_ipc_notify_init_port_deleted` writes `msgh_size` 0x20,
  `msgh_seqno` 1 (`NOTIFY_MSGH_SEQNO` = `MSG_TYPE_EMERGENCY` under `MACH_IPC_COMPAT`), `mach_msg_type_t` at +0x18.
- Probes: Mach4 file with Darwin notify.h fails; with Mach4 notify.h needs the `ipc_kmsg.h` macro fix (plan 55.0);
  probe 3 (Mach4 notify.h) and probe 4 (hybrid notify.h, chosen as smaller) give identical objects; `kern_notify`
  unchanged with either header.
- Final 07_kernel build `s5p30-build-1`: `.i` with and without `-fno-common` identical; `-O3` (`75e40452d68bd776114b6ebe22c7e51bf551ab812e68df9bf6e050690759b280`) and variant
  (`139cef5f70ffcccac91ee8d69bbbb108a92938e60ffc0b867295af5033f52fc0`) equal probe 4; variant OBJECT_MATCH 16/16 (127 references), `-fno-common` 0 byte / 0 reference differences;
  127 relocation sites correspond (65 differ only scattered-VANILLA-into-`__common` vs external, same type); bytes
  outside fields equal; template sizes = original gaps. `-O2` differs. Grade **A**.
- Regression `s5p30-regress-1`: 48/48 identical.
