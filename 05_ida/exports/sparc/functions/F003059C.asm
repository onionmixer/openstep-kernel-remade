F003059C: 9de3bf98                 save    %sp, -0x68, %sp
F00305A0: 80a6a000                 cmp     %i2, 0
F00305A4: 02800006                 be      loc_F00305BC
F00305A8: 01000000                 nop
F00305AC: 40022df1                 call    _kmgetc_silent
F00305B0: 90102000                 mov     0, %o0
F00305B4: 10800005                 ba      loc_F00305C8
F00305B8: 900a207f                 and     %o0, 0x7F, %o0
F00305BC: 40022dd8                 call    _kmgetc
F00305C0: 90102000                 mov     0, %o0
F00305C4: 900a207f                 and     %o0, 0x7F, %o0
F00305C8: 80a2200d                 cmp     %o0, 0xD
F00305CC: 22800032                 be,a    locret_F0030694
F00305D0: c02e4000                 clrb    [%i1]
F00305D4: 14800009                 bg      loc_F00305F8
F00305D8: 80a22040                 cmp     %o0, 0x40 ! '@'
F00305DC: 80a22008                 cmp     %o0, 8
F00305E0: 02800019                 be      loc_F0030644
F00305E4: 80a2200a                 cmp     %o0, 0xA
F00305E8: 2280002b                 be,a    locret_F0030694
F00305EC: c02e4000                 clrb    [%i1]
F00305F0: 10800027                 ba      loc_F003068C
F00305F4: d02e4000                 stb     %o0, [%i1]
F00305F8: 02800020                 be      loc_F0030678
F00305FC: 80a22040                 cmp     %o0, 0x40 ! '@'
F0030600: 14800007                 bg      loc_F003061C
F0030604: 80a2207f                 cmp     %o0, 0x7F
F0030608: 80a22015                 cmp     %o0, 0x15
F003060C: 2280001c                 be,a    loc_F003067C
F0030610: b2100018                 mov     %i0, %i1
F0030614: 1080001e                 ba      loc_F003068C
F0030618: d02e4000                 stb     %o0, [%i1]
F003061C: 02800004                 be      loc_F003062C
F0030620: 80a64018                 cmp     %i1, %i0
F0030624: 1080001a                 ba      loc_F003068C
F0030628: d02e4000                 stb     %o0, [%i1]
F003062C: 02800009                 be      loc_F0030650
F0030630: 01000000                 nop
F0030634: 4002056f                 call    _cnputc
F0030638: 90102008                 mov     8, %o0
F003063C: 4002056d                 call    _cnputc
F0030640: 90102008                 mov     8, %o0
F0030644: 80a64018                 cmp     %i1, %i0
F0030648: 12800006                 bne     loc_F0030660
F003064C: 01000000                 nop
F0030650: 40020568                 call    _cnputc
F0030654: 90102008                 mov     8, %o0
F0030658: 10bfffd3                 ba      loc_F00305A4
F003065C: 80a6a000                 cmp     %i2, 0
F0030660: 40020564                 call    _cnputc
F0030664: 90102020                 mov     0x20, %o0 ! ' '
F0030668: 40020562                 call    _cnputc
F003066C: 90102008                 mov     8, %o0
F0030670: 10bfffcc                 ba      loc_F00305A0
F0030674: b2067fff                 inc     -1, %i1
F0030678: b2100018                 mov     %i0, %i1
F003067C: 4002055d                 call    _cnputc
F0030680: 9010200a                 mov     0xA, %o0
F0030684: 10bfffc8                 ba      loc_F00305A4
F0030688: 80a6a000                 cmp     %i2, 0
F003068C: 10bfffc5                 ba      loc_F00305A0
F0030690: b2066001                 inc     %i1
F0030694: 81c7e008                 ret
F0030698: 81e80000                 restore
