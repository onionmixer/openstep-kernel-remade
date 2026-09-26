F0043F7C: 9de3bf98                 save    %sp, -0x68, %sp
F0043F80: d0060000                 ld      [%i0], %o0
F0043F84: 80a22000                 cmp     %o0, 0
F0043F88: 12800041                 bne     loc_F004408C
F0043F8C: 80a22001                 cmp     %o0, 1
F0043F90: d0066008                 ld      [%i1+8], %o0
F0043F94: 80a22000                 cmp     %o0, 0
F0043F98: 3280003c                 bne,a   loc_F0044088
F0043F9C: d0060000                 ld      [%i0], %o0
F0043FA0: d0066004                 ld      [%i1+4], %o0
F0043FA4: 80a22001                 cmp     %o0, 1
F0043FA8: 32800038                 bne,a   loc_F0044088
F0043FAC: d0060000                 ld      [%i0], %o0
F0043FB0: d4062004                 ld      [%i0+4], %o2
F0043FB4: d2066014                 ld      [%i1+0x14], %o1
F0043FB8: 90100018                 mov     %i0, %o0
F0043FBC: d402a018                 ld      [%o2+0x18], %o2
F0043FC0: 9fc28000                 call    %o2
F0043FC4: 92026018                 inc     0x18, %o1! void *
F0043FC8: a0920000                 orcc    %o0, %g0, %l0
F0043FCC: 2280002f                 be,a    loc_F0044088
F0043FD0: d0060000                 ld      [%i0], %o0
F0043FD4: d0064000                 ld      [%i1], %o0
F0043FD8: d0240000                 st      %o0, [%l0]
F0043FDC: d0066004                 ld      [%i1+4], %o0
F0043FE0: a0042004                 inc     4, %l0
F0043FE4: d0240000                 st      %o0, [%l0]
F0043FE8: d0066008                 ld      [%i1+8], %o0
F0043FEC: a0042004                 inc     4, %l0
F0043FF0: d0240000                 st      %o0, [%l0]
F0043FF4: d006600c                 ld      [%i1+0xC], %o0
F0043FF8: a0042004                 inc     4, %l0
F0043FFC: d0240000                 st      %o0, [%l0]
F0044000: d0066014                 ld      [%i1+0x14], %o0
F0044004: a0042004                 inc     4, %l0
F0044008: d0240000                 st      %o0, [%l0]
F004400C: d4066014                 ld      [%i1+0x14], %o2! size_t
F0044010: 80a2a000                 cmp     %o2, 0
F0044014: 02800009                 be      loc_F0044038
F0044018: a0042004                 inc     4, %l0
F004401C: d0066010                 ld      [%i1+0x10], %o0! void *
F0044020: 400142bc                 call    _bcopy
F0044024: 92100010                 mov     %l0, %o1
F0044028: d0066014                 ld      [%i1+0x14], %o0
F004402C: 90022003                 inc     3, %o0
F0044030: 900a3ffc                 and     %o0, -4, %o0
F0044034: a0040008                 add     %l0, %o0, %l0
F0044038: d0066018                 ld      [%i1+0x18], %o0
F004403C: d0240000                 st      %o0, [%l0]
F0044040: d0066018                 ld      [%i1+0x18], %o0
F0044044: 80a22000                 cmp     %o0, 0
F0044048: 02800006                 be      loc_F0044060
F004404C: 80a22002                 cmp     %o0, 2
F0044050: 02800007                 be      loc_F004406C
F0044054: 90100018                 mov     %i0, %o0! XDR *
F0044058: 1080009b                 ba      locret_F00442C4
F004405C: b0102001                 mov     1, %i0
F0044060: d206601c                 ld      [%i1+0x1C], %o1! unsigned __int32 *
F0044064: 10800072                 ba      loc_F004422C
F0044068: d4066020                 ld      [%i1+0x20], %o2
F004406C: 40000520                 call    _xdr_u_long
F0044070: 9206601c                 add     %i1, 0x1C, %o1
F0044074: 80a22000                 cmp     %o0, 0
F0044078: 02800092                 be      loc_F00442C0
F004407C: 90100018                 mov     %i0, %o0
F0044080: 10800075                 ba      loc_F0044254
F0044084: 92066020                 add     %i1, 0x20, %o1 ! ' '
F0044088: 80a22001                 cmp     %o0, 1
F004408C: 12800076                 bne     loc_F0044264
F0044090: 90100018                 mov     %i0, %o0
F0044094: d2062004                 ld      [%i0+4], %o1
F0044098: d4026018                 ld      [%o1+0x18], %o2
F004409C: 9fc28000                 call    %o2
F00440A0: 9210200c                 mov     0xC, %o1
F00440A4: a0920000                 orcc    %o0, %g0, %l0
F00440A8: 0280006f                 be      loc_F0044264
F00440AC: 90100018                 mov     %i0, %o0
F00440B0: d0040000                 ld      [%l0], %o0
F00440B4: d0264000                 st      %o0, [%i1]
F00440B8: a0042004                 inc     4, %l0
F00440BC: d0040000                 ld      [%l0], %o0
F00440C0: d0266004                 st      %o0, [%i1+4]
F00440C4: 80a22001                 cmp     %o0, 1
F00440C8: 1280007e                 bne     loc_F00442C0
F00440CC: a0042004                 inc     4, %l0
F00440D0: d0040000                 ld      [%l0], %o0
F00440D4: 80a22000                 cmp     %o0, 0
F00440D8: 0280000a                 be      loc_F0044100
F00440DC: d0266008                 st      %o0, [%i1+8]
F00440E0: 80a22001                 cmp     %o0, 1
F00440E4: 32800078                 bne,a   locret_F00442C4
F00440E8: b0102000                 mov     0, %i0
F00440EC: 90100018                 mov     %i0, %o0
F00440F0: 7fffff83                 call    _xdr_rejected_reply
F00440F4: 9206600c                 add     %i1, 0xC, %o1
F00440F8: 10800073                 ba      locret_F00442C4
F00440FC: b0100008                 mov     %o0, %i0
F0044100: d2062004                 ld      [%i0+4], %o1
F0044104: d4026018                 ld      [%o1+0x18], %o2
F0044108: 90100018                 mov     %i0, %o0
F004410C: 9fc28000                 call    %o2
F0044110: 92102008                 mov     8, %o1! int *
F0044114: a0920000                 orcc    %o0, %g0, %l0
F0044118: a406600c                 add     %i1, 0xC, %l2
F004411C: 02800007                 be      loc_F0044138
F0044120: a2100012                 mov     %l2, %l1
F0044124: d0040000                 ld      [%l0], %o0
F0044128: d026600c                 st      %o0, [%i1+0xC]
F004412C: d0042004                 ld      [%l0+4], %o0
F0044130: 1080000d                 ba      loc_F0044164
F0044134: d0266014                 st      %o0, [%i1+0x14]
F0044138: 90100018                 mov     %i0, %o0! XDR *
F004413C: 40000583                 call    _xdr_enum
F0044140: 92100012                 mov     %l2, %o1! unsigned int *
F0044144: 80a22000                 cmp     %o0, 0
F0044148: 0280005e                 be      loc_F00442C0
F004414C: 90100018                 mov     %i0, %o0! XDR *
F0044150: 400004c7                 call    _xdr_u_int
F0044154: 92066014                 add     %i1, 0x14, %o1
F0044158: 80a22000                 cmp     %o0, 0
F004415C: 2280005a                 be,a    locret_F00442C4
F0044160: b0102000                 mov     0, %i0
F0044164: d2046008                 ld      [%l1+8], %o1
F0044168: 80a26000                 cmp     %o1, 0
F004416C: 02800020                 be      loc_F00441EC
F0044170: 80a26190                 cmp     %o1, 0x190
F0044174: 38800054                 bgu,a   locret_F00442C4
F0044178: b0102000                 mov     0, %i0
F004417C: d0046004                 ld      [%l1+4], %o0
F0044180: 80a22000                 cmp     %o0, 0
F0044184: 12800007                 bne     loc_F00441A0
F0044188: 90100018                 mov     %i0, %o0
F004418C: 40008fb9                 call    _kalloc
F0044190: 90100009                 mov     %o1, %o0
F0044194: d0246004                 st      %o0, [%l1+4]
F0044198: d2046008                 ld      [%l1+8], %o1
F004419C: 90100018                 mov     %i0, %o0! XDR *
F00441A0: d4062004                 ld      [%i0+4], %o2
F00441A4: 92026003                 inc     3, %o1
F00441A8: d402a018                 ld      [%o2+0x18], %o2
F00441AC: 9fc28000                 call    %o2
F00441B0: 920a7ffc                 and     %o1, -4, %o1
F00441B4: a0920000                 orcc    %o0, %g0, %l0
F00441B8: 1280000a                 bne     loc_F00441E0
F00441BC: d2046004                 ld      [%l1+4], %o1! void *
F00441C0: d4046008                 ld      [%l1+8], %o2! unsigned int
F00441C4: 40000567                 call    _xdr_opaque
F00441C8: 90100018                 mov     %i0, %o0
F00441CC: 80a22000                 cmp     %o0, 0
F00441D0: 12800008                 bne     loc_F00441F0
F00441D4: 90100018                 mov     %i0, %o0! void *
F00441D8: 1080003b                 ba      locret_F00442C4
F00441DC: b0102000                 mov     0, %i0
F00441E0: d4046008                 ld      [%l1+8], %o2! size_t
F00441E4: 4001424b                 call    _bcopy
F00441E8: 90100010                 mov     %l0, %o0
F00441EC: 90100018                 mov     %i0, %o0! XDR *
F00441F0: 40000556                 call    _xdr_enum
F00441F4: 9204a00c                 add     %l2, 0xC, %o1
F00441F8: 80a22000                 cmp     %o0, 0
F00441FC: 22800032                 be,a    locret_F00442C4
F0044200: b0102000                 mov     0, %i0
F0044204: d004a00c                 ld      [%l2+0xC], %o0
F0044208: 80a22000                 cmp     %o0, 0
F004420C: 02800006                 be      loc_F0044224
F0044210: 80a22002                 cmp     %o0, 2
F0044214: 0280000a                 be      loc_F004423C
F0044218: 90100018                 mov     %i0, %o0
F004421C: 1080002a                 ba      locret_F00442C4
F0044220: b0102001                 mov     1, %i0
F0044224: d204a010                 ld      [%l2+0x10], %o1! unsigned __int32 *
F0044228: d404a014                 ld      [%l2+0x14], %o2
F004422C: 9fc28000                 call    %o2
F0044230: 90100018                 mov     %i0, %o0! XDR *
F0044234: 10800024                 ba      locret_F00442C4
F0044238: b0100008                 mov     %o0, %i0
F004423C: 400004ac                 call    _xdr_u_long
F0044240: 9204a010                 add     %l2, 0x10, %o1
F0044244: 80a22000                 cmp     %o0, 0
F0044248: 0280001e                 be      loc_F00442C0
F004424C: 90100018                 mov     %i0, %o0! XDR *
F0044250: 9204a014                 add     %l2, 0x14, %o1! unsigned __int32 *
F0044254: 400004a6                 call    _xdr_u_long
F0044258: 01000000                 nop
F004425C: 1080001a                 ba      locret_F00442C4
F0044260: b0100008                 mov     %o0, %i0
F0044264: 400004a2                 call    _xdr_u_long
F0044268: 92100019                 mov     %i1, %o1! int *
F004426C: 80a22000                 cmp     %o0, 0
F0044270: 02800014                 be      loc_F00442C0
F0044274: 90100018                 mov     %i0, %o0! XDR *
F0044278: 40000534                 call    _xdr_enum
F004427C: 92066004                 add     %i1, 4, %o1
F0044280: 80a22000                 cmp     %o0, 0
F0044284: 22800010                 be,a    locret_F00442C4
F0044288: b0102000                 mov     0, %i0
F004428C: d0066004                 ld      [%i1+4], %o0
F0044290: 80a22001                 cmp     %o0, 1
F0044294: 3280000c                 bne,a   locret_F00442C4
F0044298: b0102000                 mov     0, %i0
F004429C: 90100018                 mov     %i0, %o0! XDR *
F00442A0: 92066008                 add     %i1, 8, %o1! int *
F00442A4: 9406600c                 add     %i1, 0xC, %o2! char *
F00442A8: 173c04379612e1b0         set     unk_F010DDB0, %o3! xdr_discrim *
F00442B0: 400005aa                 call    _xdr_union
F00442B4: 98102000                 mov     0, %o4
F00442B8: 10800003                 ba      locret_F00442C4
F00442BC: b0100008                 mov     %o0, %i0
F00442C0: b0102000                 mov     0, %i0
F00442C4: 81c7e008                 ret
F00442C8: 81e80000                 restore
