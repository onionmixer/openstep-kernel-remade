F0067244: 9de3bf98                 save    %sp, -0x68, %sp
F0067248: a2100018                 mov     %i0, %l1
F006724C: a00460a8                 add     %l1, 0xA8, %l0
F0067250: d0040000                 ld      [%l0], %o0
F0067254: 80a22000                 cmp     %o0, 0
F0067258: 12bffffe                 bne     loc_F0067250
F006725C: 01000000                 nop
F0067260: 4000bf12                 call    _simple_lock_try
F0067264: 90100010                 mov     %l0, %o0
F0067268: 80a22000                 cmp     %o0, 0
F006726C: 02bffff9                 be      loc_F0067250
F0067270: 01000000                 nop
F0067274: d00460ac                 ld      [%l1+0xAC], %o0
F0067278: 80a22000                 cmp     %o0, 0
F006727C: 0280000a                 be      loc_F00672A4
F0067280: b0102000                 mov     0, %i0
F0067284: f00460b8                 ld      [%l1+0xB8], %i0
F0067288: 80a62000                 cmp     %i0, 0
F006728C: 02800006                 be      loc_F00672A4
F0067290: 80a63fff                 cmp     %i0, -1
F0067294: 02800004                 be      loc_F00672A4
F0067298: 01000000                 nop
F006729C: 7fffc8e5                 call    _ipc_object_reference
F00672A0: 90100018                 mov     %i0, %o0
F00672A4: c02460a8                 clr     [%l1+0xA8]
F00672A8: 81c7e008                 ret
F00672AC: 81e80000                 restore
