/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d168 */

undefined4 * _vnode_pager_create(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_zalloc(_vstruct_zone);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    _bzero(puVar1,0x18);
    *puVar1 = 0;
    *(undefined2 *)((int)puVar1 + 0xe) = 1;
    *(undefined4 **)*param_1 = puVar1;
    puVar1[5] = param_1;
    *(byte *)(puVar1 + 3) = *(byte *)(puVar1 + 3) & 0xfe;
    *(short *)((int)param_1 + 6) = *(short *)((int)param_1 + 6) + 1;
    do {
    } while (_vstruct_lock != 0);
    LOCK();
    UNLOCK();
    *(short *)((int)puVar1 + 0xe) = *(short *)((int)puVar1 + 0xe) + -1;
    LOCK();
    _vstruct_lock = 0;
    UNLOCK();
  }
  return puVar1;
}

