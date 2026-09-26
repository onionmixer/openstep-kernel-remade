F006F45C: 9de3bf98                 save    %sp, -0x68, %sp
F006F460: 80a62000                 cmp     %i0, 0
F006F464: 02800004                 be      loc_F006F474
F006F468: 80a6601f                 cmp     %i1, 0x1F
F006F46C: 08800004                 bleu    loc_F006F47C
F006F470: a0062158                 add     %i0, 0x158, %l0
F006F474: 10800020                 ba      locret_F006F4F4
F006F478: b0102004                 mov     4, %i0
F006F47C: d0040000                 ld      [%l0], %o0
F006F480: 80a22000                 cmp     %o0, 0
F006F484: 12bffffe                 bne     loc_F006F47C
F006F488: 01000000                 nop
F006F48C: 40009e87                 call    _simple_lock_try
F006F490: 90100010                 mov     %l0, %o0
F006F494: 80a22000                 cmp     %o0, 0
F006F498: 02bffff9                 be      loc_F006F47C
F006F49C: 80a6a000                 cmp     %i2, 0
F006F4A0: 02800013                 be      loc_F006F4EC
F006F4A4: f2262164                 st      %i1, [%i0+0x164]
F006F4A8: f4062138                 ld      [%i0+0x138], %i2
F006F4AC: a0062138                 add     %i0, 0x138, %l0
F006F4B0: 80a4001a                 cmp     %l0, %i2
F006F4B4: 0280000e                 be      loc_F006F4EC
F006F4B8: 01000000                 nop
F006F4BC: d006a054                 ld      [%i2+0x54], %o0
F006F4C0: 80a20019                 cmp     %o0, %i1
F006F4C4: 36800007                 bge,a   loc_F006F4E0
F006F4C8: f406a018                 ld      [%i2+0x18], %i2
F006F4CC: 9010001a                 mov     %i2, %o0
F006F4D0: 92100018                 mov     %i0, %o1
F006F4D4: 40001a09                 call    _thread_max_priority
F006F4D8: 94100019                 mov     %i1, %o2
F006F4DC: f406a018                 ld      [%i2+0x18], %i2
F006F4E0: 80a4001a                 cmp     %l0, %i2
F006F4E4: 32bffff7                 bne,a   loc_F006F4C0
F006F4E8: d006a054                 ld      [%i2+0x54], %o0
F006F4EC: c0262158                 clr     [%i0+0x158]
F006F4F0: b0102000                 mov     0, %i0
F006F4F4: 81c7e008                 ret
F006F4F8: 81e80000                 restore
