
undefined4 _sdstrategy(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar4 = (*(word *)((int)param_1 + 0x1e) & 0xff) >> 3;
  uVar3 = *(word *)((int)param_1 + 0x1e) & 7;
  iVar2 = *(int *)(unk_40B4FDE + uVar4 * 4);
  uVar6 = 0;
  if (((uVar4 == 0x10) || (iVar2 == 0)) || (0x11 < uVar4)) {
loc_407D2A8:
    *(undefined2 *)(param_1 + 7) = 6;
  }
  else {
    iVar5 = *(int *)(iVar2 + 0xd2);
    if ((uint *)(iVar2 + 0x18) == param_1) {
loc_407D306:
      if ((uint *)(iVar2 + 0x18) == param_1) {
        _disksort_enter_tail(iVar2 + 0x60,param_1);
      }
      else {
        _disksort_enter(iVar2 + 0x60,param_1);
      }
      if ((*(uint *)(iVar2 + 8) & 0x300) != 0) {
        return 0;
      }
      uVar6 = sub_407D376(iVar2);
      return uVar6;
    }
    uVar4 = param_1[9];
    param_1[0xe] = uVar4;
    if (((*param_1 & 1) != 0) || ((*(byte *)(iVar2 + 10) & 8) == 0)) {
      if ((*(word *)((int)param_1 + 0x1e) & 7) == 7) {
        uVar3 = **(int **)(iVar2 + 0xca) + 1;
        if ((int)uVar3 < (int)uVar4) {
loc_407D2D8:
          *(undefined2 *)(param_1 + 7) = 0x16;
          goto loc_407D35C;
        }
        if (uVar3 != uVar4) goto loc_407D306;
      }
      else {
        if (((*(byte *)(iVar2 + 0xb) & 4) == 0) || (7 < uVar3)) goto loc_407D2A8;
        piVar1 = (int *)(iVar5 + uVar3 * 0x2e + 0xbe);
        uVar3 = piVar1[1];
        if (((uVar3 == 0) || ((int)uVar4 < 0)) || ((int)uVar3 < (int)uVar4)) goto loc_407D2D8;
        if (uVar3 != uVar4) {
          uVar3 = *piVar1 + param_1[0xe];
          param_1[0xe] = uVar3;
          iVar5 = *(int *)(iVar5 + 0x60) * *(int *)(iVar5 + 100);
          if (0 < iVar5) {
            param_1[0xe] = (int)uVar3 / iVar5;
          }
          goto loc_407D306;
        }
      }
      param_1[10] = param_1[5];
      goto loc_407D362;
    }
    *(undefined2 *)(param_1 + 7) = 0x1e;
  }
loc_407D35C:
  *param_1 = *param_1 | 4;
  uVar6 = 0xffffffff;
loc_407D362:
  _biodone(param_1);
  return uVar6;
}
