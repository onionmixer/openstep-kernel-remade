F0099394: 9de3bf98                 save    %sp, -0x68, %sp
F0099398: a2100018                 mov     %i0, %l1
F009939C: 113c0464                 sethi   %hi(_vac), %o0
F00993A0: d0022334                 ld      [%o0+%lo(_vac)], %o0
F00993A4: 80a22000                 cmp     %o0, 0
F00993A8: 0280000a                 be      loc_F00993D0
F00993AC: b0103fff                 mov     -1, %i0
F00993B0: f2066020                 ld      [%i1+0x20], %i1
F00993B4: 80a66000                 cmp     %i1, 0
F00993B8: 02800006                 be      loc_F00993D0
F00993BC: 113c0464                 sethi   %hi(_shm_alignment), %o0
F00993C0: d0022328                 ld      [%o0+%lo(_shm_alignment)], %o0
F00993C4: 90023fff                 inc     -1, %o0
F00993C8: 900e4008                 and     %i1, %o0, %o0
F00993CC: b132200c                 srl     %o0, 12, %i0
F00993D0: 80a63fff                 cmp     %i0, -1
F00993D4: 3280000a                 bne,a   loc_F00993FC
F00993D8: 113c0464                 sethi   -0xFEE7000, %o0
F00993DC: 7ffff5eb                 call    _splusclock
F00993E0: 01000000                 nop
F00993E4: b2100008                 mov     %o0, %i1
F00993E8: 90100011                 mov     %l1, %o0
F00993EC: 40002e9d                 call    _rmalloc
F00993F0: 9210001a                 mov     %i2, %o1
F00993F4: 10800030                 ba      loc_F00994B4
F00993F8: b0100008                 mov     %o0, %i0
F00993FC: d0022334                 ld      [%o0+0x334], %o0
F0099400: 80a22000                 cmp     %o0, 0
F0099404: 02800005                 be      loc_F0099418
F0099408: 113c0464                 sethi   %hi(_shm_alignment), %o0
F009940C: d0022328                 ld      [%o0+%lo(_shm_alignment)], %o0
F0099410: 9132200c                 srl     %o0, 12, %o0
F0099414: 9a023fff                 add     %o0, -1, %o5
F0099418: d0046008                 ld      [%l1+8], %o0
F009941C: 80a22000                 cmp     %o0, 0
F0099420: 02800019                 be      loc_F0099484
F0099424: 96046008                 add     %l1, 8, %o3
F0099428: 8438000d                 xnor    %g0, %o5, %g2
F009942C: d802c000                 ld      [%o3], %o4
F0099430: 80a3001a                 cmp     %o4, %i2
F0099434: 26800010                 bl,a    loc_F0099474
F0099438: 9602e008                 inc     8, %o3
F009943C: d402e004                 ld      [%o3+4], %o2
F0099440: 900a8002                 and     %o2, %g2, %o0
F0099444: a0020018                 add     %o0, %i0, %l0
F0099448: 80a4000a                 cmp     %l0, %o2
F009944C: 16800005                 bge     loc_F0099460
F0099450: 9204001a                 add     %l0, %i2, %o1
F0099454: 90042001                 add     %l0, 1, %o0
F0099458: a002000d                 add     %o0, %o5, %l0
F009945C: 9204001a                 add     %l0, %i2, %o1
F0099460: 9002800c                 add     %o2, %o4, %o0
F0099464: 80a24008                 cmp     %o1, %o0
F0099468: 24800008                 ble,a   loc_F0099488
F009946C: d002c000                 ld      [%o3], %o0
F0099470: 9602e008                 inc     8, %o3
F0099474: d002c000                 ld      [%o3], %o0
F0099478: 80a22000                 cmp     %o0, 0
F009947C: 32bfffed                 bne,a   loc_F0099430
F0099480: d802c000                 ld      [%o3], %o4
F0099484: d002c000                 ld      [%o3], %o0
F0099488: 80a22000                 cmp     %o0, 0
F009948C: 0280000c                 be      locret_F00994BC
F0099490: b0102000                 mov     0, %i0
F0099494: 7ffff5bd                 call    _splusclock
F0099498: 01000000                 nop
F009949C: b2100008                 mov     %o0, %i1
F00994A0: 90100011                 mov     %l1, %o0
F00994A4: 9210001a                 mov     %i2, %o1
F00994A8: 40002f22                 call    _rmget
F00994AC: 94100010                 mov     %l0, %o2
F00994B0: b0100008                 mov     %o0, %i0
F00994B4: 7ffff61c                 call    _splx
F00994B8: 90100019                 mov     %i1, %o0
F00994BC: 81c7e008                 ret
F00994C0: 81e80000                 restore
