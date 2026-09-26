/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001439f8 */

void _sbupdate(int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_10;
  
  pvVar1 = *(void **)(*(int *)(param_1 + 0xc) + 0x20);
  iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 0x1c) + 0x80))(*(int *)(param_1 + 8));
  if (-1 < iVar2) {
    iVar2 = _getblk(*(undefined4 *)(param_1 + 8),(int)(0x2000 / (longlong)iVar2),
                    *(undefined4 *)((int)pvVar1 + 0x68));
    _bcopy(pvVar1,*(void **)(iVar2 + 0x20),*(size_t *)((int)pvVar1 + 0x68));
    _byte_swap_superblock(*(undefined4 *)(iVar2 + 0x20));
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x8c) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x88) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x94) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x90) = 0;
    *(undefined1 *)(*(int *)(iVar2 + 0x20) + 0xd3) = 0;
    _bwrite(iVar2);
    iVar2 = (*(int *)((int)pvVar1 + 0x9c) + -1 + *(int *)((int)pvVar1 + 0x34)) /
            *(int *)((int)pvVar1 + 0x34);
    local_10 = *(void **)((int)pvVar1 + 0x2d8);
    iVar5 = 0;
    if (0 < iVar2) {
      do {
        uVar4 = *(uint *)((int)pvVar1 + 0x30);
        if (iVar2 < iVar5 + *(int *)((int)pvVar1 + 0x38)) {
          uVar4 = (iVar2 - iVar5) * *(int *)((int)pvVar1 + 0x34);
        }
        iVar3 = _getblk(*(undefined4 *)(param_1 + 8),
                        *(int *)((int)pvVar1 + 0x98) + iVar5 <<
                        ((byte)*(undefined4 *)((int)pvVar1 + 100) & 0x1f),uVar4);
        _bcopy(local_10,*(void **)(iVar3 + 0x20),uVar4);
        _byte_swap_ints(*(undefined4 *)(iVar3 + 0x20),uVar4 >> 2);
        local_10 = (void *)((int)local_10 + uVar4);
        _bwrite(iVar3);
        iVar5 = iVar5 + *(int *)((int)pvVar1 + 0x38);
      } while (iVar5 < iVar2);
    }
  }
  return;
}

