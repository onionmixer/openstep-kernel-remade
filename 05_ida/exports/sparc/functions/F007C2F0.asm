F007C2F0: 9de3bf98                 save    %sp, -0x68, %sp
F007C2F4: d4062004                 ld      [%i0+4], %o2
F007C2F8: 80a2a023                 cmp     %o2, 0x23 ! '#'
F007C2FC: 0880001d                 bleu    loc_F007C370
F007C300: 90103ed0                 mov     -0x130, %o0
F007C304: d0060000                 ld      [%i0], %o0
F007C308: 80a22000                 cmp     %o0, 0
F007C30C: 36800004                 bge,a   loc_F007C31C
F007C310: d0062018                 ld      [%i0+0x18], %o0
F007C314: 10800017                 ba      loc_F007C370
F007C318: 90103ed0                 mov     -0x130, %o0
F007C31C: 900a200c                 and     %o0, 0xC, %o0
F007C320: 80a2200c                 cmp     %o0, 0xC
F007C324: 12800013                 bne     loc_F007C370
F007C328: 90103ed0                 mov     -0x130, %o0
F007C32C: d206201c                 ld      [%i0+0x1C], %o1! processor_cmd
F007C330: 1100008090122020         set     0x20020, %o0
F007C338: 80a24008                 cmp     %o1, %o0
F007C33C: 1280000d                 bne     loc_F007C370
F007C340: 90103ed0                 mov     -0x130, %o0
F007C344: d0062020                 ld      [%i0+0x20], %o0
F007C348: 912a2002                 sll     %o0, 2, %o0
F007C34C: 90022024                 inc     0x24, %o0 ! '$'
F007C350: 80a28008                 cmp     %o2, %o0
F007C354: 12800007                 bne     loc_F007C370
F007C358: 90103ed0                 mov     -0x130, %o0
F007C35C: 7fffa405                 call    _convert_port_to_processor
F007C360: d0062008                 ld      [%i0+8], %o0! processor
F007C364: d4062020                 ld      [%i0+0x20], %o2! processor_cmdCnt
F007C368: 7fffcbda                 call    _processor_control
F007C36C: 92062024                 add     %i0, 0x24, %o1 ! '$'
F007C370: d026601c                 st      %o0, [%i1+0x1C]
F007C374: 81c7e008                 ret
F007C378: 81e80000                 restore
