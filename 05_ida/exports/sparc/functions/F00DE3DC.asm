F00DE3DC: 9de3bf98                 save    %sp, -0x68, %sp
F00DE3E0: 80a62000                 cmp     %i0, 0
F00DE3E4: 02800008                 be      loc_F00DE404
F00DE3E8: 113c0505                 sethi   %hi(paClipcount), %o0! id
F00DE3EC: d2022008                 ld      [%o0+%lo(paClipcount)], %o1! SEL
F00DE3F0: 40004d20                 call    _objc_msgSend
F00DE3F4: 90100018                 mov     %i0, %o0
F00DE3F8: d0264000                 st      %o0, [%i1]
F00DE3FC: 10800003                 ba      locret_F00DE408
F00DE400: b0102000                 mov     0, %i0
F00DE404: b01020ca                 mov     0xCA, %i0
F00DE408: 81c7e008                 ret
F00DE40C: 81e80000                 restore
