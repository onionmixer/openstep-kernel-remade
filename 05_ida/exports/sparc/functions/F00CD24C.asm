F00CD24C: 9de3bf88                 save    %sp, -0x78, %sp
F00CD250: 960ea0ff                 and     %i2, 0xFF, %o3
F00CD254: 94102000                 mov     0, %o2
F00CD258: 9a0ee0ff                 and     %i3, 0xFF, %o5
F00CD25C: 98102000                 mov     0, %o4
F00CD260: 113c0506                 sethi   %hi(paReleasescsi3ta), %o0! id
F00CD264: d2022004                 ld      [%o0+%lo(paReleasescsi3ta)], %o1! SEL
F00CD268: f823a05c                 st      %i4, [%sp+0x78+var_1C]
F00CD26C: 40009181                 call    _objc_msgSend
F00CD270: 90100018                 mov     %i0, %o0
F00CD274: 81c7e008                 ret
F00CD278: 81e80000                 restore
