F000C5AC: 9de3bf58                 save    %sp, -0xA8, %sp
F000C5B0: 233c04cf                 sethi   %hi(_active_u), %l1
F000C5B4: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F000C5B8: d406201c                 ld      [%i0+0x1C], %o2
F000C5BC: e002201c                 ld      [%o0+0x1C], %l0
F000C5C0: 9207bfb8                 add     %fp, var_48, %o1
F000C5C4: d602a014                 ld      [%o2+0x14], %o3
F000C5C8: 90100018                 mov     %i0, %o0
F000C5CC: 9fc2c000                 call    %o3
F000C5D0: 94100010                 mov     %l0, %o2
F000C5D4: 80a22000                 cmp     %o0, 0
F000C5D8: 32800024                 bne,a   locret_F000C668
F000C5DC: b0100008                 mov     %o0, %i0
F000C5E0: d406201c                 ld      [%i0+0x1C], %o2
F000C5E4: 90100018                 mov     %i0, %o0
F000C5E8: d602a01c                 ld      [%o2+0x1C], %o3
F000C5EC: 92102040                 mov     0x40, %o1 ! '@'
F000C5F0: 9fc2c000                 call    %o3
F000C5F4: 94100010                 mov     %l0, %o2
F000C5F8: 80a22000                 cmp     %o0, 0
F000C5FC: 3280001b                 bne,a   locret_F000C668
F000C600: b0100008                 mov     %o0, %i0
F000C604: d00461d8                 ld      [%l1+0x1D8], %o0
F000C608: d0020000                 ld      [%o0], %o0
F000C60C: d0022028                 ld      [%o0+0x28], %o0
F000C610: 808a2010                 btst    0x10, %o0
F000C614: 0280000c                 be      loc_F000C644
F000C618: 90100018                 mov     %i0, %o0
F000C61C: d406201c                 ld      [%i0+0x1C], %o2
F000C620: d602a01c                 ld      [%o2+0x1C], %o3
F000C624: 92102100                 mov     0x100, %o1
F000C628: 9fc2c000                 call    %o3
F000C62C: 94100010                 mov     %l0, %o2
F000C630: 80a22000                 cmp     %o0, 0
F000C634: 22800005                 be,a    loc_F000C648
F000C638: d0062028                 ld      [%i0+0x28], %o0
F000C63C: 1080000b                 ba      locret_F000C668
F000C640: b0100008                 mov     %o0, %i0
F000C644: d0062028                 ld      [%i0+0x28], %o0
F000C648: 80a22001                 cmp     %o0, 1
F000C64C: 12800007                 bne     locret_F000C668
F000C650: b010200d                 mov     0xD, %i0
F000C654: d017bfbc                 lduh    [%fp+var_44], %o0
F000C658: 808a2049                 btst    0x49, %o0 ! 'I'
F000C65C: 12800003                 bne     locret_F000C668
F000C660: b0102000                 mov     0, %i0
F000C664: b010200d                 mov     0xD, %i0
F000C668: 81c7e008                 ret
F000C66C: 81e80000                 restore
