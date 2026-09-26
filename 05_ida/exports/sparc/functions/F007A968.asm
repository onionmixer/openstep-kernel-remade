F007A968: 9de3bf98                 save    %sp, -0x68, %sp
F007A96C: f0060000                 ld      [%i0], %i0
F007A970: d2062030                 ld      [%i0+0x30], %o1
F007A974: 80a26000                 cmp     %o1, 0
F007A978: 12800008                 bne     loc_F007A998
F007A97C: f2262030                 st      %i1, [%i0+0x30]
F007A980: 80a66000                 cmp     %i1, 0
F007A984: 02800005                 be      loc_F007A998
F007A988: 90062024                 add     %i0, 0x24, %o0 ! '$'
F007A98C: 400000c2                 call    sub_F007AC94
F007A990: 921021f4                 mov     0x1F4, %o1
F007A994: 30800009                 ba,a    locret_F007A9B8
F007A998: d0062030                 ld      [%i0+0x30], %o0
F007A99C: 80a22000                 cmp     %o0, 0
F007A9A0: 12800006                 bne     locret_F007A9B8
F007A9A4: 80a26000                 cmp     %o1, 0
F007A9A8: 02800004                 be      locret_F007A9B8
F007A9AC: 01000000                 nop
F007A9B0: 400000cf                 call    sub_F007ACEC
F007A9B4: 90062024                 add     %i0, 0x24, %o0 ! '$'
F007A9B8: 81c7e008                 ret
F007A9BC: 91e82000                 restore %g0, 0, %o0
