F0045858: 9de3bf98                 save    %sp, -0x68, %sp
F004585C: e0064000                 ld      [%i1], %l0
F0045860: 90100018                 mov     %i0, %o0! XDR *
F0045864: 7fffff02                 call    _xdr_u_int
F0045868: 9210001a                 mov     %i2, %o1
F004586C: 80a22000                 cmp     %o0, 0
F0045870: 32800005                 bne,a   loc_F0045884
F0045874: f4068000                 ld      [%i2], %i2
F0045878: 113c0437                 sethi   %hi(aXdrBytesSizeFa), %o0! "xdr_bytes: size FAILED\n"
F004587C: 1080002b                 ba      loc_F0045928
F0045880: 901223a8                 bset    %lo(aXdrBytesSizeFa), %o0! "xdr_bytes: size FAILED\n"
F0045884: 80a6801b                 cmp     %i2, %i3
F0045888: 08800008                 bleu    loc_F00458A8
F004588C: d0060000                 ld      [%i0], %o0
F0045890: 80a22002                 cmp     %o0, 2
F0045894: 02800004                 be      loc_F00458A4
F0045898: 113c0437                 sethi   %hi(aXdrBytesBadSiz), %o0! "xdr_bytes: bad size FAILED\n"
F004589C: 10800023                 ba      loc_F0045928
F00458A0: 901223c0                 bset    %lo(aXdrBytesBadSiz), %o0! "xdr_bytes: bad size FAILED\n"
F00458A4: d0060000                 ld      [%i0], %o0
F00458A8: 80a22001                 cmp     %o0, 1
F00458AC: 22800008                 be,a    loc_F00458CC
F00458B0: 80a6a000                 cmp     %i2, 0
F00458B4: 0a800010                 bcs     loc_F00458F4
F00458B8: 80a22002                 cmp     %o0, 2
F00458BC: 02800014                 be      loc_F004590C
F00458C0: 80a42000                 cmp     %l0, 0
F00458C4: 10800018                 ba      loc_F0045924
F00458C8: 113c0437                 sethi   -0xFEF2400, %o0
F00458CC: 12800004                 bne     loc_F00458DC
F00458D0: 80a42000                 cmp     %l0, 0
F00458D4: 10800017                 ba      locret_F0045930
F00458D8: b0102001                 mov     1, %i0
F00458DC: 12800007                 bne     loc_F00458F8
F00458E0: 90100018                 mov     %i0, %o0
F00458E4: 400089e3                 call    _kalloc
F00458E8: 9010001a                 mov     %i2, %o0
F00458EC: a0100008                 mov     %o0, %l0
F00458F0: e0264000                 st      %l0, [%i1]
F00458F4: 90100018                 mov     %i0, %o0! XDR *
F00458F8: 92100010                 mov     %l0, %o1! char *
F00458FC: 7fffff99                 call    _xdr_opaque
F0045900: 9410001a                 mov     %i2, %o2
F0045904: 1080000b                 ba      locret_F0045930
F0045908: b0100008                 mov     %o0, %i0
F004590C: 02bffff2                 be      loc_F00458D4
F0045910: 90100010                 mov     %l0, %o0
F0045914: 40008a23                 call    _kfree
F0045918: 9210001a                 mov     %i2, %o1
F004591C: 10bfffee                 ba      loc_F00458D4
F0045920: c0264000                 clr     [%i1]
F0045924: 901223e0                 bset    0x3E0, %o0! char *
F0045928: 7fff3b4c                 call    _printf
F004592C: b0102000                 mov     0, %i0
F0045930: 81c7e008                 ret
F0045934: 81e80000                 restore
