# x86 `src/driverkit/driverServerServer.c` (plan 344 (S5-P333), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 344 (S5-P333). Final run `s5p344-it1`; 07 file SHA-256 `dc81c4cb51dc2335309b9ee60327660166d0db9b8a32b12eca9bcd7aaed5caad`; diff `x86-driverServerServer.diff`.

- Object [0x1827f0, 0x183359) 2921 B, 21 functions ((static _X_IOGetEISADeviceConfig), _driverServer_server, _driverServer_server_routine, (static _X_IOLookupByObjectNumber), (static _X_IOLookupByDeviceName), (static _X_IOGetIntValues), (static _X_IOGetCharValues), (static _X_IOSetIntValues), (static _X_IOSetCharValues), (static _X_IOMapEISADevicePorts), (static _X_IOUnMapEISADevicePorts), (static _X_IOMapEISADeviceMemory), (static _X_IOProbeDriver), (static _X_IOGetSystemConfig), (static _X_IOUnloadDriver), (static _X_IOGetDriverConfig), (static _X_PMSetPowerState), (static _X_PMGetPowerEvent), (static _X_PMGetPowerStatus), (static _X_PMSetPowerManagement), (static _X_PMRestoreDefaults)). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x18335c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p344-it1-l1-driverServerServer-F-20261002.json`). Grade **A**.

MIG server for driverServer.defs (msg ids 2700..2738; original table 0x1e11c8, 19 routines = Darwin indices 18..38). Diagnostics s5p346-migd1..5, s5p346-ds2..ds5 (ds5 OBJECT_MATCH: -newipc and -DMACH_IPC_FLAVOR select msgh_request_port = msgh_remote_port, read at +8 in the original, and the server_routine function). Codex review of plan 344 (gpt-6.1-sol) verified (header adoptions added). s5p344-it1 from 07: OBJECT_MATCH, relcheck 0.

Header copies (plan 344, D030): 07_kernel/nextdev_private/driverkit/driverTypesPrivate.h,
nextdev_private/driverkit/i386/driverTypesPrivate.h and src/driverkit/driverServerXXX.h replace the
Darwin fallback that earlier builds read. Regression rebuilds s5p295-it2-rg1 (IODisplay), s5p325-it1-rg1
(autoconf_i386), s5p327-it2-rg1 (kmDevice), s5p331-it1-rg1 (PCPointer), s5p333-it1-rg1 (driverServerXXX)
and s5p340-it1-rg1 (kmLocalized) give the same section bytes, relocations and non-stab symbols as the
recorded runs (stab line numbers follow the head-comment length).

