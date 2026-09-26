F004C240: 9de3bf98                 save    %sp, -0x68, %sp
F004C244: a0100018                 mov     %i0, %l0
F004C248: d2042030                 ld      [%l0+0x30], %o1
F004C24C: d0072030                 ld      [%i4+0x30], %o0
F004C250: 80a24008                 cmp     %o1, %o0
F004C254: 12800034                 bne     locret_F004C324
F004C258: b0102012                 mov     0x12, %i0
F004C25C: d0172064                 lduh    [%i4+0x64], %o0
F004C260: 1300003c                 sethi   0xF000, %o1
F004C264: 900a0009                 and     %o0, %o1, %o0
F004C268: 13000010                 sethi   0x4000, %o1
F004C26C: 80a20009                 cmp     %o0, %o1
F004C270: 1280000a                 bne     loc_F004C298
F004C274: 90100010                 mov     %l0, %o0
F004C278: 9010001c                 mov     %i4, %o0
F004C27C: 9210001d                 mov     %i5, %o1
F004C280: 7fffff24                 call    sub_F004BF10
F004C284: 94100010                 mov     %l0, %o2
F004C288: 80a22000                 cmp     %o0, 0
F004C28C: 12800026                 bne     locret_F004C324
F004C290: b0100008                 mov     %o0, %i0
F004C294: 90100010                 mov     %l0, %o0
F004C298: 40000025                 call    sub_F004C32C
F004C29C: 9210001b                 mov     %i3, %o1
F004C2A0: 80a22000                 cmp     %o0, 0
F004C2A4: 12800020                 bne     locret_F004C324
F004C2A8: b0100008                 mov     %o0, %i0
F004C2AC: 92100019                 mov     %i1, %o1! __src
F004C2B0: d006e010                 ld      [%i3+0x10], %o0
F004C2B4: 9406a004                 add     %i2, 4, %o2
F004C2B8: f4322006                 sth     %i2, [%o0+6]
F004C2BC: d006e010                 ld      [%i3+0x10], %o0! __dst
F004C2C0: 940abffc                 and     %o2, -4, %o2! __n
F004C2C4: 7ffeed96                 call    _strncpy
F004C2C8: 90022008                 inc     8, %o0
F004C2CC: 9004200c                 add     %l0, 0xC, %o0
F004C2D0: d806e010                 ld      [%i3+0x10], %o4
F004C2D4: 92100019                 mov     %i1, %o1
F004C2D8: d6072048                 ld      [%i4+0x48], %o3
F004C2DC: 9407200c                 add     %i4, 0xC, %o2
F004C2E0: d6230000                 st      %o3, [%o4]
F004C2E4: 7fff651e                 call    _dnlc_enter
F004C2E8: 96102000                 mov     0, %o3
F004C2EC: 7fff611f                 call    _bwrite
F004C2F0: d006e00c                 ld      [%i3+0xC], %o0
F004C2F4: c026e00c                 clr     [%i3+0xC]
F004C2F8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004C2FC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004C300: f04a2038                 ldsb    [%o0+0x38], %i0
F004C304: 80a62000                 cmp     %i0, 0
F004C308: 12800007                 bne     locret_F004C324
F004C30C: 01000000                 nop
F004C310: c024204c                 clr     [%l0+0x4C]
F004C314: d0142044                 lduh    [%l0+0x44], %o0
F004C318: b0102000                 mov     0, %i0
F004C31C: 90122042                 bset    0x42, %o0 ! 'B'
F004C320: d0342044                 sth     %o0, [%l0+0x44]
F004C324: 81c7e008                 ret
F004C328: 81e80000                 restore
