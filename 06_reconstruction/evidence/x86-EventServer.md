# x86 `src/driverkit/libDriver/EventServer.c` (plan 343 (S5-P332), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 343 (S5-P332). Final run `s5p343-mev1`; 07 file SHA-256 `272df0442390acb773bc09f6c127e12d0b0f335927d60a9595f601973fc22ac7`; diff `x86-EventServer.diff`.

- Object [0x1bee8c, 0x1bf3fc) 1392 B, 10 functions (_Event_server, (static _XEvOpen), (static _XEvClose), (static _XEvMapEventShmem), (static _XEvFrameBufferDevicePort), (static _XEvSetSpecialKeyPort), (static _XEvGetParameterInt), (static _XEvGetParameterChar), (static _XEvSetParameterInt), (static _XEvSetParameterChar)). Front `ec 5d c3 00`, back `55 89 e5 56`, next symbol 0x1bf3fc.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p343-mev1-l1-EventServer-F-20261002.json`). Grade **A**.

MIG output of Kernel/Event.defs (s5p343-mig2). Diagnostics s5p345-migd1 and s5p345-ev1/au1/ar1 gave the same bytes and OBJECT_MATCH. Codex review of plan 343 (gpt-6.1-sol) verified (mach/msg_type.h adoption added). s5p343-mev1 from 07: OBJECT_MATCH, relcheck 0.

Input provenance (plan 407, 2026-10-08): `src/driverkit/libDriver/Kernel/Event.defs` (SHA-256 `cbaf090903ca6d9f146b4ca21b6f662cf851718fc750dfb9f50421cfc60a08bb`) is the D030 copy authored in plan 343; it is nearly the same as Darwin 0.1 driverkit-1/libDriver/Kernel/Event.defs (`driverkit-139.1-1.tar.gz` SHA-256 `255235626e702fe52b28564c0bc5644a686f1e886697f1c567b6a4275bc43102`, file SHA-256 `361d8cd44fd88e10b769af559c71553cc26a29c05591f344a6cb531e2fb60d1e`): python difflib shows only the leading notice and description comments replaced by the project head comment, body verbatim; Darwin notices not included (D017). Its PROVENANCE.tsv and MODIFICATIONS.md rows were missing since plan 343 and were added in plan 407.
