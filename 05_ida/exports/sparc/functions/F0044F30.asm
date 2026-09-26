F0044F30: 9de3bf98                 save    %sp, -0x68, %sp
F0044F34: 133c04eb                 sethi   %hi(_rsstat), %o1
F0044F38: d0026110                 ld      [%o1+%lo(_rsstat)], %o0
F0044F3C: a6126110                 or      %o1, %lo(_rsstat), %l3
F0044F40: e4062030                 ld      [%i0+0x30], %l2
F0044F44: 90022001                 inc     %o0
F0044F48: 40014753                 call    _splnet
F0044F4C: d0226110                 st      %o0, [%o1+%lo(_rsstat)]
F0044F50: a0100008                 mov     %o0, %l0
F0044F54: d0060000                 ld      [%i0], %o0
F0044F58: 7ffffd6b                 call    _ku_recvfrom
F0044F5C: 92062010                 add     %i0, 0x10, %o1
F0044F60: a2100008                 mov     %o0, %l1
F0044F64: 40014770                 call    _splx
F0044F68: 90100010                 mov     %l0, %o0
F0044F6C: 80a46000                 cmp     %l1, 0
F0044F70: 12800007                 bne     loc_F0044F8C
F0044F74: a004a00c                 add     %l2, 0xC, %l0
F0044F78: d004e008                 ld      [%l3+8], %o0
F0044F7C: b0102000                 mov     0, %i0
F0044F80: 90022001                 inc     %o0
F0044F84: 10800023                 ba      locret_F0045010
F0044F88: d024e008                 st      %o0, [%l3+8]
F0044F8C: d0146008                 lduh    [%l1+8], %o0
F0044F90: 80a2200f                 cmp     %o0, 0xF
F0044F94: 18800006                 bgu     loc_F0044FAC
F0044F98: 90100010                 mov     %l0, %o0
F0044F9C: d004e00c                 ld      [%l3+0xC], %o0
F0044FA0: 90022001                 inc     %o0
F0044FA4: 10800012                 ba      loc_F0044FEC
F0044FA8: d024e00c                 st      %o0, [%l3+0xC]
F0044FAC: 92100011                 mov     %l1, %o1! rpc_msg *
F0044FB0: 4000031e                 call    _xdrmbuf_init
F0044FB4: 94102001                 mov     1, %o2
F0044FB8: 90100010                 mov     %l0, %o0! XDR *
F0044FBC: 7ffffa8f                 call    _xdr_callmsg
F0044FC0: 92100019                 mov     %i1, %o1
F0044FC4: 80a22000                 cmp     %o0, 0
F0044FC8: 02800006                 be      loc_F0044FE0
F0044FCC: b0102001                 mov     1, %i0
F0044FD0: d0064000                 ld      [%i1], %o0
F0044FD4: d024a004                 st      %o0, [%l2+4]
F0044FD8: 1080000e                 ba      locret_F0045010
F0044FDC: e224a008                 st      %l1, [%l2+8]
F0044FE0: d004e010                 ld      [%l3+0x10], %o0
F0044FE4: 90022001                 inc     %o0
F0044FE8: d024e010                 st      %o0, [%l3+0x10]
F0044FEC: 7fff631e                 call    _m_freem
F0044FF0: 90100011                 mov     %l1, %o0
F0044FF4: c024a008                 clr     [%l2+8]
F0044FF8: 133c04eb92126110         set     _rsstat, %o1
F0045000: d0026004                 ld      [%o1+4], %o0
F0045004: b0102000                 mov     0, %i0
F0045008: 90022001                 inc     %o0
F004500C: d0226004                 st      %o0, [%o1+4]
F0045010: 81c7e008                 ret
F0045014: 81e80000                 restore
