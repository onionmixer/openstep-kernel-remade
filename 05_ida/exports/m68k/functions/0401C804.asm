0401C804: 4856                     pea     (a6)
0401C806: 2c4f                     movea.l sp,a6
0401C808: 48e73c00                 movem.l d2-d5,-(sp)
0401C80C: 2a2e000c                 move.l  $C(a6),d5
0401C810: 4879040a6722             pea     (a10mbEthernet).l; "10MB Ethernet"
0401C816: 2f05                     move.l  d5,-(sp)
0401C818: 61ff00000412             bsr.l   _if_type
0401C81E: 2e80                     move.l  d0,(sp)
0401C820: 61ff00076856             bsr.l   _strcmp
0401C826: 504f                     addq.w  #8,sp
0401C828: 4a80                     tst.l   d0
0401C82A: 6600009e                 bne.w   loc_401C8CA
0401C82E: 4878000e                 pea     ($E).w
0401C832: 61ff0002d9cc             bsr.l   _kalloc
0401C838: 2400                     move.l  d0,d2
0401C83A: 2f05                     move.l  d5,-(sp)
0401C83C: 61ff000003e0             bsr.l   _if_name
0401C842: 2800                     move.l  d0,d4
0401C844: 2f05                     move.l  d5,-(sp)
0401C846: 61ff000003c4             bsr.l   _if_unit
0401C84C: 2600                     move.l  d0,d3
0401C84E: 2f02                     move.l  d2,-(sp)
0401C850: 48781000                 pea     ($1000).w
0401C854: 48780002                 pea     (2).w
0401C858: 487805dc                 pea     ($5DC).w
0401C85C: 4879040acf58             pea     (aInternetProtoc_0).l; "Internet Protocol"
0401C862: 2f03                     move.l  d3,-(sp)
0401C864: 2f04                     move.l  d4,-(sp)
0401C866: 48790401c41e             pea     (sub_401C41E).l
0401C86C: 48790401c642             pea     (sub_401C642).l
0401C872: 48790401c310             pea     (sub_401C310).l
0401C878: 48790401c67e             pea     (sub_401C67E).l
0401C87E: 42a7                     clr.l   -(sp)
0401C880: 61ff00000568             bsr.l   _if_attach
0401C886: 2400                     move.l  d0,d2
0401C888: defc0038                 adda.w  #$38,sp ; '8'
0401C88C: 2e82                     move.l  d2,(sp)
0401C88E: 61ff0000036c             bsr.l   _if_private
0401C894: 2040                     movea.l d0,a0
0401C896: 584f                     addq.w  #4,sp
0401C898: 2145000a                 move.l  d5,$A(a0)
0401C89C: 2f02                     move.l  d2,-(sp)
0401C89E: 61ff0000035c             bsr.l   _if_private
0401C8A4: 2e80                     move.l  d0,(sp)
0401C8A6: 4879040acf7f             pea     (_IFCONTROL_GETADDR).l; "getaddr"
0401C8AC: 2f05                     move.l  d5,-(sp)
0401C8AE: 61ff00000226             bsr.l   _if_control
0401C8B4: 4879040a6722             pea     (a10mbEthernet).l; "10MB Ethernet"
0401C8BA: 2f03                     move.l  d3,-(sp)
0401C8BC: 2f04                     move.l  d4,-(sp)
0401C8BE: 4879040a6730             pea     (aIpProtocolEnab).l; "IP protocol enabled for interface %s%d,"...
0401C8C4: 61fffffeea92             bsr.l   _printf
0401C8CA: 4cee003cfff0             movem.l -$10(a6),d2-d5
0401C8D0: 4e5e                     unlk    a6
0401C8D2: 4e75                     rts
