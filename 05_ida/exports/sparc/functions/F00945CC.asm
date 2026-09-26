F00945CC: 9de3bf98                 save    %sp, -0x68, %sp
F00945D0: 80a66001                 cmp     %i1, 1
F00945D4: 02800007                 be      loc_F00945F0
F00945D8: 9010001a                 mov     %i2, %o0
F00945DC: 80a66002                 cmp     %i1, 2
F00945E0: 02800008                 be      loc_F0094600
F00945E4: 133c03d3                 sethi   -0xFF0B400, %o1
F00945E8: 1080000c                 ba      locret_F0094618
F00945EC: b0102003                 mov     3, %i0
F00945F0: 7fffff97                 call    sub_F009444C
F00945F4: 01000000                 nop
F00945F8: 10800006                 ba      loc_F0094610
F00945FC: 9010204c                 mov     0x4C, %o0! __dst
F0094600: 921262b8                 bset    0x2B8, %o1! __src
F0094604: 7ffdcb27                 call    _memcpy
F0094608: 94102110                 mov     0x110, %o2
F009460C: 90102110                 mov     0x110, %o0
F0094610: d026c000                 st      %o0, [%i3]
F0094614: b0102000                 mov     0, %i0
F0094618: 81c7e008                 ret
F009461C: 81e80000                 restore
