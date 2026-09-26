F000B5B0: 9de3bf58                 save    %sp, -0xA8, %sp
F000B5B4: d0562002                 ldsh    [%i0+2], %o0
F000B5B8: 80a22002                 cmp     %o0, 2
F000B5BC: 02800004                 be      loc_F000B5CC
F000B5C0: 80a6a002                 cmp     %i2, 2
F000B5C4: 12800010                 bne     loc_F000B604
F000B5C8: 80a22001                 cmp     %o0, 1
F000B5CC: d0066018                 ld      [%i1+0x18], %o0
F000B5D0: 133c04cf                 sethi   %hi(_active_u), %o1
F000B5D4: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F000B5D8: d402201c                 ld      [%o0+0x1C], %o2
F000B5DC: d602a014                 ld      [%o2+0x14], %o3
F000B5E0: d402601c                 ld      [%o1+0x1C], %o2
F000B5E4: 9fc2c000                 call    %o3
F000B5E8: 9207bfb8                 add     %fp, var_48, %o1
F000B5EC: 80a22000                 cmp     %o0, 0
F000B5F0: 22800004                 be,a    loc_F000B600
F000B5F4: d0562002                 ldsh    [%i0+2], %o0
F000B5F8: 10800027                 ba      locret_F000B694
F000B5FC: b0100008                 mov     %o0, %i0
F000B600: 80a22001                 cmp     %o0, 1
F000B604: 0280000d                 be      loc_F000B638
F000B608: 80a22001                 cmp     %o0, 1
F000B60C: 14800007                 bg      loc_F000B628
F000B610: 80a22002                 cmp     %o0, 2
F000B614: 80a22000                 cmp     %o0, 0
F000B618: 0280000f                 be      loc_F000B654
F000B61C: 912ea010                 sll     %i2, 16, %o0
F000B620: 1080001d                 ba      locret_F000B694
F000B624: b0102016                 mov     0x16, %i0
F000B628: 22800007                 be,a    loc_F000B644
F000B62C: d0062004                 ld      [%i0+4], %o0
F000B630: 10800019                 ba      locret_F000B694
F000B634: b0102016                 mov     0x16, %i0
F000B638: d0062004                 ld      [%i0+4], %o0
F000B63C: 10800003                 ba      loc_F000B648
F000B640: d206601c                 ld      [%i1+0x1C], %o1
F000B644: d207bfd0                 ld      [%fp+var_30], %o1
F000B648: 90020009                 add     %o0, %o1, %o0
F000B64C: d0262004                 st      %o0, [%i0+4]
F000B650: 912ea010                 sll     %i2, 16, %o0
F000B654: 913a2010                 sra     %o0, 16, %o0
F000B658: 80a22001                 cmp     %o0, 1
F000B65C: 02800007                 be      loc_F000B678
F000B660: f4362002                 sth     %i2, [%i0+2]
F000B664: 80a22002                 cmp     %o0, 2
F000B668: 22800007                 be,a    loc_F000B684
F000B66C: d0062004                 ld      [%i0+4], %o0
F000B670: 10800009                 ba      locret_F000B694
F000B674: b0102000                 mov     0, %i0
F000B678: d0062004                 ld      [%i0+4], %o0
F000B67C: 10800003                 ba      loc_F000B688
F000B680: d206601c                 ld      [%i1+0x1C], %o1
F000B684: d207bfd0                 ld      [%fp+var_30], %o1
F000B688: 90220009                 sub     %o0, %o1, %o0
F000B68C: d0262004                 st      %o0, [%i0+4]
F000B690: b0102000                 mov     0, %i0
F000B694: 81c7e008                 ret
F000B698: 81e80000                 restore
