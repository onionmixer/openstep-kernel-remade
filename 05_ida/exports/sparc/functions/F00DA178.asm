F00DA178: 9de3bf90                 save    %sp, -0x70, %sp
F00DA17C: d006204c                 ld      [%i0+0x4C], %o0
F00DA180: 80a22000                 cmp     %o0, 0
F00DA184: 12800014                 bne     locret_F00DA1D4
F00DA188: 01000000                 nop
F00DA18C: d04e2020                 ldsb    [%i0+0x20], %o0
F00DA190: 80a22000                 cmp     %o0, 0
F00DA194: 22800005                 be,a    loc_F00DA1A8
F00DA198: 113c04bb                 sethi   -0xFED1400, %o0
F00DA19C: 113c04bb                 sethi   %hi(_AudioIn_dmaBuf), %o0
F00DA1A0: 10800003                 ba      loc_F00DA1AC
F00DA1A4: d002231c                 ld      [%o0+%lo(_AudioIn_dmaBuf)], %o0
F00DA1A8: d0022328                 ld      [%o0+0x328], %o0
F00DA1AC: d026204c                 st      %o0, [%i0+0x4C]
F00DA1B0: d406204c                 ld      [%i0+0x4C], %o2
F00DA1B4: 113c04bb                 sethi   %hi(dword_F012EF34), %o0
F00DA1B8: d206204c                 ld      [%i0+0x4C], %o1
F00DA1BC: d4222334                 st      %o2, [%o0+%lo(dword_F012EF34)]
F00DA1C0: d2262048                 st      %o1, [%i0+0x48]
F00DA1C4: 113c0505                 sethi   %hi(paInitializefree), %o0! id
F00DA1C8: d20220a4                 ld      [%o0+%lo(paInitializefree)], %o1! SEL
F00DA1CC: 40005da9                 call    _objc_msgSend
F00DA1D0: 90100018                 mov     %i0, %o0
F00DA1D4: 81c7e008                 ret
F00DA1D8: 91e82001                 restore %g0, 1, %o0
