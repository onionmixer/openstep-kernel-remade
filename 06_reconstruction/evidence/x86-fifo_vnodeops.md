# x86 `src/bsd/specfs/fifo_vnodeops.c` (plan 188 (S5-P161), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 188 (S5-P161). Final run `s5p161-it4`; 07 file SHA-256 `5f313afe4b4663f52184b0e4f4360a30ca8cf0088f13a4c09369e08906a54631`; diff `x86-fifo_vnodeops.diff`.

- Object [0x138ad0, 0x1395d8) 2824 B, 13 functions ((static fifo_open), (static fifo_close), (static fifo_rdwr), (static fifo_getattr), (static fifo_select), (static fifo_inactive), (static fifo_cmp), (static fifo_invalop), (static fifo_badop), (static fifo_bufalloc), _fifosp, (static fifo_buffree), (static fifo_devblocksize)). Front `5d c3 00 00`, back `55 89 e5 6a`, next symbol 0x1395d8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p161-it4-l1-fifo_vnodeops-F-20261002.json`). Grade **A**.

Object extent [0x138ad0, 0x1395d8): the static fifo functions precede _fifosp (objects.tsv seq 122 shows only fifosp); 0x138a90 _xdr_fhstatus belongs to mountxdr. Several differences (close/rdwr thread release, read wakeup, POSIX EAGAIN, kmem_alloc_wired, fifosp bzero) were found by the codex review of plan 188 and each verified in the disassembly. Iterations: it1 rdwr +68 and bufalloc -12; it2 write path to a shared EWOULDBLOCK/EAGAIN block, kmem_alloc_wired(&addr); variants s5p161-v1 (w1: count read before the loop, re-read only at wrloop) and s5p161-v2 (t1 ternary / t2 if-else EAGAIN, both 0) -> t2; it4 return addr after fn_nbuf++ -> OBJECT_MATCH 13/13 including __data (fifo_vnodeops with the 33rd slot). Diagnostic compile without POSIX_KERN exit 0.
