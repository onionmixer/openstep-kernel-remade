/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001178dc */

void _recvit(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  iVar2 = _getsock(param_1);
  if (iVar2 != 0) {
    local_1c = param_2[2];
    local_18 = param_2[3];
    local_10 = 0;
    local_14 = 0;
    local_8 = 0;
    puVar6 = (undefined4 *)param_2[2];
    iVar4 = 0;
    if (0 < param_2[3]) {
      piVar5 = puVar6 + 1;
      do {
        iVar3 = *piVar5;
        if (iVar3 < 0) {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
          return;
        }
        if (iVar3 != 0) {
          iVar3 = _useracc(*puVar6,iVar3,0);
          if (iVar3 == 0) {
            *(undefined1 *)(DAT_001e875c + 0x68) = 0xe;
            return;
          }
          local_8 = local_8 + *piVar5;
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 2;
        puVar6 = puVar6 + 2;
      } while (iVar4 < param_2[3]);
    }
    local_28 = local_8;
    uVar1 = _soreceive(*(undefined4 *)(iVar2 + 0x18),&local_20,&local_1c,param_3,&local_24);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    *(int *)(DAT_001e875c + 0x60) = local_28 - local_8;
    if (*param_2 != 0) {
      local_28 = param_2[1];
      if ((local_28 < 1) || (local_20 == 0)) {
        local_28 = 0;
      }
      else {
        if (*(short *)(local_20 + 8) < local_28) {
          local_28 = (int)*(short *)(local_20 + 8);
        }
        _copyout(local_20 + *(int *)(local_20 + 4),*param_2,local_28);
      }
      _copyout(&local_28,param_4,4);
    }
    if (param_2[4] != 0) {
      local_28 = param_2[5];
      if ((local_28 < 1) || (local_24 == 0)) {
        local_28 = 0;
      }
      else {
        if (*(short *)(local_24 + 8) < local_28) {
          local_28 = (int)*(short *)(local_24 + 8);
        }
        _copyout(local_24 + *(int *)(local_24 + 4),param_2[4],local_28);
      }
      _copyout(&local_28,param_5,4);
    }
    if (local_24 != 0) {
      _m_freem(local_24);
    }
    if (local_20 != 0) {
      _m_freem(local_20);
    }
  }
  return;
}

