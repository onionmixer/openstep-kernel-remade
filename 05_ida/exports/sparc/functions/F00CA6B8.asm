F00CA6B8: 9de3bf98                 save    %sp, -0x68, %sp
F00CA6BC: 7ffd85ca                 call    _if_private
F00CA6C0: 90100018                 mov     %i0, %o0! id
F00CA6C4: 80a22000                 cmp     %o0, 0
F00CA6C8: 02800008                 be      loc_F00CA6E8
F00CA6CC: 133c0506                 sethi   %hi(paOutputpacketAd), %o1
F00CA6D0: d2026084                 ld      [%o1+%lo(paOutputpacketAd)], %o1! SEL
F00CA6D4: 94100019                 mov     %i1, %o2
F00CA6D8: 40009c66                 call    _objc_msgSend
F00CA6DC: 9610001a                 mov     %i2, %o3
F00CA6E0: 10800003                 ba      locret_F00CA6EC
F00CA6E4: b0100008                 mov     %o0, %i0
F00CA6E8: b0103fff                 mov     -1, %i0
F00CA6EC: 81c7e008                 ret
F00CA6F0: 81e80000                 restore
