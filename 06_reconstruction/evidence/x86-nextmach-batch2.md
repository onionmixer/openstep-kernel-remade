# x86 NeXTMach batch 2 (S5-P115, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 141-141.2. Runs `s5p114-diag-8` (diagnosis), `s5p115-build-1` (07, final flags with `-DINET`), `s5p115-build-2` (after the authored `kernserv/queue.h`; 100/100 objects identical to build-1).

- `-DINET`: the original `afswitch` (0x1db790) has `inet_hash/inet_netmatch` in slots 2 and 3 and `null_*` in slot 6 (no NS); NeXTMach/Darwin `conf/MASTER` `options INET` has no header and is passed as `-DINET`. Adding it to every compile left the 96 confirmed objects identical (`09_validation/reconstruction/s5p115-regress-compare-20261002.json`).
- `rpc/types.h`: the SDK copy is the public form (`mem_alloc` = `malloc`); the authored `07_kernel/nextdev_private/bsd/rpc/types.h` puts the SDK block under `#ifndef KERNEL` and adds the NeXTMach kernel branch (`kalloc`/`kfree`).

- `af` (`mk-108.1/net/af.c`): object [0x11ed58, 0x11eda9) 81 B, 3 functions (_null_init, _null_hash, _null_netmatch); front `ec 5d c3 00`, back `00 00 00 55`, next symbol 0x11edac. Final OBJECT_MATCH. Grade **A**.
- `netbuf` (`mk-108.1/net/netbuf.c`): object [0x1209ec, 0x120b97) 427 B, 13 functions (_nb_alloc, _nb_alloc_wrapper, _nb_map, _nb_free, _nb_free_wrapper, _nb_size, _nb_read, _nb_write, _nb_shrink_top, _nb_grow_top, _nb_shrink_bot, _nb_grow_bot, (static nb_alloc_free)); front `5d c3 00 00`, back `00 55 89 e5`, next symbol 0x120b98. Final OBJECT_MATCH. Grade **A**.
- `rpc_prot` (`mk-108.1/rpc/rpc_prot.c`): object [0x1365cc, 0x136bff) 1587 B, 7 functions (_xdr_opaque_auth, _xdr_des_block, _xdr_accepted_reply, _xdr_rejected_reply, _xdr_replymsg, _xdr_callhdr, __seterr_reply); front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x136c00. Final OBJECT_MATCH. Grade **A**.
- `rpc_callmsg` (`mk-108.1/rpc/rpc_callmsg.c`): object [0x136250, 0x1365cc) 892 B, 1 functions (_xdr_callmsg); front `ec 5d c3 00`, back `55 89 e5 56`, next symbol 0x1365cc. Final OBJECT_MATCH. Grade **A**.
