F00CCAA0: 9de3bf88                 save    %sp, -0x78, %sp
F00CCAA4: d0062158                 ld      [%i0+0x158], %o0
F00CCAA8: 80a22000                 cmp     %o0, 0
F00CCAAC: 12800008                 bne     loc_F00CCACC
F00CCAB0: 01000000                 nop
F00CCAB4: d006215c                 ld      [%i0+0x15C], %o0
F00CCAB8: 80a22000                 cmp     %o0, 0
F00CCABC: 12800004                 bne     loc_F00CCACC
F00CCAC0: 01000000                 nop
F00CCAC4: 1080001c                 ba      locret_F00CCB34
F00CCAC8: b0102000                 mov     0, %i0
F00CCACC: 7fffe584                 call    _IOGetTimestamp
F00CCAD0: 9007bfe8                 add     %fp, var_18, %o0
F00CCAD4: d2062158                 ld      [%i0+0x158], %o1
F00CCAD8: d007bfe8                 ld      [%fp+var_18], %o0
F00CCADC: 80a24008                 cmp     %o1, %o0
F00CCAE0: 3880000d                 bgu,a   loc_F00CCB14
F00CCAE4: d01e2158                 ldd     [%i0+0x158], %o0
F00CCAE8: 12800006                 bne     loc_F00CCB00
F00CCAEC: d007bfec                 ld      [%fp+var_18+4], %o0
F00CCAF0: d206215c                 ld      [%i0+0x15C], %o1
F00CCAF4: 80a24008                 cmp     %o1, %o0
F00CCAF8: 38800007                 bgu,a   loc_F00CCB14
F00CCAFC: d01e2158                 ldd     [%i0+0x158], %o0
F00CCB00: 84102000                 mov     0, %g2
F00CCB04: 86102000                 mov     0, %g3
F00CCB08: c43e2158                 std     %g2, [%i0+0x158]
F00CCB0C: 1080000a                 ba      locret_F00CCB34
F00CCB10: b0102000                 mov     0, %i0
F00CCB14: 170003d0                 sethi   0xF4000, %o3
F00CCB18: 94102000                 mov     0, %o2
F00CCB1C: d81fbfe8                 ldd     [%fp+var_18], %o4
F00CCB20: 92a2400d                 subcc   %o1, %o5, %o1
F00CCB24: 9062000c                 subc    %o0, %o4, %o0
F00CCB28: 7ffce4b2                 call    __udivdi3
F00CCB2C: 9612e240                 bset    0x240, %o3
F00CCB30: b0100009                 mov     %o1, %i0
F00CCB34: 81c7e008                 ret
F00CCB38: 81e80000                 restore
