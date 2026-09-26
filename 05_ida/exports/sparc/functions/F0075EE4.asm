F0075EE4: 9de3bf98                 save    %sp, -0x68, %sp
F0075EE8: 80a62000                 cmp     %i0, 0
F0075EEC: 02800008                 be      loc_F0075F0C
F0075EF0: 80a66000                 cmp     %i1, 0
F0075EF4: 02800006                 be      loc_F0075F0C
F0075EF8: 113c04d0                 sethi   %hi(_active_threads), %o0
F0075EFC: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0075F00: 80a64008                 cmp     %i1, %o0
F0075F04: 02800004                 be      loc_F0075F14
F0075F08: 01000000                 nop
F0075F0C: 1080001a                 ba      locret_F0075F74
F0075F10: b0102004                 mov     4, %i0
F0075F14: 4000831d                 call    _splusclock
F0075F18: b0066020                 add     %i1, 0x20, %i0 ! ' '
F0075F1C: a0100008                 mov     %o0, %l0
F0075F20: d0060000                 ld      [%i0], %o0
F0075F24: 80a22000                 cmp     %o0, 0
F0075F28: 12bffffe                 bne     loc_F0075F20
F0075F2C: 01000000                 nop
F0075F30: 400083de                 call    _simple_lock_try
F0075F34: 90100018                 mov     %i0, %o0
F0075F38: 80a22000                 cmp     %o0, 0
F0075F3C: 02bffff9                 be      loc_F0075F20
F0075F40: 80a6a000                 cmp     %i2, 0
F0075F44: 02800006                 be      loc_F0075F5C
F0075F48: 90102001                 mov     1, %o0
F0075F4C: d0266078                 st      %o0, [%i1+0x78]
F0075F50: 7ffff818                 call    _stack_privilege
F0075F54: 90100019                 mov     %i1, %o0
F0075F58: 30800003                 ba,a    loc_F0075F64
F0075F5C: c0266078                 clr     [%i1+0x78]
F0075F60: c0266030                 clr     [%i1+0x30]
F0075F64: c0266020                 clr     [%i1+0x20]
F0075F68: 4000836f                 call    _splx
F0075F6C: 90100010                 mov     %l0, %o0
F0075F70: b0102000                 mov     0, %i0
F0075F74: 81c7e008                 ret
F0075F78: 81e80000                 restore
