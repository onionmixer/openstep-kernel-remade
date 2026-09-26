F004F108: 9de3bf98                 save    %sp, -0x68, %sp
F004F10C: 808e6080                 btst    0x80, %i1
F004F110: 02800022                 be      loc_F004F198
F004F114: 113c04cf                 sethi   -0xFECC400, %o0
F004F118: d0062050                 ld      [%i0+0x50], %o0
F004F11C: d04a20d2                 ldsb    [%o0+0xD2], %o0
F004F120: 80a22000                 cmp     %o0, 0
F004F124: 02800011                 be      loc_F004F168
F004F128: a006200c                 add     %i0, 0xC, %l0
F004F12C: d0162064                 lduh    [%i0+0x64], %o0
F004F130: 1300003c                 sethi   0xF000, %o1
F004F134: 920a0009                 and     %o0, %o1, %o1
F004F138: 11000008                 sethi   0x2000, %o0
F004F13C: 80a24008                 cmp     %o1, %o0
F004F140: 0280000a                 be      loc_F004F168
F004F144: 11000018                 sethi   0x6000, %o0
F004F148: 80a24008                 cmp     %o1, %o0
F004F14C: 02800007                 be      loc_F004F168
F004F150: 11000004                 sethi   0x1000, %o0
F004F154: 80a24008                 cmp     %o1, %o0
F004F158: 22800005                 be,a    loc_F004F16C
F004F15C: d0142004                 lduh    [%l0+4], %o0
F004F160: 10800036                 ba      locret_F004F238
F004F164: b010201e                 mov     0x1E, %i0
F004F168: d0142004                 lduh    [%l0+4], %o0
F004F16C: 808a2002                 btst    2, %o0
F004F170: 22800005                 be,a    loc_F004F184
F004F174: d0142004                 lduh    [%l0+4], %o0
F004F178: 4000f412                 call    _vnode_uncache
F004F17C: 9006200c                 add     %i0, 0xC, %o0
F004F180: d0142004                 lduh    [%l0+4], %o0
F004F184: 808a2002                 btst    2, %o0
F004F188: 02800004                 be      loc_F004F198
F004F18C: 113c04cf                 sethi   -0xFECC400, %o0
F004F190: 1080002a                 ba      locret_F004F238
F004F194: b010201a                 mov     0x1A, %i0
F004F198: d00221d8                 ld      [%o0+0x1D8], %o0
F004F19C: d602201c                 ld      [%o0+0x1C], %o3
F004F1A0: d252e002                 ldsh    [%o3+2], %o1
F004F1A4: 80a26000                 cmp     %o1, 0
F004F1A8: 32800004                 bne,a   loc_F004F1B8
F004F1AC: d0562068                 ldsh    [%i0+0x68], %o0
F004F1B0: 10800022                 ba      locret_F004F238
F004F1B4: b0102000                 mov     0, %i0
F004F1B8: 80a24008                 cmp     %o1, %o0
F004F1BC: 2280001b                 be,a    loc_F004F228
F004F1C0: d0162064                 lduh    [%i0+0x64], %o0
F004F1C4: d252e004                 ldsh    [%o3+4], %o1
F004F1C8: d056206a                 ldsh    [%i0+0x6A], %o0
F004F1CC: 80a24008                 cmp     %o1, %o0
F004F1D0: 02800015                 be      loc_F004F224
F004F1D4: b33e6003                 sra     %i1, 3, %i1
F004F1D8: 9402e00a                 add     %o3, 0xA, %o2
F004F1DC: 9002e02a                 add     %o3, 0x2A, %o0 ! '*'
F004F1E0: 80a28008                 cmp     %o2, %o0
F004F1E4: 3a800010                 bcc,a   loc_F004F224
F004F1E8: b33e6003                 sra     %i1, 3, %i1
F004F1EC: 96100008                 mov     %o0, %o3
F004F1F0: d2528000                 ldsh    [%o2], %o1
F004F1F4: 80a27fff                 cmp     %o1, -1
F004F1F8: 2280000b                 be,a    loc_F004F224
F004F1FC: b33e6003                 sra     %i1, 3, %i1
F004F200: d056206a                 ldsh    [%i0+0x6A], %o0
F004F204: 80a20009                 cmp     %o0, %o1
F004F208: 22800008                 be,a    loc_F004F228
F004F20C: d0162064                 lduh    [%i0+0x64], %o0
F004F210: 9402a002                 inc     2, %o2
F004F214: 80a2800b                 cmp     %o2, %o3
F004F218: 2abffff7                 bcs,a   loc_F004F1F4
F004F21C: d2528000                 ldsh    [%o2], %o1
F004F220: b33e6003                 sra     %i1, 3, %i1
F004F224: d0162064                 lduh    [%i0+0x64], %o0
F004F228: 902e4008                 andn    %i1, %o0, %o0
F004F22C: 80a00008                 cmp     %g0, %o0
F004F230: b0602000                 subc    %g0, 0, %i0
F004F234: b00e200d                 and     %i0, 0xD, %i0
F004F238: 81c7e008                 ret
F004F23C: 81e80000                 restore
