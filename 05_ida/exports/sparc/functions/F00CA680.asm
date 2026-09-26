F00CA680: 9de3bf98                 save    %sp, -0x68, %sp
F00CA684: 7ffd85d8                 call    _if_private
F00CA688: 90100018                 mov     %i0, %o0
F00CA68C: 94920000                 orcc    %o0, %g0, %o2
F00CA690: 02800007                 be      loc_F00CA6AC
F00CA694: 113c0506                 sethi   %hi(paFinishinitiali), %o0! id
F00CA698: d2022088                 ld      [%o0+%lo(paFinishinitiali)], %o1! SEL
F00CA69C: 40009c75                 call    _objc_msgSend
F00CA6A0: 9010000a                 mov     %o2, %o0
F00CA6A4: 10800003                 ba      locret_F00CA6B0
F00CA6A8: b0100008                 mov     %o0, %i0
F00CA6AC: b0103fff                 mov     -1, %i0
F00CA6B0: 81c7e008                 ret
F00CA6B4: 81e80000                 restore
