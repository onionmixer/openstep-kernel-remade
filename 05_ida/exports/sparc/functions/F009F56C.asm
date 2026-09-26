F009F56C: 9de3bf98                 save    %sp, -0x68, %sp
F009F570: 113c0464                 sethi   %hi(_physmax), %o0
F009F574: d0022388                 ld      [%o0+%lo(_physmax)], %o0
F009F578: 80a60008                 cmp     %i0, %o0
F009F57C: 1a80000b                 bcc     locret_F009F5A8
F009F580: a0102000                 mov     0, %l0
F009F584: 7fff9b93                 call    _vm_valid_page
F009F588: 90100018                 mov     %i0, %o0
F009F58C: 80a22000                 cmp     %o0, 0
F009F590: 02800006                 be      locret_F009F5A8
F009F594: 90100018                 mov     %i0, %o0
F009F598: 7fffff26                 call    _pmap_check_page_attrib
F009F59C: 92102002                 mov     2, %o1
F009F5A0: 80a00008                 cmp     %g0, %o0
F009F5A4: a0402000                 addc    %g0, 0, %l0
F009F5A8: 81c7e008                 ret
F009F5AC: 91e80010                 restore %g0, %l0, %o0
