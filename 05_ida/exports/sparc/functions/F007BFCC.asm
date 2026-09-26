F007BFCC: 9de3bf98                 save    %sp, -0x68, %sp
F007BFD0: 90102001                 mov     1, %o0
F007BFD4: d02e6003                 stb     %o0, [%i1+3]
F007BFD8: 90102020                 mov     0x20, %o0 ! ' '
F007BFDC: d0266004                 st      %o0, [%i1+4]
F007BFE0: d0062008                 ld      [%i0+8], %o0
F007BFE4: d0266008                 st      %o0, [%i1+8]
F007BFE8: c026600c                 clr     [%i1+0xC]
F007BFEC: d0062010                 ld      [%i0+0x10], %o0
F007BFF0: d0266010                 st      %o0, [%i1+0x10]
F007BFF4: d0062014                 ld      [%i0+0x14], %o0
F007BFF8: 133c03d3                 sethi   %hi(dword_F00F4E60), %o1
F007BFFC: d2026260                 ld      [%o1+%lo(dword_F00F4E60)], %o1
F007C000: 90022064                 inc     0x64, %o0 ! 'd'
F007C004: d0266014                 st      %o0, [%i1+0x14]
F007C008: d2266018                 st      %o1, [%i1+0x18]
F007C00C: 90103ed1                 mov     -0x12F, %o0
F007C010: d026601c                 st      %o0, [%i1+0x1C]
F007C014: d2062014                 ld      [%i0+0x14], %o1
F007C018: 80a26960                 cmp     %o1, 0x960
F007C01C: 3280000e                 bne,a   locret_F007C054
F007C020: b0102000                 mov     0, %i0
F007C024: 113c03ca901220e4         set     loc_F00F28E4, %o0
F007C02C: 932a6002                 sll     %o1, 2, %o1
F007C030: d4020009                 ld      [%o0+%o1], %o2
F007C034: 80a2a000                 cmp     %o2, 0
F007C038: 12800004                 bne     loc_F007C048
F007C03C: 90100018                 mov     %i0, %o0
F007C040: 10800005                 ba      locret_F007C054
F007C044: b0102000                 mov     0, %i0
F007C048: 9fc28000                 call    %o2
F007C04C: 92100019                 mov     %i1, %o1
F007C050: b0102001                 mov     1, %i0
F007C054: 81c7e008                 ret
F007C058: 81e80000                 restore
