F0013FA4: 9de3bf98                 save    %sp, -0x68, %sp
F0013FA8: a6264018                 sub     %i1, %i0, %l3
F0013FAC: 293c042d                 sethi   %hi(dword_F010B480), %l4
F0013FB0: 2b3c042d                 sethi   -0xFEF4C00, %l5
F0013FB4: 2d3c042d                 sethi   -0xFEF4C00, %l6
F0013FB8: e0052080                 ld      [%l4+%lo(dword_F010B480)], %l0
F0013FBC: 90100013                 mov     %l3, %o0! int
F0013FC0: 7fffc992                 call    _div
F0013FC4: 92100010                 mov     %l0, %o1
F0013FC8: 92100008                 mov     %o0, %o1
F0013FCC: 90100010                 mov     %l0, %o0
F0013FD0: 7fffc94c                 call    _umul
F0013FD4: 933a6001                 sra     %o1, 1, %o1
F0013FD8: a2060008                 add     %i0, %o0, %l1
F0013FDC: 113c042d                 sethi   %hi(dword_F010B488), %o0
F0013FE0: d0022088                 ld      [%o0+%lo(dword_F010B488)], %o0
F0013FE4: 80a4c008                 cmp     %l3, %o0
F0013FE8: 06800029                 bl      loc_F001408C
F0013FEC: a4100011                 mov     %l1, %l2
F0013FF0: 90100018                 mov     %i0, %o0
F0013FF4: 92100011                 mov     %l1, %o1
F0013FF8: d405607c                 ld      [%l5+0x7C], %o2
F0013FFC: 9fc28000                 call    %o2
F0014000: a0100011                 mov     %l1, %l0
F0014004: 80a22000                 cmp     %o0, 0
F0014008: 34800002                 bg,a    loc_F0014010
F001400C: a0100018                 mov     %i0, %l0
F0014010: d2052080                 ld      [%l4+0x80], %o1
F0014014: 90100010                 mov     %l0, %o0
F0014018: d405607c                 ld      [%l5+0x7C], %o2
F001401C: a6264009                 sub     %i1, %o1, %l3
F0014020: 9fc28000                 call    %o2
F0014024: 92100013                 mov     %l3, %o1
F0014028: 80a22000                 cmp     %o0, 0
F001402C: 0480000c                 ble     loc_F001405C
F0014030: 80a40018                 cmp     %l0, %i0
F0014034: 12800003                 bne     loc_F0014040
F0014038: 90100018                 mov     %i0, %o0
F001403C: 90100011                 mov     %l1, %o0
F0014040: a0100008                 mov     %o0, %l0
F0014044: d405607c                 ld      [%l5+0x7C], %o2
F0014048: 9fc28000                 call    %o2
F001404C: 92100013                 mov     %l3, %o1
F0014050: 80a22000                 cmp     %o0, 0
F0014054: 26800002                 bl,a    loc_F001405C
F0014058: a0100013                 mov     %l3, %l0
F001405C: 80a40011                 cmp     %l0, %l1
F0014060: 0280000c                 be      loc_F0014090
F0014064: d0052080                 ld      [%l4+0x80], %o0
F0014068: d2052080                 ld      [%l4+0x80], %o1
F001406C: d60c4000                 ldub    [%l1], %o3
F0014070: d00c0000                 ldub    [%l0], %o0
F0014074: 92827fff                 inccc   -1, %o1
F0014078: d02c4000                 stb     %o0, [%l1]
F001407C: a2046001                 inc     %l1
F0014080: d62c0000                 stb     %o3, [%l0]
F0014084: 12bffffa                 bne     loc_F001406C
F0014088: a0042001                 inc     %l0
F001408C: d0052080                 ld      [%l4+0x80], %o0
F0014090: a2100018                 mov     %i0, %l1
F0014094: 10800009                 ba      loc_F00140B8
F0014098: a0264008                 sub     %i1, %o0, %l0
F001409C: d405607c                 ld      [%l5+0x7C], %o2
F00140A0: 9fc28000                 call    %o2
F00140A4: 92100012                 mov     %l2, %o1
F00140A8: 80a22000                 cmp     %o0, 0
F00140AC: 14800015                 bg      loc_F0014100
F00140B0: d0052080                 ld      [%l4+0x80], %o0
F00140B4: a2044008                 add     %l1, %o0, %l1
F00140B8: 80a44012                 cmp     %l1, %l2
F00140BC: 0abffff8                 bcs     loc_F001409C
F00140C0: 90100011                 mov     %l1, %o0
F00140C4: 10800010                 ba      loc_F0014104
F00140C8: 80a40012                 cmp     %l0, %l2
F00140CC: d405607c                 ld      [%l5+0x7C], %o2
F00140D0: 9fc28000                 call    %o2
F00140D4: 92100010                 mov     %l0, %o1
F00140D8: 80a22000                 cmp     %o0, 0
F00140DC: 14800004                 bg      loc_F00140EC
F00140E0: d0052080                 ld      [%l4+0x80], %o0
F00140E4: 10800007                 ba      loc_F0014100
F00140E8: a0240008                 sub     %l0, %o0, %l0
F00140EC: 80a44012                 cmp     %l1, %l2
F00140F0: 02800019                 be      loc_F0014154
F00140F4: a6044008                 add     %l1, %o0, %l3
F00140F8: 1080000b                 ba      loc_F0014124
F00140FC: 94100010                 mov     %l0, %o2
F0014100: 80a40012                 cmp     %l0, %l2
F0014104: 18bffff2                 bgu     loc_F00140CC
F0014108: 90100012                 mov     %l2, %o0
F001410C: 80a44012                 cmp     %l1, %l2
F0014110: 02800014                 be      loc_F0014160
F0014114: 94100012                 mov     %l2, %o2
F0014118: a4100011                 mov     %l1, %l2
F001411C: d0052080                 ld      [%l4+0x80], %o0
F0014120: a6100011                 mov     %l1, %l3
F0014124: a0240008                 sub     %l0, %o0, %l0
F0014128: d2052080                 ld      [%l4+0x80], %o1
F001412C: d60c4000                 ldub    [%l1], %o3
F0014130: d00a8000                 ldub    [%o2], %o0
F0014134: 92827fff                 inccc   -1, %o1
F0014138: d02c4000                 stb     %o0, [%l1]
F001413C: a2046001                 inc     %l1
F0014140: d62a8000                 stb     %o3, [%o2]
F0014144: 12bffffa                 bne     loc_F001412C
F0014148: 9402a001                 inc     %o2
F001414C: 10bfffdb                 ba      loc_F00140B8
F0014150: a2100013                 mov     %l3, %l1
F0014154: 94100010                 mov     %l0, %o2
F0014158: 10bffff4                 ba      loc_F0014128
F001415C: a4100010                 mov     %l0, %l2
F0014160: a0100012                 mov     %l2, %l0
F0014164: d0052080                 ld      [%l4+0x80], %o0
F0014168: a6240018                 sub     %l0, %i0, %l3
F001416C: a2040008                 add     %l0, %o0, %l1
F0014170: a4264011                 sub     %i1, %l1, %l2
F0014174: 80a4c012                 cmp     %l3, %l2
F0014178: 1480000a                 bg      loc_F00141A0
F001417C: d005a084                 ld      [%l6+0x84], %o0
F0014180: 80a4c008                 cmp     %l3, %o0
F0014184: 06800004                 bl      loc_F0014194
F0014188: 90100018                 mov     %i0, %o0
F001418C: 7fffff86                 call    sub_F0013FA4
F0014190: 92100010                 mov     %l0, %o1
F0014194: b0100011                 mov     %l1, %i0
F0014198: 10800008                 ba      loc_F00141B8
F001419C: a6100012                 mov     %l2, %l3
F00141A0: 80a48008                 cmp     %l2, %o0
F00141A4: 06800004                 bl      loc_F00141B4
F00141A8: 90100011                 mov     %l1, %o0
F00141AC: 7fffff7e                 call    sub_F0013FA4
F00141B0: 92100019                 mov     %i1, %o1
F00141B4: b2100010                 mov     %l0, %i1
F00141B8: d005a084                 ld      [%l6+0x84], %o0
F00141BC: 80a4c008                 cmp     %l3, %o0
F00141C0: 16bfff7f                 bge     loc_F0013FBC
F00141C4: e0052080                 ld      [%l4+0x80], %l0
F00141C8: 81c7e008                 ret
F00141CC: 81e80000                 restore
