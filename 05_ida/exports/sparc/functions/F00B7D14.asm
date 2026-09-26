F00B7D14: 9de3bf98                 save    %sp, -0x68, %sp
F00B7D18: 90100018                 mov     %i0, %o0
F00B7D1C: 133c047b                 sethi   %hi(aS_5), %o1! "%s\n"
F00B7D20: e606209c                 ld      [%i0+0x9C], %l3
F00B7D24: 921260d8                 bset    %lo(aS_5), %o1! "%s\n"
F00B7D28: e40620a0                 ld      [%i0+0xA0], %l2
F00B7D2C: 7fffffd8                 call    _eprintf
F00B7D30: 94100019                 mov     %i1, %o2
F00B7D34: 213c047b                 sethi   %hi(aStateSLastStat), %l0! "\tState=%s Last State=%s\n"
F00B7D38: d00e2041                 ldub    [%i0+0x41], %o0
F00B7D3C: 40000093                 call    _esp_state_name
F00B7D40: a01420e0                 bset    %lo(aStateSLastStat), %l0! "\tState=%s Last State=%s\n"
F00B7D44: a2100008                 mov     %o0, %l1
F00B7D48: 40000090                 call    _esp_state_name
F00B7D4C: d00e2042                 ldub    [%i0+0x42], %o0
F00B7D50: 94100008                 mov     %o0, %o2
F00B7D54: 90100010                 mov     %l0, %o0! char *
F00B7D58: 7ffd7240                 call    _printf
F00B7D5C: 92100011                 mov     %l1, %o1
F00B7D60: d0048000                 ld      [%l2], %o0
F00B7D64: 808a2200                 btst    0x200, %o0
F00B7D68: 22800007                 be,a    loc_F00B7D84
F00B7D6C: da0ce01c                 ldub    [%l3+0x1C], %o5
F00B7D70: 900a3dff                 and     %o0, -0x201, %o0
F00B7D74: d0248000                 st      %o0, [%l2]
F00B7D78: da0ce01c                 ldub    [%l3+0x1C], %o5
F00B7D7C: 90122200                 bset    0x200, %o0
F00B7D80: d0248000                 st      %o0, [%l2]
F00B7D84: d20e2043                 ldub    [%i0+0x43], %o1
F00B7D88: 113c0478                 sethi   %hi(_esp_stat_bits), %o0
F00B7D8C: d40221d8                 ld      [%o0+%lo(_esp_stat_bits)], %o2
F00B7D90: 193c0478                 sethi   %hi(_esp_int_bits), %o4
F00B7D94: d60e2044                 ldub    [%i0+0x44], %o3
F00B7D98: d8032208                 ld      [%o4+%lo(_esp_int_bits)], %o4
F00B7D9C: 113c047b                 sethi   %hi(aLatchedStat0xB), %o0! "\tLatched stat=0x%b intr=0x%b fifo 0x%x"...
F00B7DA0: 7ffd722e                 call    _printf
F00B7DA4: 90122100                 bset    %lo(aLatchedStat0xB), %o0! "\tLatched stat=0x%b intr=0x%b fifo 0x%x"...
F00B7DA8: 213c047b                 sethi   %hi(aLastMsgOutSLas), %l0! "\tlast msg out: %s; last msg in: %s\n"
F00B7DAC: d00e2052                 ldub    [%i0+0x52], %o0
F00B7DB0: 4000058a                 call    _scsi_mname
F00B7DB4: a0142128                 bset    %lo(aLastMsgOutSLas), %l0! "\tlast msg out: %s; last msg in: %s\n"
F00B7DB8: a2100008                 mov     %o0, %l1
F00B7DBC: 40000587                 call    _scsi_mname
F00B7DC0: d00e2054                 ldub    [%i0+0x54], %o0
F00B7DC4: 94100008                 mov     %o0, %o2
F00B7DC8: 90100010                 mov     %l0, %o0! char *
F00B7DCC: 7ffd7223                 call    _printf
F00B7DD0: 92100011                 mov     %l1, %o1
F00B7DD4: 113c0478                 sethi   %hi(_dmaga_bits), %o0
F00B7DD8: d402224c                 ld      [%o0+%lo(_dmaga_bits)], %o2
F00B7DDC: d80620a4                 ld      [%i0+0xA4], %o4
F00B7DE0: d00620a0                 ld      [%i0+0xA0], %o0
F00B7DE4: d2020000                 ld      [%o0], %o1
F00B7DE8: d6022004                 ld      [%o0+4], %o3
F00B7DEC: da0620a8                 ld      [%i0+0xA8], %o5
F00B7DF0: 113c047b                 sethi   %hi(aDmaCsr0xBAddrX), %o0! "\tDMA csr=0x%b\n\taddr=%x last=%x last_"...
F00B7DF4: 7ffd7219                 call    _printf
F00B7DF8: 90122150                 bset    %lo(aDmaCsr0xBAddrX), %o0! "\tDMA csr=0x%b\n\taddr=%x last=%x last_"...
F00B7DFC: d05620b2                 ldsh    [%i0+0xB2], %o0
F00B7E00: 80a23fff                 cmp     %o0, -1
F00B7E04: 02800009                 be      locret_F00B7E28
F00B7E08: 912a2002                 sll     %o0, 2, %o0
F00B7E0C: 90020018                 add     %o0, %i0, %o0
F00B7E10: d00220b8                 ld      [%o0+0xB8], %o0
F00B7E14: 80a22000                 cmp     %o0, 0
F00B7E18: 02800004                 be      locret_F00B7E28
F00B7E1C: 01000000                 nop
F00B7E20: 40000004                 call    _esp_dump_cmd
F00B7E24: 01000000                 nop
F00B7E28: 81c7e008                 ret
F00B7E2C: 81e80000                 restore
