F00C7DC0: 9de3bf90                 save    %sp, -0x70, %sp
F00C7DC4: 90100018                 mov     %i0, %o0! id
F00C7DC8: b52ea018                 sll     %i2, 24, %i2
F00C7DCC: 80a0001a                 cmp     %g0, %i2
F00C7DD0: 92402000                 addc    %g0, 0, %o1
F00C7DD4: d22a21aa                 stb     %o1, [%o0+0x1AA]
F00C7DD8: 13003fff                 sethi   0xFFFC00, %o1
F00C7DDC: d40221a8                 ld      [%o0+0x1A8], %o2
F00C7DE0: 92126300                 bset    0x300, %o1
F00C7DE4: 940a8009                 and     %o2, %o1, %o2
F00C7DE8: 80a0000a                 cmp     %g0, %o2
F00C7DEC: 133c0506                 sethi   %hi(paSetinstanceope), %o1
F00C7DF0: d2026140                 ld      [%o1+%lo(paSetinstanceope)], %o1! SEL
F00C7DF4: 4000a69f                 call    _objc_msgSend
F00C7DF8: 94402000                 addc    %g0, 0, %o2
F00C7DFC: 81c7e008                 ret
F00C7E00: 81e80000                 restore
