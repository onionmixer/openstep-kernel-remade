F008A4A4: 9de3bf98                 save    %sp, -0x68, %sp
F008A4A8: 113c0447                 sethi   %hi(aDevicePageoutC), %o0! "device_pageout called"
F008A4AC: 7ffe2b31                 call    _panic
F008A4B0: 90122270                 bset    %lo(aDevicePageoutC), %o0! "device_pageout called"
F008A4B4: 81c7e008                 ret
F008A4B8: 81e80000                 restore
