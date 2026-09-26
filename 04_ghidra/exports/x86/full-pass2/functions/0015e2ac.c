/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e2ac */

uint __regparm1 _unmap_vnode(uint param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  iVar4 = *param_2;
  if ((*(byte *)(iVar4 + 0x38) & 0x10) != 0) {
    sVar3 = *(short *)(iVar4 + 4);
    *(short *)(iVar4 + 4) = sVar3 + -1;
    param_1 = (uint)(ushort)(sVar3 - 1U);
    if ((short)(sVar3 - 1U) < 1) {
      *(short *)(iVar4 + 4) = sVar3;
      (**(code **)(param_2[7] + 0x7c))(param_2,&local_8);
      sVar3 = *(short *)(iVar4 + 4);
      *(short *)(iVar4 + 4) = sVar3 + -1;
      if (local_8 == 0) {
        param_1 = _mfs_memfree(iVar4,0);
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x24);
        if ((_close_flush != 0) || ((*(byte *)(iVar4 + 0x38) & 4) != 0)) {
          *(short *)(iVar4 + 4) = sVar3;
          _vmp_get(iVar4);
          _vmp_push(iVar4);
        }
        piVar1 = (int *)(iVar5 + 0x10);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        _vm_object_deactivate_pages(iVar5);
        LOCK();
        param_1 = *(uint *)(iVar5 + 0x10);
        *(uint *)(iVar5 + 0x10) = 0;
        UNLOCK();
        if ((_close_flush != 0) || ((*(byte *)(iVar4 + 0x38) & 4) != 0)) {
          param_1 = _vmp_put(iVar4);
          *(short *)(iVar4 + 4) = *(short *)(iVar4 + 4) + -1;
        }
      }
    }
  }
  return param_1;
}

