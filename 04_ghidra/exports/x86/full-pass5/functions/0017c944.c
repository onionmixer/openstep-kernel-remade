/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c944 */

undefined4 _vnode_pager_vput(int param_1)

{
  undefined4 uVar1;
  
  do {
  } while (_vstruct_lock != 0);
  LOCK();
  _vstruct_lock = 1;
  UNLOCK();
  *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -1;
  uVar1 = _vstruct_lock;
  LOCK();
  _vstruct_lock = 0;
  UNLOCK();
  return uVar1;
}

