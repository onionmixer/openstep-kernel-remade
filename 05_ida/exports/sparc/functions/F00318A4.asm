F00318A4: 9de3bf98                 save    %sp, -0x68, %sp
F00318A8: d6062010                 ld      [%i0+0x10], %o3
F00318AC: a0102000                 mov     0, %l0
F00318B0: d206200c                 ld      [%i0+0xC], %o1
F00318B4: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F00318B8: d4022070                 ld      [%o0+%lo(_in_ifaddr)], %o2
F00318BC: d2262010                 st      %o1, [%i0+0x10]
F00318C0: d00e0000                 ldub    [%i0], %o0
F00318C4: 80a2a000                 cmp     %o2, 0
F00318C8: 900a200f                 and     %o0, 0xF, %o0
F00318CC: 912a2002                 sll     %o0, 2, %o0
F00318D0: 02800014                 be      loc_F0031920
F00318D4: a2023fec                 add     %o0, -0x14, %l1
F00318D8: d002a004                 ld      [%o2+4], %o0
F00318DC: 80a2c008                 cmp     %o3, %o0
F00318E0: 02800010                 be      loc_F0031920
F00318E4: 80a2a000                 cmp     %o2, 0
F00318E8: d002a020                 ld      [%o2+0x20], %o0
F00318EC: d012200c                 lduh    [%o0+0xC], %o0
F00318F0: 808a2002                 btst    2, %o0
F00318F4: 22800007                 be,a    loc_F0031910
F00318F8: d402a040                 ld      [%o2+0x40], %o2
F00318FC: d002a014                 ld      [%o2+0x14], %o0
F0031900: 80a2c008                 cmp     %o3, %o0
F0031904: 02800007                 be      loc_F0031920
F0031908: 80a2a000                 cmp     %o2, 0
F003190C: d402a040                 ld      [%o2+0x40], %o2
F0031910: 80a2a000                 cmp     %o2, 0
F0031914: 32bffff2                 bne,a   loc_F00318DC
F0031918: d002a004                 ld      [%o2+4], %o0
F003191C: 80a2a000                 cmp     %o2, 0
F0031920: 12800005                 bne     loc_F0031934
F0031924: 80a2a000                 cmp     %o2, 0
F0031928: 40000020                 call    _ifptoia
F003192C: 90100019                 mov     %i1, %o0
F0031930: 94920000                 orcc    %o0, %g0, %o2
F0031934: 32800005                 bne,a   loc_F0031948
F0031938: d602a004                 ld      [%o2+4], %o3
F003193C: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0031940: d4022070                 ld      [%o0+%lo(_in_ifaddr)], %o2
F0031944: d602a004                 ld      [%o2+4], %o3
F0031948: 80a46000                 cmp     %l1, 0
F003194C: 901020ff                 mov     0xFF, %o0
F0031950: d626200c                 st      %o3, [%i0+0xC]
F0031954: 0480000b                 ble     loc_F0031980
F0031958: d02e2008                 stb     %o0, [%i0+8]
F003195C: 40000541                 call    _ip_srcroute
F0031960: 01000000                 nop
F0031964: a0100008                 mov     %o0, %l0
F0031968: 90100018                 mov     %i0, %o0
F003196C: d4162002                 lduh    [%i0+2], %o2
F0031970: 92102000                 mov     0, %o1
F0031974: 94228011                 sub     %o2, %l1, %o2
F0031978: 40000567                 call    _ip_stripoptions
F003197C: d4362002                 sth     %o2, [%i0+2]
F0031980: 90100018                 mov     %i0, %o0
F0031984: 4000001b                 call    _icmp_send
F0031988: 92100010                 mov     %l0, %o1
F003198C: 80a42000                 cmp     %l0, 0
F0031990: 02800004                 be      locret_F00319A0
F0031994: 01000000                 nop
F0031998: 7fffb047                 call    _m_free
F003199C: 90100010                 mov     %l0, %o0
F00319A0: 81c7e008                 ret
F00319A4: 81e80000                 restore
