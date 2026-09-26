F004DB40: 9de3bf98                 save    %sp, -0x68, %sp
F004DB44: 153c04eb                 sethi   %hi(_ifreeh), %o2
F004DB48: e002a1a0                 ld      [%o2+%lo(_ifreeh)], %l0
F004DB4C: 80a42000                 cmp     %l0, 0
F004DB50: 02800023                 be      loc_F004DBDC
F004DB54: 113c04d4                 sethi   -0xFECB000, %o0
F004DB58: a812a1a0                 or      %o2, %lo(_ifreeh), %l4
F004DB5C: a610000a                 mov     %o2, %l3
F004DB60: 25000020                 sethi   0x8000, %l2
F004DB64: e204205c                 ld      [%l0+0x5C], %l1
F004DB68: 80a46000                 cmp     %l1, 0
F004DB6C: 32800002                 bne,a   loc_F004DB74
F004DB70: e8246060                 st      %l4, [%l1+0x60]
F004DB74: e224e1a0                 st      %l1, [%l3+0x1A0]
F004DB78: c024205c                 clr     [%l0+0x5C]
F004DB7C: c0242060                 clr     [%l0+0x60]
F004DB80: 40007b89                 call    _mfs_uncache
F004DB84: 9004200c                 add     %l0, 0xC, %o0
F004DB88: e4342044                 sth     %l2, [%l0+0x44]
F004DB8C: d0142044                 lduh    [%l0+0x44], %o0
F004DB90: d2142012                 lduh    [%l0+0x12], %o1
F004DB94: 90122001                 bset    1, %o0
F004DB98: 80a26000                 cmp     %o1, 0
F004DB9C: 02800005                 be      loc_F004DBB0
F004DBA0: d0342044                 sth     %o0, [%l0+0x44]
F004DBA4: 113c043b                 sethi   %hi(aFreeInodeIsnT), %o0! "free inode isn't"
F004DBA8: 7fff1d72                 call    _panic
F004DBAC: 90122000                 bset    %lo(aFreeInodeIsnT), %o0! "free inode isn't"
F004DBB0: d2040000                 ld      [%l0], %o1
F004DBB4: d0042004                 ld      [%l0+4], %o0
F004DBB8: d0226004                 st      %o0, [%o1+4]
F004DBBC: d2042004                 ld      [%l0+4], %o1
F004DBC0: d0040000                 ld      [%l0], %o0
F004DBC4: 153c04eb                 sethi   %hi(_ifreeh), %o2
F004DBC8: e002a1a0                 ld      [%o2+%lo(_ifreeh)], %l0
F004DBCC: 80a42000                 cmp     %l0, 0
F004DBD0: 12bfffe5                 bne     loc_F004DB64
F004DBD4: d0224000                 st      %o0, [%o1]
F004DBD8: 113c04d4                 sethi   -0xFECB000, %o0
F004DBDC: e0022140                 ld      [%o0+0x140], %l0
F004DBE0: 80a42000                 cmp     %l0, 0
F004DBE4: 0280001f                 be      locret_F004DC60
F004DBE8: a4100010                 mov     %l0, %l2
F004DBEC: 2d000020                 sethi   0x8000, %l6
F004DBF0: aa100008                 mov     %o0, %l5
F004DBF4: 293c04d2                 sethi   -0xFECB800, %l4
F004DBF8: 273c04ef                 sethi   -0xFEC4400, %l3
F004DBFC: d0142044                 lduh    [%l0+0x44], %o0
F004DC00: 808a0016                 btst    %l6, %o0
F004DC04: 02800011                 be      loc_F004DC48
F004DC08: 80a48010                 cmp     %l2, %l0
F004DC0C: 12800005                 bne     loc_F004DC20
F004DC10: d0042008                 ld      [%l0+8], %o0
F004DC14: d0256140                 st      %o0, [%l5+0x140]
F004DC18: 10800003                 ba      loc_F004DC24
F004DC1C: a4100008                 mov     %o0, %l2
F004DC20: d024a008                 st      %o0, [%l2+8]
F004DC24: d0052250                 ld      [%l4+0x250], %o0
F004DC28: d204200c                 ld      [%l0+0xC], %o1
F004DC2C: 4000ad69                 call    _zfree
F004DC30: e2042008                 ld      [%l0+8], %l1
F004DC34: d004e1b0                 ld      [%l3+0x1B0], %o0
F004DC38: 4000ad66                 call    _zfree
F004DC3C: 92100010                 mov     %l0, %o1
F004DC40: 10800005                 ba      loc_F004DC54
F004DC44: a0100011                 mov     %l1, %l0
F004DC48: e2042008                 ld      [%l0+8], %l1
F004DC4C: a4100010                 mov     %l0, %l2
F004DC50: a0100011                 mov     %l1, %l0
F004DC54: 80a42000                 cmp     %l0, 0
F004DC58: 32bfffea                 bne,a   loc_F004DC00
F004DC5C: d0142044                 lduh    [%l0+0x44], %o0
F004DC60: 81c7e008                 ret
F004DC64: 81e80000                 restore
