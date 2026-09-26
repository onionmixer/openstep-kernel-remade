F007673C: 9de3bf98                 save    %sp, -0x68, %sp
F0076740: 40008472                 call    _clock_value
F0076744: 90102001                 mov     1, %o0
F0076748: d4062018                 ld      [%i0+0x18], %o2
F007674C: a0100008                 mov     %o0, %l0
F0076750: a2100009                 mov     %o1, %l1
F0076754: 80a4000a                 cmp     %l0, %o2
F0076758: 18800008                 bgu     loc_F0076778
F007675C: 01000000                 nop
F0076760: 12800009                 bne     loc_F0076784
F0076764: 01000000                 nop
F0076768: d006201c                 ld      [%i0+0x1C], %o0
F007676C: 80a44008                 cmp     %l1, %o0
F0076770: 08800005                 bleu    loc_F0076784
F0076774: 01000000                 nop
F0076778: 94102000                 mov     0, %o2
F007677C: 96102000                 mov     0, %o3
F0076780: 30800010                 ba,a    loc_F00767C0
F0076784: 400084ae                 call    _timer_attributes
F0076788: 90102000                 mov     0, %o0
F007678C: d41e2018                 ldd     [%i0+0x18], %o2
F0076790: d81a0000                 ldd     [%o0], %o4
F0076794: 96a2c011                 subcc   %o3, %l1, %o3
F0076798: 94628010                 subc    %o2, %l0, %o2
F007679C: 80a2800c                 cmp     %o2, %o4
F00767A0: 18800006                 bgu     loc_F00767B8
F00767A4: 01000000                 nop
F00767A8: 12800006                 bne     loc_F00767C0
F00767AC: 80a2c00d                 cmp     %o3, %o5
F00767B0: 08800004                 bleu    loc_F00767C0
F00767B4: 01000000                 nop
F00767B8: 9410000c                 mov     %o4, %o2
F00767BC: 9610000d                 mov     %o5, %o3
F00767C0: 9210000a                 mov     %o2, %o1
F00767C4: 9410000b                 mov     %o3, %o2
F00767C8: 400084ad                 call    _set_timer
F00767CC: 90102000                 mov     0, %o0
F00767D0: 81c7e008                 ret
F00767D4: 81e80000                 restore
