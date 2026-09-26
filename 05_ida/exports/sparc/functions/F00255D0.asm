F00255D0: 9de3bf98                 save    %sp, -0x68, %sp
F00255D4: 113c04cf                 sethi   -0xFECC400, %o0
F00255D8: 94122300                 or      %o0, 0x300, %o2
F00255DC: 9002a0c0                 add     %o2, 0xC0, %o0
F00255E0: 80a28008                 cmp     %o2, %o0
F00255E4: 1a80001c                 bcc     locret_F0025654
F00255E8: 17000040                 sethi   0x10000, %o3
F00255EC: 98100008                 mov     %o0, %o4
F00255F0: d202a004                 ld      [%o2+4], %o1
F00255F4: 80a2400a                 cmp     %o1, %o2
F00255F8: 22800014                 be,a    loc_F0025648
F00255FC: 9402a00c                 inc     0xC, %o2
F0025600: d0026040                 ld      [%o1+0x40], %o0
F0025604: 80a20018                 cmp     %o0, %i0
F0025608: 3280000c                 bne,a   loc_F0025638
F002560C: d2026004                 ld      [%o1+4], %o1
F0025610: d0024000                 ld      [%o1], %o0
F0025614: 808a000b                 btst    %o3, %o0
F0025618: 32800008                 bne,a   loc_F0025638
F002561C: d2026004                 ld      [%o1+4], %o1
F0025620: 9012000b                 bset    %o3, %o0
F0025624: d0224000                 st      %o0, [%o1]
F0025628: 4000001a                 call    sub_F0025690
F002562C: 90100009                 mov     %o1, %o0
F0025630: 10bfffea                 ba      loc_F00255D8
F0025634: 113c04cf                 sethi   -0xFECC400, %o0
F0025638: 80a2400a                 cmp     %o1, %o2
F002563C: 32bffff2                 bne,a   loc_F0025604
F0025640: d0026040                 ld      [%o1+0x40], %o0
F0025644: 9402a00c                 inc     0xC, %o2
F0025648: 80a2800c                 cmp     %o2, %o4
F002564C: 2abfffea                 bcs,a   loc_F00255F4
F0025650: d202a004                 ld      [%o2+4], %o1
F0025654: 81c7e008                 ret
F0025658: 81e80000                 restore
