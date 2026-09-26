F00D0608: 9de3bf88                 save    %sp, -0x78, %sp
F00D060C: a0100018                 mov     %i0, %l0
F00D0610: d0042128                 ld      [%l0+0x128], %o0! id
F00D0614: 133c0504                 sethi   %hi(paNumberoftarget), %o1
F00D0618: d20261f0                 ld      [%o1+%lo(paNumberoftarget)], %o1! SEL
F00D061C: 40008495                 call    _objc_msgSend
F00D0620: f00fa05f                 ldub    [%fp+arg_5F], %i0
F00D0624: 953a201f                 sra     %o0, 31, %o2
F00D0628: 80a2801a                 cmp     %o2, %i2
F00D062C: 18800008                 bgu     loc_F00D064C
F00D0630: 96100008                 mov     %o0, %o3
F00D0634: 80a2801a                 cmp     %o2, %i2
F00D0638: 3280002b                 bne,a   locret_F00D06E4
F00D063C: b0103d3e                 mov     -0x2C2, %i0
F00D0640: 80a2c01b                 cmp     %o3, %i3
F00D0644: 28800028                 bleu,a  locret_F00D06E4
F00D0648: b0103d3e                 mov     -0x2C2, %i0
F00D064C: 80a72000                 cmp     %i4, 0
F00D0650: 38800025                 bgu,a   locret_F00D06E4
F00D0654: b0103d3e                 mov     -0x2C2, %i0
F00D0658: 12800007                 bne     loc_F00D0674
F00D065C: 113c0505                 sethi   %hi(paClearreservati), %o0! id
F00D0660: 80a76008                 cmp     %i5, 8
F00D0664: 08800005                 bleu    loc_F00D0678
F00D0668: d2022368                 ld      [%o0+%lo(paClearreservati)], %o1
F00D066C: 1080001e                 ba      locret_F00D06E4
F00D0670: b0103d3e                 mov     -0x2C2, %i0
F00D0674: d2022368                 ld      [%o0+0x368], %o1! SEL
F00D0678: 4000847e                 call    _objc_msgSend
F00D067C: 90100010                 mov     %l0, %o0
F00D0680: 133c0506                 sethi   %hi(paReservescsi3ta), %o1
F00D0684: 9410001a                 mov     %i2, %o2
F00D0688: 9610001b                 mov     %i3, %o3
F00D068C: d0042128                 ld      [%l0+0x128], %o0! id
F00D0690: 9810001c                 mov     %i4, %o4
F00D0694: 9a10001d                 mov     %i5, %o5
F00D0698: d2026008                 ld      [%o1+%lo(paReservescsi3ta)], %o1! SEL
F00D069C: 40008475                 call    _objc_msgSend
F00D06A0: e023a05c                 st      %l0, [%sp+0x78+var_1C]
F00D06A4: 80a22000                 cmp     %o0, 0
F00D06A8: 02800006                 be      loc_F00D06C0
F00D06AC: 80a62000                 cmp     %i0, 0
F00D06B0: 32800007                 bne,a   loc_F00D06CC
F00D06B4: f43c2108                 std     %i2, [%l0+0x108]
F00D06B8: 1080000b                 ba      locret_F00D06E4
F00D06BC: b0103d2b                 mov     -0x2D5, %i0
F00D06C0: 90102001                 mov     1, %o0
F00D06C4: d0242120                 st      %o0, [%l0+0x120]
F00D06C8: f43c2108                 std     %i2, [%l0+0x108]
F00D06CC: f83c2110                 std     %i4, [%l0+0x110]
F00D06D0: b0102000                 mov     0, %i0
F00D06D4: d0042124                 ld      [%l0+0x124], %o0
F00D06D8: 13200000                 sethi   0x80000000, %o1
F00D06DC: 90120009                 bset    %o1, %o0
F00D06E0: d0242124                 st      %o0, [%l0+0x124]
F00D06E4: 81c7e008                 ret
F00D06E8: 81e80000                 restore
