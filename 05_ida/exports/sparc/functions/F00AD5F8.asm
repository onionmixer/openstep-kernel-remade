F00AD5F8: 9de3bf98                 save    %sp, -0x68, %sp
F00AD5FC: d2066020                 ld      [%i1+0x20], %o1
F00AD600: d006601c                 ld      [%i1+0x1C], %o0
F00AD604: 80924008                 orcc    %o1, %o0, %g0
F00AD608: 02800042                 be      locret_F00AD710
F00AD60C: 90100018                 mov     %i0, %o0
F00AD610: 4000052d                 call    _fpu_set_exception
F00AD614: 92102000                 mov     0, %o1
F00AD618: d0062004                 ld      [%i0+4], %o0
F00AD61C: 80a22001                 cmp     %o0, 1
F00AD620: 22800012                 be,a    loc_F00AD668
F00AD624: a0102000                 mov     0, %l0
F00AD628: 0a800008                 bcs     loc_F00AD648
F00AD62C: 80a22002                 cmp     %o0, 2
F00AD630: 02800008                 be      loc_F00AD650
F00AD634: 80a22003                 cmp     %o0, 3
F00AD638: 2280000a                 be,a    loc_F00AD660
F00AD63C: d0064000                 ld      [%i1], %o0
F00AD640: 1080000b                 ba      loc_F00AD66C
F00AD644: 80a42000                 cmp     %l0, 0
F00AD648: 10800008                 ba      loc_F00AD668
F00AD64C: e006601c                 ld      [%i1+0x1C], %l0
F00AD650: d0064000                 ld      [%i1], %o0
F00AD654: 80a00008                 cmp     %g0, %o0
F00AD658: 10800004                 ba      loc_F00AD668
F00AD65C: a0603fff                 subc    %g0, -1, %l0
F00AD660: 80a00008                 cmp     %g0, %o0
F00AD664: a0402000                 addc    %g0, 0, %l0
F00AD668: 80a42000                 cmp     %l0, 0
F00AD66C: 2280001d                 be,a    loc_F00AD6E0
F00AD670: d0062004                 ld      [%i0+4], %o0
F00AD674: d0066018                 ld      [%i1+0x18], %o0
F00AD678: 90022001                 inc     %o0
F00AD67C: 80a22000                 cmp     %o0, 0
F00AD680: 12800017                 bne     loc_F00AD6DC
F00AD684: d0266018                 st      %o0, [%i1+0x18]
F00AD688: d0066014                 ld      [%i1+0x14], %o0
F00AD68C: 90022001                 inc     %o0
F00AD690: 80a22000                 cmp     %o0, 0
F00AD694: 12800012                 bne     loc_F00AD6DC
F00AD698: d0266014                 st      %o0, [%i1+0x14]
F00AD69C: d0066010                 ld      [%i1+0x10], %o0
F00AD6A0: 90022001                 inc     %o0
F00AD6A4: 80a22000                 cmp     %o0, 0
F00AD6A8: 1280000d                 bne     loc_F00AD6DC
F00AD6AC: d0266010                 st      %o0, [%i1+0x10]
F00AD6B0: d006600c                 ld      [%i1+0xC], %o0
F00AD6B4: 13000080                 sethi   0x20000, %o1
F00AD6B8: 90022001                 inc     %o0
F00AD6BC: 80a20009                 cmp     %o0, %o1
F00AD6C0: 12800007                 bne     loc_F00AD6DC
F00AD6C4: d026600c                 st      %o0, [%i1+0xC]
F00AD6C8: d0066008                 ld      [%i1+8], %o0
F00AD6CC: 13000040                 sethi   0x10000, %o1
F00AD6D0: d226600c                 st      %o1, [%i1+0xC]
F00AD6D4: 90022001                 inc     %o0
F00AD6D8: d0266008                 st      %o0, [%i1+8]
F00AD6DC: d0062004                 ld      [%i0+4], %o0
F00AD6E0: 80a22000                 cmp     %o0, 0
F00AD6E4: 1280000b                 bne     locret_F00AD710
F00AD6E8: 01000000                 nop
F00AD6EC: d0066020                 ld      [%i1+0x20], %o0
F00AD6F0: 80a22000                 cmp     %o0, 0
F00AD6F4: 12800007                 bne     locret_F00AD710
F00AD6F8: 80a42000                 cmp     %l0, 0
F00AD6FC: 02800005                 be      locret_F00AD710
F00AD700: 01000000                 nop
F00AD704: d0066018                 ld      [%i1+0x18], %o0
F00AD708: 900a3ffe                 and     %o0, -2, %o0
F00AD70C: d0266018                 st      %o0, [%i1+0x18]
F00AD710: 81c7e008                 ret
F00AD714: 81e80000                 restore
