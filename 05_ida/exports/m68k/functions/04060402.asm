04060402: 4856                     pea     (a6)
04060404: 2c4f                     movea.l sp,a6
04060406: 4879040a9895             pea     (aVmObjectReques).l; "vm_object_request_object: called\n"
0406040C: 61fffffaaf4a             bsr.l   _printf
04060412: 4280                     clr.l   d0
04060414: 4e5e                     unlk    a6
04060416: 4e75                     rts
