
undefined4 _fdstrategy(uint *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar4 = (*(word *)((int)param_1 + 0x1e) & 0xff) >> 3;
  uVar3 = *(word *)((int)param_1 + 0x1e) & 7;
  iVar2 = *(int *)(_fd_volume_p + uVar4 * 4);
  uVar6 = 0;
  if ((uVar4 < 0xb) && (iVar2 != 0)) {
    iVar5 = *(int *)(iVar2 + 0x14);
    if ((uint *)(iVar2 + 0x18) == param_1) {
loc_406BE86:
      iVar5 = iVar2 + 0xba;
      if ((uint *)(iVar2 + 0x18) == param_1) {
        if (*(int *)(*(int *)(iVar2 + 0x5c) + 6) == 2) {
          _disksort_enter_tail(iVar5,param_1);
        }
        else {
          _disksort_enter_head(iVar5,param_1);
        }
      }
      else {
        _disksort_enter(iVar5,param_1);
      }
      if (*(int *)(iVar2 + 0x132) != 0) {
        return 0;
      }
      uVar6 = _fd_start(iVar2);
      return uVar6;
    }
    if ((*(uint *)(iVar2 + 0x176) & 1) == 0) goto loc_406BE0E;
    if ((param_1[5] & *(int *)(iVar2 + 0x186) - 1U) == 0) {
      if (((*param_1 & 1) == 0) && ((*(uint *)(iVar2 + 0x176) & 4) != 0)) {
        *(undefined2 *)(param_1 + 7) = 0x1e;
        goto loc_406BEE2;
      }
      if (uVar3 != 1) {
        if ((*(byte *)(iVar2 + 0x179) & 2) != 0) {
          uVar4 = param_1[9];
          param_1[0xe] = uVar4;
          if (uVar3 < 2) {
            piVar1 = (int *)(iVar5 + uVar3 * 0x2e + 0xbe);
            uVar3 = piVar1[1];
            if (((uVar3 == 0) || ((int)uVar4 < 0)) || ((int)uVar3 < (int)uVar4)) goto loc_406BE72;
            if (uVar3 != uVar4) {
              uVar4 = *piVar1 + uVar4;
              param_1[0xe] = uVar4;
              iVar5 = *(int *)(iVar5 + 0x60) * *(int *)(iVar5 + 100);
              if (0 < iVar5) {
                param_1[0xe] = (int)uVar4 / iVar5;
              }
              goto loc_406BE86;
            }
            goto loc_406BE7E;
          }
        }
        goto loc_406BE0E;
      }
      uVar3 = param_1[9];
      param_1[0xe] = uVar3;
      if ((-1 < (int)uVar3) && (uVar3 <= *(uint *)(iVar2 + 0x192))) {
        if (*(uint *)(iVar2 + 0x192) != uVar3) goto loc_406BE86;
loc_406BE7E:
        param_1[10] = param_1[5];
        goto loc_406BEE8;
      }
    }
loc_406BE72:
    *(undefined2 *)(param_1 + 7) = 0x16;
  }
  else {
loc_406BE0E:
    *(undefined2 *)(param_1 + 7) = 6;
  }
loc_406BEE2:
  *param_1 = *param_1 | 4;
  uVar6 = 0xffffffff;
loc_406BEE8:
  _biodone(param_1);
  return uVar6;
}
