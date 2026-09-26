F00CB694: 9de3bf88                 save    %sp, -0x78, %sp
F00CB698: d0062130                 ld      [%i0+0x130], %o0
F00CB69C: 80a22000                 cmp     %o0, 0
F00CB6A0: 12800008                 bne     loc_F00CB6C0
F00CB6A4: 01000000                 nop
F00CB6A8: d0062134                 ld      [%i0+0x134], %o0
F00CB6AC: 80a22000                 cmp     %o0, 0
F00CB6B0: 12800004                 bne     loc_F00CB6C0
F00CB6B4: 01000000                 nop
F00CB6B8: 1080001c                 ba      locret_F00CB728
F00CB6BC: b0102000                 mov     0, %i0
F00CB6C0: 7fffea87                 call    _IOGetTimestamp
F00CB6C4: 9007bfe8                 add     %fp, var_18, %o0
F00CB6C8: d2062130                 ld      [%i0+0x130], %o1
F00CB6CC: d007bfe8                 ld      [%fp+var_18], %o0
F00CB6D0: 80a24008                 cmp     %o1, %o0
F00CB6D4: 3880000d                 bgu,a   loc_F00CB708
F00CB6D8: d01e2130                 ldd     [%i0+0x130], %o0
F00CB6DC: 12800006                 bne     loc_F00CB6F4
F00CB6E0: d007bfec                 ld      [%fp+var_18+4], %o0
F00CB6E4: d2062134                 ld      [%i0+0x134], %o1
F00CB6E8: 80a24008                 cmp     %o1, %o0
F00CB6EC: 38800007                 bgu,a   loc_F00CB708
F00CB6F0: d01e2130                 ldd     [%i0+0x130], %o0
F00CB6F4: 84102000                 mov     0, %g2
F00CB6F8: 86102000                 mov     0, %g3
F00CB6FC: c43e2130                 std     %g2, [%i0+0x130]
F00CB700: 1080000a                 ba      locret_F00CB728
F00CB704: b0102000                 mov     0, %i0
F00CB708: 170003d0                 sethi   0xF4000, %o3
F00CB70C: 94102000                 mov     0, %o2
F00CB710: d81fbfe8                 ldd     [%fp+var_18], %o4
F00CB714: 92a2400d                 subcc   %o1, %o5, %o1
F00CB718: 9062000c                 subc    %o0, %o4, %o0
F00CB71C: 7ffce9b5                 call    __udivdi3
F00CB720: 9612e240                 bset    0x240, %o3
F00CB724: b0100009                 mov     %o1, %i0
F00CB728: 81c7e008                 ret
F00CB72C: 81e80000                 restore
