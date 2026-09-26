F00AE2E8: 9de3bf98                 save    %sp, -0x68, %sp
F00AE2EC: f4068000                 ld      [%i2], %i2
F00AE2F0: 131fe000                 sethi   0x7F800000, %o1
F00AE2F4: c026601c                 clr     [%i1+0x1C]
F00AE2F8: c0266020                 clr     [%i1+0x20]
F00AE2FC: 9136a01f                 srl     %i2, 31, %o0
F00AE300: d0264000                 st      %o0, [%i1]
F00AE304: c0266010                 clr     [%i1+0x10]
F00AE308: c0266014                 clr     [%i1+0x14]
F00AE30C: 113fe000                 sethi   -0x800000, %o0
F00AE310: a02e8008                 andn    %i2, %o0, %l0
F00AE314: 908e8009                 andcc   %i2, %o1, %o0
F00AE318: 1280000e                 bne     loc_F00AE350
F00AE31C: c0266018                 clr     [%i1+0x18]
F00AE320: 80a42000                 cmp     %l0, 0
F00AE324: 12800004                 bne     loc_F00AE334
F00AE328: 90102001                 mov     1, %o0
F00AE32C: 1080002d                 ba      locret_F00AE3E0
F00AE330: c0266004                 clr     [%i1+4]
F00AE334: d0266004                 st      %o0, [%i1+4]
F00AE338: 90103f7b                 mov     -0x85, %o0
F00AE33C: d0266008                 st      %o0, [%i1+8]
F00AE340: e026600c                 st      %l0, [%i1+0xC]
F00AE344: 40000125                 call    _fpu_normalize
F00AE348: 90100019                 mov     %i1, %o0
F00AE34C: 30800025                 ba,a    locret_F00AE3E0
F00AE350: 80a20009                 cmp     %o0, %o1
F00AE354: 32800018                 bne,a   loc_F00AE3B4
F00AE358: 9136a017                 srl     %i2, 23, %o0
F00AE35C: 80a42000                 cmp     %l0, 0
F00AE360: 12800005                 bne     loc_F00AE374
F00AE364: 11001000                 sethi   0x400000, %o0
F00AE368: 90102002                 mov     2, %o0
F00AE36C: 1080001d                 ba      locret_F00AE3E0
F00AE370: d0266004                 st      %o0, [%i1+4]
F00AE374: 808c0008                 btst    %o0, %l0
F00AE378: 22800005                 be,a    loc_F00AE38C
F00AE37C: 90102005                 mov     5, %o0
F00AE380: 90102004                 mov     4, %o0
F00AE384: 10800006                 ba      loc_F00AE39C
F00AE388: d0266004                 st      %o0, [%i1+4]
F00AE38C: d0266004                 st      %o0, [%i1+4]
F00AE390: 90100018                 mov     %i0, %o0
F00AE394: 400001cc                 call    _fpu_set_exception
F00AE398: 92102004                 mov     4, %o1
F00AE39C: 91342007                 srl     %l0, 7, %o0
F00AE3A0: 13000060                 sethi   0x18000, %o1
F00AE3A4: 90120009                 bset    %o1, %o0
F00AE3A8: d026600c                 st      %o0, [%i1+0xC]
F00AE3AC: 1080000c                 ba      loc_F00AE3DC
F00AE3B0: 912c2019                 sll     %l0, 25, %o0
F00AE3B4: 900a20ff                 and     %o0, 0xFF, %o0
F00AE3B8: 90023f81                 inc     -0x7F, %o0
F00AE3BC: d0266008                 st      %o0, [%i1+8]
F00AE3C0: 90102001                 mov     1, %o0
F00AE3C4: d0266004                 st      %o0, [%i1+4]
F00AE3C8: 91342007                 srl     %l0, 7, %o0
F00AE3CC: 13000040                 sethi   0x10000, %o1
F00AE3D0: 90120009                 bset    %o1, %o0
F00AE3D4: d026600c                 st      %o0, [%i1+0xC]
F00AE3D8: 912ea019                 sll     %i2, 25, %o0
F00AE3DC: d0266010                 st      %o0, [%i1+0x10]
F00AE3E0: 81c7e008                 ret
F00AE3E4: 81e80000                 restore
