F0083B58: 9de3bf98                 save    %sp, -0x68, %sp! int
F0083B5C: d0062024                 ld      [%i0+0x24], %o0
F0083B60: 133c04f0                 sethi   %hi(_kernel_pmap), %o1
F0083B64: d2026100                 ld      [%o1+%lo(_kernel_pmap)], %o1! void *
F0083B68: 80a20009                 cmp     %o0, %o1
F0083B6C: 12800007                 bne     loc_F0083B88
F0083B70: 9410001b                 mov     %i3, %o2! int
F0083B74: 90100019                 mov     %i1, %o0! void *
F0083B78: 400043e6                 call    _bcopy
F0083B7C: 9210001a                 mov     %i2, %o1! int
F0083B80: 1080000d                 ba      locret_F0083BB4
F0083B84: b0102000                 mov     0, %i0
F0083B88: 113c04d0                 sethi   %hi(_active_threads), %o0
F0083B8C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0083B90: d002200c                 ld      [%o0+0xC], %o0
F0083B94: d002200c                 ld      [%o0+0xC], %o0
F0083B98: 80a20018                 cmp     %o0, %i0
F0083B9C: 12800006                 bne     locret_F0083BB4
F0083BA0: b0102001                 mov     1, %i0
F0083BA4: 90100019                 mov     %i1, %o0! int
F0083BA8: 40005149                 call    _copyout
F0083BAC: 9210001a                 mov     %i2, %o1
F0083BB0: b0100008                 mov     %o0, %i0
F0083BB4: 81c7e008                 ret
F0083BB8: 81e80000                 restore
