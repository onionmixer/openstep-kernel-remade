F00B9A40: 9de3bf98                 save    %sp, -0x68, %sp
F00B9A44: 253c0483                 sethi   %hi(_kbddev), %l2
F00B9A48: 912e2010                 sll     %i0, 16, %o0
F00B9A4C: d254a224                 ldsh    [%l2+%lo(_kbddev)], %o1
F00B9A50: a33a2010                 sra     %o0, 16, %l1
F00B9A54: 80a44009                 cmp     %l1, %o1
F00B9A58: 0280004f                 be      locret_F00B9B94
F00B9A5C: 01000000                 nop
F00B9A60: 7fff7456                 call    _spltty
F00B9A64: 01000000                 nop
F00B9A68: 900e201f                 and     %i0, 0x1F, %o0
F00B9A6C: 932a2004                 sll     %o0, 4, %o1
F00B9A70: 92024008                 add     %o1, %o0, %o1
F00B9A74: 932a6003                 sll     %o1, 3, %o1
F00B9A78: 113c04fb90122260         set     _zs_tty, %o0
F00B9A80: a0024008                 add     %o1, %o0, %l0
F00B9A84: d24c2047                 ldsb    [%l0+0x47], %o1
F00B9A88: 912a6001                 sll     %o1, 1, %o0
F00B9A8C: 90020009                 add     %o0, %o1, %o0
F00B9A90: 912a2004                 sll     %o0, 4, %o0
F00B9A94: 133c042e921260cc         set     _linesw, %o1
F00B9A9C: 90020009                 add     %o0, %o1, %o0
F00B9AA0: d2022004                 ld      [%o0+4], %o1
F00B9AA4: 9fc24000                 call    %o1
F00B9AA8: 90100010                 mov     %l0, %o0
F00B9AAC: d2042040                 ld      [%l0+0x40], %o1
F00B9AB0: 11100000                 sethi   0x40000000, %o0
F00B9AB4: f0042034                 ld      [%l0+0x34], %i0
F00B9AB8: 902a4008                 andn    %o1, %o0, %o0
F00B9ABC: d0242040                 st      %o0, [%l0+0x40]
F00B9AC0: d00e2025                 ldub    [%i0+0x25], %o0
F00B9AC4: 808a2010                 btst    0x10, %o0
F00B9AC8: 2280000d                 be,a    loc_F00B9AFC
F00B9ACC: d0042040                 ld      [%l0+0x40], %o0
F00B9AD0: 7fff7427                 call    _splzs
F00B9AD4: 01000000                 nop
F00B9AD8: d40e2025                 ldub    [%i0+0x25], %o2
F00B9ADC: 92102005                 mov     5, %o1
F00B9AE0: d0062010                 ld      [%i0+0x10], %o0
F00B9AE4: 940aa0ef                 and     %o2, 0xEF, %o2
F00B9AE8: 4000069f                 call    _zszwrite
F00B9AEC: d42e2025                 stb     %o2, [%i0+0x25]
F00B9AF0: 7fff7432                 call    _spltty
F00B9AF4: 01000000                 nop
F00B9AF8: d0042040                 ld      [%l0+0x40], %o0
F00B9AFC: 900a2206                 and     %o0, 0x206, %o0
F00B9B00: 80a22004                 cmp     %o0, 4
F00B9B04: 02800010                 be      loc_F00B9B44
F00B9B08: 113c04fb                 sethi   %hi(_rconsdev), %o0
F00B9B0C: d0522248                 ldsh    [%o0+%lo(_rconsdev)], %o0
F00B9B10: 80a44008                 cmp     %l1, %o0
F00B9B14: 0280000c                 be      loc_F00B9B44
F00B9B18: d054a224                 ldsh    [%l2+0x224], %o0
F00B9B1C: 80a44008                 cmp     %l1, %o0
F00B9B20: 02800009                 be      loc_F00B9B44
F00B9B24: 90100010                 mov     %l0, %o0
F00B9B28: 92102000                 mov     0, %o1
F00B9B2C: 40000264                 call    _zsmctl
F00B9B30: 94102000                 mov     0, %o2
F00B9B34: 113c04d190122350         set     _lbolt, %o0! unsigned int
F00B9B3C: 7ffd62cf                 call    _sleep
F00B9B40: 9210201d                 mov     0x1D, %o1
F00B9B44: 7ffd7896                 call    _ttyclose
F00B9B48: 90100010                 mov     %l0, %o0
F00B9B4C: d0042040                 ld      [%l0+0x40], %o0
F00B9B50: 808a2006                 btst    6, %o0
F00B9B54: 1280000c                 bne     loc_F00B9B84
F00B9B58: 01000000                 nop
F00B9B5C: 7fff7404                 call    _splzs
F00B9B60: 01000000                 nop
F00B9B64: d40e2021                 ldub    [%i0+0x21], %o2
F00B9B68: 92102001                 mov     1, %o1
F00B9B6C: d0062010                 ld      [%i0+0x10], %o0
F00B9B70: 940aa0ef                 and     %o2, 0xEF, %o2
F00B9B74: 4000067c                 call    _zszwrite
F00B9B78: d42e2021                 stb     %o2, [%i0+0x21]
F00B9B7C: 7fff740f                 call    _spltty
F00B9B80: 01000000                 nop
F00B9B84: 7ffd6499                 call    _wakeup
F00B9B88: 90042040                 add     %l0, 0x40, %o0 ! '@'
F00B9B8C: 7fff7455                 call    _spl0
F00B9B90: 01000000                 nop
F00B9B94: 81c7e008                 ret
F00B9B98: 81e80000                 restore
