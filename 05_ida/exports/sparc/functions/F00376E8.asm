F00376E8: 9de3bf88                 save    %sp, -0x78, %sp
F00376EC: 92100019                 mov     %i1, %o1
F00376F0: 113c00dd                 sethi   %hi(_tcp_notify), %o0
F00376F4: 80a62004                 cmp     %i0, 4
F00376F8: 0280000b                 be      loc_F0037724
F00376FC: 86122274                 or      %o0, %lo(_tcp_notify), %g3
F0037700: 80a62015                 cmp     %i0, 0x15
F0037704: 18800023                 bgu     locret_F0037790
F0037708: 113c0432                 sethi   %hi(_inetctlerrmap), %o0
F003770C: 90122010                 bset    %lo(_inetctlerrmap), %o0
F0037710: d00e0008                 ldub    [%i0+%o0], %o0
F0037714: 80a22000                 cmp     %o0, 0
F0037718: 12800006                 bne     loc_F0037730
F003771C: 80a6a000                 cmp     %i2, 0
F0037720: 3080001c                 ba,a    locret_F0037790
F0037724: 113c00dd86122398         set     _tcp_quench, %g3
F003772C: 80a6a000                 cmp     %i2, 0
F0037730: 0280000e                 be      loc_F0037768
F0037734: 113c04d9                 sethi   %hi(_tcb), %o0
F0037738: d80e8000                 ldub    [%i2], %o4
F003773C: d406a00c                 ld      [%i2+0xC], %o2
F0037740: 90122340                 bset    %lo(_tcb), %o0
F0037744: d427bff4                 st      %o2, [%fp+var_C]
F0037748: 980b200f                 and     %o4, 0xF, %o4
F003774C: 992b2002                 sll     %o4, 2, %o4
F0037750: 9406800c                 add     %i2, %o4, %o2
F0037754: d412a002                 lduh    [%o2+2], %o2
F0037758: 9607bff4                 add     %fp, var_C, %o3
F003775C: d816800c                 lduh    [%i2+%o4], %o4
F0037760: 1080000a                 ba      loc_F0037788
F0037764: 9a100018                 mov     %i0, %o5
F0037768: 90122340                 bset    0x340, %o0
F003776C: 94102000                 mov     0, %o2
F0037770: 9607bff4                 add     %fp, var_C, %o3
F0037774: 1b3c04d9                 sethi   %hi(_zeroin_addr), %o5
F0037778: c4036150                 ld      [%o5+%lo(_zeroin_addr)], %g2
F003777C: 98102000                 mov     0, %o4
F0037780: 9a100018                 mov     %i0, %o5
F0037784: c427bff4                 st      %g2, [%fp+var_C]
F0037788: 7fffe583                 call    _in_pcbnotify
F003778C: c623a05c                 st      %g3, [%sp+0x78+var_1C]
F0037790: 81c7e008                 ret
F0037794: 81e80000                 restore
