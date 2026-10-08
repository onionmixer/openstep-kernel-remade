# x86 `src/bsd/netinet/ip_icmp.c` (plan 170 (S5-P143), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 170 (S5-P143). Final run `s5p143-it3`; 07 file SHA-256 `2ee8c357e899a935fff654b64916d5e2ef3c420158fab7abbc1e6ecdcb4d5c9e`; diff `x86-ip_icmp.diff`.

- Object [0x125554, 0x125f54) 2560 B, 7 functions (_icmp_error, _icmp_input, _icmp_reflect, _ifptoia, _icmp_send, _iptime, _icmp_sendMaskPacket). Front `ec 5d c3 00`, back `55 89 e5 83`, next symbol 0x125f54.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p143-it3-l1-ip_icmp-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE (and -DMULTICAST). it1 icmp_input 1204/1188 (other 6 functions size-equal); it2 printf argument ia_subnetmask, still 1204; staged variant v1 (`mask` temporary for the first MASKREPLY test) -> icmp_input MATCH, icmp_send 5-argument ip_output remaining; it3 OBJECT_MATCH 7/7, 2560 B. Diagnostic compile without -DMULTICAST (s5p143-nomc) exits 0 with no diagnostics. The codex review added the MASKREQ/MASKREPLY flag tests (verified in the bytes) and corrected two plan citations.
