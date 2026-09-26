F008BD9C: 9de3bf98                 save    %sp, -0x68, %sp
F008BDA0: a0100018                 mov     %i0, %l0
F008BDA4: 7fffffc8                 call    _vswap_allocate
F008BDA8: b0102000                 mov     0, %i0
F008BDAC: 80a22000                 cmp     %o0, 0
F008BDB0: 02800005                 be      locret_F008BDC4
F008BDB4: 01000000                 nop
F008BDB8: 7ffffc69                 call    _pagerfile_pager_create
F008BDBC: 92100010                 mov     %l0, %o1
F008BDC0: b0100008                 mov     %o0, %i0
F008BDC4: 81c7e008                 ret
F008BDC8: 81e80000                 restore
