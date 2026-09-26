040937C8: 4856                     pea     (a6)
040937CA: 2c4f                     movea.l sp,a6
040937CC: 4879040a62e7             pea     (unk_40A62E7).l
040937D2: 2f39040c9560             move.l  (_reboot_how).l,-(sp)
040937D8: 48780001                 pea     (1).w
040937DC: 61fffff74c60             bsr.l   _boot
040937E2: 4e5e                     unlk    a6
040937E4: 4e75                     rts
