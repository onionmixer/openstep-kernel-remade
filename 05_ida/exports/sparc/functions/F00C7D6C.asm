F00C7D6C: 9de3bf90                 save    %sp, -0x70, %sp
F00C7D70: 90100018                 mov     %i0, %o0! id
F00C7D74: b52ea018                 sll     %i2, 24, %i2
F00C7D78: 80a0001a                 cmp     %g0, %i2
F00C7D7C: 92402000                 addc    %g0, 0, %o1
F00C7D80: d22a21a9                 stb     %o1, [%o0+0x1A9]
F00C7D84: 13003fff                 sethi   0xFFFC00, %o1
F00C7D88: d40221a8                 ld      [%o0+0x1A8], %o2
F00C7D8C: 92126300                 bset    0x300, %o1
F00C7D90: 940a8009                 and     %o2, %o1, %o2
F00C7D94: 80a0000a                 cmp     %g0, %o2
F00C7D98: 133c0506                 sethi   %hi(paSetinstanceope), %o1
F00C7D9C: d2026140                 ld      [%o1+%lo(paSetinstanceope)], %o1! SEL
F00C7DA0: 4000a6b4                 call    _objc_msgSend
F00C7DA4: 94402000                 addc    %g0, 0, %o2
F00C7DA8: 81c7e008                 ret
F00C7DAC: 81e80000                 restore
