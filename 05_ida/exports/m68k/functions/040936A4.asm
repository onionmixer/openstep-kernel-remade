040936A4: 4856                     pea     (a6)
040936A6: 2c4f                     movea.l sp,a6
040936A8: 2f0a                     move.l  a2,-(sp)
040936AA: 2f02                     move.l  d2,-(sp)
040936AC: 242e0008                 move.l  8(a6),d2
040936B0: 4879040c3b70             pea     (_boot_dev).l
040936B6: 4879040c94d8             pea     (_boot_param).l
040936BC: 45f90409305c             lea     (_strcat).l,a2
040936C2: 4e92                     jsr     (a2)
040936C4: 4879040ac3dc             pea     (asc_40AC3DC).l; " "
040936CA: 4879040c94d8             pea     (_boot_param).l
040936D0: 4e92                     jsr     (a2)
040936D2: 41f9040c8ed4             lea     (_boot_info).l,a0
040936D8: 504f                     addq.w  #8,sp
040936DA: 504f                     addq.w  #8,sp
040936DC: 4a10                     tst.b   (a0)
040936DE: 671c                     beq.s   loc_40936FC
040936E0: 2f08                     move.l  a0,-(sp)
040936E2: 4879040c94d8             pea     (_boot_param).l
040936E8: 4e92                     jsr     (a2)
040936EA: 4879040ac3dc             pea     (asc_40AC3DC).l; " "
040936F0: 4879040c94d8             pea     (_boot_param).l
040936F6: 4e92                     jsr     (a2)
040936F8: 504f                     addq.w  #8,sp
040936FA: 504f                     addq.w  #8,sp
040936FC: 4879040b6d98             pea     (_boot_file).l
04093702: 4879040c94d8             pea     (_boot_param).l
04093708: 4e92                     jsr     (a2)
0409370A: 4879040ac3dc             pea     (asc_40AC3DC).l; " "
04093710: 4879040c94d8             pea     (_boot_param).l
04093716: 4e92                     jsr     (a2)
04093718: 504f                     addq.w  #8,sp
0409371A: 504f                     addq.w  #8,sp
0409371C: 4a82                     tst.l   d2
0409371E: 671c                     beq.s   loc_409373C
04093720: 2f02                     move.l  d2,-(sp)
04093722: 4879040c94d8             pea     (_boot_param).l
04093728: 4e92                     jsr     (a2)
0409372A: 4879040ac3dc             pea     (asc_40AC3DC).l; " "
04093730: 4879040c94d8             pea     (_boot_param).l
04093736: 4e92                     jsr     (a2)
04093738: 504f                     addq.w  #8,sp
0409373A: 504f                     addq.w  #8,sp
0409373C: 2f39040c94d4             move.l  (_boot_args).l,-(sp)
04093742: 4879040c94d8             pea     (_boot_param).l
04093748: 4e92                     jsr     (a2)
0409374A: 4879040c94d8             pea     (_boot_param).l
04093750: 61ff00000010             bsr.l   _mon_call
04093756: 242efff8                 move.l  -8(a6),d2
0409375A: 246efffc                 movea.l -4(a6),a2
0409375E: 4e5e                     unlk    a6
04093760: 4e75                     rts
