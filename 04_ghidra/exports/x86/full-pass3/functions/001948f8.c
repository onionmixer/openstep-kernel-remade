/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001948f8 */

void _cnopen(undefined2 param_1,undefined4 param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = _ttynty(_cons_tp);
  uVar1 = *(ushort *)(_cons_tp + 0x38);
  iVar3 = *_active_u;
  iVar6 = _get_posix_proc((int)*(short *)(iVar3 + 0x30));
  if ((*(byte *)(iVar3 + 0x16) & 2) == 0) {
    if ((*(byte *)(iVar3 + 0x2b) & 0x40) == 0) {
      _active_u[0x5a] = _cons_tp;
      *(undefined2 *)(_active_u + 0x5b) = param_1;
      *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0x10) + 8);
      *(int *)(*(int *)(*(int *)(iVar6 + 0x10) + 8) + 8) = _cons_tp;
      sVar2 = *(short *)(_cons_tp + 0x44);
      if (sVar2 == 0) {
        _enterpgrp(iVar3,(int)*(short *)(iVar3 + 0x30),0);
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0x10);
        *(undefined2 *)(_cons_tp + 0x44) = *(undefined2 *)(*(int *)(iVar6 + 0x10) + 0xc);
      }
      else if (*(short *)(iVar3 + 0x2e) != sVar2) {
        _enterpgrp(iVar3,(int)sVar2,0);
      }
    }
  }
  else {
    iVar4 = *(int *)(*(int *)(iVar6 + 0x10) + 8);
    if ((((*(int *)(iVar4 + 4) == iVar3) && (*(int *)(iVar4 + 8) == 0)) &&
        (*(int *)(iVar5 + 8) == 0)) && ((*(byte *)(iVar6 + 0x18) & 2) == 0)) {
      _active_u[0x5a] = _cons_tp;
      *(undefined2 *)(_active_u + 0x5b) = param_1;
      *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0x10) + 8);
      *(int *)(*(int *)(*(int *)(iVar6 + 0x10) + 8) + 8) = _cons_tp;
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0x10);
      *(undefined2 *)(_cons_tp + 0x44) = *(undefined2 *)(*(int *)(iVar6 + 0x10) + 0xc);
      *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) | 0x40000000;
    }
  }
  (*(code *)(&_cdevsw)[(short)(uVar1 >> 8) * 0xb])((int)(short)uVar1,param_2);
  return;
}

