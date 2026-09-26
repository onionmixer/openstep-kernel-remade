F0097C28: 9de3bf90                 save    %sp, -0x70, %sp
F0097C2C: 7ffffbd7                 call    _splusclock
F0097C30: 01000000                 nop
F0097C34: 133fbfe4                 sethi   -0x1007000, %o1
F0097C38: 150000109412a004         set     0x4004, %o2
F0097C40: c402400a                 ld      [%o1+%o2], %g2
F0097C44: 86100008                 mov     %o0, %g3
F0097C48: 133c04c5                 sethi   %hi(qword_F0131478), %o1
F0097C4C: 80a0a000                 cmp     %g2, 0
F0097C50: 1680000b                 bge     loc_F0097C7C
F0097C54: d81a6078                 ldd     [%o1+%lo(qword_F0131478)], %o4
F0097C58: 90102000                 mov     0, %o0
F0097C5C: 1300000992126310         set     0x2710, %o1
F0097C64: 9a834009                 addcc   %o5, %o1, %o5
F0097C68: 98430008                 addc    %o4, %o0, %o4
F0097C6C: 94102000                 mov     0, %o2
F0097C70: 96102001                 mov     1, %o3
F0097C74: 10800006                 ba      loc_F0097C8C
F0097C78: 133c04c5                 sethi   -0xFECEC00, %o1
F0097C7C: 9130a00a                 srl     %g2, 10, %o0
F0097C80: 96100008                 mov     %o0, %o3
F0097C84: 94102000                 mov     0, %o2
F0097C88: 133c04c5                 sethi   -0xFECEC00, %o1
F0097C8C: d0026080                 ld      [%o1+0x80], %o0
F0097C90: 9683400b                 addcc   %o5, %o3, %o3
F0097C94: 9443000a                 addc    %o4, %o2, %o2
F0097C98: 80a2000a                 cmp     %o0, %o2
F0097C9C: 12800008                 bne     loc_F0097CBC
F0097CA0: 92126080                 bset    0x80, %o1
F0097CA4: d0026004                 ld      [%o1+4], %o0
F0097CA8: 80a2000b                 cmp     %o0, %o3
F0097CAC: 32800005                 bne,a   loc_F0097CC0
F0097CB0: 113c04c5                 sethi   -0xFECEC00, %o0
F0097CB4: 9682e001                 inccc   %o3
F0097CB8: 9442a000                 addc    %o2, 0, %o2
F0097CBC: 113c04c5                 sethi   -0xFECEC00, %o0
F0097CC0: d43a2080                 std     %o2, [%o0+0x80]
F0097CC4: d43fbff0                 std     %o2, [%fp+var_10]
F0097CC8: 7ffffc17                 call    _splx
F0097CCC: 90100003                 mov     %g3, %o0
F0097CD0: f007bff4                 ld      [%fp+var_10+4], %i0
F0097CD4: 81c7e008                 ret
F0097CD8: 81e80000                 restore
