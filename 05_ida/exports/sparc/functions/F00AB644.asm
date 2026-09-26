F00AB644: 9de3bf98                 save    %sp, -0x68, %sp
F00AB648: d6066004                 ld      [%i1+4], %o3
F00AB64C: 80a2e004                 cmp     %o3, 4
F00AB650: 0280000a                 be      loc_F00AB678
F00AB654: 90100018                 mov     %i0, %o0
F00AB658: d406a004                 ld      [%i2+4], %o2
F00AB65C: 80a2a004                 cmp     %o2, 4
F00AB660: 02800006                 be      loc_F00AB678
F00AB664: 80a2e005                 cmp     %o3, 5
F00AB668: 02800004                 be      loc_F00AB678
F00AB66C: 80a2a005                 cmp     %o2, 5
F00AB670: 12800009                 bne     loc_F00AB694
F00AB674: 80a2e000                 cmp     %o3, 0
F00AB678: 80a6e000                 cmp     %i3, 0
F00AB67C: 02800039                 be      locret_F00AB760
F00AB680: b0102003                 mov     3, %i0
F00AB684: 40000d10                 call    _fpu_set_exception
F00AB688: 92102004                 mov     4, %o1
F00AB68C: 10800035                 ba      locret_F00AB760
F00AB690: b0102003                 mov     3, %i0
F00AB694: 32800007                 bne,a   loc_F00AB6B0
F00AB698: d4064000                 ld      [%i1], %o2
F00AB69C: 80a2a000                 cmp     %o2, 0
F00AB6A0: 32800004                 bne,a   loc_F00AB6B0
F00AB6A4: d4064000                 ld      [%i1], %o2
F00AB6A8: 1080002e                 ba      locret_F00AB760
F00AB6AC: b0102000                 mov     0, %i0
F00AB6B0: d0068000                 ld      [%i2], %o0
F00AB6B4: 80a28008                 cmp     %o2, %o0
F00AB6B8: 16800004                 bge     loc_F00AB6C8
F00AB6BC: 01000000                 nop
F00AB6C0: 10800028                 ba      locret_F00AB760
F00AB6C4: b0102002                 mov     2, %i0
F00AB6C8: 14800026                 bg      locret_F00AB760
F00AB6CC: b0102001                 mov     1, %i0
F00AB6D0: d0066004                 ld      [%i1+4], %o0
F00AB6D4: d406a004                 ld      [%i2+4], %o2
F00AB6D8: 80a2000a                 cmp     %o0, %o2
F00AB6DC: 14800019                 bg      loc_F00AB740
F00AB6E0: b0102002                 mov     2, %i0
F00AB6E4: 80a2000a                 cmp     %o0, %o2
F00AB6E8: 0680000d                 bl      loc_F00AB71C
F00AB6EC: 80a22002                 cmp     %o0, 2
F00AB6F0: 32800004                 bne,a   loc_F00AB700
F00AB6F4: d4066008                 ld      [%i1+8], %o2
F00AB6F8: 10800012                 ba      loc_F00AB740
F00AB6FC: b0102000                 mov     0, %i0
F00AB700: d006a008                 ld      [%i2+8], %o0
F00AB704: 80a28008                 cmp     %o2, %o0
F00AB708: 1480000e                 bg      loc_F00AB740
F00AB70C: b0102002                 mov     2, %i0
F00AB710: 80a28008                 cmp     %o2, %o0
F00AB714: 16800004                 bge     loc_F00AB724
F00AB718: 9006600c                 add     %i1, 0xC, %o0
F00AB71C: 10800009                 ba      loc_F00AB740
F00AB720: b0102001                 mov     1, %i0
F00AB724: 9206a00c                 add     %i2, 0xC, %o1
F00AB728: 40000d26                 call    _fpu_cmpli
F00AB72C: 94102004                 mov     4, %o2
F00AB730: 80a22000                 cmp     %o0, 0
F00AB734: 14800003                 bg      loc_F00AB740
F00AB738: b0102002                 mov     2, %i0
F00AB73C: b132201f                 srl     %o0, 31, %i0
F00AB740: d0064000                 ld      [%i1], %o0
F00AB744: 80a22000                 cmp     %o0, 0
F00AB748: 02800006                 be      locret_F00AB760
F00AB74C: 80a62001                 cmp     %i0, 1
F00AB750: 02bfffdc                 be      loc_F00AB6C0
F00AB754: 80a62002                 cmp     %i0, 2
F00AB758: 22800002                 be,a    locret_F00AB760
F00AB75C: b0102001                 mov     1, %i0
F00AB760: 81c7e008                 ret
F00AB764: 81e80000                 restore
