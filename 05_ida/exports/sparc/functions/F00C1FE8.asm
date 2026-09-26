F00C1FE8: 9de3bf88                 save    %sp, -0x78, %sp
F00C1FEC: d216a008                 lduh    [%i2+8], %o1
F00C1FF0: d8068000                 ld      [%i2], %o4
F00C1FF4: 90026001                 add     %o1, 1, %o0
F00C1FF8: d036a008                 sth     %o0, [%i2+8]
F00C1FFC: 912a2010                 sll     %o0, 16, %o0
F00C2000: 913a2010                 sra     %o0, 16, %o0
F00C2004: 932a6010                 sll     %o1, 16, %o1
F00C2008: d4530000                 ldsh    [%o4], %o2
F00C200C: 933a6010                 sra     %o1, 16, %o1
F00C2010: 80a2000a                 cmp     %o0, %o2
F00C2014: 912a6001                 sll     %o1, 1, %o0
F00C2018: 90020009                 add     %o0, %o1, %o0
F00C201C: 912a2002                 sll     %o0, 2, %o0
F00C2020: 9a022004                 add     %o0, 4, %o5
F00C2024: 06800003                 bl      loc_F00C2030
F00C2028: 9603000d                 add     %o4, %o5, %o3
F00C202C: c036a008                 clrh    [%i2+8]
F00C2030: d207bff0                 ld      [%fp+var_10], %o1
F00C2034: 15004000                 sethi   0x1000000, %o2
F00C2038: d00ae002                 ldub    [%o3+2], %o0
F00C203C: 942a400a                 andn    %o1, %o2, %o2
F00C2040: 91322002                 srl     %o0, 2, %o0
F00C2044: 901a2001                 btog    1, %o0
F00C2048: 900a2001                 and     %o0, 1, %o0
F00C204C: 912a2018                 sll     %o0, 24, %o0
F00C2050: 94128008                 bset    %o0, %o2
F00C2054: d427bff0                 st      %o2, [%fp+var_10]
F00C2058: 13008000                 sethi   0x2000000, %o1
F00C205C: d00ae002                 ldub    [%o3+2], %o0
F00C2060: 922a8009                 andn    %o2, %o1, %o1
F00C2064: 901a2001                 btog    1, %o0
F00C2068: 900a2001                 and     %o0, 1, %o0
F00C206C: 912a2019                 sll     %o0, 25, %o0
F00C2070: 92124008                 bset    %o0, %o1
F00C2074: d227bff0                 st      %o1, [%fp+var_10]
F00C2078: d40b000d                 ldub    [%o4+%o5], %o2
F00C207C: 133c04cc                 sethi   %hi(dword_F0133028), %o1
F00C2080: d0026028                 ld      [%o1+%lo(dword_F0133028)], %o0
F00C2084: d42fbff1                 stb     %o2, [%fp+var_10+1]
F00C2088: d60ae001                 ldub    [%o3+1], %o3
F00C208C: 80a22000                 cmp     %o0, 0
F00C2090: 0280000b                 be      loc_F00C20BC
F00C2094: d62fbff2                 stb     %o3, [%fp+var_10+2]
F00C2098: 113c04cc90122018         set     unk_F0133018, %o0
F00C20A0: d20a2009                 ldub    [%o0+9], %o1
F00C20A4: 9202400a                 add     %o1, %o2, %o1
F00C20A8: d40a200a                 ldub    [%o0+0xA], %o2
F00C20AC: d22a2009                 stb     %o1, [%o0+9]
F00C20B0: 9402800b                 add     %o2, %o3, %o2
F00C20B4: 10800019                 ba      locret_F00C2118
F00C20B8: d42a200a                 stb     %o2, [%o0+0xA]
F00C20BC: a0102001                 mov     1, %l0
F00C20C0: e0226028                 st      %l0, [%o1+0x28]
F00C20C4: 113c04cc                 sethi   %hi(qword_F0133008), %o0
F00C20C8: d41fbfe8                 ldd     [%fp+var_18], %o2
F00C20CC: 133c04cc                 sethi   %hi(byte_F0133021), %o1
F00C20D0: d43a2008                 std     %o2, [%o0+%lo(qword_F0133008)]
F00C20D4: d41fbff0                 ldd     [%fp+var_10], %o2
F00C20D8: 98126021                 or      %o1, %lo(byte_F0133021), %o4
F00C20DC: da0b2001                 ldub    [%o4+1], %o5
F00C20E0: 90122008                 bset    %lo(qword_F0133008), %o0
F00C20E4: d43a2008                 std     %o2, [%o0+8]
F00C20E8: d60a6021                 ldub    [%o1+%lo(byte_F0133021)], %o3
F00C20EC: c02b2001                 clrb    [%o4+1]
F00C20F0: d40a2009                 ldub    [%o0+9], %o2
F00C20F4: c02a6021                 clrb    [%o1+%lo(byte_F0133021)]
F00C20F8: 9402800b                 add     %o2, %o3, %o2
F00C20FC: d20a200a                 ldub    [%o0+0xA], %o1
F00C2100: d42a2009                 stb     %o2, [%o0+9]
F00C2104: 9202400d                 add     %o1, %o5, %o1
F00C2108: 40000ff5                 call    _IOGetTimestamp
F00C210C: d22a200a                 stb     %o1, [%o0+0xA]
F00C2110: 113c0484                 sethi   %hi(dword_F0121134), %o0
F00C2114: e0222134                 st      %l0, [%o0+%lo(dword_F0121134)]
F00C2118: 81c7e008                 ret
F00C211C: 81e80000                 restore
