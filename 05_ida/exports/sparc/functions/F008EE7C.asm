F008EE7C: 9de3bf98                 save    %sp, -0x68, %sp
F008EE80: 113c0504                 sethi   %hi(paFreeobjects), %o0! id
F008EE84: d20220cc                 ld      [%o0+%lo(paFreeobjects)], %o1! SEL
F008EE88: 40018a7a                 call    _objc_msgSend
F008EE8C: 90100018                 mov     %i0, %o0
F008EE90: 113c0503                 sethi   %hi(paFree), %o0! id
F008EE94: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008EE98: 40018a76                 call    _objc_msgSend
F008EE9C: 90100018                 mov     %i0, %o0
F008EEA0: 81c7e008                 ret
F008EEA4: 81e80000                 restore
