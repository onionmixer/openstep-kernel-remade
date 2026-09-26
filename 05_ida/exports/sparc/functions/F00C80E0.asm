F00C80E0: 9de3bf90                 save    %sp, -0x70, %sp
F00C80E4: 113c0506                 sethi   %hi(paNextlogicaldis_0), %o0! id
F00C80E8: d2022198                 ld      [%o0+%lo(paNextlogicaldis_0)], %o1! SEL
F00C80EC: 4000a5e1                 call    _objc_msgSend
F00C80F0: 90100018                 mov     %i0, %o0
F00C80F4: d20621a4                 ld      [%i0+0x1A4], %o1
F00C80F8: 80a26000                 cmp     %o1, 0
F00C80FC: 02800008                 be      loc_F00C811C
F00C8100: a0100008                 mov     %o0, %l0
F00C8104: 90100018                 mov     %i0, %o0
F00C8108: 133c0504                 sethi   %hi(paName), %o1
F00C810C: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C8110: 213c03eb                 sethi   %hi(aSFreepartition), %l0! "%s: _freePartitions on partition != 0\n"
F00C8114: 1080001d                 ba      loc_F00C8188
F00C8118: a0142288                 bset    %lo(aSFreepartition), %l0! "%s: _freePartitions on partition != 0\n"
F00C811C: 80a42000                 cmp     %l0, 0
F00C8120: 12800004                 bne     loc_F00C8130
F00C8124: 113c0506                 sethi   -0xFEBE800, %o0! id
F00C8128: 1080001d                 ba      locret_F00C819C
F00C812C: b0102000                 mov     0, %i0
F00C8130: d2022194                 ld      [%o0+0x194], %o1! SEL
F00C8134: 4000a5cf                 call    _objc_msgSend
F00C8138: 90100010                 mov     %l0, %o0
F00C813C: 912a2018                 sll     %o0, 24, %o0
F00C8140: 80a22000                 cmp     %o0, 0
F00C8144: 1280000d                 bne     loc_F00C8178
F00C8148: 90100018                 mov     %i0, %o0
F00C814C: 113c0503                 sethi   %hi(paFree), %o0! id
F00C8150: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C8154: 4000a5c7                 call    _objc_msgSend
F00C8158: 90100010                 mov     %l0, %o0
F00C815C: 90100018                 mov     %i0, %o0! id
F00C8160: 133c0506                 sethi   %hi(paSetlogicaldisk), %o1
F00C8164: d20261a4                 ld      [%o1+%lo(paSetlogicaldisk)], %o1! SEL
F00C8168: 4000a5c2                 call    _objc_msgSend
F00C816C: 94102000                 mov     0, %o2
F00C8170: 1080000b                 ba      locret_F00C819C
F00C8174: b0102000                 mov     0, %i0
F00C8178: 133c0504                 sethi   %hi(paName), %o1
F00C817C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C8180: 213c03eba01422b0         set     aSFreepartition_0, %l0! "%s: _freePartitions with open partition"...
F00C8188: 4000a5ba                 call    _objc_msgSend
F00C818C: b0103d2b                 mov     -0x2D5, %i0
F00C8190: 92100008                 mov     %o0, %o1
F00C8194: 7ffff7d8                 call    _IOLog
F00C8198: 90100010                 mov     %l0, %o0
F00C819C: 81c7e008                 ret
F00C81A0: 81e80000                 restore
