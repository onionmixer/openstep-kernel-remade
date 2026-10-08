# x86 `src/driverkit/libDriver/EventServer.c` (plan 343 (S5-P332), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 343 (S5-P332). Final run `s5p343-mev1`; 07 file SHA-256 `272df0442390acb773bc09f6c127e12d0b0f335927d60a9595f601973fc22ac7`; diff `x86-EventServer.diff`.

- Object [0x1bee8c, 0x1bf3fc) 1392 B, 10 functions (_Event_server, (static _XEvOpen), (static _XEvClose), (static _XEvMapEventShmem), (static _XEvFrameBufferDevicePort), (static _XEvSetSpecialKeyPort), (static _XEvGetParameterInt), (static _XEvGetParameterChar), (static _XEvSetParameterInt), (static _XEvSetParameterChar)). Front `ec 5d c3 00`, back `55 89 e5 56`, next symbol 0x1bf3fc.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p343-mev1-l1-EventServer-F-20261002.json`). Grade **A**.

MIG output of Kernel/Event.defs (s5p343-mig2). Diagnostics s5p345-migd1 and s5p345-ev1/au1/ar1 gave the same bytes and OBJECT_MATCH. Codex review of plan 343 (gpt-6.1-sol) verified (mach/msg_type.h adoption added). s5p343-mev1 from 07: OBJECT_MATCH, relcheck 0.
