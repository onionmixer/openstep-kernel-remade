F00EF65C: 9de3bf98                 save    %sp, -0x68, %sp
F00EF660: a0100018                 mov     %i0, %l0
F00EF664: 113c04bc                 sethi   %hi(dword_F012F0DC), %o0
F00EF668: d00220dc                 ld      [%o0+%lo(dword_F012F0DC)], %o0! name
F00EF66C: 80a22000                 cmp     %o0, 0
F00EF670: 02800005                 be      loc_F00EF684
F00EF674: b0102000                 mov     0, %i0
F00EF678: 7ffffc6e                 call    _NXMapGet
F00EF67C: 92100010                 mov     %l0, %o1
F00EF680: b0100008                 mov     %o0, %i0
F00EF684: 80a62000                 cmp     %i0, 0
F00EF688: 12800005                 bne     locret_F00EF69C
F00EF68C: 01000000                 nop
F00EF690: 4000099d                 call    _objc_getClass
F00EF694: 90100010                 mov     %l0, %o0
F00EF698: b0100008                 mov     %o0, %i0
F00EF69C: 81c7e008                 ret
F00EF6A0: 81e80000                 restore
