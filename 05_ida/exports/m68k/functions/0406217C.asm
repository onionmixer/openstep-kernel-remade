0406217C: 4856                     pea     (a6)
0406217E: 2c4f                     movea.l sp,a6
04062180: 4879040a9a05             pea     (aDevicePageoutC).l; "device_pageout called"
04062186: 61fffffa9ade             bsr.l   _panic
