# x86 `src/driverkit/disk_label.c` (plan 286 (S5-P276), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 286 (S5-P276). Final run `s5p276-it1`; 07 file SHA-256 `09ec0f0e9a1dd64fb08f741aedf67aebc86535de5439ce0559c5aac4d15de42b`; diff `x86-disk_label.diff`.

- Object [0x1bd3e8, 0x1bda47) 1631 B, 8 functions (_get_partition, _get_disktab, _get_dl_un, _get_disk_label, _put_partition, _put_disktab, _put_dl_un, _put_disk_label). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x1bda48.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p276-it1-l1-disk_label-F-20261002.json`). Grade **A**.

Object extent [0x1bd3e8, 0x1bda47) 1631 B + 00; front snd_server area (00 at 0x1bd3e7), next label_subr 0x1bda48. Eight global functions; loops NBOOTS 1, NPART 7 (stride 46), NBAD 1670; checksum fields +0x1c46 and +0x22e. References by file name: Darwin 0.1 driverkit-1/libDriver/i386/disk_label.c (text nearly the same), ppc/disk_label.c, driverkit/diskstruct.h; Mach4 kernel/scsi/disk_label.c (different code, unused); no NeXTMach file. The codex review of plan 286 confirmed the bytes, qualified the header-value claim (effective values only) and raised the Darwin-text question, which the user decided as D030 (project-authored, stated as nearly Darwin's). it1 (s5p276-it1) from 07 OBJECT_MATCH, relcheck 0.
