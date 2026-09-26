04099184: 4e56ff80                 link    a6,#-$80
04099188: 48e73830                 movem.l d2-d4/a2-a3,-(sp)
0409918C: 4283                     clr.l   d3
0409918E: 08390000040b606f         btst    #0,(byte_40B606F).l
04099196: 6614                     bne.s   loc_40991AC
04099198: 4a39040c94cc             tst.b   (_rootdevice).l
0409919E: 6700017e                 beq.w   loc_409931E
040991A2: 08390000040b606f         btst    #0,(byte_40B606F).l
040991AA: 6720                     beq.s   loc_40991CC
040991AC: 4879040ac9ba             pea     (aRootDevice).l; "root device? "
040991B2: 61fffff721a4             bsr.l   _printf
040991B8: 45eeff80                 lea     var_80(a6),a2
040991BC: 2f0a                     move.l  a2,-(sp)
040991BE: 2f0a                     move.l  a2,-(sp)
040991C0: 61ff000002b4             bsr.l   _gets
040991C6: 504f                     addq.w  #8,sp
040991C8: 584f                     addq.w  #4,sp
040991CA: 6016                     bra.s   loc_40991E2
040991CC: 45f9040c94cc             lea     (_rootdevice).l,a2
040991D2: 2f0a                     move.l  a2,-(sp)
040991D4: 4879040ac9c8             pea     (aRootOnS).l; "root on %s\n"
040991DA: 61fffff7217c             bsr.l   _printf
040991E0: 504f                     addq.w  #8,sp
040991E2: 23fc040b2bde040b5644     move.l  #$40B2BDE,(dword_40B5644).l
040991EC: 4ab9040b2bde             tst.l   (off_40B2BDE).l
040991F2: 67000094                 beq.w   loc_4099288
040991F6: 2079040b5644             movea.l (dword_40B5644).l,a0
040991FC: 22680004                 movea.l 4(a0),a1
04099200: 1811                     move.b  (a1),d4
04099202: b812                     cmp.b   (a2),d4
04099204: 660a                     bne.s   loc_4099210
04099206: 18290001                 move.b  1(a1),d4
0409920A: b82a0001                 cmp.b   1(a2),d4
0409920E: 6712                     beq.s   loc_4099222
04099210: 47e8000a                 lea     $A(a0),a3
04099214: 23cb040b5644             move.l  a3,(dword_40B5644).l
0409921A: 4aa8000a                 tst.l   $A(a0)
0409921E: 66d6                     bne.s   loc_40991F6
04099220: 6066                     bra.s   loc_4099288
04099222: 0c68ffff0008             cmpi.w  #$FFFF,8(a0)
04099228: 670001d8                 beq.w   loc_4099402
0409922C: 0c2a002a0003             cmpi.b  #$2A,3(a2) ; '*'
04099232: 6606                     bne.s   loc_409923A
04099234: 156a00040003             move.b  4(a2),3(a2)
0409923A: 102a0002                 move.b  2(a2),d0
0409923E: 0600ffd0                 addi.b  #-$30,d0
04099242: 0c000007                 cmpi.b  #7,d0
04099246: 6232                     bhi.s   loc_409927A
04099248: 122a0003                 move.b  3(a2),d1
0409924C: 1001                     move.b  d1,d0
0409924E: 0600ff9f                 addi.b  #-$61,d0
04099252: 0c000007                 cmpi.b  #7,d0
04099256: 630c                     bls.s   loc_4099264
04099258: 4a01                     tst.b   d1
0409925A: 6710                     beq.s   loc_409926C
0409925C: 4879040ac9d4             pea     (aBadPartitionNu).l; "bad partition number\n"
04099262: 601c                     bra.s   loc_4099280
04099264: 1001                     move.b  d1,d0
04099266: 49c0                     extb.l  d0
04099268: 769f                     moveq   #$FFFFFF9F,d3
0409926A: d680                     add.l   d0,d3
0409926C: 102a0002                 move.b  2(a2),d0
04099270: 49c0                     extb.l  d0
04099272: 74d0                     moveq   #$FFFFFFD0,d2
04099274: d480                     add.l   d0,d2
04099276: 6000017c                 bra.w   loc_40993F4
0409927A: 4879040ac9ea             pea     (aBadMissingUnit).l; "bad/missing unit number\n"
04099280: 61fffff720d6             bsr.l   _printf
04099286: 584f                     addq.w  #4,sp
04099288: 23fc040b2bde040b5644     move.l  #$40B2BDE,(dword_40B5644).l
04099292: 4ab9040b2bde             tst.l   (off_40B2BDE).l
04099298: 6754                     beq.s   loc_40992EE
0409929A: 2079040b5644             movea.l (dword_40B5644).l,a0
040992A0: 2f280004                 move.l  4(a0),-(sp)
040992A4: b1fc040b2bde             cmpa.l  #$40B2BDE,a0
040992AA: 6714                     beq.s   loc_40992C0
040992AC: 203c040aca06             move.l  #$40ACA06,d0
040992B2: 4aa8000a                 tst.l   $A(a0)
040992B6: 670e                     beq.s   loc_40992C6
040992B8: 203c040aca03             move.l  #$40ACA03,d0
040992BE: 6006                     bra.s   loc_40992C6
040992C0: 203c040aca0b             move.l  #$40ACA0B,d0
040992C6: 2f00                     move.l  d0,-(sp)
040992C8: 4879040aca10             pea     (aSSD).l; "%s%s%%d"
040992CE: 61fffff72088             bsr.l   _printf
040992D4: 504f                     addq.w  #8,sp
040992D6: 584f                     addq.w  #4,sp
040992D8: 2079040b5644             movea.l (dword_40B5644).l,a0
040992DE: 47e8000a                 lea     $A(a0),a3
040992E2: 23cb040b5644             move.l  a3,(dword_40B5644).l
040992E8: 4aa8000a                 tst.l   $A(a0)
040992EC: 66ac                     bne.s   loc_409929A
040992EE: 4879040a6049             pea     (asc_40A6049).l; "\n"
040992F4: 61fffff72062             bsr.l   _printf
040992FA: 7801                     moveq   #1,d4
040992FC: 89b9040b606c             or.l    d4,(_boothowto).l
04099302: 584f                     addq.w  #4,sp
04099304: 6000fe9c                 bra.w   loc_40991A2
04099308: 2f02                     move.l  d2,-(sp)
0409930A: 2f2a0016                 move.l  $16(a2),-(sp)
0409930E: 4879040aca18             pea     (aRootOnSD).l; "root on %s%d\n"
04099314: 61fffff72042             bsr.l   _printf
0409931A: 600000d8                 bra.w   loc_40993F4
0409931E: 4282                     clr.l   d2
04099320: 4a39040c3b70             tst.b   (_boot_dev).l
04099326: 670000b4                 beq.w   loc_40993DC
0409932A: 4a39040c8ed4             tst.b   (_boot_info).l
04099330: 670c                     beq.s   loc_409933E
04099332: 1039040c8ed5             move.b  (byte_40C8ED5).l,d0
04099338: 49c0                     extb.l  d0
0409933A: 74d0                     moveq   #$FFFFFFD0,d2
0409933C: d480                     add.l   d0,d2
0409933E: 23fc040b2bde040b5644     move.l  #$40B2BDE,(dword_40B5644).l
04099348: 4ab9040b2bde             tst.l   (off_40B2BDE).l
0409934E: 6774                     beq.s   loc_40993C4
04099350: 2079040b5644             movea.l (dword_40B5644).l,a0
04099356: 2f280004                 move.l  4(a0),-(sp)
0409935A: 4879040c3b70             pea     (_boot_dev).l
04099360: 61ffffff9d16             bsr.l   _strcmp
04099366: 504f                     addq.w  #8,sp
04099368: 4a80                     tst.l   d0
0409936A: 6642                     bne.s   loc_40993AE
0409936C: 45f9040b2d52             lea     (_bus_dinit).l,a2
04099372: 4a92                     tst.l   (a2)
04099374: 6738                     beq.s   loc_40993AE
04099376: 4a6a001a                 tst.w   $1A(a2)
0409937A: 672a                     beq.s   loc_40993A6
0409937C: 306a0004                 movea.w 4(a2),a0
04099380: b488                     cmp.l   a0,d2
04099382: 6622                     bne.s   loc_40993A6
04099384: 2079040b5644             movea.l (dword_40B5644).l,a0
0409938A: 2652                     movea.l (a2),a3
0409938C: b7d0                     cmpa.l  (a0),a3
0409938E: 6616                     bne.s   loc_40993A6
04099390: 2f280004                 move.l  4(a0),-(sp)
04099394: 2f2a0016                 move.l  $16(a2),-(sp)
04099398: 61ffffff9cde             bsr.l   _strcmp
0409939E: 504f                     addq.w  #8,sp
040993A0: 4a80                     tst.l   d0
040993A2: 6700ff64                 beq.w   loc_4099308
040993A6: d4fc002a                 adda.w  #$2A,a2 ; '*'
040993AA: 4a92                     tst.l   (a2)
040993AC: 66c8                     bne.s   loc_4099376
040993AE: 2079040b5644             movea.l (dword_40B5644).l,a0
040993B4: 47e8000a                 lea     $A(a0),a3
040993B8: 23cb040b5644             move.l  a3,(dword_40B5644).l
040993BE: 4aa8000a                 tst.l   $A(a0)
040993C2: 668c                     bne.s   loc_4099350
040993C4: 2f02                     move.l  d2,-(sp)
040993C6: 4879040c3b70             pea     (_boot_dev).l
040993CC: 4879040aca26             pea     (aRootDeviceSDNo).l; "root device %s%d not configured\n"
040993D2: 61fffff71f84             bsr.l   _printf
040993D8: 504f                     addq.w  #8,sp
040993DA: 584f                     addq.w  #4,sp
040993DC: 4879040aca47             pea     (aNoSuitableRoot).l; "no suitable root\n"
040993E2: 61fffff71f74             bsr.l   _printf
040993E8: 4879040ac6e6             pea     (aH).l; "-h"
040993EE: 61ffffffa2b4             bsr.l   _mon_boot
040993F4: 2079040b5644             movea.l (dword_40B5644).l,a0
040993FA: 0c68ffff0008             cmpi.w  #$FFFF,8(a0)
04099400: 662a                     bne.s   loc_409942C
04099402: 13f9040a66b2040b6a8c     move.b  (aNfs).l,(_rootfs).l; "nfs" ...
0409940C: 13f9040a66b3040b6a8d     move.b  (aNfs+1).l,(byte_40B6A8D).l; "fs" ...
04099416: 13f9040a66b4040b6a8e     move.b  (aNfs+2).l,(byte_40B6A8E).l; "s" ...
04099420: 13f9040a66b5040b6a8f     move.b  (aNfs+3).l,(byte_40B6A8F).l; "" ...
0409942A: 6040                     bra.s   loc_409946C
0409942C: 13f9040a66b6040b6a8c     move.b  (a43).l,(_rootfs).l; "4.3" ...
04099436: 13f9040a66b7040b6a8d     move.b  (a43+1).l,(byte_40B6A8D).l; ".3" ...
04099440: 13f9040a66b8040b6a8e     move.b  (a43+2).l,(byte_40B6A8E).l; "3" ...
0409944A: 13f9040a66b9040b6a8f     move.b  (a43+3).l,(byte_40B6A8F).l; "" ...
04099454: 12280008                 move.b  8(a0),d1
04099458: e141                     asl.w   #8,d1
0409945A: 2002                     move.l  d2,d0
0409945C: e780                     asl.l   #3,d0
0409945E: d043                     add.w   d3,d0
04099460: 8240                     or.w    d0,d1
04099462: 31410008                 move.w  d1,8(a0)
04099466: 33c1040b6010             move.w  d1,(_rootdev).l
0409946C: 4cee0c1cff6c             movem.l var_94(a6),d2-d4/a2-a3
04099472: 4e5e                     unlk    a6
04099474: 4e75                     rts
