0407BB30: 4856                     pea     (a6)
0407BB32: 2c4f                     movea.l sp,a6
0407BB34: 48e7003c                 movem.l a2-a5,-(sp)
0407BB38: 246e0008                 movea.l 8(a6),a2
0407BB3C: 2852                     movea.l (a2),a4
0407BB3E: 206c0010                 movea.l $10(a4),a0
0407BB42: 2a680008                 movea.l 8(a0),a5
0407BB46: 266a0226                 movea.l $226(a2),a3
0407BB4A: 4a8b                     tst.l   a3
0407BB4C: 660e                     bne.s   loc_407BB5C
0407BB4E: 4879040ab4d1             pea     (aScmsginNoCurre).l; "scmsgin: no current sd"
0407BB54: 61fffff90110             bsr.l   _panic
0407BB5A: 584f                     addq.w  #4,sp
0407BB5C: 0c2a0001021f             cmpi.b  #1,$21F(a2)
0407BB62: 660a                     bne.s   loc_407BB6E
0407BB64: 157c00080236             move.b  #8,$236(a2)
0407BB6A: 600000d4                 bra.w   loc_407BC40
0407BB6E: 4280                     clr.l   d0
0407BB70: 102a0236                 move.b  $236(a2),d0
0407BB74: 720b                     moveq   #$B,d1
0407BB76: b280                     cmp.l   d0,d1
0407BB78: 650000ac                 bcs.w   loc_407BC26
0407BB7C: 207c0407bb88             movea.l #$407BB88,a0
0407BB82: 20700c00                 movea.l (a0,d0.l*4),a0
0407BB86: 4ed0                     jmp     (a0)
0407BB88: 0407bc40                 subi.b  #$40,d7 ; '@'
0407BB8C: 0407bc26                 subi.b  #$26,d7 ; '&'
0407BB90: 0407bbce                 subi.b  #$CE,d7
0407BB94: 0407bbec                 subi.b  #$EC,d7
0407BB98: 0407bbb8                 subi.b  #$B8,d7
0407BB9C: 0407bc26                 subi.b  #$26,d7 ; '&'
0407BBA0: 0407bc26                 subi.b  #$26,d7 ; '&'
0407BBA4: 0407bc04                 subi.b  #4,d7
0407BBA8: 0407bc26                 subi.b  #$26,d7 ; '&'
0407BBAC: 0407bc26                 subi.b  #$26,d7 ; '&'
0407BBB0: 0407bc14                 subi.b  #$14,d7
0407BBB4: 0407bc14                 subi.b  #$14,d7
0407BBB8: 082b00040024             btst    #4,$24(a3)
0407BBBE: 6706                     beq.s   loc_407BBC6
0407BBC0: 4a2a00fc                 tst.b   $FC(a2)
0407BBC4: 667a                     bne.s   loc_407BC40
0407BBC6: 157c00080236             move.b  #8,$236(a2)
0407BBCC: 605e                     bra.s   loc_407BC2C
0407BBCE: 276a022a0032             move.l  $22A(a2),$32(a3)
0407BBD4: 202a022e                 move.l  $22E(a2),d0
0407BBD8: 27400046                 move.l  d0,$46(a3)
0407BBDC: 27400036                 move.l  d0,$36(a3)
0407BBE0: 222a0232                 move.l  $232(a2),d1
0407BBE4: 5381                     subq.l  #1,d1
0407BBE6: 2741003a                 move.l  d1,$3A(a3)
0407BBEA: 6054                     bra.s   loc_407BC40
0407BBEC: 256b0032022a             move.l  $32(a3),$22A(a2)
0407BBF2: 256b0036022e             move.l  $36(a3),$22E(a2)
0407BBF8: 222b003a                 move.l  $3A(a3),d1
0407BBFC: 5281                     addq.l  #1,d1
0407BBFE: 25410232                 move.l  d1,$232(a2)
0407BC02: 603c                     bra.s   loc_407BC40
0407BC04: 4879040ab4e8             pea     (aScMessageRejec).l; "sc: MESSAGE REJECT RECEIVED\n"
0407BC0A: 61fffff8f74c             bsr.l   _printf
0407BC10: 584f                     addq.w  #4,sp
0407BC12: 602c                     bra.s   loc_407BC40
0407BC14: 4879040ab505             pea     (aLinkedCommand).l; "Linked command"
0407BC1A: 42a7                     clr.l   -(sp)
0407BC1C: 2f0c                     move.l  a4,-(sp)
0407BC1E: 61ff00000096             bsr.l   sub_407BCB6
0407BC24: 6016                     bra.s   loc_407BC3C
0407BC26: 4a2a0236                 tst.b   $236(a2)
0407BC2A: 6d14                     blt.s   loc_407BC40
0407BC2C: 48780003                 pea     (3).w
0407BC30: 48780007                 pea     (7).w
0407BC34: 2f0a                     move.l  a2,-(sp)
0407BC36: 61ff0000004e             bsr.l   sub_407BC86
0407BC3C: 504f                     addq.w  #8,sp
0407BC3E: 584f                     addq.w  #4,sp
0407BC40: 082a00030225             btst    #3,$225(a2)
0407BC46: 6612                     bne.s   loc_407BC5A
0407BC48: 4879040ab514             pea     (aScmsginNoFuncc).l; "scmsgin: no FUNCCMPLT"
0407BC4E: 42a7                     clr.l   -(sp)
0407BC50: 2f0c                     move.l  a4,-(sp)
0407BC52: 61ff00000062             bsr.l   sub_407BCB6
0407BC58: 6022                     bra.s   loc_407BC7C
0407BC5A: 157c0007021e             move.b  #7,$21E(a2)
0407BC60: 1b7c00120003             move.b  #$12,3(a5)
0407BC66: 222b0042                 move.l  $42(a3),d1
0407BC6A: 4c391800040af7e4         muls.l  (_hz).l,d1
0407BC72: 2941005c                 move.l  d1,$5C(a4)
0407BC76: 197c0001005b             move.b  #1,$5B(a4)
0407BC7C: 4cee3c00fff0             movem.l -$10(a6),a2-a5
0407BC82: 4e5e                     unlk    a6
0407BC84: 4e75                     rts
