F00B96A8: 9de3bf98                 save    %sp, -0x68, %sp
F00B96AC: b00e201f                 and     %i0, 0x1F, %i0
F00B96B0: 912e2004                 sll     %i0, 4, %o0
F00B96B4: 90020018                 add     %o0, %i0, %o0
F00B96B8: 912a2003                 sll     %o0, 3, %o0
F00B96BC: 133c04fb92126260         set     _zs_tty, %o1
F00B96C4: 90020009                 add     %o0, %o1, %o0
F00B96C8: f0022034                 ld      [%o0+0x34], %i0
F00B96CC: 80a62000                 cmp     %i0, 0
F00B96D0: 32800004                 bne,a   loc_F00B96E0
F00B96D4: d0062010                 ld      [%i0+0x10], %o0
F00B96D8: 10800017                 ba      locret_F00B9734
F00B96DC: b0102006                 mov     6, %i0
F00B96E0: 4000079e                 call    _zszread
F00B96E4: 9210200c                 mov     0xC, %o1
F00B96E8: a0100008                 mov     %o0, %l0
F00B96EC: d0062010                 ld      [%i0+0x10], %o0
F00B96F0: 4000079a                 call    _zszread
F00B96F4: 9210200d                 mov     0xD, %o1
F00B96F8: 912a2008                 sll     %o0, 8, %o0
F00B96FC: a0140008                 bset    %o0, %l0
F00B9700: b0102000                 mov     0, %i0
F00B9704: 113c047e941222cc         set     _zs_speeds, %o2
F00B970C: 92102000                 mov     0, %o1
F00B9710: d012400a                 lduh    [%o1+%o2], %o0
F00B9714: 80a20010                 cmp     %o0, %l0
F00B9718: 02800007                 be      locret_F00B9734
F00B971C: 01000000                 nop
F00B9720: b0062001                 inc     %i0
F00B9724: 80a6200f                 cmp     %i0, 0xF
F00B9728: 04bffffa                 ble     loc_F00B9710
F00B972C: 92026002                 inc     2, %o1
F00B9730: b010200d                 mov     0xD, %i0
F00B9734: 81c7e008                 ret
F00B9738: 81e80000                 restore
