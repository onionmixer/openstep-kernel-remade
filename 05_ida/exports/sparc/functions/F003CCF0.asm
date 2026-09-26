F003CCF0: 9de3bf90                 save    %sp, -0x70, %sp
F003CCF4: a6100018                 mov     %i0, %l3
F003CCF8: a4102000                 mov     0, %l2
F003CCFC: 90100013                 mov     %l3, %o0
F003CD00: 40000178                 call    sub_F003D2E0
F003CD04: 9210001a                 mov     %i2, %o1
F003CD08: a2920000                 orcc    %o0, %g0, %l1
F003CD0C: 12800067                 bne     loc_F003CEA8
F003CD10: 80a66000                 cmp     %i1, 0
F003CD14: 173c0434                 sethi   %hi(_rpfreelist), %o3
F003CD18: d402e048                 ld      [%o3+%lo(_rpfreelist)], %o2
F003CD1C: 80a2a000                 cmp     %o2, 0
F003CD20: 02800015                 be      loc_F003CD74
F003CD24: 113c04ea                 sethi   %hi(_rnew), %o0
F003CD28: d2022268                 ld      [%o0+%lo(_rnew)], %o1
F003CD2C: 113c0433                 sethi   %hi(_nrnode), %o0
F003CD30: d0022178                 ld      [%o0+%lo(_nrnode)], %o0
F003CD34: 80a24008                 cmp     %o1, %o0
F003CD38: 0680000f                 bl      loc_F003CD74
F003CD3C: a210000a                 mov     %o2, %l1
F003CD40: d2044000                 ld      [%l1], %o1
F003CD44: 90100011                 mov     %l1, %o0
F003CD48: 40000133                 call    sub_F003D214
F003CD4C: d222e048                 st      %o1, [%o3+%lo(_rpfreelist)]
F003CD50: 400000b7                 call    _rp_rmhash
F003CD54: 90100011                 mov     %l1, %o0
F003CD58: 4000014b                 call    _rinactive
F003CD5C: 90100011                 mov     %l1, %o0
F003CD60: 133c04ea                 sethi   %hi(_rreuse), %o1
F003CD64: d0026290                 ld      [%o1+%lo(_rreuse)], %o0
F003CD68: 90022001                 inc     %o0
F003CD6C: 10800019                 ba      loc_F003CDD0
F003CD70: d0226290                 st      %o0, [%o1+%lo(_rreuse)]
F003CD74: 213c0434                 sethi   %hi(_rnode_zone), %l0
F003CD78: d004204c                 ld      [%l0+%lo(_rnode_zone)], %o0
F003CD7C: 80a22000                 cmp     %o0, 0
F003CD80: 1280000a                 bne     loc_F003CDA8
F003CD84: 94102000                 mov     0, %o2
F003CD88: 901020c8                 mov     0xC8, %o0
F003CD8C: 130007a192126080         set     0x1E8480, %o1
F003CD94: 96102000                 mov     0, %o3
F003CD98: 193c0434                 sethi   %hi(aRnodeStructure), %o4! "rnode structures"
F003CD9C: 4000ec67                 call    _zinit
F003CDA0: 98132050                 bset    %lo(aRnodeStructure), %o4! "rnode structures"
F003CDA4: d024204c                 st      %o0, [%l0+%lo(_rnode_zone)]
F003CDA8: 4000f0c9                 call    _zalloc
F003CDAC: d004204c                 ld      [%l0+0x4C], %o0
F003CDB0: a2100008                 mov     %o0, %l1
F003CDB4: c024600c                 clr     [%l1+0xC]
F003CDB8: 4000bcf1                 call    _vm_info_init
F003CDBC: 9004600c                 add     %l1, 0xC, %o0
F003CDC0: 133c04ea                 sethi   %hi(_rnew), %o1! size_t
F003CDC4: d0026268                 ld      [%o1+%lo(_rnew)], %o0
F003CDC8: 90022001                 inc     %o0
F003CDCC: d0226268                 st      %o0, [%o1+%lo(_rnew)]
F003CDD0: b004600c                 add     %l1, 0xC, %i0
F003CDD4: 90100011                 mov     %l1, %o0! void *
F003CDD8: e004600c                 ld      [%l1+0xC], %l0
F003CDDC: 4001601f                 call    _bzero
F003CDE0: 921020c8                 mov     0xC8, %o1
F003CDE4: e024600c                 st      %l0, [%l1+0xC]
F003CDE8: 4000beef                 call    _mfs_uncache
F003CDEC: 90100018                 mov     %i0, %o0
F003CDF0: d204600c                 ld      [%l1+0xC], %o1
F003CDF4: 90100013                 mov     %l3, %o0! void *
F003CDF8: c0224000                 clr     [%o1]
F003CDFC: d804600c                 ld      [%l1+0xC], %o4
F003CE00: 94102020                 mov     0x20, %o2 ! ' '! size_t
F003CE04: d6046098                 ld      [%l1+0x98], %o3
F003CE08: 92046040                 add     %l1, 0x40, %o1 ! '@'! void *
F003CE0C: 40015f41                 call    _bcopy
F003CE10: d6232014                 st      %o3, [%o4+0x14]
F003CE14: 90102001                 mov     1, %o0
F003CE18: d0346012                 sth     %o0, [%l1+0x12]
F003CE1C: 113c0435901221cc         set     _nfs_vnodeops, %o0
F003CE24: 80a66000                 cmp     %i1, 0
F003CE28: 02800016                 be      loc_F003CE80
F003CE2C: d0246028                 st      %o0, [%l1+0x28]
F003CE30: d2064000                 ld      [%i1], %o1
F003CE34: 80a26004                 cmp     %o1, 4
F003CE38: 12800007                 bne     loc_F003CE54
F003CE3C: 90100009                 mov     %o1, %o0
F003CE40: d006601c                 ld      [%i1+0x1C], %o0
F003CE44: 80a23fff                 cmp     %o0, -1
F003CE48: 12800003                 bne     loc_F003CE54
F003CE4C: 90100009                 mov     %o1, %o0
F003CE50: 90102008                 mov     8, %o0
F003CE54: d0262028                 st      %o0, [%i0+0x28]
F003CE58: d0064000                 ld      [%i1], %o0
F003CE5C: 80a22004                 cmp     %o0, 4
F003CE60: 32800007                 bne,a   loc_F003CE7C
F003CE64: d016601e                 lduh    [%i1+0x1E], %o0
F003CE68: d006601c                 ld      [%i1+0x1C], %o0
F003CE6C: 80a23fff                 cmp     %o0, -1
F003CE70: 22800003                 be,a    loc_F003CE7C
F003CE74: 90102000                 mov     0, %o0
F003CE78: d016601e                 lduh    [%i1+0x1E], %o0
F003CE7C: d036202c                 sth     %o0, [%i0+0x2C]
F003CE80: e2262030                 st      %l1, [%i0+0x30]
F003CE84: f4262024                 st      %i2, [%i0+0x24]
F003CE88: 4000001b                 call    sub_F003CEF4
F003CE8C: 90100011                 mov     %l1, %o0
F003CE90: d206a128                 ld      [%i2+0x128], %o1
F003CE94: d0026018                 ld      [%o1+0x18], %o0
F003CE98: a404a001                 inc     %l2
F003CE9C: 90022001                 inc     %o0
F003CEA0: d0226018                 st      %o0, [%o1+0x18]
F003CEA4: 80a66000                 cmp     %i1, 0
F003CEA8: 02800011                 be      locret_F003CEEC
F003CEAC: b004600c                 add     %l1, 0xC, %i0
F003CEB0: 912ca018                 sll     %l2, 24, %o0
F003CEB4: 80a22000                 cmp     %o0, 0
F003CEB8: 1280000b                 bne     loc_F003CEE4
F003CEBC: 90100018                 mov     %i0, %o0
F003CEC0: d2066034                 ld      [%i1+0x34], %o1
F003CEC4: d227bff0                 st      %o1, [%fp+var_10]
F003CEC8: d4066038                 ld      [%i1+0x38], %o2
F003CECC: 96102000                 mov     0, %o3
F003CED0: d427bff4                 st      %o2, [%fp+var_C]
F003CED4: d4066014                 ld      [%i1+0x14], %o2
F003CED8: 7ffff1ef                 call    _nfs_cache_check
F003CEDC: 9207bff0                 add     %fp, var_10, %o1
F003CEE0: 90100018                 mov     %i0, %o0
F003CEE4: 7ffff204                 call    _nfs_attrcache
F003CEE8: 92100019                 mov     %i1, %o1
F003CEEC: 81c7e008                 ret
F003CEF0: 81e80000                 restore
