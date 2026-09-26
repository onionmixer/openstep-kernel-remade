F00C09D4: 9de3bf90                 save    %sp, -0x70, %sp
F00C09D8: 9010001a                 mov     %i2, %o0! id
F00C09DC: 133c0504                 sethi   %hi(paConformsto), %o1
F00C09E0: d2026018                 ld      [%o1+%lo(paConformsto)], %o1! SEL
F00C09E4: 153c0516                 sethi   %hi(stru_F01458FC), %o2
F00C09E8: 4000c3a2                 call    _objc_msgSend
F00C09EC: 9412a0fc                 bset    %lo(stru_F01458FC), %o2
F00C09F0: 912a2018                 sll     %o0, 24, %o0
F00C09F4: 80a22000                 cmp     %o0, 0
F00C09F8: 3280000b                 bne,a   loc_F00C0A24
F00C09FC: f4262128                 st      %i2, [%i0+0x128]
F00C0A00: 9010001a                 mov     %i2, %o0! id
F00C0A04: 213c0483                 sethi   %hi(aPcpointerSetev), %l0! "PCPointer setEventTarget: new target [%"...
F00C0A08: 4000b9e0                 call    _object_getClassName
F00C0A0C: a0142190                 bset    %lo(aPcpointerSetev), %l0! "PCPointer setEventTarget: new target [%"...
F00C0A10: 92100008                 mov     %o0, %o1
F00C0A14: 400015b8                 call    _IOLog
F00C0A18: 90100010                 mov     %l0, %o0
F00C0A1C: 10800003                 ba      locret_F00C0A28
F00C0A20: b0102000                 mov     0, %i0
F00C0A24: b0102001                 mov     1, %i0
F00C0A28: 81c7e008                 ret
F00C0A2C: 81e80000                 restore
