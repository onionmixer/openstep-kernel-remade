F0062E80: 9de3bf88                 save    %sp, -0x78, %sp
F0062E84: 90100018                 mov     %i0, %o0
F0062E88: 92100019                 mov     %i1, %o1
F0062E8C: 7fffe2fc                 call    _ipc_right_lookup_write
F0062E90: 9407bff4                 add     %fp, var_C, %o2
F0062E94: 80a22000                 cmp     %o0, 0
F0062E98: 32800025                 bne,a   locret_F0062F2C
F0062E9C: b0102004                 mov     4, %i0
F0062EA0: 90100018                 mov     %i0, %o0
F0062EA4: 92100019                 mov     %i1, %o1
F0062EA8: d407bff4                 ld      [%fp+var_C], %o2
F0062EAC: 9607bff0                 add     %fp, var_10, %o3
F0062EB0: 7fffe784                 call    _ipc_right_info
F0062EB4: 9807bfec                 add     %fp, var_14, %o4
F0062EB8: 80a22000                 cmp     %o0, 0
F0062EBC: 02800004                 be      loc_F0062ECC
F0062EC0: d207bff0                 ld      [%fp+var_10], %o1
F0062EC4: 1080001a                 ba      locret_F0062F2C
F0062EC8: b0102004                 mov     4, %i0
F0062ECC: 11000080                 sethi   0x20000, %o0
F0062ED0: 808a4008                 btst    %o0, %o1
F0062ED4: 12800009                 bne     loc_F0062EF8
F0062ED8: d007bff4                 ld      [%fp+var_C], %o0
F0062EDC: c0262008                 clr     [%i0+8]
F0062EE0: 110005c0                 sethi   0x170000, %o0
F0062EE4: 808a4008                 btst    %o0, %o1
F0062EE8: 02800011                 be      locret_F0062F2C
F0062EEC: b0102004                 mov     4, %i0
F0062EF0: 1080000f                 ba      locret_F0062F2C
F0062EF4: b0102007                 mov     7, %i0
F0062EF8: f2022004                 ld      [%o0+4], %i1
F0062EFC: d0064000                 ld      [%i1], %o0
F0062F00: 80a22000                 cmp     %o0, 0
F0062F04: 12bffffe                 bne     loc_F0062EFC
F0062F08: 01000000                 nop
F0062F0C: 4000cfe7                 call    _simple_lock_try
F0062F10: 90100019                 mov     %i1, %o0
F0062F14: 80a22000                 cmp     %o0, 0
F0062F18: 02bffff9                 be      loc_F0062EFC
F0062F1C: 01000000                 nop
F0062F20: c0262008                 clr     [%i0+8]
F0062F24: f2268000                 st      %i1, [%i2]
F0062F28: b0102000                 mov     0, %i0
F0062F2C: 81c7e008                 ret
F0062F30: 81e80000                 restore
