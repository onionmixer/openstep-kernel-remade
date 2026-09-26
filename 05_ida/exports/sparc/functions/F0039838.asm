F0039838: 9de3bf90                 save    %sp, -0x70, %sp
F003983C: e0062030                 ld      [%i0+0x30], %l0
F0039840: 7fff65d3                 call    _getthetime
F0039844: 9007bff0                 add     %fp, var_10, %o0
F0039848: d207bff0                 ld      [%fp+var_10], %o1
F003984C: d00420c0                 ld      [%l0+0xC0], %o0
F0039850: 80a24008                 cmp     %o1, %o0
F0039854: 2680000a                 bl,a    loc_F003987C
F0039858: 90100019                 mov     %i1, %o0
F003985C: 32800022                 bne,a   locret_F00398E4
F0039860: b0102000                 mov     0, %i0
F0039864: d207bff4                 ld      [%fp+var_C], %o1
F0039868: d00420c4                 ld      [%l0+0xC4], %o0
F003986C: 80a24008                 cmp     %o1, %o0
F0039870: 3680001d                 bge,a   locret_F00398E4
F0039874: b0102000                 mov     0, %i0
F0039878: 90100019                 mov     %i1, %o0! __dst
F003987C: 92042080                 add     %l0, 0x80, %o1! __src
F0039880: 7fff3688                 call    _memcpy
F0039884: 94102040                 mov     0x40, %o2 ! '@'
F0039888: d0062024                 ld      [%i0+0x24], %o0
F003988C: d2022128                 ld      [%o0+0x128], %o1
F0039890: 1100003f                 sethi   0xFC00, %o0
F0039894: d2026028                 ld      [%o1+0x28], %o1
F0039898: 90122300                 bset    0x300, %o0
F003989C: 92124008                 bset    %o0, %o1
F00398A0: d226600c                 st      %o1, [%i1+0xC]
F00398A4: f0060000                 ld      [%i0], %i0
F00398A8: d0066018                 ld      [%i1+0x18], %o0
F00398AC: d4062014                 ld      [%i0+0x14], %o2
F00398B0: 80a2000a                 cmp     %o0, %o2
F00398B4: 1a80000b                 bcc     loc_F00398E0
F00398B8: 11100000                 sethi   0x40000000, %o0
F00398BC: d2062038                 ld      [%i0+0x38], %o1
F00398C0: 808a4008                 btst    %o0, %o1
F00398C4: 32800007                 bne,a   loc_F00398E0
F00398C8: d4266018                 st      %o2, [%i1+0x18]
F00398CC: d0142060                 lduh    [%l0+0x60], %o0
F00398D0: 808a2010                 btst    0x10, %o0
F00398D4: 02800004                 be      locret_F00398E4
F00398D8: b0102001                 mov     1, %i0
F00398DC: d4266018                 st      %o2, [%i1+0x18]
F00398E0: b0102001                 mov     1, %i0
F00398E4: 81c7e008                 ret
F00398E8: 81e80000                 restore
