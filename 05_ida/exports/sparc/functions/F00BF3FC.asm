F00BF3FC: 9de3bf98                 save    %sp, -0x68, %sp
F00BF400: 113c0504                 sethi   %hi(paAutorepeat), %o0! id
F00BF404: d2022294                 ld      [%o0+%lo(paAutorepeat)], %o1! SEL
F00BF408: 4000c91a                 call    _objc_msgSend
F00BF40C: 90100018                 mov     %i0, %o0
F00BF410: 81c7e008                 ret
F00BF414: 81e80000                 restore
