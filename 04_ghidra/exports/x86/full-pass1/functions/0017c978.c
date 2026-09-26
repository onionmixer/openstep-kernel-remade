/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c978 */

undefined4 _vnode_pager_vget(int param_1)

{
  do {
  } while (_vstruct_lock != 0);
  LOCK();
  UNLOCK();
  *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
  LOCK();
  _vstruct_lock = 0;
  UNLOCK();
  return *(undefined4 *)(param_1 + 0x14);
}

