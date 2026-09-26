/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d7d4 */

undefined4 _task_map_io_ports(int param_1,uint param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  uint uVar8;
  
  iVar2 = *(int *)(param_1 + 0x40);
  uVar8 = param_2 + param_3;
  if (uVar8 < 0x10001) {
    if (*(int *)(param_1 + 0x50) == 0) {
      iVar5 = _task_hold(param_1);
      if (iVar5 == 0) {
        uVar6 = uVar8 + 7 >> 3;
        _lock_write(iVar2 + 0x10);
        if (*(uint *)(iVar2 + 0xc) < uVar6) {
          pvVar7 = (void *)_kalloc(uVar6);
          _memset(pvVar7,0xff,uVar6);
          _memcpy(pvVar7,*(void **)(iVar2 + 8),*(size_t *)(iVar2 + 0xc));
          _kfree(*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc));
          *(void **)(iVar2 + 8) = pvVar7;
          *(uint *)(iVar2 + 0xc) = uVar6;
        }
        for (; param_2 < uVar8; param_2 = param_2 + 1) {
          if (param_4 == 0) {
            uVar6 = param_2;
            if ((int)param_2 < 0) {
              uVar6 = param_2 + 7;
            }
            bVar3 = (char)param_2 + (char)((int)uVar6 >> 3) * -8 & 0x1f;
            pbVar1 = (byte *)(((int)uVar6 >> 3) + *(int *)(iVar2 + 8));
            *pbVar1 = *pbVar1 & ((byte)(-2 << bVar3) | (byte)(0xfffffffe >> 0x20 - bVar3));
          }
          else {
            uVar6 = param_2;
            if ((int)param_2 < 0) {
              uVar6 = param_2 + 7;
            }
            pbVar1 = (byte *)(((int)uVar6 >> 3) + *(int *)(iVar2 + 8));
            *pbVar1 = *pbVar1 | (byte)(1 << ((char)param_2 + (char)((int)uVar6 >> 3) * -8 & 0x1fU));
          }
        }
        _task_dowait(param_1,1);
        FUN_0018d610(param_1);
        _task_release(param_1);
        _lock_done(iVar2 + 0x10);
        uVar4 = 0;
      }
      else {
        uVar4 = 4;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}

