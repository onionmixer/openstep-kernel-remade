F0079300: 9de3bf98                 save    %sp, -0x68, %sp
F0079304: 80a72000                 cmp     %i4, 0
F0079308: d206202c                 ld      [%i0+0x2C], %o1
F007930C: 11200000                 sethi   0x80000000, %o0
F0079310: b32e601f                 sll     %i1, 31, %i1
F0079314: b40ea001                 and     %i2, 1, %i2
F0079318: b52ea01e                 sll     %i2, 30, %i2
F007931C: b60ee001                 and     %i3, 1, %i3
F0079320: b72ee01d                 sll     %i3, 29, %i3
F0079324: 902a4008                 andn    %o1, %o0, %o0
F0079328: 90120019                 bset    %i1, %o0
F007932C: 13100000                 sethi   0x40000000, %o1
F0079330: 922a0009                 andn    %o0, %o1, %o1
F0079334: 9212401a                 bset    %i2, %o1
F0079338: 11080000                 sethi   0x20000000, %o0
F007933C: 902a4008                 andn    %o1, %o0, %o0
F0079340: 9012001b                 bset    %i3, %o0
F0079344: 12800005                 bne     loc_F0079358
F0079348: d026202c                 st      %o0, [%i0+0x2C]
F007934C: 113c04f290122350         set     __zone_default_space, %o0
F0079354: d026203c                 st      %o0, [%i0+0x3C]
F0079358: d006202c                 ld      [%i0+0x2C], %o0
F007935C: 80a22000                 cmp     %o0, 0
F0079360: 16800005                 bge     loc_F0079374
F0079364: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0079368: 7fffbe68                 call    _lock_init
F007936C: 92102001                 mov     1, %o1
F0079370: 30800002                 ba,a    locret_F0079378
F0079374: c0260000                 clr     [%i0]
F0079378: 81c7e008                 ret
F007937C: 81e80000                 restore
