04079892: 4856                     pea     (a6)
04079894: 2c4f                     movea.l sp,a6
04079896: 206e0008                 movea.l 8(a6),a0
0407989A: 4268000a                 clr.w   $A(a0)
0407989E: 487904079892             pea     (_od_creq_timeout).l
040798A4: 61fffff9095c             bsr.l   _wakeup
040798AA: 4e5e                     unlk    a6
040798AC: 4e75                     rts
