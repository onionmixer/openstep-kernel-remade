F007B5B4: 9de3bf98                 save    %sp, -0x68, %sp
F007B5B8: d2062004                 ld      [%i0+4], %o1
F007B5BC: 80a26028                 cmp     %o1, 0x28 ! '('
F007B5C0: 12800005                 bne     loc_F007B5D4
F007B5C4: d00e2003                 ldub    [%i0+3], %o0
F007B5C8: 80a22001                 cmp     %o0, 1
F007B5CC: 22800005                 be,a    loc_F007B5E0
F007B5D0: d0062018                 ld      [%i0+0x18], %o0
F007B5D4: 90103ed0                 mov     -0x130, %o0
F007B5D8: 1080001f                 ba      locret_F007B654
F007B5DC: d026601c                 st      %o0, [%i1+0x1C]
F007B5E0: 133c03d3                 sethi   %hi(dword_F00F4DA8), %o1
F007B5E4: d20261a8                 ld      [%o1+%lo(dword_F00F4DA8)], %o1
F007B5E8: 80a20009                 cmp     %o0, %o1
F007B5EC: 12800012                 bne     loc_F007B634
F007B5F0: 90103ed0                 mov     -0x130, %o0
F007B5F4: d0062020                 ld      [%i0+0x20], %o0
F007B5F8: 133c03d3                 sethi   %hi(dword_F00F4DAC), %o1
F007B5FC: d20261ac                 ld      [%o1+%lo(dword_F00F4DAC)], %o1
F007B600: 80a20009                 cmp     %o0, %o1
F007B604: 1280000c                 bne     loc_F007B634
F007B608: 90103ed0                 mov     -0x130, %o0
F007B60C: d606a014                 ld      [%i2+0x14], %o3
F007B610: 80a2e000                 cmp     %o3, 0
F007B614: 32800005                 bne,a   loc_F007B628
F007B618: d0068000                 ld      [%i2], %o0
F007B61C: 90103ed1                 mov     -0x12F, %o0
F007B620: 1080000d                 ba      locret_F007B654
F007B624: d026601c                 st      %o0, [%i1+0x1C]
F007B628: d206201c                 ld      [%i0+0x1C], %o1
F007B62C: 9fc2c000                 call    %o3
F007B630: d4062024                 ld      [%i0+0x24], %o2
F007B634: d026601c                 st      %o0, [%i1+0x1C]
F007B638: d006601c                 ld      [%i1+0x1C], %o0
F007B63C: 80a22000                 cmp     %o0, 0
F007B640: 12800005                 bne     locret_F007B654
F007B644: 92102020                 mov     0x20, %o1 ! ' '
F007B648: 90102001                 mov     1, %o0
F007B64C: d02e6003                 stb     %o0, [%i1+3]
F007B650: d2266004                 st      %o1, [%i1+4]
F007B654: 81c7e008                 ret
F007B658: 81e80000                 restore
