F005B03C: 9de3bf98                 save    %sp, -0x68, %sp
F005B040: 80a62000                 cmp     %i0, 0
F005B044: 0280001a                 be      locret_F005B0AC
F005B048: 80a63fff                 cmp     %i0, -1
F005B04C: 02800018                 be      locret_F005B0AC
F005B050: 01000000                 nop
F005B054: d0060000                 ld      [%i0], %o0
F005B058: 80a22000                 cmp     %o0, 0
F005B05C: 12bffffe                 bne     loc_F005B054
F005B060: 01000000                 nop
F005B064: 4000ef91                 call    _simple_lock_try
F005B068: 90100018                 mov     %i0, %o0
F005B06C: 80a22000                 cmp     %o0, 0
F005B070: 02bffff9                 be      loc_F005B054
F005B074: 01000000                 nop
F005B078: d0062008                 ld      [%i0+8], %o0
F005B07C: 80a22000                 cmp     %o0, 0
F005B080: 36800009                 bge,a   loc_F005B0A4
F005B084: 90103fff                 mov     -1, %o0
F005B088: d0062004                 ld      [%i0+4], %o0
F005B08C: 90022001                 inc     %o0
F005B090: d0262004                 st      %o0, [%i0+4]
F005B094: d006201c                 ld      [%i0+0x1C], %o0
F005B098: 90022001                 inc     %o0
F005B09C: d026201c                 st      %o0, [%i0+0x1C]
F005B0A0: 90100018                 mov     %i0, %o0
F005B0A4: c0260000                 clr     [%i0]
F005B0A8: b0100008                 mov     %o0, %i0
F005B0AC: 81c7e008                 ret
F005B0B0: 81e80000                 restore
