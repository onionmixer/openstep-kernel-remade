/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e104 */

void _vnode_uncache(int *param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  
  if (((int *)*param_1 != (int *)0x0) && (*(int *)*param_1 != 0)) {
    bVar2 = false;
    if ((undefined **)param_1[7] == &_ufs_vnodeops) {
      uVar1 = *(ushort *)(param_1[0xc] + 0x44);
      if ((uVar1 & 1) != 0) {
        bVar2 = true;
        *(ushort *)(param_1[0xc] + 0x44) = uVar1 & 0xfffe;
      }
    }
    else if ((undefined **)param_1[7] == &_nfs_vnodeops) {
      uVar1 = *(ushort *)(param_1[0xc] + 0x60);
      if ((uVar1 & 1) != 0) {
        bVar2 = true;
        *(ushort *)(param_1[0xc] + 0x60) = uVar1 & 0xfffe;
      }
    }
    _mfs_uncache(param_1);
    uVar3 = _vm_object_lookup(*(undefined4 *)*param_1,0);
    _vm_object_cache_object(uVar3);
    if (bVar2) {
      if ((undefined **)param_1[7] == &_ufs_vnodeops) {
        *(byte *)(param_1[0xc] + 0x44) = *(byte *)(param_1[0xc] + 0x44) | 1;
      }
      else if ((undefined **)param_1[7] == &_nfs_vnodeops) {
        *(byte *)(param_1[0xc] + 0x60) = *(byte *)(param_1[0xc] + 0x60) | 1;
      }
    }
  }
  return;
}

