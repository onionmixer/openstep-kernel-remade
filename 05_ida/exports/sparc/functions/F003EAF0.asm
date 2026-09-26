F003EAF0: 9de3bf98                 save    %sp, -0x68, %sp
F003EAF4: e0062128                 ld      [%i0+0x128], %l0
F003EAF8: 7ffffa78                 call    _rflush
F003EAFC: 90100018                 mov     %i0, %o0
F003EB00: 7ffffa4c                 call    _rinval
F003EB04: 90100018                 mov     %i0, %o0
F003EB08: d0042018                 ld      [%l0+0x18], %o0
F003EB0C: 80a22001                 cmp     %o0, 1
F003EB10: 1280001c                 bne     locret_F003EB80
F003EB14: b0102010                 mov     0x10, %i0
F003EB18: d2042010                 ld      [%l0+0x10], %o1
F003EB1C: d0126006                 lduh    [%o1+6], %o0
F003EB20: 80a22001                 cmp     %o0, 1
F003EB24: 12800017                 bne     locret_F003EB80
F003EB28: 01000000                 nop
F003EB2C: 7ffff940                 call    _rp_rmhash
F003EB30: d0026030                 ld      [%o1+0x30], %o0
F003EB34: d0042010                 ld      [%l0+0x10], %o0
F003EB38: 7ffff9d3                 call    _rinactive
F003EB3C: d0022030                 ld      [%o0+0x30], %o0
F003EB40: 7fffa809                 call    _vn_rele
F003EB44: d0042010                 ld      [%l0+0x10], %o0
F003EB48: 113c04bd                 sethi   %hi(unk_F012F4F4), %o0
F003EB4C: d2042028                 ld      [%l0+0x28], %o1
F003EB50: 7fff9666                 call    _vfs_putnum
F003EB54: 901220f4                 bset    %lo(unk_F012F4F4), %o0
F003EB58: d2042058                 ld      [%l0+0x58], %o1
F003EB5C: 80a26000                 cmp     %o1, 0
F003EB60: 06800005                 bl      loc_F003EB74
F003EB64: 90100010                 mov     %l0, %o0
F003EB68: 4000a58e                 call    _kfree
F003EB6C: d0042054                 ld      [%l0+0x54], %o0
F003EB70: 90100010                 mov     %l0, %o0
F003EB74: 4000a58b                 call    _kfree
F003EB78: 92102070                 mov     0x70, %o1 ! 'p'
F003EB7C: b0102000                 mov     0, %i0
F003EB80: 81c7e008                 ret
F003EB84: 81e80000                 restore
