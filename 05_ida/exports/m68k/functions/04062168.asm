04062168: 4856                     pea     (a6)
0406216A: 2c4f                     movea.l sp,a6
0406216C: 4879040a99f0             pea     (aDevicePageinCa).l; "device_pagein called"
04062172: 61fffffa9af2             bsr.l   _panic
