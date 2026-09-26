/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139648 */

int _specvp(int param_1,ushort param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined1 local_44 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  pvVar2 = (void *)FUN_00139a30((int)(short)param_2,param_1,param_3);
  if (pvVar2 == (void *)0x0) {
    if ((param_1 == 0) || (*(int *)(param_1 + 0x28) != 8)) {
      pvVar2 = (void *)_kalloc(0x68);
      _bzero(pvVar2,0x68);
      *(undefined ***)((int)pvVar2 + 0x20) = &_spec_vnodeops;
      if (param_1 != 0) {
        iVar3 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
                          (param_1,local_44,*(undefined4 *)(_active_u + 0x1c));
        if (iVar3 == 0) {
          *(undefined4 *)((int)pvVar2 + 0x4c) = local_24;
          *(undefined4 *)((int)pvVar2 + 0x50) = local_20;
          *(undefined4 *)((int)pvVar2 + 0x54) = local_1c;
          *(undefined4 *)((int)pvVar2 + 0x58) = local_18;
          *(undefined4 *)((int)pvVar2 + 0x5c) = local_14;
          *(undefined4 *)((int)pvVar2 + 0x60) = local_10;
        }
      }
    }
    else {
      pvVar2 = (void *)_fifosp(param_1);
    }
    *(int *)((int)pvVar2 + 0x38) = param_1;
    *(ushort *)((int)pvVar2 + 0x42) = param_2;
    *(ushort *)((int)pvVar2 + 0x30) = param_2;
    *(undefined2 *)((int)pvVar2 + 10) = 1;
    *(void **)((int)pvVar2 + 0x34) = pvVar2;
    if (param_1 == 0) {
      *(undefined4 *)((int)pvVar2 + 0x2c) = 3;
      *(undefined4 *)((int)pvVar2 + 0x28) = 0;
      *(int *)((int)pvVar2 + 0x3c) = (int)pvVar2 + 4;
    }
    else {
      *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + 1;
      *(undefined4 *)((int)pvVar2 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)((int)pvVar2 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      if (*(int *)(param_1 + 0x28) == 3) {
        iVar3 = _specvp(0,(int)(short)param_2,3);
        *(int *)((int)pvVar2 + 0x3c) = iVar3;
        *(undefined4 *)((int)pvVar2 + 0x48) = *(undefined4 *)(*(int *)(iVar3 + 0x30) + 0x48);
      }
    }
    FUN_00139860(pvVar2);
  }
  if (((short)(param_2 >> 8) < _nblkdev) &&
     ((code *)(&PTR__nodev_001e2d04)[(short)(param_2 >> 8) * 6] != (code *)0x0)) {
    iVar3 = (*(code *)(&PTR__nodev_001e2d04)[(short)(param_2 >> 8) * 6])((int)(short)param_2);
    if (iVar3 != -1) {
      *(int *)((int)pvVar2 + 0x48) = iVar3;
      if ((*(int *)((int)pvVar2 + 0x3c) != 0) &&
         (iVar1 = *(int *)(*(int *)((int)pvVar2 + 0x3c) + 0x30), *(int *)(iVar1 + 0x48) == 0)) {
        *(int *)(iVar1 + 0x48) = iVar3;
      }
      goto LAB_001397a3;
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x48) = 0;
LAB_001397a3:
  return (int)pvVar2 + 4;
}

