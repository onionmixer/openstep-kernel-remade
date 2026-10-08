# x86 `src/driverkit/libDriver/audioReplyUser.c` (plan 343 (S5-P332), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 343 (S5-P332). Final run `s5p343-mar1`; 07 file SHA-256 `969e91d88b3b9ada78071146f2505e25b89189f27c1cf053fb825c9feebbbf90`; diff `x86-audioReplyUser.diff`.

- Object [0x1c07d8, 0x1c0918) 320 B, 2 functions (__NXAudioReplyStreamStatus, __NXAudioReplyRecordedData). Front `c3 00 00 00`, back `55 89 e5 c7`, next symbol 0x1c0918.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p343-mar1-l1-audioReplyUser-F-20261002.json`). Grade **A**.

MIG output of Kernel/audioReply.defs (s5p343-mig3). Diagnostics s5p345-migd1 and s5p345-ev1/au1/ar1 gave the same bytes and OBJECT_MATCH. Codex review of plan 343 (gpt-6.1-sol) verified (mach/msg_type.h adoption added). s5p343-mar1 from 07: OBJECT_MATCH, relcheck 0.
