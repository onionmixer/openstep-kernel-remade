F00479B8: 9de3bf90                 save    %sp, -0x70, %sp
F00479BC: 40009b05                 call    _microtime
F00479C0: 9007bff0                 add     %fp, var_10, %o0
F00479C4: d0162040                 lduh    [%i0+0x40], %o0
F00479C8: 808e6004                 btst    4, %i1
F00479CC: 90120019                 bset    %i1, %o0
F00479D0: 02800006                 be      loc_F00479E8
F00479D4: d0362040                 sth     %o0, [%i0+0x40]
F00479D8: d007bff0                 ld      [%fp+var_10], %o0
F00479DC: d026204c                 st      %o0, [%i0+0x4C]
F00479E0: d007bff4                 ld      [%fp+var_C], %o0
F00479E4: d0262050                 st      %o0, [%i0+0x50]
F00479E8: 808e6002                 btst    2, %i1
F00479EC: 02800005                 be      loc_F0047A00
F00479F0: d007bff0                 ld      [%fp+var_10], %o0
F00479F4: d0262054                 st      %o0, [%i0+0x54]
F00479F8: d007bff4                 ld      [%fp+var_C], %o0
F00479FC: d0262058                 st      %o0, [%i0+0x58]
F0047A00: 808e6040                 btst    0x40, %i1 ! '@'
F0047A04: 02800005                 be      locret_F0047A18
F0047A08: d007bff0                 ld      [%fp+var_10], %o0
F0047A0C: d026205c                 st      %o0, [%i0+0x5C]
F0047A10: d007bff4                 ld      [%fp+var_C], %o0
F0047A14: d0262060                 st      %o0, [%i0+0x60]
F0047A18: 81c7e008                 ret
F0047A1C: 81e80000                 restore
