# x86 `src/bsd/netinet/ip_input.c` (plan 225 (S5-P204), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 225 (S5-P204). Final run `s5p204-it3`; 07 file SHA-256 `1fb0c81fbc8fb079610ba0462aa2bed59f3ef4cd6aa998b671a97d1da9dec6d4`; diff `x86-ip_input.diff`.

- Object [0x125f54, 0x12727e) 4906 B, 14 functions (_ip_init, _ipintr, _ip_reass, _ip_freef, _ip_enq, _ip_deq, _ip_slowtimo, _ip_drain, _ip_dooptions, _ip_rtaddr, _save_rte, _ip_srcroute, _ip_stripoptions, _ip_forward). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x127280.
- Final L1 `09_validation/reconstruction/s5p204-it3-l1-ip_input-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x125f54, 0x127280): after the confirmed ip_icmp, linker 0x00 fill before ip_output. Diagnosis 13 failed on mon/bootp.h (the SDK has netinet/bootp.h); diagnosis build s5p204-d2 (NeXTMach text, temporary IPPORT_BOOTPC, not 07) matched 10 functions. The codex review of plan 225 was checked; its claim that icmp_error takes a struct in_addr by value was rejected (the confirmed ip_icmp takes a pointer, plan 170). Iterations: it1 ip_forward passes &dest (original 0x127261); it2/it3 all 14 functions match, extern relocation names match (relcheck 0). The static ip_srcrt in __DATA,__bss is reference-inferred after decision D025 (a scattered reference with an addend of -4 from array index arithmetic is range-checked by its r_value); before D025 the tool concluded fail on that field.

Common symbols: the object's common `_etherbroadcastaddr` has size 8 for the `u_char etherbroadcastaddr[6]` declaration in netinet/if_ether.h; in the original it, like `_nmbclusters` and the other listed commons, is an initialized __DATA,__data definition (section 4) from another object, so the common allocates nothing. The recording tool's size check applies only to symbols the original places in __DATA,__common.
