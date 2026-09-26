F00CA6F4: 9de3bf98                 save    %sp, -0x68, %sp
F00CA6F8: 7ffd85bb                 call    _if_private
F00CA6FC: 90100018                 mov     %i0, %o0
F00CA700: 94920000                 orcc    %o0, %g0, %o2
F00CA704: 02800007                 be      loc_F00CA720
F00CA708: 113c0506                 sethi   %hi(paAllocatenetbuf), %o0! id
F00CA70C: d2022080                 ld      [%o0+%lo(paAllocatenetbuf)], %o1! SEL
F00CA710: 40009c58                 call    _objc_msgSend
F00CA714: 9010000a                 mov     %o2, %o0
F00CA718: 10800003                 ba      locret_F00CA724
F00CA71C: b0100008                 mov     %o0, %i0
F00CA720: b0102000                 mov     0, %i0
F00CA724: 81c7e008                 ret
F00CA728: 81e80000                 restore
