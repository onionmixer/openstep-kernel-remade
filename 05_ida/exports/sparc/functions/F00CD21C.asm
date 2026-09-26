F00CD21C: 9de3bf88                 save    %sp, -0x78, %sp
F00CD220: 960ea0ff                 and     %i2, 0xFF, %o3
F00CD224: 94102000                 mov     0, %o2
F00CD228: 9a0ee0ff                 and     %i3, 0xFF, %o5
F00CD22C: 98102000                 mov     0, %o4
F00CD230: 113c0506                 sethi   %hi(paReservescsi3ta), %o0! id
F00CD234: d2022008                 ld      [%o0+%lo(paReservescsi3ta)], %o1! SEL
F00CD238: f823a05c                 st      %i4, [%sp+0x78+var_1C]
F00CD23C: 4000918d                 call    _objc_msgSend
F00CD240: 90100018                 mov     %i0, %o0
F00CD244: 81c7e008                 ret
F00CD248: 91e80008                 restore %g0, %o0, %o0
