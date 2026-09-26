F0041F34: 9de3bf80                 save    %sp, -0x80, %sp
F0041F38: 90102001                 mov     1, %o0
F0041F3C: d027bff4                 st      %o0, [%fp+var_C]
F0041F40: d0060000                 ld      [%i0], %o0
F0041F44: 80a22000                 cmp     %o0, 0
F0041F48: 12800055                 bne     loc_F004209C
F0041F4C: c027bfe4                 clr     [%fp+var_1C]
F0041F50: 90100018                 mov     %i0, %o0! XDR *
F0041F54: 40000dfd                 call    _xdr_enum
F0041F58: 92066004                 add     %i1, 4, %o1
F0041F5C: 80a22000                 cmp     %o0, 0
F0041F60: 22800055                 be,a    locret_F00420B4
F0041F64: b0102000                 mov     0, %i0
F0041F68: d0066004                 ld      [%i1+4], %o0
F0041F6C: 80a22000                 cmp     %o0, 0
F0041F70: 22800004                 be,a    loc_F0041F80
F0041F74: d0062004                 ld      [%i0+4], %o0
F0041F78: 1080004f                 ba      locret_F00420B4
F0041F7C: b0102001                 mov     1, %i0
F0041F80: d2022010                 ld      [%o0+0x10], %o1
F0041F84: 9fc24000                 call    %o1
F0041F88: 90100018                 mov     %i0, %o0
F0041F8C: e206600c                 ld      [%i1+0xC], %l1
F0041F90: d2066008                 ld      [%i1+8], %o1
F0041F94: a4100008                 mov     %o0, %l2
F0041F98: e0066014                 ld      [%i1+0x14], %l0
F0041F9C: 80a46000                 cmp     %l1, 0
F0041FA0: 04800039                 ble     loc_F0042084
F0041FA4: d227bfe8                 st      %o1, [%fp+var_18]
F0041FA8: d2142004                 lduh    [%l0+4], %o1
F0041FAC: 80a26000                 cmp     %o1, 0
F0041FB0: 22800041                 be,a    locret_F00420B4
F0041FB4: b0102000                 mov     0, %i0
F0041FB8: d0142006                 lduh    [%l0+6], %o0
F0041FBC: 90022009                 inc     9, %o0
F0041FC0: 80a20009                 cmp     %o0, %o1
F0041FC4: 18800036                 bgu     loc_F004209C
F0041FC8: d007bfe8                 ld      [%fp+var_18], %o0
F0041FCC: 90020009                 add     %o0, %o1, %o0
F0041FD0: d2040000                 ld      [%l0], %o1
F0041FD4: 80a26000                 cmp     %o1, 0
F0041FD8: 02800026                 be      loc_F0042070
F0041FDC: d027bfe8                 st      %o0, [%fp+var_18]
F0041FE0: 90042008                 add     %l0, 8, %o0
F0041FE4: d027bff0                 st      %o0, [%fp+var_10]
F0041FE8: 90100018                 mov     %i0, %o0! XDR *
F0041FEC: d4142006                 lduh    [%l0+6], %o2
F0041FF0: 9207bff4                 add     %fp, var_C, %o1! int *
F0041FF4: 40000dac                 call    _xdr_bool
F0041FF8: d427bfec                 st      %o2, [%fp+var_14]
F0041FFC: 80a22000                 cmp     %o0, 0
F0042000: 02800027                 be      loc_F004209C
F0042004: 90100018                 mov     %i0, %o0! XDR *
F0042008: 40000d39                 call    _xdr_u_long
F004200C: 92100010                 mov     %l0, %o1
F0042010: 80a22000                 cmp     %o0, 0
F0042014: 02800022                 be      loc_F004209C
F0042018: 90100018                 mov     %i0, %o0! XDR *
F004201C: 9207bff0                 add     %fp, var_10, %o1! char **
F0042020: 9407bfec                 add     %fp, var_14, %o2! unsigned int *
F0042024: 40000e0d                 call    _xdr_bytes
F0042028: 961020ff                 mov     0xFF, %o3
F004202C: 80a22000                 cmp     %o0, 0
F0042030: 0280001b                 be      loc_F004209C
F0042034: 90100018                 mov     %i0, %o0! XDR *
F0042038: 40000d2d                 call    _xdr_u_long
F004203C: 9207bfe8                 add     %fp, var_18, %o1
F0042040: 80a22000                 cmp     %o0, 0
F0042044: 2280001c                 be,a    locret_F00420B4
F0042048: b0102000                 mov     0, %i0
F004204C: d0062004                 ld      [%i0+4], %o0
F0042050: d2022010                 ld      [%o0+0x10], %o1
F0042054: 9fc24000                 call    %o1
F0042058: 90100018                 mov     %i0, %o0
F004205C: d2064000                 ld      [%i1], %o1! int *
F0042060: 90220012                 sub     %o0, %l2, %o0
F0042064: 80a20009                 cmp     %o0, %o1
F0042068: 3a800007                 bcc,a   loc_F0042084
F004206C: c0266010                 clr     [%i1+0x10]
F0042070: d0142004                 lduh    [%l0+4], %o0
F0042074: a2244008                 sub     %l1, %o0, %l1
F0042078: 80a46000                 cmp     %l1, 0
F004207C: 14bfffcb                 bg      loc_F0041FA8
F0042080: a0040008                 add     %l0, %o0, %l0
F0042084: 90100018                 mov     %i0, %o0! XDR *
F0042088: 40000d87                 call    _xdr_bool
F004208C: 9207bfe4                 add     %fp, var_1C, %o1! int *
F0042090: 80a22000                 cmp     %o0, 0
F0042094: 12800004                 bne     loc_F00420A4
F0042098: 90100018                 mov     %i0, %o0! XDR *
F004209C: 10800006                 ba      locret_F00420B4
F00420A0: b0102000                 mov     0, %i0
F00420A4: 40000d80                 call    _xdr_bool
F00420A8: 92066010                 add     %i1, 0x10, %o1
F00420AC: 80a00008                 cmp     %g0, %o0
F00420B0: b0402000                 addc    %g0, 0, %i0
F00420B4: 81c7e008                 ret
F00420B8: 81e80000                 restore
