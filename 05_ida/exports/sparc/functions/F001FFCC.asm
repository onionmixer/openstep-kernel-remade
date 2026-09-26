F001FFCC: 9de3bf98                 save    %sp, -0x68, %sp
F001FFD0: e0062010                 ld      [%i0+0x10], %l0
F001FFD4: 80a42000                 cmp     %l0, 0
F001FFD8: 02800013                 be      loc_F0020024
F001FFDC: 90100018                 mov     %i0, %o0
F001FFE0: 400000a0                 call    _soqremque
F001FFE4: 92102000                 mov     0, %o1
F001FFE8: 80a22000                 cmp     %o0, 0
F001FFEC: 32800006                 bne,a   loc_F0020004
F001FFF0: 90100010                 mov     %l0, %o0
F001FFF4: 113c042f                 sethi   %hi(aSoisconnected), %o0! "soisconnected"
F001FFF8: 7fffd45e                 call    _panic
F001FFFC: 90122088                 bset    %lo(aSoisconnected), %o0! "soisconnected"
F0020000: 90100010                 mov     %l0, %o0
F0020004: 92100018                 mov     %i0, %o1
F0020008: 40000072                 call    _soqinsque
F002000C: 94102001                 mov     1, %o2
F0020010: 90100010                 mov     %l0, %o0
F0020014: 400000fe                 call    _sowakeup
F0020018: 92042024                 add     %l0, 0x24, %o1 ! '$'
F002001C: 7fffcb73                 call    _wakeup
F0020020: 90042054                 add     %l0, 0x54, %o0 ! 'T'
F0020024: d2162006                 lduh    [%i0+6], %o1
F0020028: 90062054                 add     %i0, 0x54, %o0 ! 'T'
F002002C: 920a7ff3                 and     %o1, -0xD, %o1
F0020030: 92126002                 bset    2, %o1
F0020034: 7fffcb6d                 call    _wakeup
F0020038: d2362006                 sth     %o1, [%i0+6]
F002003C: 90100018                 mov     %i0, %o0
F0020040: 400000f3                 call    _sowakeup
F0020044: 92062024                 add     %i0, 0x24, %o1 ! '$'
F0020048: 90100018                 mov     %i0, %o0
F002004C: 400000f0                 call    _sowakeup
F0020050: 9202203c                 add     %o0, 0x3C, %o1 ! '<'
F0020054: 81c7e008                 ret
F0020058: 81e80000                 restore
