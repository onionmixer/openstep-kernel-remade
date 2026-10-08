# x86 `src/bsd/netinet/tcp_output.c` (plan 174 (S5-P147), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 174 (S5-P147). Final run `s5p147-it3`; 07 file SHA-256 `2df60edba5bf6c6ef1f24ffd389baac5deeb5498d1c06030868fe3200425a516`; diff `x86-tcp_output.diff`.

- Object [0x129d8c, 0x12a431) 1701 B, 2 functions (_tcp_output, _tcp_setpersist). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x12a434.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p147-it3-l1-tcp_output-F-20261002.json`). Grade **A**.

Built with -DMULTICAST -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 1576/1584 (missing outer `flags & (TH_SYN|TH_FIN)` test, ip_len from hdrlen); it2 2 bytes (m_off as MMAXOFF - hdrlen); it3 OBJECT_MATCH 2/2. TCP_TTL is 60 from the SDK tcp_timer.h (NeXT branch; NeXTMach has 30). nomc diagnostic compile exit 0.
