F00C47A0: 9de3bf98                 save    %sp, -0x68, %sp
F00C47A4: 213c04cc                 sethi   %hi(dword_F013304C), %l0
F00C47A8: d004204c                 ld      [%l0+%lo(dword_F013304C)], %o0! id
F00C47AC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C47B0: 4000b430                 call    _objc_msgSend
F00C47B4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C47B8: 113c04cc                 sethi   %hi(dword_F0133044), %o0
F00C47BC: d2022044                 ld      [%o0+%lo(dword_F0133044)], %o1
F00C47C0: 90122044                 bset    %lo(dword_F0133044), %o0
F00C47C4: 80a24008                 cmp     %o1, %o0
F00C47C8: 02800011                 be      loc_F00C480C
F00C47CC: 96100010                 mov     %l0, %o3
F00C47D0: 193c0504                 sethi   -0xFEBF000, %o4
F00C47D4: 94100008                 mov     %o0, %o2
F00C47D8: d0024000                 ld      [%o1], %o0
F00C47DC: 80a20018                 cmp     %o0, %i0
F00C47E0: 32800008                 bne,a   loc_F00C4800
F00C47E4: d2026014                 ld      [%o1+0x14], %o1! SEL
F00C47E8: d2264000                 st      %o1, [%i1]
F00C47EC: d002e04c                 ld      [%o3+0x4C], %o0! id
F00C47F0: 4000b420                 call    _objc_msgSend
F00C47F4: d2032244                 ld      [%o4+0x244], %o1
F00C47F8: 1080000b                 ba      locret_F00C4824
F00C47FC: b0102000                 mov     0, %i0
F00C4800: 80a2400a                 cmp     %o1, %o2
F00C4804: 32bffff6                 bne,a   loc_F00C47DC
F00C4808: d0024000                 ld      [%o1], %o0
F00C480C: 113c04cc                 sethi   %hi(dword_F013304C), %o0
F00C4810: d002204c                 ld      [%o0+%lo(dword_F013304C)], %o0! id
F00C4814: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C4818: 4000b416                 call    _objc_msgSend
F00C481C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C4820: b0103d29                 mov     -0x2D7, %i0
F00C4824: 81c7e008                 ret
F00C4828: 81e80000                 restore
