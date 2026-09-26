F00DE040: 9de3bf98                 save    %sp, -0x68, %sp
F00DE044: 80a62000                 cmp     %i0, 0
F00DE048: 02800008                 be      loc_F00DE068
F00DE04C: 113c0505                 sethi   %hi(paExclusiveuser), %o0! id
F00DE050: d2022228                 ld      [%o0+%lo(paExclusiveuser)], %o1! SEL
F00DE054: 40004e07                 call    _objc_msgSend
F00DE058: 90100018                 mov     %i0, %o0
F00DE05C: d0264000                 st      %o0, [%i1]
F00DE060: 10800003                 ba      locret_F00DE06C
F00DE064: b0102000                 mov     0, %i0
F00DE068: b01020ca                 mov     0xCA, %i0
F00DE06C: 81c7e008                 ret
F00DE070: 81e80000                 restore
