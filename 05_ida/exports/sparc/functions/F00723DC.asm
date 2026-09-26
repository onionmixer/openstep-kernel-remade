F00723DC: 9de3bf98                 save    %sp, -0x68, %sp
F00723E0: 233c04f0                 sethi   -0xFEC4000, %l1
F00723E4: 213c01c8                 sethi   -0xFF8E000, %l0
F00723E8: 7fffde5e                 call    _compute_mach_factor
F00723EC: 01000000                 nop
F00723F0: d0046298                 ld      [%l1+0x298], %o0
F00723F4: 808a2001                 btst    1, %o0
F00723F8: 02800005                 be      loc_F007240C
F00723FC: 90102000                 mov     0, %o0
F0072400: 40000068                 call    _do_thread_scan
F0072404: 01000000                 nop
F0072408: 90102000                 mov     0, %o0
F007240C: 7ffffa32                 call    _assert_wait
F0072410: 92102000                 mov     0, %o1
F0072414: 7ffffccb                 call    _thread_block_with_continuation
F0072418: 901423dc                 or      %l0, 0x3DC, %o0
F007241C: 30bffff3                 ba,a    loc_F00723E8
