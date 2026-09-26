F0069B40: 9de3bf98                 save    %sp, -0x68, %sp
F0069B44: 80a62000                 cmp     %i0, 0
F0069B48: 0280001a                 be      locret_F0069BB0
F0069B4C: b0102016                 mov     0x16, %i0
F0069B50: 4000b40e                 call    _splusclock
F0069B54: 01000000                 nop
F0069B58: 193c043e                 sethi   %hi(_time), %o4
F0069B5C: d4064000                 ld      [%i1], %o2
F0069B60: 961323e8                 or      %o4, %lo(_time), %o3
F0069B64: d42323e8                 st      %o2, [%o4+%lo(_time)]
F0069B68: d2066004                 ld      [%i1+4], %o1
F0069B6C: b0100008                 mov     %o0, %i0
F0069B70: d222e004                 st      %o1, [%o3+4]
F0069B74: 113c043f                 sethi   %hi(_mtime), %o0
F0069B78: d2022000                 ld      [%o0+%lo(_mtime)], %o1
F0069B7C: 80a26000                 cmp     %o1, 0
F0069B80: 02800007                 be      loc_F0069B9C
F0069B84: 01000000                 nop
F0069B88: d4226008                 st      %o2, [%o1+8]
F0069B8C: d002e004                 ld      [%o3+4], %o0
F0069B90: d0226004                 st      %o0, [%o1+4]
F0069B94: d00323e8                 ld      [%o4+%lo(_time)], %o0
F0069B98: d0224000                 st      %o0, [%o1]
F0069B9C: 40001232                 call    _set_calendar_time_value
F0069BA0: 9010000b                 mov     %o3, %o0
F0069BA4: 4000b460                 call    _splx
F0069BA8: 90100018                 mov     %i0, %o0
F0069BAC: b0102000                 mov     0, %i0
F0069BB0: 81c7e008                 ret
F0069BB4: 81e80000                 restore
