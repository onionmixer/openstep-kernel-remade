/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ed98 */

undefined4 _ttyopen(undefined2 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar5 = _ttynty(param_2);
  iVar2 = *_active_u;
  iVar6 = _get_posix_proc((int)*(short *)(iVar2 + 0x30));
  if ((*(byte *)(iVar2 + 0x16) & 2) == 0) {
    if ((*(byte *)(iVar2 + 0x2b) & 0x40) != 0) goto LAB_0010eec2;
    _active_u[0x5a] = param_2;
    *(undefined2 *)(_active_u + 0x5b) = param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0x10) + 8);
    *(int *)(*(int *)(*(int *)(iVar6 + 0x10) + 8) + 8) = param_2;
    sVar1 = *(short *)(param_2 + 0x44);
    if (sVar1 == 0) {
      _enterpgrp(iVar2,(int)*(short *)(iVar2 + 0x30),1);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0x10);
      *(undefined2 *)(param_2 + 0x44) = *(undefined2 *)(*(int *)(iVar6 + 0x10) + 0xc);
    }
    else if (*(short *)(iVar2 + 0x2e) != sVar1) {
      _enterpgrp(iVar2,(int)sVar1,0);
    }
  }
  else {
    iVar3 = *(int *)(*(int *)(iVar6 + 0x10) + 8);
    if ((((*(int *)(iVar3 + 4) != iVar2) || (*(int *)(iVar3 + 8) != 0)) ||
        (*(int *)(iVar5 + 8) != 0)) || ((*(byte *)(iVar6 + 0x18) & 2) != 0)) goto LAB_0010eec2;
    _active_u[0x5a] = param_2;
    *(undefined2 *)(_active_u + 0x5b) = param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0x10) + 8);
    *(int *)(*(int *)(*(int *)(iVar6 + 0x10) + 8) + 8) = param_2;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 0x10);
    *(undefined2 *)(param_2 + 0x44) = *(undefined2 *)(*(int *)(iVar6 + 0x10) + 0xc);
  }
  *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) | 0x40000000;
LAB_0010eec2:
  *(undefined2 *)(param_2 + 0x38) = param_1;
  uVar7 = _spltty();
  uVar4 = *(uint *)(param_2 + 0x40);
  uVar8 = uVar4 & 0xfffffffd;
  *(uint *)(param_2 + 0x40) = uVar8;
  if ((uVar4 & 4) == 0) {
    *(uint *)(param_2 + 0x40) = uVar8 | 4;
    _splx(uVar7);
    *(undefined4 *)(iVar5 + 0x10) = 0x1c251a1c;
    *(undefined1 *)(iVar5 + 0x14) = 0x5c;
    *(undefined1 *)(iVar5 + 0x15) = 1;
    *(undefined1 *)(iVar5 + 0x16) = 0;
    _bzero((void *)(param_2 + 0x5c),8);
    if (*(char *)(param_2 + 0x47) != '\x02') {
      _ttywait(param_2);
      _ttyflush(param_2,1);
    }
  }
  else {
    _splx(uVar7);
  }
  _ttysetspec(iVar5);
  return 0;
}

