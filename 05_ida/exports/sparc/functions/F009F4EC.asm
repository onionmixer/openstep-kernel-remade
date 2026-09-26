F009F4EC: 9de3bf98                 save    %sp, -0x68, %sp
F009F4F0: 113c0464                 sethi   %hi(_physmax), %o0
F009F4F4: d0022388                 ld      [%o0+%lo(_physmax)], %o0
F009F4F8: 80a60008                 cmp     %i0, %o0
F009F4FC: 1a80000b                 bcc     locret_F009F528
F009F500: a0102000                 mov     0, %l0
F009F504: 7fff9bb3                 call    _vm_valid_page
F009F508: 90100018                 mov     %i0, %o0
F009F50C: 80a22000                 cmp     %o0, 0
F009F510: 02800006                 be      locret_F009F528
F009F514: 90100018                 mov     %i0, %o0
F009F518: 7fffff46                 call    _pmap_check_page_attrib
F009F51C: 92102001                 mov     1, %o1
F009F520: 80a00008                 cmp     %g0, %o0
F009F524: a0402000                 addc    %g0, 0, %l0
F009F528: 81c7e008                 ret
F009F52C: 91e80010                 restore %g0, %l0, %o0
