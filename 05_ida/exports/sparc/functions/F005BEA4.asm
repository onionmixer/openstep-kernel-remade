F005BEA4: 9de3bf98                 save    %sp, -0x68, %sp
F005BEA8: d0064000                 ld      [%i1], %o0
F005BEAC: 80a22000                 cmp     %o0, 0
F005BEB0: 12bffffe                 bne     loc_F005BEA8
F005BEB4: 01000000                 nop
F005BEB8: 4000ebfc                 call    _simple_lock_try
F005BEBC: 90100019                 mov     %i1, %o0
F005BEC0: 80a22000                 cmp     %o0, 0
F005BEC4: 02bffff9                 be      loc_F005BEA8
F005BEC8: 01000000                 nop
F005BECC: d0066008                 ld      [%i1+8], %o0
F005BED0: 80a22000                 cmp     %o0, 0
F005BED4: 16800004                 bge     loc_F005BEE4
F005BED8: 01000000                 nop
F005BEDC: 1080002d                 ba      locret_F005BF90
F005BEE0: b0102000                 mov     0, %i0
F005BEE4: c0264000                 clr     [%i1]
F005BEE8: e006c000                 ld      [%i3], %l0
F005BEEC: 11000040                 sethi   0x10000, %o0
F005BEF0: 808c0008                 btst    %o0, %l0
F005BEF4: 0280000e                 be      loc_F005BF2C
F005BEF8: 11000800                 sethi   0x200000, %o0
F005BEFC: 808c0008                 btst    %o0, %l0
F005BF00: 22800007                 be,a    loc_F005BF1C
F005BF04: 90100018                 mov     %i0, %o0
F005BF08: a02c0008                 bclr    %o0, %l0
F005BF0C: 90100018                 mov     %i0, %o0
F005BF10: 7ffff018                 call    _ipc_marequest_cancel
F005BF14: 9210001a                 mov     %i2, %o1
F005BF18: 90100018                 mov     %i0, %o0
F005BF1C: 92100019                 mov     %i1, %o1
F005BF20: 9410001a                 mov     %i2, %o2
F005BF24: 7fffe1a3                 call    _ipc_hash_delete
F005BF28: 9610001b                 mov     %i3, %o3
F005BF2C: 7ffff5d1                 call    _ipc_object_release
F005BF30: 90100019                 mov     %i1, %o0
F005BF34: 11001000                 sethi   0x400000, %o0
F005BF38: 808c0008                 btst    %o0, %l0
F005BF3C: 02800009                 be      loc_F005BF60
F005BF40: 90100018                 mov     %i0, %o0
F005BF44: c026e008                 clr     [%i3+8]
F005BF48: c026e004                 clr     [%i3+4]
F005BF4C: 9210001a                 mov     %i2, %o1
F005BF50: 7fffdfca                 call    _ipc_entry_dealloc
F005BF54: 9410001b                 mov     %i3, %o2
F005BF58: 1080000e                 ba      locret_F005BF90
F005BF5C: b0102001                 mov     1, %i0
F005BF60: 110007c0                 sethi   0x1F0000, %o0
F005BF64: 902c0008                 andn    %l0, %o0, %o0
F005BF68: 13000400                 sethi   0x100000, %o1
F005BF6C: d406e008                 ld      [%i3+8], %o2
F005BF70: 80a2a000                 cmp     %o2, 0
F005BF74: 02800004                 be      loc_F005BF84
F005BF78: a0120009                 or      %o0, %o1, %l0
F005BF7C: c026e008                 clr     [%i3+8]
F005BF80: a0042001                 inc     %l0
F005BF84: e026c000                 st      %l0, [%i3]
F005BF88: c026e004                 clr     [%i3+4]
F005BF8C: b0102001                 mov     1, %i0
F005BF90: 81c7e008                 ret
F005BF94: 81e80000                 restore
