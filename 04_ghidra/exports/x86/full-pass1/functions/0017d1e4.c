/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d1e4 */

undefined4 _vnode_pager_setup(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 2;
  }
  puVar1 = DAT_001e7288;
  if (*(int *)*param_1 == 0) {
    for (; (undefined4 **)puVar1 != &DAT_001e7288; puVar1 = (undefined4 *)*puVar1) {
      if ((undefined4 *)puVar1[2] == param_1) {
        return 0;
      }
    }
    puVar1 = (undefined4 *)_zalloc(_vstruct_zone);
    if (puVar1 != (undefined4 *)0x0) {
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
    if (param_3 != 0) {
      uVar2 = _vm_object_lookup(*(undefined4 *)*param_1,1);
      _vm_object_cache_object(uVar2);
    }
  }
  uVar2 = _zalloc(_vstruct_zone);
  _zfree(_vstruct_zone,uVar2);
  return *(undefined4 *)*param_1;
}

