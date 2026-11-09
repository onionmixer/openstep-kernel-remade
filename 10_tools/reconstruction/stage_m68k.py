#!/usr/bin/env python3
"""stage_m68k.py -- plan 433 (M3-9, D068): m68k staging from the 07 overlay trees and the
reproduction of the plan 429/432 test results.

  python3 10_tools/reconstruction/stage_m68k.py stage STAGE_DIR
  python3 10_tools/reconstruction/stage_m68k.py cmd CC.cmd
  python3 10_tools/reconstruction/stage_m68k.py x86gate WORKDIR
  python3 10_tools/reconstruction/stage_m68k.py compare RUN_ID STAGE_DIR WORKDIR GATE.json RECORD.json
  Every command takes an optional leading --plan N (433 when absent; 435, 437, 438, 441, 444, 445, 446, 447, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 465, 466, 467, 468, 469, 471, 472, 473, 474, 475, 476, 478, 479, 480, 482, 483, 485, 488, 494, 497, 502, 504, 506, 508, 510, 512, 514, 517, 520, 523, 526, 529, 531, 535, 538, 542, 544, 547, 549, 551, 554, 556, 559, 563, 566, 570, 573, 576, 579, 583, 585, 600, 602, 604, 609, 612, 614, 618, 622, 627, 636, 639, 642, 644, 646, 649, 652, 655, 657, 663, 667, 670, 674, 676, 679, 683, 687, 689, 724, 727, 729, 736, 739, 754, 756, 758, 759, 761, 763, 764, 766, 770, 779, 784, 786): the
  record's plan number, the output prefix O<N>__ and the pre-registered exception list.

stage    s6l4-g1a-stage (the x86 base; s6l5-g1a-stage from plan 466, D082; s6l6 from plan 467; s6l7 from plan 469; s6l8 from plan 471; s6l9 from plan 472; s6la from plan 473; s6lb from plan 474; s6lc from plan 475; s6ld from plan 476; s6le from plan 478; s6lf from plan 479; s6lg from plan 480; s6lh from plan 482; s6li from plan 483; s6lj from plan 485; s6lk from plan 488; s6ll from plan 494) + the real-machine SDK m68k headers (plan 413, local
         copy hash-checked against its target list) + 07_kernel/v183.34/common + 07_kernel/
         v183.34/m68k, copied in this order (a later file replaces an earlier one; D068 picks
         m68k, then common, then the 07 main tree).  STAGE_DIR.manifest.json: [path, origin,
         sha256] per file.  An overlay .c file must be its 07 main file plus inserted lines
         that each carry a registered marker (MARKERS; plan 435's D070 line at most once,
         right after '#import <sys/param.h>'; plan 437 generalisation).  From plan 497 (D103) the
         m68k-only sources 07_kernel/src/machdep/m68k/*.c go to src/machdep/m68k/ before the
         overlays (no file may be there yet); the manifest lists them in m4_sources.  From plan
         502 only the files registered in M4FILES for the plan are staged, and every .c of that
         directory must be registered (plan 512: .s sources too; m68k assembly is compiled with
         -DASSEMBLER, D108).  From plan 506 (D104, D105) the NeXTMach-only headers of
         M4HEADERS (07_kernel/nextmach/<mk-108.1 path> -> stage path; plan 535: an optional third value
         07_kernel/nextdev takes a real-machine SDK copy instead) are staged after the SDK
         copy (no file may be there yet, no overlay may have the path); the manifest lists them in
         m4_headers.
         Plan 639 (D145): a .h file in 07_kernel/src/machdep/m68k is allowed when some plan's M4HEADERS
         lists it with root 07_kernel/src; only the chosen plan's headers are staged.
cmd      the 205 compile lines of the plan 429 (run m3p429-cc2, -c only) and plan 432 (run
         m3p432-int) runs, output prefix O433__.
x86gate  re-stage every s6l4-g* x86 stage (s6l5-g* from plan 466, s6l6-g* from 467, s6l7-g* from 469, s6l8-g* from 471, s6l9-g* from 472, s6la-g* from 473, s6lb-g* from 474, s6lc-g* from 475, s6ld-g* from 476, s6le-g* from 478, s6lf-g* from 479, s6lg-g* from 480, s6lh-g* from 482, s6li-g* from 483, s6lj-g* from 485, s6lk-g* from 488, s6ll-g* from 494) with stage_headers.py and its
         manifest options and require the manifests to be unchanged (the x86 build does not read
         v183.34); all seven groups must be present.
compare  every O433 object against the test-run object (non-STABS section bytes and
         relocations with external symbol numbers replaced by names) and L1 against the
         original; the pre-registered exceptions are x86-subr_kudp and x86-if_venip.
Read-only apart from the outputs named above.
"""
import sys, os, re, json, glob, shutil, subprocess, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import macho_obj
import m0_m68k_cause as C
import m0_m68k_l1 as L
import m3_m68k_wide as W
import m3_m68k_diag as D

OVL = ['07_kernel/v183.34/common', '07_kernel/v183.34/m68k']
M4SRC = '07_kernel/src/machdep/m68k'      # plan 497 (D103): m68k-only main-tree sources
M4FILES = {497: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c'],              # plan 502: files staged per plan
           502: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c'],
           504: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c'],
           506: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c'],
           508: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c'],
           510: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c'],
           512: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s'],
           514: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s'],
           517: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c'],
           520: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c'],
           523: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c', 'in_bootp.c'],
           526: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c', 'in_bootp.c', 'autoconf.c'],
           529: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c', 'in_bootp.c', 'autoconf.c', 'kern_machdep.c'],
           531: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c', 'in_bootp.c', 'autoconf.c', 'kern_machdep.c', 'kdp_machdep.c'],
           535: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c', 'in_bootp.c', 'autoconf.c', 'kern_machdep.c', 'kdp_machdep.c', 'clock.c'],
           538: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c', 'in_bootp.c', 'autoconf.c', 'kern_machdep.c', 'kdp_machdep.c', 'clock.c', 'nextdbgasm.s'],
           542: ['checksum_16.c', 'dkbad.c', 'ufs_machdep.c', 'cons.c', 'bus.c', 'nbic.c', 'next_table.c', 'mem.c', 'libc.s', 'monitor.s',
                 'machargs.c', 'in_cksum.c', 'in_bootp.c', 'autoconf.c', 'kern_machdep.c', 'kdp_machdep.c', 'clock.c', 'nextdbgasm.s',
                 'machine_clock.c']}
M4FILES[544] = list(M4FILES[542])   # plan 544 (D119): header only, no new m68k object
M4FILES[547] = list(M4FILES[542]) + ['dma.c']   # plan 547 (D120)
M4FILES[549] = list(M4FILES[547]) + ['np.c']   # plan 549 (D121)
M4FILES[551] = list(M4FILES[549]) + ['snd_rcv.c']   # plan 551 (D122)
M4FILES[554] = list(M4FILES[551]) + ['snd_reply.c']   # plan 554 (D123)
M4FILES[556] = list(M4FILES[554]) + ['snd_device.c']   # plan 556 (D124)
M4FILES[559] = list(M4FILES[556]) + ['snd_dspcmd.c']   # plan 559 (D125)
M4FILES[563] = list(M4FILES[559]) + ['snd_dspdev.c']   # plan 563 (D126)
M4FILES[566] = list(M4FILES[563]) + ['snd_dspqueue.c']   # plan 566 (D127)
M4FILES[570] = list(M4FILES[566]) + ['fd_subr.c']   # plan 570 (D128)
M4FILES[573] = list(M4FILES[570]) + ['fd_io.c']   # plan 573 (D129)
M4FILES[576] = list(M4FILES[573]) + ['fd_driver.c']   # plan 576 (D130)
M4FILES[579] = list(M4FILES[576]) + ['fd_cmds.c']   # plan 579 (D131)
M4FILES[583] = list(M4FILES[579])   # plan 583 (D132): no new source
M4FILES[585] = list(M4FILES[579])   # plan 585 (D133): no new source
M4FILES[600] = list(M4FILES[585]) + ['machdep.c']   # plan 600 (D134)
M4FILES[602] = list(M4FILES[600]) + ['miniMonMachdep.c', 'next_exception.c']   # plan 602 (D135)
M4FILES[604] = list(M4FILES[602]) + ['APM.c']   # plan 604 (D136)
M4FILES[609] = list(M4FILES[604]) + ['m68k_init.c']   # plan 609 (D137)
M4FILES[612] = list(M4FILES[609]) + ['swapgeneric.c']   # plan 612 (D138)
M4FILES[614] = list(M4FILES[612]) + ['shutdown.c']   # plan 614 (D139)
M4FILES[618] = list(M4FILES[614]) + ['vm_machdep.c']   # plan 618 (D141)
M4FILES[622] = list(M4FILES[618])   # plan 622 (D142): overlay machdep/m68k/thread.h struct pcb
M4FILES[627] = list(M4FILES[622]) + ['pcb.c']   # plan 627 (D143)
M4FILES[636] = list(M4FILES[627]) + ['trap.c']   # plan 636 (D144)
M4FILES[639] = list(M4FILES[636]) + ['ashldi3.c', 'bdiv.c', 'lshldi3.c', 'lshrdi3.c', 'udivdi3.c', 'umoddi3.c']   # plan 639 (D145)
M4FILES[642] = list(M4FILES[639]) + ['kernel_pmon.c']   # plan 642 (D146)
M4FILES[644] = list(M4FILES[642]) + ['snd_stream.c']   # plan 644 (D147)
M4FILES[646] = list(M4FILES[644]) + ['snd_unix.c']   # plan 646 (D148)
M4FILES[649] = list(M4FILES[646])   # plan 649 (D149): 07 nextmach/nextdev/scsivar.h changed in place
M4FILES[652] = list(M4FILES[649]) + ['st.c']   # plan 652 (D150)
M4FILES[655] = list(M4FILES[652]) + ['sg.c']   # plan 655 (D151)
M4FILES[657] = list(M4FILES[655]) + ['sf_access.c']   # plan 657 (D152)
M4FILES[663] = list(M4FILES[657]) + ['sd.c']   # plan 663 (D153); 07 nextmach/nextdev/scsireg.h and st.c changed in place
M4FILES[667] = list(M4FILES[663]) + ['scsi.c']   # plan 667 (D154)
M4FILES[670] = list(M4FILES[667]) + ['sc.c']   # plan 670 (D155)
M4FILES[674] = list(M4FILES[670]) + ['zscom.c']   # plan 674 (D156)
M4FILES[676] = list(M4FILES[674]) + ['if_bus.c']   # plan 676 (D157)
M4FILES[679] = list(M4FILES[676]) + ['km.c']   # plan 679 (D158)
M4FILES[683] = list(M4FILES[679]) + ['od.c']   # plan 683 (D159); generated od.h NOD 2/NOC 1, machargs.c comment
M4FILES[687] = list(M4FILES[683]) + ['pmap.c']   # plan 687 (D160); the machine pmap definitions are in pmap.c
M4FILES[689] = list(M4FILES[687]) + ['ev.c']   # plan 689 (D161): m68k ev.c
M4FILES[724] = list(M4FILES[689]) + ['ev_ioctl.c']   # plan 724 (D162): m68k ev_ioctl.c
M4FILES[727] = list(M4FILES[724]) + ['if_en.c']   # plan 727 (D163): m68k if_en.c
M4FILES[729] = list(M4FILES[727]) + ['ev_kbd.c']   # plan 729 (D164): m68k ev_kbd.c
M4FILES[736] = list(M4FILES[729]) + ['ev_mouse.c']   # plan 736 (D165): m68k ev_mouse.c
M4FILES[739] = list(M4FILES[736]) + ['nextdbg.c']   # plan 739 (D166): m68k nextdbg.c
M4FILES[754] = list(M4FILES[739]) + ['locore.s']   # plan 754 (D167, D168): m68k locore.s
M4FILES[756] = list(M4FILES[754]) + ['snd_link.c']   # plan 756 (D169): m68k snd_link.c
M4FILES[758] = list(M4FILES[756])   # plan 758 (D170): snd_link re-accepted with the corrected nextdev/snd_audio.h
M4FILES[759] = list(M4FILES[758]) + ['snd_server.c']   # plan 759 (D170): m68k snd_server.c
M4FILES[761] = list(M4FILES[759]) + ['video.c']   # plan 761 (D171): m68k video.c
M4FILES[763] = list(M4FILES[761]) + ['zs.c']   # plan 763 (D172): m68k zs.c
M4FILES[764] = list(M4FILES[763])   # plan 764: no new machdep file (the tty_pty tail is an overlay of a 07 main file)
M4FILES[766] = list(M4FILES[764]) + ['adb.c']   # plan 766 (D173): m68k adb.c
M4FILES[770] = list(M4FILES[766]) + ['fpsp.s']   # plan 770 (D174, D175): m68k fpsp.s (hybrid of NeXTMach FPSP lines and lines written from the original bytes)
M4FILES[774] = list(M4FILES[770]) + ['fd_global.c', 'scsiconf.c']   # plan 774 (D104, D107): NeXTMach nextdev/fd_global.c and scsiconf.c (data-only objects; include substitutions)
M4FILES[777] = list(M4FILES[774]) + ['conf.c', 'ioconf.c', 'vers.c']   # plan 777 (D177): NeXTMach next/conf.c with marked changes; ioconf.c and vers.c in the generator-output form written from the original bytes (data-only objects)
M4FILES[779] = list(M4FILES[777])   # plan 779 (D178): no new machdep source; ev.c, if_en.c, m68k_init.c, nextdbg.c, fpsp.s changed in place
M4FILES[784] = list(M4FILES[779])   # plan 784 (D179): no new machdep source; the swapfs.c m68k overlay
M4FILES[786] = list(M4FILES[784])   # plan 786 (D180): no new machdep source; the nfs_client.c m68k overlay
M4HEADERS = {506: [('next/bmap.h', 'src/bsd/m68k/bmap.h')],   # plan 506 (D104): 07_kernel/nextmach/<path> -> stage path
             510: [('next/bmap.h', 'src/bsd/m68k/bmap.h'), ('next/mmu.h', 'src/bsd/m68k/mmu.h'),   # plan 510 (D107)
                   ('nextdev/snd_dspreg.h', 'src/bsd/dev/m68k/snd_dspreg.h')],
             512: [('next/bmap.h', 'src/bsd/m68k/bmap.h'), ('next/mmu.h', 'src/bsd/m68k/mmu.h'),   # plan 512 (D108)
                   ('nextdev/snd_dspreg.h', 'src/bsd/dev/m68k/snd_dspreg.h'), ('next/cframe.h', 'src/bsd/m68k/cframe.h')],
             514: [('next/bmap.h', 'src/bsd/m68k/bmap.h'), ('next/mmu.h', 'src/bsd/m68k/mmu.h'),   # plan 514 (D109): next/cpu.h for assembly only
                   ('nextdev/snd_dspreg.h', 'src/bsd/dev/m68k/snd_dspreg.h'), ('next/cframe.h', 'src/bsd/m68k/cframe.h'),
                   ('next/cpu.h', 'src/bsd/next/cpu.h'), ('nextdev/monreg.h', 'src/bsd/dev/m68k/monreg.h')],
             517: [('next/bmap.h', 'src/bsd/m68k/bmap.h'), ('next/mmu.h', 'src/bsd/m68k/mmu.h'),   # plan 517 (D110)
                   ('nextdev/snd_dspreg.h', 'src/bsd/dev/m68k/snd_dspreg.h'), ('next/cframe.h', 'src/bsd/m68k/cframe.h'),
                   ('next/cpu.h', 'src/bsd/next/cpu.h'), ('nextdev/monreg.h', 'src/bsd/dev/m68k/monreg.h'),
                   ('next/event_meter.h', 'src/bsd/next/event_meter.h')]}
M4HEADERS[520] = list(M4HEADERS[517])   # plan 520 (D111): no new header
M4HEADERS[523] = list(M4HEADERS[517])   # plan 523 (D112): no new header
M4HEADERS[526] = list(M4HEADERS[517]) + [('next/autoconf.h', 'src/bsd/next/autoconf.h'),   # plan 526 (D113)
                                         ('nextdev/scsireg.h', 'src/bsd/dev/m68k/scsireg.h'), ('nextdev/scsivar.h', 'src/bsd/dev/m68k/scsivar.h')]
M4HEADERS[529] = list(M4HEADERS[526])   # plan 529 (D114): no new header
M4HEADERS[531] = list(M4HEADERS[529])   # plan 531 (D115): no new header
M4HEADERS[535] = list(M4HEADERS[531]) + [('next/clock.h', 'src/bsd/next/clock.h'), ('mon/nvram.h', 'src/mon/nvram.h'),   # plan 535 (D116)
                                         ('bsd/dev/m68k/video.h', 'src/bsd/dev/m68k/video.h', '07_kernel/nextdev')]
M4HEADERS[538] = list(M4HEADERS[535])   # plan 538 (D117): no new header
M4HEADERS[542] = list(M4HEADERS[538])   # plan 542 (D118): no new header
M4HEADERS[544] = list(M4HEADERS[542]) + [('nextdev/dma.h', 'src/bsd/nextdev/dma.h')]   # plan 544 (D119): 1997 struct dma_chan
M4HEADERS[547] = list(M4HEADERS[544])   # plan 547 (D120): no new header (nextdev/dma.h edited)
M4HEADERS[549] = list(M4HEADERS[547]) + [('nextdev/npreg.h', 'src/bsd/nextdev/npreg.h'),   # plan 549 (D121)
                                         ('bsd/dev/m68k/npio.h', 'src/bsd/dev/m68k/npio.h', '07_kernel/nextdev')]
M4HEADERS[551] = list(M4HEADERS[549]) + [('nextdev/snd_var.h', 'src/bsd/nextdev/snd_var.h'),   # plan 551 (D122)
                                         ('nextdev/snd_msgs.h', 'src/bsd/nextdev/snd_msgs.h')]
M4HEADERS[554] = [h for h in M4HEADERS[551] if h[0] != 'nextdev/snd_msgs.h'] + [   # plan 554 (D123): the x86 07 driverkit/snd_msgs.h for <nextdev/snd_msgs.h>
    ('driverkit/snd_msgs.h', 'src/bsd/nextdev/snd_msgs.h', '07_kernel/src'), ('nextdev/snd_dsp.h', 'src/bsd/nextdev/snd_dsp.h')]
M4HEADERS[556] = list(M4HEADERS[554]) + [('nextdev/snd_snd.h', 'src/bsd/nextdev/snd_snd.h')]   # plan 556 (D124)
M4HEADERS[570] = list(M4HEADERS[556]) + [   # plan 570 (D128): floppy and pmon headers (fd_extern.h is the Darwin 0.1 text, user decision)
    ('nextdev/fd_extern.h', 'src/bsd/nextdev/fd_extern.h'), ('nextdev/fd_vars.h', 'src/bsd/nextdev/fd_vars.h'), ('nextdev/fd_reg.h', 'src/bsd/nextdev/fd_reg.h'),
    ('nextdev/sf_access.h', 'src/bsd/nextdev/sf_access.h'), ('next/pmon.h', 'src/bsd/next/pmon.h'), ('next/pmon_ipc.h', 'src/bsd/next/pmon_ipc.h'),
    ('next/pmon_targets.h', 'src/bsd/next/pmon_targets.h'), ('next/kernel_pmon.h', 'src/bsd/next/kernel_pmon.h')]
M4HEADERS[573] = list(M4HEADERS[570]) + [('nextdev/odreg.h', 'src/bsd/nextdev/odreg.h')]   # plan 573 (D129)
M4HEADERS[583] = list(M4HEADERS[573]) + [('mon/global.h', 'src/mon/global.h'), ('mon/assym.h', 'src/mon/assym.h'),   # plan 583 (D132): full NeXTMach mon/global.h and its closure
                                          ('mon/region.h', 'src/mon/region.h'), ('mon/tftp.h', 'src/mon/tftp.h'), ('mon/bootp.h', 'src/mon/bootp.h'),
                                          ('mon/animate.h', 'src/mon/animate.h'), ('mon/sio.h', 'src/mon/sio.h'), ('mon/kmreg.h', 'src/mon/kmreg.h'),
                                          ('nextdev/kmreg.h', 'src/bsd/nextdev/kmreg.h')]
M4HEADERS[585] = [h for h in M4HEADERS[583] if h[0] not in ('mon/tftp.h', 'mon/bootp.h')]   # plan 585 (D133): mon/global.h no longer imports mon/tftp.h
M4HEADERS[600] = list(M4HEADERS[585]) + [('next/scb.h', 'src/bsd/next/scb.h')]   # plan 600 (D134): the NeXTMach copy for machdep.c
M4HEADERS[639] = list(M4HEADERS[600]) + [('machdep/m68k/dword.h', 'src/machdep/m68k/dword.h', '07_kernel/src')]   # plan 639 (D145): authored header of the M4SRC directory
M4HEADERS[652] = list(M4HEADERS[639]) + [('nextdev/stvar.h', 'src/bsd/nextdev/stvar.h'), ('nextdev/screg.h', 'src/bsd/nextdev/screg.h'),   # plan 652 (D150): NeXTMach copies for st.c
                                         ('nextdev/scvar.h', 'src/bsd/nextdev/scvar.h')]
M4HEADERS[655] = list(M4HEADERS[652]) + [('nextdev/sgvar.h', 'src/bsd/nextdev/sgvar.h')]   # plan 655 (D151): NeXTMach copy for sg.c, SG_UNIT changed
M4HEADERS[663] = list(M4HEADERS[655]) + [('nextdev/sdvar.h', 'src/bsd/nextdev/sdvar.h')]   # plan 663 (D153): NeXTMach copy for sd.c, sdv_dlp_alloc
M4HEADERS[674] = list(M4HEADERS[663]) + [('nextdev/zscom.h', 'src/bsd/nextdev/zscom.h'),   # plan 674 (D156): NeXTMach copy for zscom.c and the
                                         ('architecture/zs85C30.h', 'components/architecture/zs85C30.h', '07_kernel/nextdev')]   # real-machine SDK header the SDK zsreg.h imports
M4HEADERS[676] = list(M4HEADERS[674]) + [('nextif/if_bus.h', 'src/bsd/nextif/if_bus.h')]   # plan 676 (D157): NeXTMach copy for if_bus.c, 3-argument if_rbusget
M4HEADERS[679] = list(M4HEADERS[676]) + [('nextdev/td.h', 'src/bsd/nextdev/td.h'), ('nextdev/km_pcode.h', 'src/bsd/nextdev/km_pcode.h'),   # plan 679 (D158): km.c headers
                                         ('nextdev/ohlfs12.h', 'src/bsd/nextdev/ohlfs12.h'),
                                         ('bsd/dev/m68k/keycodes.h', 'src/bsd/dev/m68k/keycodes.h', '07_kernel/nextdev'),
                                         ('bsd/dev/m68k/event.h', 'src/bsd/dev/m68k/event.h', '07_kernel/nextdev'),
                                         ('bsd/dev/m68k/evio.h', 'src/bsd/dev/m68k/evio.h', '07_kernel/nextdev')]
M4HEADERS[683] = list(M4HEADERS[679]) + [('nextdev/odvar.h', 'src/bsd/nextdev/odvar.h'), ('nextdev/canon.h', 'src/bsd/nextdev/canon.h')]   # plan 683 (D159): NeXTMach copies for od.c
M4HEADERS[687] = list(M4HEADERS[683])   # plan 687 (D160): no new header
M4HEADERS[689] = list(M4HEADERS[687])   # plan 689 (D161): no new header
M4HEADERS[724] = list(M4HEADERS[689]) + [('bsd/dev/m68k/evsio.h', 'src/bsd/dev/m68k/evsio.h', '07_kernel/nextdev')]   # plan 724 (D162): real-machine evsio.h
M4HEADERS[727] = list(M4HEADERS[724]) + [('nextif/if_enreg.h', 'src/bsd/nextif/if_enreg.h')]   # plan 727 (D163): NeXTMach copy for if_en.c
M4HEADERS[729] = list(M4HEADERS[727])   # plan 729 (D164): no new header
M4HEADERS[736] = list(M4HEADERS[729])   # plan 736 (D165): no new header
M4HEADERS[739] = list(M4HEADERS[736])   # plan 739 (D166): no new header
M4HEADERS[754] = list(M4HEADERS[739])   # plan 754 (D167, D168): no new header
M4HEADERS[756] = list(M4HEADERS[754]) + [('nextdev/snd_audio.h', 'src/bsd/nextdev/snd_audio.h')]   # plan 756 (D169): this project's audio layer declarations
M4HEADERS[758] = list(M4HEADERS[756])   # plan 758 (D170): the header nextdev/snd_audio.h is already registered; its content is the corrected one
M4HEADERS[759] = list(M4HEADERS[758])   # plan 759 (D170): no new header
M4HEADERS[761] = list(M4HEADERS[759])   # plan 761 (D171): no new header
M4HEADERS[763] = list(M4HEADERS[761])   # plan 763 (D172): no new header
M4HEADERS[764] = list(M4HEADERS[763])   # plan 764: no new header
M4HEADERS[766] = list(M4HEADERS[764]) + [('machdep/m68k/adb.h', 'src/machdep/m68k/adb.h', '07_kernel/src')]   # plan 766 (D173): authored header of the M4SRC directory
M4HEADERS[770] = list(M4HEADERS[766]) + [('machdep/m68k/fpsp.h', 'src/machdep/m68k/fpsp.h', '07_kernel/src')]   # plan 770 (D175): fpsp.h = NeXTMach conv output of fpsp.sa, next to fpsp.s (quote include)
M4HEADERS[779] = list(M4HEADERS[770]) + [('mon/tftp.h', 'src/mon/tftp.h'), ('mon/bootp.h', 'src/mon/bootp.h'),   # plan 779 (D178): mon/tftp.h for subr_prf.c (D133 kept),
                                         ('next/scr.h', 'src/bsd/m68k/scr.h'),   # NeXTMach next/scr.h without scr1 for kern_exit.c,
                                         ('machdep/m68k/ev_vars.h', 'src/machdep/m68k/ev_vars.h', '07_kernel/src')]   # the ev variables header of ev.c
OVLFROM = {'src/bsd/kern/tty_pty.c': 764, 'src/bsd/kern/init_sysent.c': 774, 'generated/ldd.h': 777, 'generated/km.h': 777, 'generated/ev.h': 777, 'generated/vol.h': 777, 'src/bsd/dev/vol.c': 779, 'src/bsd/swapfs/swapfs.c': 784, 'src/bsd/nfs/nfs_client.c': 786}   # plan 764 (D064): overlay path -> first plan that stages it (older plans regenerate unchanged)
OVLDROP = {433: [], 583: ['src/mon/global.h']}   # plan 583 (D132): overlay paths not staged from this plan on (the plan 437 partial mon/global.h)
REFS = [('m3p429-cc2', 'W429__'), ('m3p432-int', 'A432__')]
PLAN = 433                                # set by --plan (plan 435)
EXCEPTS = {433: {'x86-subr_kudp': 'SDK machparam.h spl import not taken (D069 pending)',
                 'x86-if_venip': 'SDK machparam.h spl import not taken (D069 pending)'},
           435: {},
           437: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (expected to differ from the test run)'},
           441: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           444: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           445: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           446: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           447: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)'},
           449: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)'},
           450: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)'},
           451: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)'},
           452: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)'},
           453: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)'},
           454: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)'},
           455: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)'},
           456: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)'},
           457: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)'},
           458: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)',
                 'x86-in_pcb': 'multicast ifp form in the m68k overlay (plan 458)'},
           459: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)',
                 'x86-in_pcb': 'multicast ifp form in the m68k overlay (plan 458)',
                 'x86-ip_output': 'fragment offset initialisation in the m68k overlay (plan 459)'},
           460: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)',
                 'x86-in_pcb': 'multicast ifp form in the m68k overlay (plan 458)',
                 'x86-ip_output': 'fragment offset initialisation in the m68k overlay (plan 459)',
                 'x86-vm_kern': 'kmem_alloc_prim find_space argument in the m68k overlay (plan 460)'},
           461: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)',
                 'x86-in_pcb': 'multicast ifp form in the m68k overlay (plan 458)',
                 'x86-ip_output': 'fragment offset initialisation in the m68k overlay (plan 459)',
                 'x86-vm_kern': 'kmem_alloc_prim find_space argument in the m68k overlay (plan 460)',
                 'x86-ip_icmp': 'mask assignment test form in the m68k overlay (plan 461)'},
           462: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)',
                 'x86-in_pcb': 'multicast ifp form in the m68k overlay (plan 458)',
                 'x86-ip_output': 'fragment offset initialisation in the m68k overlay (plan 459)',
                 'x86-vm_kern': 'kmem_alloc_prim find_space argument in the m68k overlay (plan 460)',
                 'x86-ip_icmp': 'mask assignment test form in the m68k overlay (plan 461)',
                 'x86-vfs_dnlc': 'static inline queue helpers in the m68k overlay (plan 462)'},
           463: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)',
                 'x86-in_pcb': 'multicast ifp form in the m68k overlay (plan 458)',
                 'x86-ip_output': 'fragment offset initialisation in the m68k overlay (plan 459)',
                 'x86-vm_kern': 'kmem_alloc_prim find_space argument in the m68k overlay (plan 460)',
                 'x86-ip_icmp': 'mask assignment test form in the m68k overlay (plan 461)',
                 'x86-vfs_dnlc': 'static inline queue helpers in the m68k overlay (plan 462)',
                 'x86-tcp_input': 'ti_len htons store and offer MIN in the m68k overlay (plan 463)'},
           465: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (plan 438)',
                 'x86-ufs_vnodeops': 'i386 byte swap removed in the m68k overlay (plan 449)',
                 'x86-ufs_inode': 'NeXTMach structure assignment restored in the m68k overlay (plan 449)',
                 'x86-ufs_vfsops': 'i386 byte swap removed, frame filler 58 in the m68k overlay (plan 450)',
                 'x86-ufs_dir': 'i386 directory byte swap removed in the m68k overlay (plan 451)',
                 'x86-ufs_alloc': 'i386 cylinder group byte swap removed, NeXTMach checks in the m68k overlay (plan 452)',
                 'x86-kern_shutdown': 'DELAY instead of us_spin in the m68k overlay (plan 453)',
                 'x86-init_main': 'no Objective-C/autoconf, ns_timer_init and softint thread in the m68k overlay (plan 454)',
                 'x86-kern_clock': 'hardclock SIMPLE_CLOCK block in the m68k overlay (plan 455)',
                 'x86-kern_uname': 'machine_type cases in the m68k overlay (plan 456)',
                 'x86-ufs_dsort': 'no classic disksort, spldma in the m68k overlay (plan 457)',
                 'x86-in_pcb': 'multicast ifp form in the m68k overlay (plan 458)',
                 'x86-ip_output': 'fragment offset initialisation in the m68k overlay (plan 459)',
                 'x86-vm_kern': 'kmem_alloc_prim find_space argument in the m68k overlay (plan 460)',
                 'x86-ip_icmp': 'mask assignment test form in the m68k overlay (plan 461)',
                 'x86-vfs_dnlc': 'static inline queue helpers in the m68k overlay (plan 462)',
                 'x86-tcp_input': 'ti_len htons store and offer MIN in the m68k overlay (plan 463)',
                 'x86-vm_pager': 'vm_pager_deallocate branch order in the m68k overlay (plan 465)'},
           466: {},   # filled below: plan 465 + x86-kdp
           467: {},   # filled below: plan 466 + nfs_subr, nfs_vfsops
           438: {'x86-subr_prf': 'ROM Monitor line added in the m68k overlay (plan 437)',
                 'x86-kern_server': 'KERNOBJC 0 in the m68k overlay (expected to differ from the test run)'}}
MARKERS = {'plan 435 (D070)': {'src/bsd/rpc/subr_kudp.c': 1, 'src/bsd/net/if_venip.c': 1},   # registered overlay
           'plan 437 (m68k)': {'src/bsd/kern/subr_prf.c': 5},          # markers: file -> number of marked lines
           'plan 441 (m68k)': {'src/kern/ast.c': 32},                  # (a begin..end block counts every line)
           'plan 444 (m68k)': {'src/bsd/kern/mach_process.c': 7, 'src/bsd/kern/kern_exec.c': 5},
           'plan 445 (m68k)': {'src/bsd/kern/kern_exec.c': 9},
           'plan 446 (m68k)': {'src/vm/vm_fault.c': 46},
           'plan 447 (m68k)': {'src/vm/vm_pageout.c': 26},
           'plan 449 (m68k)': {'src/bsd/ufs/ufs_vnodeops.c': 4, 'src/bsd/ufs/ufs_inode.c': 8},
           'plan 450 (m68k)': {'src/bsd/ufs/ufs_vfsops.c': 18},
           'plan 451 (m68k)': {'src/bsd/ufs/ufs_dir.c': 7},
           'plan 452 (m68k)': {'src/bsd/ufs/ufs_alloc.c': 64},
           'plan 453 (m68k)': {'src/bsd/kern/kern_shutdown.c': 4},
           'plan 454 (m68k)': {'src/bsd/kern/init_main.c': 16},
           'plan 455 (m68k)': {'src/bsd/kern/kern_clock.c': 75},
           'plan 456 (m68k)': {'src/bsd/kern/kern_uname.c': 52},
           'plan 457 (m68k)': {'src/bsd/ufs/ufs_dsort.c': 14},
           'plan 458 (m68k)': {'src/bsd/netinet/in_pcb.c': 36},
           'plan 459 (m68k)': {'src/bsd/netinet/ip_output.c': 6},
           'plan 460 (m68k)': {'src/vm/vm_kern.c': 30},
           'plan 461 (m68k)': {'src/bsd/netinet/ip_icmp.c': 33},
           'plan 462 (m68k)': {'src/bsd/kern/vfs_dnlc.c': 16},
           'plan 463 (m68k)': {'src/bsd/netinet/tcp_input.c': 9},
           'plan 465 (m68k)': {'src/vm/vm_pager.c': 7},
           'plan 468 (m68k)': {'src/kern/ns_timer.c': 252},
           'plan 471 (m68k)': {'src/bsd/kern/kern_exit.c': 9, 'src/bsd/kern/kern_proc.c': 7},
           'plan 472 (m68k)': {'src/kern/mfs_prim.c': 6},
           'plan 473 (m68k)': {'src/kern/mach_clock.c': 6},
           'plan 764 (m68k)': {'src/bsd/kern/tty_pty.c': 85},   # plan 764: the begin..end block of pts_process_putc and ptsputc
           'plan 774 (m68k)': {'src/bsd/kern/init_sysent.c': 8},   # plan 774: entries 139 (sigreturn,0) and 151 (machparam,2) under #if !m68k / #else / #endif
           'plan 779 (m68k)': {'src/bsd/kern/subr_prf.c': 2, 'src/bsd/kern/kern_exit.c': 1, 'src/bsd/dev/vol.c': 3},   # plan 779 (D178): __common declarations at the file ends
           'plan 784 (m68k)': {'src/bsd/swapfs/swapfs.c': 12},   # plan 784 (D179): sd_flags/flags as char and the second mask, under #if !m68k / #else / #endif
           'plan 786 (m68k)': {'src/bsd/nfs/nfs_client.c': 8}}   # plan 786 (D180): set_attrcache_time as static void, under #if !m68k / #else / #endif
EXCEPTS[466] = dict(EXCEPTS[465], **{'x86-kdp': 'kdp_regions range from VM_MIN/MAX_KERNEL_ADDRESS in the 07 main file (plan 466, D082)'})
EXCEPTS[467] = dict(EXCEPTS[466], **{'x86-nfs_subr': 'rlock_awaken before rlock_timeout in the 07 main file (plan 467, D084)',
                                    'x86-nfs_vfsops': 'unused hostpath under #if !MACH in the 07 main file (plan 467, D085)'})
EXCEPTS[468] = dict(EXCEPTS[467])   # plan 468: the ns_timer overlay; ns_timer is not among the 205 reference lines
EXCEPTS[469] = dict(EXCEPTS[468])   # plan 469: ns_timer main file and overlay (D088); not among the 205 reference lines
EXCEPTS[471] = dict(EXCEPTS[469], **{'x86-kalloc': 'realloc comparison in the 07 main file (plan 471, D089)',
                                    'x86-kern_exit': 'od_unlock_check block in the m68k overlay (plan 471)',
                                    'x86-kern_proc': 'alloc_posix_proc bzero in the m68k overlay (plan 471)'})
EXCEPTS[472] = dict(EXCEPTS[471], **{'x86-cmu_syscalls': 'table else block in the 07 main file (plan 472, D090)',
                                    'x86-mfs_prim': 'mfs_map_size in double in the m68k overlay (plan 472, D090)'})
EXCEPTS[473] = dict(EXCEPTS[472], **{'x86-mach_clock': 'service_timer placement in the 07 main file, no time_of_boot in the m68k overlay (plan 473, D091)',
                                    'x86-time_stamp': 'event_set_ts of the m68k overlay eventc.h (plan 473, D091)'})
EXCEPTS[474] = dict(EXCEPTS[473], **{'x86-igmp': 'IGMP_RANDOM_DELAY order and traversal helpers in the 07 main file (plan 474, D092)'})
EXCEPTS[475] = dict(EXCEPTS[474], **{'x86-kern_fork': 'switch_unix_context cpu index in the 07 main file (plan 475, D093)'})
EXCEPTS[476] = dict(EXCEPTS[475], **{'x86-ipc_mig': 'msg_rpc inner mqueue declaration in the 07 main file (plan 476, D094)'})
EXCEPTS[478] = dict(EXCEPTS[476], **{'x86-ufs_subr': 'bufstats counts declaration under #if m68k in the 07 main file (plan 478, D095)'})
EXCEPTS[479] = dict(EXCEPTS[478], **{'x86-mach_net': 'netipc_listen CC_OPT pragma pair under #if m68k in the 07 main file (plan 479, D096)'})
EXCEPTS[480] = dict(EXCEPTS[479], **{'x86-netif': 'static function order, if_control call and #if i386 hostid block in the 07 main file (plan 480, D097)'})
EXCEPTS[482] = dict(EXCEPTS[480], **{'x86-miniMon': 'lock header, prf/simple_lock_alloc declarations, mm_getline order and command loop in the 07 main file (plans 481-482, D098)'})
EXCEPTS[483] = dict(EXCEPTS[482], **{'x86-kdp_udp': 'kdp_handler, kdp_connection_wait and kdp_send_exception not inline in the 07 main file (plan 483, D099)'})
EXCEPTS[485] = dict(EXCEPTS[483], **{'x86-callout': 'helper order and inline forms, remove return value, callout_thread order and calloutEntryRemove handle copy in the 07 main file (plans 484-485, D100)'})
EXCEPTS[488] = dict(EXCEPTS[485], **{'x86-tty': 'u_char forms of the character tests, ttbreakc and ttyblkin, and the TS_TBLOCK test in the 07 main file (plans 486-488, D101)'})
EXCEPTS[494] = dict(EXCEPTS[488], **{'x86-swapfs': 'm68k function order and inline forms, swapfs_release and swapfs_setsysent, rcache/wcache argument order, K&R logswap and the m68k pagein exit in the 07 main file (plans 489-494, D102)'})
EXCEPTS[497] = dict(EXCEPTS[494])   # plan 497 (D103): m68k-only sources added, no x86 object changes
EXCEPTS[502] = dict(EXCEPTS[497])   # plan 502: m68k cons.c added to M4FILES, no x86 object changes
EXCEPTS[504] = dict(EXCEPTS[502])   # plan 504: m68k bus.c added to M4FILES, no x86 object changes
EXCEPTS[506] = dict(EXCEPTS[504])   # plan 506: m68k nbic.c and next/bmap.h, no x86 object changes
EXCEPTS[508] = dict(EXCEPTS[506])   # plan 508: m68k next_table.c, no x86 object changes
EXCEPTS[510] = dict(EXCEPTS[508])   # plan 510: m68k mem.c, next/mmu.h and nextdev/snd_dspreg.h, no x86 object changes
EXCEPTS[512] = dict(EXCEPTS[510])   # plan 512: m68k libc.s and next/cframe.h, no x86 object changes
EXCEPTS[514] = dict(EXCEPTS[512])   # plan 514: m68k monitor.s, next/cpu.h and nextdev/monreg.h, no x86 object changes
EXCEPTS[517] = dict(EXCEPTS[514], **{   # plan 517 (D110): m68k machargs.c, next/event_meter.h, five m68k generated headers;
    # the two m68k overlays below changed these objects (OBJECT_MATCH gained) but were never registered here (user, 2026-10-26)
    'x86-vm_fault': 'm68k overlay src/vm/vm_fault.c (plan 446 MARKERS)',
    'x86-vm_pageout': 'm68k overlay src/vm/vm_pageout.c (plan 447 MARKERS)'})
EXCEPTS[520] = dict(EXCEPTS[517])   # plan 520 (D111): m68k in_cksum.c (in_cksum and the oc_cksum asm), no x86 object changes
EXCEPTS[523] = dict(EXCEPTS[520])   # plan 523 (D112): m68k in_bootp.c, no x86 object changes
EXCEPTS[526] = dict(EXCEPTS[523])   # plan 526 (D113): m68k autoconf.c and three NeXTMach headers, no x86 object changes
EXCEPTS[529] = dict(EXCEPTS[526])   # plan 529 (D114): m68k kern_machdep.c, no x86 object changes
EXCEPTS[531] = dict(EXCEPTS[529])   # plan 531 (D115): m68k kdp_machdep.c, no x86 object changes
EXCEPTS[535] = dict(EXCEPTS[531])   # plan 535 (D116): m68k clock.c, next/clock.h, mon/nvram.h, SDK dev/m68k/video.h, no x86 object changes
EXCEPTS[538] = dict(EXCEPTS[535])   # plan 538 (D117): m68k nextdbgasm.s, no x86 object changes
EXCEPTS[542] = dict(EXCEPTS[538])   # plan 542 (D118): m68k machine_clock.c, no x86 object changes
EXCEPTS[544] = dict(EXCEPTS[542])   # plan 544 (D119): m68k nextdev/dma.h, no x86 object changes
EXCEPTS[547] = dict(EXCEPTS[544])   # plan 547 (D120): m68k dma.c, no x86 object changes
EXCEPTS[549] = dict(EXCEPTS[547])   # plan 549 (D121): m68k np.c, no x86 object changes
EXCEPTS[551] = dict(EXCEPTS[549])   # plan 551 (D122): m68k snd_rcv.c, no x86 object changes
EXCEPTS[554] = dict(EXCEPTS[551])   # plan 554 (D123): m68k snd_reply.c; x86 driverkit/snd_msgs.h prototypes (x86 rebuild s6lm)
EXCEPTS[556] = dict(EXCEPTS[554])   # plan 556 (D124): m68k snd_device.c and nextdev/snd_snd.h only; no x86 change
EXCEPTS[559] = dict(EXCEPTS[556])   # plan 559 (D125): m68k snd_dspcmd.c, generated dsp.h; x86 driverkit/snd_msgs.h snd_stream_msg_t (x86 rebuild s6ln)
EXCEPTS[563] = dict(EXCEPTS[559])   # plan 563 (D126): m68k snd_dspdev.c
EXCEPTS[566] = dict(EXCEPTS[563])   # plan 566 (D127): m68k snd_dspqueue.c
EXCEPTS[570] = dict(EXCEPTS[566])   # plan 570 (D128): m68k fd_subr.c, floppy/pmon headers, generated fd.h
EXCEPTS[573] = dict(EXCEPTS[570])   # plan 573 (D129): m68k fd_io.c, odreg.h, generated sc.h
EXCEPTS[576] = dict(EXCEPTS[573])   # plan 576 (D130): m68k fd_driver.c
EXCEPTS[579] = dict(EXCEPTS[576])   # plan 579 (D131): m68k fd_cmds.c
EXCEPTS[583] = dict(EXCEPTS[579])   # plan 583 (D132): full mon/global.h (07 nextmach) and closure; clock re-accepted
EXCEPTS[585] = dict(EXCEPTS[583])   # plan 585 (D133): mon/global.h without mon/tftp.h; clock re-accepted
EXCEPTS[600] = dict(EXCEPTS[585])   # plan 600 (D134): m68k machdep.c, next/scb.h
EXCEPTS[602] = dict(EXCEPTS[600])   # plan 602 (D135): m68k miniMonMachdep.c, next_exception.c
EXCEPTS[604] = dict(EXCEPTS[602])   # plan 604 (D136): m68k APM.c
EXCEPTS[609] = dict(EXCEPTS[604])   # plan 609 (D137): m68k m68k_init.c
EXCEPTS[612] = dict(EXCEPTS[609])   # plan 612 (D138): m68k swapgeneric.c, generated sd.h and rd.h
EXCEPTS[614] = dict(EXCEPTS[612])   # plan 614 (D139): m68k shutdown.c
EXCEPTS[618] = dict(EXCEPTS[614])   # plan 618 (D141): m68k vm_machdep.c (pagemove)
EXCEPTS[622] = dict(EXCEPTS[618])   # plan 622 (D142): 1997 struct pcb in the m68k overlay thread.h
EXCEPTS[627] = dict(EXCEPTS[622])   # plan 627 (D143): m68k pcb.c
EXCEPTS[636] = dict(EXCEPTS[627])   # plan 636 (D144): m68k trap.c
EXCEPTS[639] = dict(EXCEPTS[636])   # plan 639 (D145): m68k 64-bit helpers
EXCEPTS[642] = dict(EXCEPTS[639])   # plan 642 (D146): m68k kernel_pmon.c
EXCEPTS[644] = dict(EXCEPTS[642])   # plan 644 (D147): m68k snd_stream.c
EXCEPTS[646] = dict(EXCEPTS[644])   # plan 646 (D148): m68k snd_unix.c
EXCEPTS[649] = dict(EXCEPTS[646])   # plan 649 (D149): 1997 struct scsi_ctrl in the shared scsivar.h
EXCEPTS[652] = dict(EXCEPTS[649])   # plan 652 (D150): m68k st.c, NeXTMach st headers, generated st.h
EXCEPTS[655] = dict(EXCEPTS[652])   # plan 655 (D151): m68k sg.c, 07 sgvar.h, generated sg.h
EXCEPTS[657] = dict(EXCEPTS[655])   # plan 657 (D152): m68k sf_access.c
EXCEPTS[663] = dict(EXCEPTS[657])   # plan 663 (D153): m68k sd.c, 07 sdvar.h, 1997 inquiry_reply in the 07 scsireg.h
EXCEPTS[667] = dict(EXCEPTS[663])   # plan 667 (D154): m68k scsi.c
EXCEPTS[670] = dict(EXCEPTS[667])   # plan 670 (D155): m68k sc.c, scvar.h without s5c_dmastatus
EXCEPTS[674] = dict(EXCEPTS[670])   # plan 674 (D156): m68k zscom.c, zscom.h, zs85C30.h, generated zs.h
EXCEPTS[676] = dict(EXCEPTS[674])   # plan 676 (D157): m68k if_bus.c, nextif/if_bus.h
EXCEPTS[679] = dict(EXCEPTS[676])   # plan 679 (D158): m68k km.c, its headers, kmreg.h ioctl names
EXCEPTS[683] = dict(EXCEPTS[679])   # plan 683 (D159): m68k od.c, odvar.h, canon.h
EXCEPTS[687] = dict(EXCEPTS[683])   # plan 687 (D160): m68k pmap.c
EXCEPTS[689] = dict(EXCEPTS[687])   # plan 689 (D161): m68k ev.c
EXCEPTS[724] = dict(EXCEPTS[689])   # plan 724 (D162): m68k ev_ioctl.c
EXCEPTS[727] = dict(EXCEPTS[724])   # plan 727 (D163): m68k if_en.c, nextif/if_enreg.h
EXCEPTS[729] = dict(EXCEPTS[727])   # plan 729 (D164): m68k ev_kbd.c
EXCEPTS[736] = dict(EXCEPTS[729])   # plan 736 (D165): m68k ev_mouse.c
EXCEPTS[739] = dict(EXCEPTS[736])   # plan 739 (D166): m68k nextdbg.c
EXCEPTS[754] = dict(EXCEPTS[739])   # plan 754 (D167, D168): m68k locore.s
EXCEPTS[756] = dict(EXCEPTS[754])   # plan 756 (D169): m68k snd_link.c and nextdev/snd_audio.h only; no x86 change
EXCEPTS[758] = dict(EXCEPTS[756])   # plan 758 (D170): m68k snd_link.c with the corrected nextdev/snd_audio.h; no x86 change
EXCEPTS[759] = dict(EXCEPTS[758])   # plan 759 (D170): m68k snd_server.c; no x86 change
EXCEPTS[761] = dict(EXCEPTS[759])   # plan 761 (D171): m68k video.c; no x86 change
EXCEPTS[763] = dict(EXCEPTS[761])   # plan 763 (D172): m68k zs.c; no x86 change
EXCEPTS[764] = dict(EXCEPTS[763], **{'x86-tty_pty': 'm68k tail functions pts_process_putc and ptsputc added in the m68k overlay (plan 764)'})   # plan 764: m68k tty_pty.c overlay; no x86 change
EXCEPTS[766] = dict(EXCEPTS[764])   # plan 766 (D173): m68k adb.c and adb.h; no x86 change
EXCEPTS[770] = dict(EXCEPTS[766])   # plan 770 (D175): m68k fpsp.s and fpsp.h; no x86 change
EXCEPTS[774] = dict(EXCEPTS[770])   # plan 774: m68k fd_global.c, scsiconf.c and the init_sysent.c overlay (139, 151); no x86 change
EXCEPTS[777] = dict(EXCEPTS[774])   # plan 777: m68k conf.c, ioconf.c, vers.c and the count headers ldd.h km.h ev.h vol.h; no x86 change
EXCEPTS[779] = dict(EXCEPTS[777])   # plan 779 (D178): __common declarations (COMMON only, canon unchanged) and the fpsp counters; no x86 change
EXCEPTS[784] = dict(EXCEPTS[779], **{'x86-swapfs': EXCEPTS[779]['x86-swapfs'] + '; m68k overlay of plan 784 (D179): char sd_flags, char flags, second mask ~SD_WANTED'})   # plan 784; no x86 change
EXCEPTS[786] = dict(EXCEPTS[784], **{'x86-nfs_client': 'm68k overlay of plan 786 (D180): set_attrcache_time as static void (no d0 in the int-return call, so reload spills d0 in nfs_attrcache_va)'})   # plan 786; no x86 change
X86 = {433: 's6l4', 466: 's6l5', 467: 's6l6', 469: 's6l7', 471: 's6l8', 472: 's6l9', 473: 's6la', 474: 's6lb', 475: 's6lc', 476: 's6ld', 478: 's6le', 479: 's6lf', 480: 's6lg', 482: 's6lh', 483: 's6li', 485: 's6lj', 488: 's6lk', 494: 's6ll', 554: 's6lm', 559: 's6ln'}   # plans 466-494, 554: x86 rebuild prefix of the base and the x86 gate
GROUPS = ['g1a', 'g2aa', 'g2ba', 'g3a', 'g4a', 'g5a', 'g6a']


def x86_prefix():
    return X86[max(k for k in X86 if k <= PLAN)]


def base_stage():
    return '08_build/runs/tools/%s-g1a-stage' % x86_prefix()


def base_manifest():
    b = base_stage()
    m = json.load(open(b + '.manifest.json'))
    for e in m['files']:
        assert sha(os.path.join(b, e[0])) == e[2], e[0]
    return m


DERIVED = '#import <machine/spl.h>\t/* plan 435 (D070): m68k inline spl */\n'
TEST_STAGE = '08_build/runs/tools/m0p432-stage-int'
sha = C.sha


def overlay_files(root):
    if not os.path.isdir(root):
        return []
    out = []
    for r, ds, fs in os.walk(root):
        ds.sort()
        for f in sorted(fs):
            p = os.path.join(r, f)
            rel = os.path.relpath(p, root)
            if rel == 'README.md':
                continue
            assert not os.path.islink(p), p
            out.append((rel, p))
    return out


def check_derived(rel, src):
    """plans 435/437: overlay source = 07 main file + inserted lines, each carrying a registered
    marker (nothing deleted or changed); the D070 line at most once, right after
    '#import <sys/param.h>'.  Placement of other marked lines is evidenced by the diff files."""
    A = open(os.path.join('07_kernel', rel)).readlines()
    B = open(src).readlines()
    assert not any(m in l for l in A for m in MARKERS), 'marker text in the 07 main file: ' + rel
    owner = {}                                  # line -> marker (plan 441: '<marker> begin' .. '<marker> end' blocks)
    open_m = None
    for i, l in enumerate(B):
        hit = [m for m in MARKERS if m in l]
        assert len(hit) <= 1, 'several markers on one line: %s:%d' % (rel, i + 1)
        if open_m:
            assert not hit or hit == [open_m], 'marker inside another block: %s:%d' % (rel, i + 1)
            owner[i] = open_m
            if open_m + ' end' in l:
                open_m = None
            continue
        if hit:
            owner[i] = hit[0]
            if hit[0] + ' begin' in l:
                assert hit[0] + ' end' not in l, rel
                open_m = hit[0]
            else:
                assert hit[0] + ' end' not in l, 'block end without begin: %s:%d' % (rel, i + 1)
    assert open_m is None, 'unclosed marker block in ' + rel
    marked = sorted(owner)
    assert marked, 'overlay source without a registered marker: ' + rel
    for i in marked:
        assert rel in MARKERS[owner[i]], 'marker not registered for %s: line %d' % (rel, i + 1)
    for m, files in MARKERS.items():
        n = sum(1 for i in marked if owner[i] == m)
        assert n == files.get(rel, 0), 'marker %r: %d lines in %s, registered %d' % (m, n, rel, files.get(rel, 0))
    d070 = [i for i in marked if owner[i] == 'plan 435 (D070)']
    assert len(d070) <= 1, (rel, d070)
    for i in d070:
        assert B[i] == DERIVED and i > 0 and B[i - 1] == '#import <sys/param.h>\n', rel
    assert [l for i, l in enumerate(B) if i not in set(marked)] == A, 'overlay source differs from 07 main file: ' + rel


def cmd_stage(stage):
    m = base_manifest()
    assert not os.path.exists(stage), stage
    files = L.sdk_files()
    shutil.copytree(base_stage(), stage, symlinks=True)
    ent = collections.OrderedDict((e[0], list(e[:3])) for e in m['files'])
    for rel, h, dst in files:
        p = os.path.join(stage, dst)
        if os.path.exists(p):
            assert sha(p) == h, 'different file already at ' + dst
            continue
        os.makedirs(os.path.dirname(p), exist_ok=True)
        shutil.copyfile(os.path.join(L.SDK, rel), p)
        assert sha(p) == h
        ent[dst] = [dst, 'real machine ' + L.SDK_ROOT + rel, h]
    m4h = []
    if PLAN >= 506:                       # plan 506 (D104, D105)
        drop = OVLDROP[max(k for k in OVLDROP if k <= PLAN)]   # plan 583 (D132)
        ovl = {rel for root in OVL for rel, _ in overlay_files(root)} - set(drop)
        for ent_h in M4HEADERS[max(k for k in M4HEADERS if k <= PLAN)]:
            rel, dst = ent_h[0], ent_h[1]
            root = ent_h[2] if len(ent_h) == 3 else '07_kernel/nextmach'   # plan 535 (D116): or a 07_kernel/nextdev real-machine copy
            assert len(ent_h) in (2, 3) and root in ('07_kernel/nextmach', '07_kernel/nextdev', '07_kernel/src'), ent_h   # plan 554 (D123): or the 07 main tree
            src = os.path.join(root, rel)
            assert os.path.isfile(src) and not os.path.islink(src), src
            q = os.path.join(stage, dst)
            assert not os.path.exists(q) and dst not in ent and dst not in ovl, 'file already at ' + dst
            os.makedirs(os.path.dirname(q), exist_ok=True)
            shutil.copyfile(src, q)
            ent[dst] = [dst, src, sha(q)]
            m4h.append(dst)
    m4 = []
    if PLAN >= 497:                       # plan 497 (D103)
        on_dir = [rel for rel, _ in overlay_files(M4SRC)]
        hdrs = {h[0][len('machdep/m68k/'):] for t in M4HEADERS.values() for h in t   # plan 639 (D145): a header of this directory
                if len(h) == 3 and h[2] == '07_kernel/src' and h[0].startswith('machdep/m68k/') and h[0].endswith('.h')}   # registered in any plan's M4HEADERS
        known = set().union(*M4FILES.values()) | hdrs
        assert set(on_dir) <= known, ('unregistered', sorted(set(on_dir) - known))
        for rel in M4FILES[max(k for k in M4FILES if k <= PLAN)]:
            src = os.path.join(M4SRC, rel)
            assert rel.endswith(('.c', '.s')) and os.sep not in rel and os.path.isfile(src) and not os.path.islink(src), rel   # plan 512: .s
            dst = 'src/machdep/m68k/' + rel
            q = os.path.join(stage, dst)
            assert not os.path.exists(q), 'file already at ' + dst
            os.makedirs(os.path.dirname(q), exist_ok=True)
            shutil.copyfile(src, q)
            ent[dst] = [dst, src, sha(q)]
            m4.append(dst)
    replaced, added = [], []
    drop = OVLDROP[max(k for k in OVLDROP if k <= PLAN)]   # plan 583 (D132)
    for root in OVL:
        for rel, src in overlay_files(root):
            if rel in drop or PLAN < OVLFROM.get(rel, 0):   # plan 583 (D132); plan 764
                continue
            q = os.path.join(stage, rel)
            assert rel.startswith(('generated/', 'src/')), rel
            if rel.endswith('.c'):
                check_derived(rel, src)
            (replaced if os.path.exists(q) else added).append(rel)
            if os.path.exists(q):
                os.chmod(q, 0o644)
                os.remove(q)
            os.makedirs(os.path.dirname(q), exist_ok=True)
            shutil.copyfile(src, q)
            ent[rel] = [rel, src, sha(q)]
    on_disk = sorted(os.path.relpath(os.path.join(r, f), stage) for r, _, fs in os.walk(stage) for f in fs)
    assert on_disk == sorted(ent), 'stage content differs from manifest'
    for e in ent.values():
        assert sha(os.path.join(stage, e[0])) == e[2], e[0]
    man = dict(plan=PLAN, base=base_stage(), base_manifest_sha256=sha(base_stage() + '.manifest.json'),
               sdk_list=L.SDK_SHA, sdk_list_sha256=sha(L.SDK_SHA), overlays=OVL, replaced=replaced, added=added)
    if PLAN >= 497:
        man['m4_sources'] = m4
    if PLAN >= 506:
        man['m4_headers'] = m4h
    if drop:                              # plan 583 (D132)
        man['overlays_dropped'] = drop
    man['files'] = list(ent.values())
    json.dump(man, open(stage + '.manifest.json', 'w'), indent=1)
    print('stage', stage, 'files', len(ent), 'overlay replaced', len(replaced), 'added', len(added))


def ref_lines():
    out = []
    for rid, pfx in REFS:
        for l in open(os.path.join('08_build/runs', rid, 'run.cmd')):
            if l.startswith('RUN ') and ' -c ' in l:
                assert l.count('stage/' + pfx) == 1, l
                out.append((rid, pfx, l.rstrip('\n')))
    return out


def cmd_cmd(out):
    R = ref_lines()
    PFX = 'O%d__' % PLAN
    L_ = [l.replace('stage/' + pfx, 'stage/' + PFX) for _, pfx, l in R]
    E = ['EXPECT %s' % l.split()[-1][len('stage/'):] for l in L_]
    assert len(L_) == 205 and len(set(E)) == 205, (len(L_), len(set(E)))
    open(out, 'w').write('\n'.join(['# m3p%d: plan %d m68k compile from the 07 overlay stage (stage_m68k.py cmd)' % (PLAN, PLAN)] + L_ + E) + '\n')
    print('lines', len(L_))


def cmd_x86gate(workdir):
    os.makedirs(workdir, exist_ok=True)
    rows = []
    ps = sorted(glob.glob('08_build/runs/tools/%s-g*-stage.manifest.json' % x86_prefix()))
    assert [os.path.basename(p) for p in ps] == ['%s-%s-stage.manifest.json' % (x86_prefix(), g) for g in sorted(GROUPS)], ps
    for p in ps:
        m = json.load(open(p))
        name = os.path.basename(p)[:-len('.manifest.json')]
        out = os.path.join(workdir, name)
        assert not os.path.exists(out), out
        args = ['--prefer-07'] if m['prefer_07'] else []
        args += ['--nextdev'] if m['nextdev'] else []
        args += ['--bsd-set', m['bsd_set']] if m['bsd_set'] else []
        args += ['--mach-set', m['mach_set']] if m['mach_set'] else []
        for ps in m.get('public_sdk', []):   # plan 293 option of s6l4-g5a
            args += ['--public-sdk', ps]
        assert set(m) <= {'sources', 'files', 'unresolved', 'prefer_07', 'nextdev', 'bsd_set', 'bsd_not_adopted', 'mach_set',
                          'mach_replaced_07', 'mach_not_adopted', 'public_sdk'}, sorted(m)
        subprocess.run([sys.executable, '10_tools/reconstruction/stage_headers.py'] + args + [out] + m['sources'],
                       check=True, stdout=subprocess.DEVNULL)
        n = json.load(open(out + '.manifest.json'))
        rows.append(dict(stage=name, manifest_sha256=sha(p), files=len(m['files']), options=args,
                         same=(m == n), v183_paths=sum(1 for e in n['files'] if 'v183.34' in e[1])))
    print(json.dumps(rows, indent=1))
    assert all(r['same'] and not r['v183_paths'] for r in rows)
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/stage_m68k.py', tool_sha256=sha(os.path.abspath(__file__)),
                   stage_headers_sha256=sha('10_tools/reconstruction/stage_headers.py'), stages=rows),
              open(os.path.join(workdir, 'x86gate.json'), 'w'), indent=1)


def cmd_compare(rid, stage, workdir, gate, outj):
    PFX, EXCEPT = 'O%d__' % PLAN, EXCEPTS[PLAN]
    T = {t['base']: t for t in W.targets()}
    by_obj = {}
    for r in json.load(open('09_validation/reconstruction/m3-m68k-wide-20261009.json'))['objects']:
        by_obj[r['object']] = r['verdict']
    for o, r in json.load(open('09_validation/reconstruction/m3-m68k-ast-20261009.json'))['objects_int'].items():
        assert o not in by_obj
        by_obj[o] = r['verdict']
    assert len(by_obj) == 205
    img = C.Img()
    img_names = {y['name'] for y in img.img.o['symbols']}   # plan 437: original symbol names
    os.makedirs(workdir, exist_ok=True)
    rows = []
    for rrid, pfx, l in ref_lines():
        f = os.path.basename(l.split()[-1])
        base = f[len(pfx):-2]
        t = T[base]
        ref = os.path.join('08_build/runs', rrid, 'out', f)
        new = os.path.join('08_build/runs', rid, 'out', PFX + base + '.o')
        cr, cn = D.canon(ref), D.canon(new)
        diff = sorted(k for k in set(cr) | set(cn) if cr.get(k) != cn.get(k))
        d = C.run_l1(new, os.path.join(workdir, 'l1-%s.json' % t['object']))
        no = macho_obj.parse(open(new, 'rb').read())
        undef_spl = sorted(y['name'] for y in no['symbols'] if y['kind'] == 'UNDF' and y['name'].startswith('_spl'))
        undef_new = sorted({y['name'] for y in no['symbols'] if y['kind'] == 'UNDF' and not y['stab']} - img_names
                           - {y['name'] for y in macho_obj.parse(open(ref, 'rb').read())['symbols']
                              if y['kind'] == 'UNDF' and not y['stab']})
        rows.append(dict(object=t['object'], ref_run=rrid, ref_sha256=sha(ref), sha256=sha(new),
                         byte_identical=sha(ref) == sha(new), sections_differ=diff,
                         verdict=d['object_verdict'], ref_verdict=by_obj[t['object']], exception=EXCEPT.get(t['object'], ''), undefined_spl=undef_spl, undefined_new_not_in_original=undef_new))
    S = collections.OrderedDict()
    S['objects'] = len(rows)
    S['same_non_stabs'] = sum(1 for r in rows if not r['sections_differ'])
    S['byte_identical'] = sum(1 for r in rows if r['byte_identical'])
    S['differ'] = sorted(r['object'] for r in rows if r['sections_differ'])
    S['differ_unexpected'] = sorted(r['object'] for r in rows if r['sections_differ'] and not r['exception'])
    S['object_match'] = [sum(r['ref_verdict'] == 'OBJECT_MATCH' for r in rows), sum(r['verdict'] == 'OBJECT_MATCH' for r in rows)]
    S['undefined_spl'] = {r['object']: r['undefined_spl'] for r in rows if r['undefined_spl']}   # plan 435
    S['undefined_new_not_in_original'] = {r['object']: r['undefined_new_not_in_original'] for r in rows
                                          if r['undefined_new_not_in_original']}   # plan 437
    S['lost'] = sorted(r['object'] for r in rows if r['ref_verdict'] == 'OBJECT_MATCH' and r['verdict'] != 'OBJECT_MATCH')
    S['gained'] = sorted(r['object'] for r in rows if r['ref_verdict'] != 'OBJECT_MATCH' and r['verdict'] == 'OBJECT_MATCH')
    sm = json.load(open(stage + '.manifest.json'))
    tm = {e[0]: e[2] for e in json.load(open(TEST_STAGE + '.manifest.json'))['files']}
    nm = {e[0]: e[2] for e in sm['files']}
    S['stage_vs_test_stage'] = sorted(p for p in set(tm) | set(nm) if tm.get(p) != nm.get(p))
    G = json.load(open(gate))
    S['x86gate'] = [[g['stage'], g['same']] for g in G['stages']]
    json.dump(dict(plan=PLAN, tool='10_tools/reconstruction/stage_m68k.py', tool_sha256=sha(os.path.abspath(__file__)),
                   run=rid, stage=stage, stage_manifest_sha256=sha(stage + '.manifest.json'),
                   sdk_input=dict(dir=L.SDK, list=sm['sdk_list'], list_sha256=sm['sdk_list_sha256']),
                   base=sm['base'], base_manifest_sha256=sm['base_manifest_sha256'],
                   overlay=[[e[0], e[1], e[2]] for e in sm['files'] if e[1].startswith('07_kernel/v183.34/')],
                   overlay_replaced=sm['replaced'], overlay_added=sm['added'],
                   refs=REFS, exceptions=EXCEPT, x86gate=G, summary=S, objects=rows), open(outj, 'w'), indent=1)
    print(json.dumps(S, indent=1))


def main():
    global PLAN
    a = sys.argv[1:]
    if a[:1] == ['--plan'] and len(a) >= 2 and a[1].isdigit() and int(a[1]) in EXCEPTS:   # plan 435
        PLAN = int(a[1])
        a = a[2:]
    if a[:1] == ['stage'] and len(a) == 2:
        cmd_stage(a[1])
    elif a[:1] == ['cmd'] and len(a) == 2:
        cmd_cmd(a[1])
    elif a[:1] == ['x86gate'] and len(a) == 2:
        cmd_x86gate(a[1])
    elif a[:1] == ['compare'] and len(a) == 6:
        cmd_compare(*a[1:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main()
