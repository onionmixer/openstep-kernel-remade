F00C79C0: 9de3bf90                 save    %sp, -0x70, %sp
F00C79C4: 113c0506                 sethi   %hi(paPhysicaldisk_0), %o0! id
F00C79C8: d2022164                 ld      [%o0+%lo(paPhysicaldisk_0)], %o1! SEL
F00C79CC: 4000a7a9                 call    _objc_msgSend
F00C79D0: 90100018                 mov     %i0, %o0
F00C79D4: a0100008                 mov     %o0, %l0
F00C79D8: 90100018                 mov     %i0, %o0! id
F00C79DC: 133c0506                 sethi   %hi(paChecksafeconfi), %o1
F00C79E0: 153c03eb                 sethi   %hi(aEject), %o2! "eject"
F00C79E4: d202615c                 ld      [%o1+%lo(paChecksafeconfi)], %o1! SEL
F00C79E8: 4000a7a2                 call    _objc_msgSend
F00C79EC: 9412a1e0                 bset    %lo(aEject), %o2! "eject"
F00C79F0: 80a22000                 cmp     %o0, 0
F00C79F4: 1280001e                 bne     locret_F00C7A6C
F00C79F8: 01000000                 nop
F00C79FC: 113c0506                 sethi   %hi(paFreepartitions), %o0! id
F00C7A00: d2022154                 ld      [%o0+%lo(paFreepartitions)], %o1! SEL
F00C7A04: 4000a79b                 call    _objc_msgSend
F00C7A08: 90100018                 mov     %i0, %o0
F00C7A0C: c02e21a8                 clrb    [%i0+0x1A8]
F00C7A10: f027bff0                 st      %i0, [%fp+var_10]
F00C7A14: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C7A18: 133c0507                 sethi   %hi(stru_F0141F0C.ext), %o1
F00C7A1C: d6026338                 ld      [%o1+%lo(stru_F0141F0C.ext)], %o3
F00C7A20: 94102000                 mov     0, %o2
F00C7A24: 133c0506                 sethi   %hi(paSetformattedin), %o1
F00C7A28: d20261ac                 ld      [%o1+%lo(paSetformattedin)], %o1! SEL
F00C7A2C: 4000a7d4                 call    _objc_msgSendSuper
F00C7A30: d627bff4                 st      %o3, [%fp+var_C]
F00C7A34: 113c0506                 sethi   %hi(paNeedsmanualpol), %o0! id
F00C7A38: d2022148                 ld      [%o0+%lo(paNeedsmanualpol)], %o1! SEL
F00C7A3C: 4000a78d                 call    _objc_msgSend
F00C7A40: 90100010                 mov     %l0, %o0
F00C7A44: 912a2018                 sll     %o0, 24, %o0
F00C7A48: 80a22000                 cmp     %o0, 0
F00C7A4C: 22800005                 be,a    loc_F00C7A60
F00C7A50: 113c0506                 sethi   -0xFEBE800, %o0
F00C7A54: 7fff31fc                 call    _vol_check_manual_poll
F00C7A58: 01000000                 nop
F00C7A5C: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C7A60: d2022144                 ld      [%o0+0x144], %o1! SEL
F00C7A64: 4000a783                 call    _objc_msgSend
F00C7A68: 90100010                 mov     %l0, %o0
F00C7A6C: 81c7e008                 ret
F00C7A70: 91e80008                 restore %g0, %o0, %o0
