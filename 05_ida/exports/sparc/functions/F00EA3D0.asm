F00EA3D0: 9de3bf90                 save    %sp, -0x70, %sp
F00EA3D4: 133c0506                 sethi   %hi(paSetversion), %o1
F00EA3D8: 90100018                 mov     %i0, %o0! id
F00EA3DC: d2026264                 ld      [%o1+%lo(paSetversion)], %o1! SEL
F00EA3E0: 40001d24                 call    _objc_msgSend
F00EA3E4: 94102001                 mov     1, %o2
F00EA3E8: 81c7e008                 ret
F00EA3EC: 81e80000                 restore
