/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ed2c */

int FUN_0013ed2c(int param_1,uint *param_2)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint local_14;
  int local_8;
  
  uVar4 = param_2[1] + param_2[2];
  if (*param_2 == 0) {
    if ((param_2[1] & 0x3ff) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_dirprepareentry__new_block_001dde5a);
    }
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x34) < 0x400) {
                    /* WARNING: Subroutine does not return */
      _panic(s_DIRBLKSIZ_>_fsize_001dde75);
    }
    iVar1 = _bmap(param_1,param_2[1] >>
                          ((byte)*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x50) & 0x1f),0,
                  (~*(uint *)(*(int *)(param_1 + 0x50) + 0x48) & param_2[1]) + 0x400,0);
    if ((iVar1 < 1) || (*(char *)(DAT_001e875c + 0x68) != '\0')) {
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        return 0x1c;
      }
      return (int)*(char *)(DAT_001e875c + 0x68);
    }
    *(uint *)(param_1 + 0x6c) = uVar4;
  }
  else {
    if (uVar4 <= *(uint *)(param_1 + 0x6c)) goto LAB_0013edf3;
    *(uint *)(param_1 + 0x6c) = uVar4 + 0x3ff & 0xfffffc00;
  }
  *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
LAB_0013edf3:
  uVar4 = _blkatoff(param_1,param_2[1],param_2 + 4);
  param_2[3] = uVar4;
  if (uVar4 == 0) {
    iVar1 = (int)*(char *)(DAT_001e875c + 0x68);
  }
  else {
    piVar6 = (int *)param_2[4];
    if (*param_2 == 0) {
      _bzero(piVar6,0x400);
      *(undefined2 *)(piVar6 + 1) = 0x400;
    }
    else {
      if (2 < *param_2) {
                    /* WARNING: Subroutine does not return */
        _panic(s_dirprepareentry__invalid_slot_st_001dde87);
      }
      sVar3 = (*(ushort *)((int)piVar6 + 6) + 4 & 0xfffffffc) + 8;
      local_14 = (uint)*(ushort *)(piVar6 + 1);
      local_8 = local_14 - sVar3;
      piVar5 = piVar6;
      if ((int)local_14 < (int)param_2[2]) {
        do {
          pvVar2 = (void *)((int)piVar6 + local_14);
          if (*piVar5 == 0) {
            local_8 = local_8 + sVar3;
          }
          else {
            *(short *)(piVar5 + 1) = (short)sVar3;
            piVar5 = (int *)((int)piVar5 + sVar3);
          }
          sVar3 = (*(ushort *)((int)pvVar2 + 6) + 4 & 0xfffffffc) + 8;
          local_8 = local_8 + (*(ushort *)((int)pvVar2 + 4) - sVar3);
          local_14 = local_14 + *(ushort *)((int)pvVar2 + 4);
          _bcopy(pvVar2,piVar5,sVar3);
        } while ((int)local_14 < (int)param_2[2]);
      }
      piVar6 = piVar5;
      if (*piVar6 == 0) {
        *(short *)(piVar6 + 1) = (short)local_8 + (short)sVar3;
      }
      else {
        *(short *)(piVar6 + 1) = (short)sVar3;
        piVar6 = (int *)((int)piVar6 + sVar3);
        *(short *)(piVar6 + 1) = (short)local_8;
      }
    }
    param_2[4] = (uint)piVar6;
    iVar1 = 0;
  }
  return iVar1;
}

