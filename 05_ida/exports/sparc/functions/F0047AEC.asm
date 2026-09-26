F0047AEC: 9de3bf90                 save    %sp, -0x70, %sp
F0047AF0: a4100018                 mov     %i0, %l2
F0047AF4: d0048000                 ld      [%l2], %o0
F0047AF8: e6022030                 ld      [%o0+0x30], %l3
F0047AFC: d0022028                 ld      [%o0+0x28], %o0
F0047B00: 92023ffd                 add     %o0, -3, %o1
F0047B04: 80a26006                 cmp     %o1, 6! switch 7 cases
F0047B08: 18800067                 bgu     def_F0047B20! jumptable F0047B20 default case, cases 2,4
F0047B0C: e014e042                 lduh    [%l3+0x42], %l0
F0047B10: 113c011e90122328         set     jpt_F0047B20, %o0
F0047B18: 932a6002                 sll     %o1, 2, %o1
F0047B1C: d0024008                 ld      [%o1+%o0], %o0
F0047B20: 81c20000                 jmp     %o0! switch jump
F0047B24: 01000000                 nop
F0047B44: e037bff6                 sth     %l0, [%fp+var_A]! jumptable F0047B20 cases 1,6
F0047B48: 113c0472a81221f0         set     _cdevsw, %l4
F0047B50: e017bff6                 lduh    [%fp+var_A], %l0
F0047B54: 113c0474                 sethi   %hi(_nchrdev), %o0
F0047B58: d2022154                 ld      [%o0+%lo(_nchrdev)], %o1
F0047B5C: 972c2010                 sll     %l0, 16, %o3
F0047B60: 9132e018                 srl     %o3, 24, %o0
F0047B64: 80a20009                 cmp     %o0, %o1
F0047B68: 1a80004d                 bcc     loc_F0047C9C
F0047B6C: a210000b                 mov     %o3, %l1
F0047B70: a13c6010                 sra     %l1, 16, %l0
F0047B74: d0048000                 ld      [%l2], %o0
F0047B78: d2022028                 ld      [%o0+0x28], %o1
F0047B7C: 7ffffeeb                 call    _isclosing
F0047B80: 90100010                 mov     %l0, %o0
F0047B84: 80a22000                 cmp     %o0, 0
F0047B88: 02800006                 be      loc_F0047BA0
F0047B8C: 90100013                 mov     %l3, %o0! unsigned int
F0047B90: 7fff2aba                 call    _sleep
F0047B94: 92102028                 mov     0x28, %o1 ! '('
F0047B98: 10bffff8                 ba      loc_F0047B78
F0047B9C: d0048000                 ld      [%l2], %o0
F0047BA0: 90100010                 mov     %l0, %o0
F0047BA4: 97346018                 srl     %l1, 24, %o3
F0047BA8: 952ae001                 sll     %o3, 1, %o2
F0047BAC: 9402800b                 add     %o2, %o3, %o2
F0047BB0: 952aa002                 sll     %o2, 2, %o2
F0047BB4: 9422800b                 sub     %o2, %o3, %o2
F0047BB8: 952aa002                 sll     %o2, 2, %o2
F0047BBC: d6028014                 ld      [%o2+%l4], %o3
F0047BC0: 92100019                 mov     %i1, %o1
F0047BC4: 9fc2c000                 call    %o3
F0047BC8: 9407bff6                 add     %fp, var_A, %o2
F0047BCC: d257bff6                 ldsh    [%fp+var_A], %o1
F0047BD0: 80a24010                 cmp     %o1, %l0
F0047BD4: 02800035                 be      loc_F0047CA8
F0047BD8: b0100008                 mov     %o0, %i0
F0047BDC: 80a62000                 cmp     %i0, 0
F0047BE0: 02800006                 be      loc_F0047BF8
F0047BE4: 80a6200b                 cmp     %i0, 0xB
F0047BE8: 02800004                 be      loc_F0047BF8
F0047BEC: 80a62011                 cmp     %i0, 0x11
F0047BF0: 1280002f                 bne     loc_F0047CAC
F0047BF4: 80a62000                 cmp     %i0, 0
F0047BF8: d0048000                 ld      [%l2], %o0
F0047BFC: d257bff6                 ldsh    [%fp+var_A], %o1
F0047C00: 7ffffde6                 call    _specvp
F0047C04: 94102004                 mov     4, %o2
F0047C08: a0100008                 mov     %o0, %l0
F0047C0C: d0048000                 ld      [%l2], %o0
F0047C10: 7fff83d5                 call    _vn_rele
F0047C14: e6042030                 ld      [%l0+0x30], %l3
F0047C18: 10bfffce                 ba      loc_F0047B50
F0047C1C: e0248000                 st      %l0, [%l2]
F0047C20: 113c0439                 sethi   %hi(aSpecOpenGotAVf), %o0! jumptable F0047B20 case 5
F0047C24: 7fff328d                 call    _printf
F0047C28: 90122058                 bset    %lo(aSpecOpenGotAVf), %o0! "spec_open: got a VFIFO???\n"
F0047C2C: 1080001f                 ba      loc_F0047CA8! jumptable F0047B20 case 3
F0047C30: b010202d                 mov     0x2D, %i0 ! '-'
F0047C34: 912c2010                 sll     %l0, 16, %o0! jumptable F0047B20 case 0
F0047C38: 133c0472                 sethi   %hi(_nblkdev), %o1
F0047C3C: d20261ec                 ld      [%o1+%lo(_nblkdev)], %o1
F0047C40: 95322018                 srl     %o0, 24, %o2
F0047C44: 80a28009                 cmp     %o2, %o1
F0047C48: 0a800004                 bcs     loc_F0047C58
F0047C4C: 913a2010                 sra     %o0, 16, %o0
F0047C50: 1080000b                 ba      loc_F0047C7C
F0047C54: b0102006                 mov     6, %i0
F0047C58: 932aa001                 sll     %o2, 1, %o1
F0047C5C: 9202400a                 add     %o1, %o2, %o1
F0047C60: 932a6003                 sll     %o1, 3, %o1
F0047C64: 153c04719412a3ac         set     _bdevsw, %o2
F0047C6C: d402400a                 ld      [%o1+%o2], %o2
F0047C70: 9fc28000                 call    %o2
F0047C74: 92100019                 mov     %i1, %o1
F0047C78: b0100008                 mov     %o0, %i0
F0047C7C: 80a62000                 cmp     %i0, 0
F0047C80: 1280000b                 bne     loc_F0047CAC
F0047C84: 90100013                 mov     %l3, %o0
F0047C88: 932c2010                 sll     %l0, 16, %o1
F0047C8C: 7ffffd9e                 call    _set_blocksize
F0047C90: 933a6010                 sra     %o1, 16, %o1
F0047C94: 10800006                 ba      loc_F0047CAC
F0047C98: 80a62000                 cmp     %i0, 0
F0047C9C: 10800009                 ba      locret_F0047CC0
F0047CA0: b0102006                 mov     6, %i0
F0047CA4: b0102000                 mov     0, %i0! jumptable F0047B20 default case, cases 2,4
F0047CA8: 80a62000                 cmp     %i0, 0
F0047CAC: 12800005                 bne     locret_F0047CC0
F0047CB0: 01000000                 nop
F0047CB4: d004e064                 ld      [%l3+0x64], %o0
F0047CB8: 90022001                 inc     %o0
F0047CBC: d024e064                 st      %o0, [%l3+0x64]
F0047CC0: 81c7e008                 ret
F0047CC4: 81e80000                 restore
