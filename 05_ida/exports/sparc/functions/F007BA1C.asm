F007BA1C: 9de3bf98                 save    %sp, -0x68, %sp
F007BA20: d2062004                 ld      [%i0+4], %o1
F007BA24: 80a26020                 cmp     %o1, 0x20 ! ' '
F007BA28: 12800005                 bne     loc_F007BA3C
F007BA2C: d00e2003                 ldub    [%i0+3], %o0
F007BA30: 80a22001                 cmp     %o0, 1
F007BA34: 22800005                 be,a    loc_F007BA48
F007BA38: d0062018                 ld      [%i0+0x18], %o0
F007BA3C: 90103ed0                 mov     -0x130, %o0
F007BA40: 10800018                 ba      locret_F007BAA0
F007BA44: d026601c                 st      %o0, [%i1+0x1C]
F007BA48: 133c03d3                 sethi   %hi(dword_F00F4DDC), %o1
F007BA4C: d20261dc                 ld      [%o1+%lo(dword_F00F4DDC)], %o1
F007BA50: 80a20009                 cmp     %o0, %o1
F007BA54: 1280000b                 bne     loc_F007BA80
F007BA58: 90103ed0                 mov     -0x130, %o0
F007BA5C: d406a034                 ld      [%i2+0x34], %o2
F007BA60: 80a2a000                 cmp     %o2, 0
F007BA64: 32800005                 bne,a   loc_F007BA78
F007BA68: d0068000                 ld      [%i2], %o0
F007BA6C: 90103ed1                 mov     -0x12F, %o0
F007BA70: 1080000c                 ba      locret_F007BAA0
F007BA74: d026601c                 st      %o0, [%i1+0x1C]
F007BA78: 9fc28000                 call    %o2
F007BA7C: d206201c                 ld      [%i0+0x1C], %o1
F007BA80: d026601c                 st      %o0, [%i1+0x1C]
F007BA84: d006601c                 ld      [%i1+0x1C], %o0
F007BA88: 80a22000                 cmp     %o0, 0
F007BA8C: 12800005                 bne     locret_F007BAA0
F007BA90: 92102020                 mov     0x20, %o1 ! ' '
F007BA94: 90102001                 mov     1, %o0
F007BA98: d02e6003                 stb     %o0, [%i1+3]
F007BA9C: d2266004                 st      %o1, [%i1+4]
F007BAA0: 81c7e008                 ret
F007BAA4: 81e80000                 restore
