F00A7344: 9de3bf98                 save    %sp, -0x68, %sp
F00A7348: 113c046c                 sethi   %hi(_boothowto), %o0
F00A734C: d0022104                 ld      [%o0+%lo(_boothowto)], %o0
F00A7350: 808a2001                 btst    1, %o0
F00A7354: 02800009                 be      locret_F00A7378
F00A7358: 92100018                 mov     %i0, %o1
F00A735C: 113c046c90122298         set     aSKeyS, %o0! "%s key [%s]: "
F00A7364: 7ffdb4bd                 call    _printf
F00A7368: 94100009                 mov     %o1, %o2
F00A736C: 90100019                 mov     %i1, %o0! char *
F00A7370: 7fffffbe                 call    _gets
F00A7374: 92100008                 mov     %o0, %o1
F00A7378: 81c7e008                 ret
F00A737C: 81e80000                 restore
