F009F530: 9de3bf98                 save    %sp, -0x68, %sp
F009F534: 113c0464                 sethi   %hi(_physmax), %o0
F009F538: d0022388                 ld      [%o0+%lo(_physmax)], %o0
F009F53C: 80a60008                 cmp     %i0, %o0
F009F540: 1a800009                 bcc     locret_F009F564
F009F544: 01000000                 nop
F009F548: 7fff9ba2                 call    _vm_valid_page
F009F54C: 90100018                 mov     %i0, %o0
F009F550: 80a22000                 cmp     %o0, 0
F009F554: 02800004                 be      locret_F009F564
F009F558: 90100018                 mov     %i0, %o0
F009F55C: 7ffffe99                 call    _pmap_clear_page_attrib
F009F560: 92102002                 mov     2, %o1
F009F564: 81c7e008                 ret
F009F568: 81e80000                 restore
