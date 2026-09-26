F004707C: 9de3bf98                 save    %sp, -0x68, %sp
F0047080: e0062030                 ld      [%i0+0x30], %l0
F0047084: 40000164                 call    _sunsave
F0047088: 90100010                 mov     %l0, %o0
F004708C: 90100018                 mov     %i0, %o0! vnop_fsync_args *
F0047090: 4000051d                 call    _spec_fsync
F0047094: 92100019                 mov     %i1, %o1
F0047098: d0042038                 ld      [%l0+0x38], %o0
F004709C: 80a22000                 cmp     %o0, 0
F00470A0: 22800006                 be,a    loc_F00470B8
F00470A4: d0062030                 ld      [%i0+0x30], %o0
F00470A8: 7fff86af                 call    _vn_rele
F00470AC: 01000000                 nop
F00470B0: c0242038                 clr     [%l0+0x38]
F00470B4: d0062030                 ld      [%i0+0x30], %o0
F00470B8: 4000843a                 call    _kfree
F00470BC: 9210208c                 mov     0x8C, %o1
F00470C0: 81c7e008                 ret
F00470C4: 91e82000                 restore %g0, 0, %o0
