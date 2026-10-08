# x86 `src/bsd/net/if_venip.c` (plan 176 (S5-P149), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 176 (S5-P149). Final run `s5p149-it5`; 07 file SHA-256 `5a54f67fe6f6be87d7fffc4cb89b4c2b8c30df47db463698978e0967c517d161`; diff `x86-if_venip.diff`.

- Object [0x11f560, 0x11fb81) 1569 B, 10 functions (_VENIP_PRIVATE, _VENIP_ENADDRP, _VENIP_IPADDR, _VENIP_RIF, (static venip_control), (static venip_input), _venip_config, (static venip_attach), (static venip_output), (static venip_getbuf)). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x11fb84.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p149-it5-l1-if_venip-F-20261002.json`). Grade **A**.

Object extent: the static functions venip_attach, venip_output and venip_getbuf follow venip_config without symbols, so the compilation unit is [0x11f560, 0x11fb81) with the next symbol _SRHash at 0x11fb84 (objects.tsv seq 67 text_end 0x11f97b stops at the last named function). Built with -DMULTICAST -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 struct ifreq undeclared (import net/if.h); it2 control 352/348 (multicast EAFNOSUPPORT return placed after the mapping, as at 0x11f6e0); it3 output 252/256; it4 a separate type temporary (no); it5 AF_UNSPEC `eh.ether_type = htons(eh.ether_type)` -> OBJECT_MATCH 12/12 (function order now as in the original: control is no longer an inline candidate). nomc diagnostic compile exit 0.
