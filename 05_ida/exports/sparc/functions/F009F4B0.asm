F009F4B0: 9de3bf98                 save    %sp, -0x68, %sp
F009F4B4: 113c0464                 sethi   %hi(_physmax), %o0
F009F4B8: d0022388                 ld      [%o0+%lo(_physmax)], %o0
F009F4BC: 80a60008                 cmp     %i0, %o0
F009F4C0: 1a800009                 bcc     locret_F009F4E4
F009F4C4: 01000000                 nop
F009F4C8: 7fff9bc2                 call    _vm_valid_page
F009F4CC: 90100018                 mov     %i0, %o0
F009F4D0: 80a22000                 cmp     %o0, 0
F009F4D4: 02800004                 be      locret_F009F4E4
F009F4D8: 90100018                 mov     %i0, %o0
F009F4DC: 7ffffeb9                 call    _pmap_clear_page_attrib
F009F4E0: 92102001                 mov     1, %o1
F009F4E4: 81c7e008                 ret
F009F4E8: 81e80000                 restore
