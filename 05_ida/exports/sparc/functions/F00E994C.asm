F00E994C: 9de3bf90                 save    %sp, -0x70, %sp
F00E9950: 113c0503                 sethi   %hi(paAlloc), %o0! id
F00E9954: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F00E9958: 40001fc6                 call    _objc_msgSend
F00E995C: 90100018                 mov     %i0, %o0! id
F00E9960: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00E9964: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00E9968: 40001fc2                 call    _objc_msgSend
F00E996C: 9410001a                 mov     %i2, %o2
F00E9970: b0920000                 orcc    %o0, %g0, %i0
F00E9974: 0280000c                 be      loc_F00E99A4
F00E9978: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00E997C: 153c03f2                 sethi   %hi(aLinearFramebuf), %o2! "Linear Framebuffer"
F00E9980: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00E9984: 40001fbb                 call    _objc_msgSend
F00E9988: 9412a368                 bset    %lo(aLinearFramebuf), %o2! "Linear Framebuffer"
F00E998C: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00E9990: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00E9994: 40001fb7                 call    _objc_msgSend
F00E9998: 90100018                 mov     %i0, %o0
F00E999C: 10800003                 ba      locret_F00E99A8
F00E99A0: b0102001                 mov     1, %i0
F00E99A4: b0102000                 mov     0, %i0
F00E99A8: 81c7e008                 ret
F00E99AC: 81e80000                 restore
