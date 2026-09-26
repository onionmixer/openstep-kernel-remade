F007A350: 9de3bf98                 save    %sp, -0x68, %sp
F007A354: d006600c                 ld      [%i1+0xC], %o0
F007A358: 80a22000                 cmp     %o0, 0
F007A35C: 12800008                 bne     loc_F007A37C
F007A360: 01000000                 nop
F007A364: d2066008                 ld      [%i1+8], %o1
F007A368: d4066004                 ld      [%i1+4], %o2
F007A36C: 9fc28000                 call    %o2
F007A370: 90100018                 mov     %i0, %o0
F007A374: 10800018                 ba      locret_F007A3D4
F007A378: b0100008                 mov     %o0, %i0
F007A37C: 7fffb73d                 call    _kalloc
F007A380: 11000008                 sethi   0x2000, %o0
F007A384: a0100008                 mov     %o0, %l0
F007A388: d2066008                 ld      [%i1+8], %o1
F007A38C: 90100018                 mov     %i0, %o0
F007A390: d222200c                 st      %o1, [%o0+0xC]
F007A394: d4066004                 ld      [%i1+4], %o2
F007A398: 9fc28000                 call    %o2
F007A39C: 92100010                 mov     %l0, %o1
F007A3A0: f004201c                 ld      [%l0+0x1C], %i0
F007A3A4: 80a63ecf                 cmp     %i0, -0x131
F007A3A8: 12800004                 bne     loc_F007A3B8
F007A3AC: 90100010                 mov     %l0, %o0
F007A3B0: 10800007                 ba      loc_F007A3CC
F007A3B4: b0102000                 mov     0, %i0
F007A3B8: 92102000                 mov     0, %o1
F007A3BC: 7fffae46                 call    _msg_send
F007A3C0: 94102000                 mov     0, %o2
F007A3C4: b0100008                 mov     %o0, %i0
F007A3C8: 90100010                 mov     %l0, %o0
F007A3CC: 7fffb775                 call    _kfree
F007A3D0: 13000008                 sethi   0x2000, %o1
F007A3D4: 81c7e008                 ret
F007A3D8: 81e80000                 restore
