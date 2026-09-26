F0097B64: 9de3bf90                 save    %sp, -0x70, %sp
F0097B68: 7ffffc08                 call    _splusclock
F0097B6C: 01000000                 nop
F0097B70: 133fbfe4                 sethi   -0x1007000, %o1
F0097B74: 150000109412a004         set     0x4004, %o2
F0097B7C: c402400a                 ld      [%o1+%o2], %g2
F0097B80: 86100008                 mov     %o0, %g3
F0097B84: 133c04c5                 sethi   %hi(qword_F0131478), %o1
F0097B88: 80a0a000                 cmp     %g2, 0
F0097B8C: 1680000b                 bge     loc_F0097BB8
F0097B90: d81a6078                 ldd     [%o1+%lo(qword_F0131478)], %o4
F0097B94: 90102000                 mov     0, %o0
F0097B98: 1300000992126310         set     0x2710, %o1
F0097BA0: 9a834009                 addcc   %o5, %o1, %o5
F0097BA4: 98430008                 addc    %o4, %o0, %o4
F0097BA8: 94102000                 mov     0, %o2
F0097BAC: 96102001                 mov     1, %o3
F0097BB0: 10800006                 ba      loc_F0097BC8
F0097BB4: 133c04c5                 sethi   -0xFECEC00, %o1
F0097BB8: 9130a00a                 srl     %g2, 10, %o0
F0097BBC: 96100008                 mov     %o0, %o3
F0097BC0: 94102000                 mov     0, %o2
F0097BC4: 133c04c5                 sethi   -0xFECEC00, %o1
F0097BC8: d0026080                 ld      [%o1+0x80], %o0
F0097BCC: 9683400b                 addcc   %o5, %o3, %o3
F0097BD0: 9443000a                 addc    %o4, %o2, %o2
F0097BD4: 80a2000a                 cmp     %o0, %o2
F0097BD8: 12800008                 bne     loc_F0097BF8
F0097BDC: 92126080                 bset    0x80, %o1
F0097BE0: d0026004                 ld      [%o1+4], %o0
F0097BE4: 80a2000b                 cmp     %o0, %o3
F0097BE8: 32800005                 bne,a   loc_F0097BFC
F0097BEC: 113c04c5                 sethi   -0xFECEC00, %o0
F0097BF0: 9682e001                 inccc   %o3
F0097BF4: 9442a000                 addc    %o2, 0, %o2
F0097BF8: 113c04c5                 sethi   -0xFECEC00, %o0
F0097BFC: d43a2080                 std     %o2, [%o0+0x80]
F0097C00: d43fbff0                 std     %o2, [%fp+var_10]
F0097C04: 7ffffc48                 call    _splx
F0097C08: 90100003                 mov     %g3, %o0
F0097C0C: d41fbff0                 ldd     [%fp+var_10], %o2
F0097C10: 9210000a                 mov     %o2, %o1
F0097C14: 90102000                 mov     0, %o0
F0097C18: d2262004                 st      %o1, [%i0+4]
F0097C1C: d6260000                 st      %o3, [%i0]
F0097C20: 81c7e008                 ret
F0097C24: 81e80000                 restore
