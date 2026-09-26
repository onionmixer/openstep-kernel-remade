F001FF24: 9de3bf98                 save    %sp, -0x68, %sp
F001FF28: d056205a                 ldsh    [%i0+0x5A], %o0
F001FF2C: 80a22000                 cmp     %o0, 0
F001FF30: 16800007                 bge     loc_F001FF4C
F001FF34: 01000000                 nop
F001FF38: 90200008                 neg     %o0
F001FF3C: 7fffc568                 call    _gsignal
F001FF40: 92102010                 mov     0x10, %o1! char *
F001FF44: 1080000c                 ba      loc_F001FF74
F001FF48: d0062034                 ld      [%i0+0x34], %o0
F001FF4C: 2480000a                 ble,a   loc_F001FF74
F001FF50: d0062034                 ld      [%i0+0x34], %o0
F001FF54: 7fffb95b                 call    _pfind
F001FF58: 01000000                 nop
F001FF5C: 80a22000                 cmp     %o0, 0
F001FF60: 22800005                 be,a    loc_F001FF74
F001FF64: d0062034                 ld      [%i0+0x34], %o0! unsigned int
F001FF68: 7fffc583                 call    _psignal
F001FF6C: 92102010                 mov     0x10, %o1
F001FF70: d0062034                 ld      [%i0+0x34], %o0
F001FF74: 80a22000                 cmp     %o0, 0
F001FF78: 0280000a                 be      locret_F001FFA0
F001FF7C: 01000000                 nop
F001FF80: d2162038                 lduh    [%i0+0x38], %o1
F001FF84: 7fffd864                 call    _selwakeup
F001FF88: 920a6010                 and     %o1, 0x10, %o1
F001FF8C: 7fffd852                 call    _selthreadclear
F001FF90: 90062034                 add     %i0, 0x34, %o0 ! '4'
F001FF94: d0162038                 lduh    [%i0+0x38], %o0
F001FF98: 900a3fef                 and     %o0, -0x11, %o0
F001FF9C: d0362038                 sth     %o0, [%i0+0x38]
F001FFA0: 81c7e008                 ret
F001FFA4: 81e80000                 restore
