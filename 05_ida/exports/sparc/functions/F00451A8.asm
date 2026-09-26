F00451A8: 9de3bf98                 save    %sp, -0x68, %sp
F00451AC: f0062030                 ld      [%i0+0x30], %i0
F00451B0: d0062008                 ld      [%i0+8], %o0
F00451B4: 80a22000                 cmp     %o0, 0
F00451B8: 02800004                 be      loc_F00451C8
F00451BC: a006200c                 add     %i0, 0xC, %l0
F00451C0: 7fff62a9                 call    _m_freem
F00451C4: 01000000                 nop
F00451C8: 80a6a000                 cmp     %i2, 0
F00451CC: 12800004                 bne     loc_F00451DC
F00451D0: c0262008                 clr     [%i0+8]
F00451D4: 10800008                 ba      locret_F00451F4
F00451D8: b0102001                 mov     1, %i0
F00451DC: 90102002                 mov     2, %o0
F00451E0: d026200c                 st      %o0, [%i0+0xC]
F00451E4: 90100010                 mov     %l0, %o0
F00451E8: 9fc64000                 call    %i1
F00451EC: 9210001a                 mov     %i2, %o1
F00451F0: b0100008                 mov     %o0, %i0
F00451F4: 81c7e008                 ret
F00451F8: 81e80000                 restore
