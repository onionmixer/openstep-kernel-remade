040969B4: 4856                     pea     (a6)
040969B6: 2c4f                     movea.l sp,a6
040969B8: 61ff00000008             bsr.l   _thread_exception_return
040969BE: 4e5e                     unlk    a6
040969C0: 4e75                     rts
