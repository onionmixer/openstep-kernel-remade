F00BE0C4: 9de3bf90                 save    %sp, -0x70, %sp
F00BE0C8: 7fffffee                 call    sub_F00BE080
F00BE0CC: 90100018                 mov     %i0, %o0
F00BE0D0: b32e6018                 sll     %i1, 24, %i1
F00BE0D4: b33e6018                 sra     %i1, 24, %i1
F00BE0D8: 80a6601f                 cmp     %i1, 0x1F
F00BE0DC: 0480001e                 ble     locret_F00BE154
F00BE0E0: 992e6001                 sll     %i1, 1, %o4
F00BE0E4: 98030019                 add     %o4, %i1, %o4
F00BE0E8: 992b2002                 sll     %o4, 2, %o4
F00BE0EC: 173c04809612e3d0         set     unk_F01203D0, %o3
F00BE0F4: d0062028                 ld      [%i0+0x28], %o0
F00BE0F8: 9603000b                 add     %o4, %o3, %o3
F00BE0FC: d206200c                 ld      [%i0+0xC], %o1
F00BE100: 912a2003                 sll     %o0, 3, %o0
F00BE104: 92024008                 add     %o1, %o0, %o1
F00BE108: d237bff0                 sth     %o1, [%fp+var_10]
F00BE10C: d4062024                 ld      [%i0+0x24], %o2
F00BE110: 90102000                 mov     0, %o0
F00BE114: 932aa001                 sll     %o2, 1, %o1
F00BE118: 9202400a                 add     %o1, %o2, %o1
F00BE11C: d4062010                 ld      [%i0+0x10], %o2
F00BE120: 932a6002                 sll     %o1, 2, %o1
F00BE124: 94028009                 add     %o2, %o1, %o2
F00BE128: d437bff2                 sth     %o2, [%fp+var_E]
F00BE12C: 92102008                 mov     8, %o1
F00BE130: d237bff4                 sth     %o1, [%fp+var_C]
F00BE134: 9210200c                 mov     0xC, %o1
F00BE138: d237bff6                 sth     %o1, [%fp+var_A]
F00BE13C: 9207bff0                 add     %fp, var_10, %o1
F00BE140: 40009e2e                 call    _sparcfbDrawRect
F00BE144: 94102001                 mov     1, %o2
F00BE148: d0062028                 ld      [%i0+0x28], %o0
F00BE14C: 90022001                 inc     %o0
F00BE150: d0262028                 st      %o0, [%i0+0x28]
F00BE154: 81c7e008                 ret
F00BE158: 81e80000                 restore
