F0062AF0: 9de3bf88                 save    %sp, -0x78, %sp
F0062AF4: 90960000                 orcc    %i0, %g0, %o0
F0062AF8: 12800004                 bne     loc_F0062B08
F0062AFC: 92100019                 mov     %i1, %o1
F0062B00: 10800041                 ba      locret_F0062C04
F0062B04: b0102010                 mov     0x10, %i0
F0062B08: 80a73fff                 cmp     %i4, -1
F0062B0C: 12800004                 bne     loc_F0062B1C
F0062B10: 80a6a046                 cmp     %i2, 0x46 ! 'F'
F0062B14: 1080003c                 ba      locret_F0062C04
F0062B18: b0102014                 mov     0x14, %i0
F0062B1C: 02800025                 be      loc_F0062BB0
F0062B20: 80a6a046                 cmp     %i2, 0x46 ! 'F'
F0062B24: 14800007                 bg      loc_F0062B40
F0062B28: 80a6a048                 cmp     %i2, 0x48 ! 'H'
F0062B2C: 80a6a045                 cmp     %i2, 0x45 ! 'E'
F0062B30: 02800008                 be      loc_F0062B50
F0062B34: 80a6e000                 cmp     %i3, 0
F0062B38: 10800033                 ba      locret_F0062C04
F0062B3C: b0102012                 mov     0x12, %i0
F0062B40: 02800029                 be      loc_F0062BE4
F0062B44: 80a0001b                 cmp     %g0, %i3
F0062B48: 1080002f                 ba      locret_F0062C04
F0062B4C: b0102012                 mov     0x12, %i0
F0062B50: 1280002d                 bne     locret_F0062C04
F0062B54: b0102012                 mov     0x12, %i0
F0062B58: 94102001                 mov     1, %o2
F0062B5C: 7fffdae0                 call    _ipc_object_translate
F0062B60: 9607bff4                 add     %fp, var_C, %o3
F0062B64: 80a22000                 cmp     %o0, 0
F0062B68: 12800027                 bne     locret_F0062C04
F0062B6C: b0100008                 mov     %o0, %i0
F0062B70: 9210001c                 mov     %i4, %o1
F0062B74: d007bff4                 ld      [%fp+var_C], %o0
F0062B78: 7fffdef2                 call    _ipc_port_pdrequest
F0062B7C: 9407bff0                 add     %fp, var_10, %o2
F0062B80: d007bff0                 ld      [%fp+var_10], %o0
F0062B84: 80a22000                 cmp     %o0, 0
F0062B88: 02800008                 be      loc_F0062BA8
F0062B8C: 808a2001                 btst    1, %o0
F0062B90: 2280001c                 be,a    loc_F0062C00
F0062B94: d0274000                 st      %o0, [%i5]
F0062B98: 7fffe161                 call    _ipc_port_release_send
F0062B9C: 900a3ffe                 and     %o0, -2, %o0
F0062BA0: c027bff0                 clr     [%fp+var_10]
F0062BA4: d007bff0                 ld      [%fp+var_10], %o0
F0062BA8: 10800016                 ba      loc_F0062C00
F0062BAC: d0274000                 st      %o0, [%i5]
F0062BB0: 94102001                 mov     1, %o2
F0062BB4: 7fffdaca                 call    _ipc_object_translate
F0062BB8: 9607bfec                 add     %fp, var_14, %o3
F0062BBC: 80a22000                 cmp     %o0, 0
F0062BC0: 12800011                 bne     locret_F0062C04
F0062BC4: b0100008                 mov     %o0, %i0
F0062BC8: d007bfec                 ld      [%fp+var_14], %o0
F0062BCC: 9210001b                 mov     %i3, %o1
F0062BD0: 9410001c                 mov     %i4, %o2
F0062BD4: 7fffdee2                 call    _ipc_port_nsrequest
F0062BD8: 9610001d                 mov     %i5, %o3
F0062BDC: 1080000a                 ba      locret_F0062C04
F0062BE0: b0102000                 mov     0, %i0
F0062BE4: 94402000                 addc    %g0, 0, %o2
F0062BE8: 9610001c                 mov     %i4, %o3
F0062BEC: 7fffe3e7                 call    _ipc_right_dnrequest
F0062BF0: 9810001d                 mov     %i5, %o4
F0062BF4: 80a22000                 cmp     %o0, 0
F0062BF8: 12800003                 bne     locret_F0062C04
F0062BFC: b0100008                 mov     %o0, %i0
F0062C00: b0102000                 mov     0, %i0
F0062C04: 81c7e008                 ret
F0062C08: 81e80000                 restore
