F007A9C0: 9de3bf90                 save    %sp, -0x70, %sp
F007A9C4: f0060000                 ld      [%i0], %i0
F007A9C8: d0062030                 ld      [%i0+0x30], %o0
F007A9CC: 80a22000                 cmp     %o0, 0
F007A9D0: 32800007                 bne,a   loc_F007A9EC
F007A9D4: d6062028                 ld      [%i0+0x28], %o3
F007A9D8: d0062008                 ld      [%i0+8], %o0
F007A9DC: 4001e4a4                 call    _port_deallocate_EXTERNAL
F007A9E0: 92100019                 mov     %i1, %o1
F007A9E4: 10800031                 ba      locret_F007AAA8
F007A9E8: b0102065                 mov     0x65, %i0 ! 'e'
F007A9EC: d2062024                 ld      [%i0+0x24], %o1
F007A9F0: 80a2c009                 cmp     %o3, %o1
F007A9F4: 12800004                 bne     loc_F007AA04
F007A9F8: 153c04d0                 sethi   -0xFECC000, %o2
F007A9FC: 1080002a                 ba      loc_F007AAA4
F007AA00: f2262018                 st      %i1, [%i0+0x18]
F007AA04: e002a0d8                 ld      [%o2+0xD8], %l0
F007AA08: 9807bff0                 add     %fp, var_10, %o4
F007AA0C: d00624cc                 ld      [%i0+0x4CC], %o0
F007AA10: 9422c009                 sub     %o3, %o1, %o2
F007AA14: 94028010                 add     %o2, %l0, %o2
F007AA18: a02a8010                 andn    %o2, %l0, %l0
F007AA1C: 94100010                 mov     %l0, %o2
F007AA20: 4001e6a5                 call    _vm_read_EXTERNAL
F007AA24: 9607bff4                 add     %fp, var_C, %o3
F007AA28: d4062028                 ld      [%i0+0x28], %o2
F007AA2C: d6062024                 ld      [%i0+0x24], %o3
F007AA30: 90100019                 mov     %i1, %o0
F007AA34: d207bff4                 ld      [%fp+var_C], %o1
F007AA38: 9422800b                 sub     %o2, %o3, %o2
F007AA3C: 40000511                 call    _kern_serv_log_data
F007AA40: 953aa005                 sra     %o2, 5, %o2
F007AA44: d0062008                 ld      [%i0+8], %o0
F007AA48: 4001e489                 call    _port_deallocate_EXTERNAL
F007AA4C: 92100019                 mov     %i1, %o1
F007AA50: d0062008                 ld      [%i0+8], %o0
F007AA54: d207bff4                 ld      [%fp+var_C], %o1
F007AA58: 4001e654                 call    _vm_deallocate_EXTERNAL
F007AA5C: 94100010                 mov     %l0, %o2
F007AA60: 4000704a                 call    _splusclock
F007AA64: 01000000                 nop
F007AA68: a0100008                 mov     %o0, %l0
F007AA6C: d0060000                 ld      [%i0], %o0
F007AA70: 80a22000                 cmp     %o0, 0
F007AA74: 12bffffe                 bne     loc_F007AA6C
F007AA78: 01000000                 nop
F007AA7C: 4000710b                 call    _simple_lock_try
F007AA80: 90100018                 mov     %i0, %o0
F007AA84: 80a22000                 cmp     %o0, 0
F007AA88: 02bffff9                 be      loc_F007AA6C
F007AA8C: 01000000                 nop
F007AA90: c0260000                 clr     [%i0]
F007AA94: d2062024                 ld      [%i0+0x24], %o1
F007AA98: 90100010                 mov     %l0, %o0
F007AA9C: 400070a2                 call    _splx
F007AAA0: d2262028                 st      %o1, [%i0+0x28]
F007AAA4: b0102000                 mov     0, %i0
F007AAA8: 81c7e008                 ret
F007AAAC: 81e80000                 restore
