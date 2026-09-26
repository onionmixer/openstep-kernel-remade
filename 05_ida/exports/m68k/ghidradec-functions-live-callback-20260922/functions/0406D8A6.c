
void _fd_intr(int param_1)

{
  uint uVar1;
  undefined6 *puVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined6 *puStack_1c;
  
  bVar3 = *(byte *)(param_1 + 0x6a);
  if ((*(int *)(param_1 + 4) == 0) && (-1 < *(sword *)(dword_40C3710 + 0xc))) {
    uVar1 = (int)*(sword *)(dword_40C3710 + 0xc) & 0x3f;
    _dk_busy = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & _dk_busy;
  }
  puStack_1c = (undefined6 *)(param_1 + 0xba);
  iStack_20 = 0x406d8e6;
  iVar4 = _disksort_first();
  piVar7 = (int *)&stack0xffffffe8;
  if (param_1 + 0x18 == iVar4) goto loc_406DB02;
  if (*(uint *)(param_1 + 0xa6) != 0) {
    puVar2 = *(undefined6 **)(param_1 + 0x186);
    if ((byte)((bVar3 & 0x1f) - 5) < 2) {
      *(uint *)(param_1 + 0xa6) = -(int)puVar2 & *(uint *)(param_1 + 0xa6);
    }
    if ((*(int *)(param_1 + 0x9e) == 6) && (*(int *)(param_1 + 0xa6) != 0)) {
      *(int *)(param_1 + 0xa6) = *(int *)(param_1 + 0xa6) - (int)puVar2;
    }
    if (*(int *)(param_1 + 0x164) == 0) {
      *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0xa6);
    }
    else {
      iStack_20 = *(int *)(param_1 + 0x160);
      iStack_24 = 0x406d936;
      puStack_1c = puVar2;
      _kfree();
      if (*(int *)(param_1 + 0xa6) == *(int *)(param_1 + 0x14c)) {
        *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x164);
      }
      *(undefined4 *)(param_1 + 0x164) = 0;
    }
    *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0xa6) + *(int *)(param_1 + 0x144);
    if (puVar2 != (undefined6 *)0x0) {
      *(int *)(param_1 + 0x13c) =
           *(uint *)(param_1 + 0xa6) / (uint)puVar2 + *(int *)(param_1 + 0x13c);
    }
  }
  piVar7 = (int *)&stack0xffffffe8;
  switch(*(undefined4 *)(param_1 + 0x9e)) {
  case :
    iVar4 = *(int *)(param_1 + 0x132);
    if (iVar4 == 2) {
      uVar5 = 1;
loc_406D9F8:
      *(undefined4 *)(param_1 + 0x132) = uVar5;
    }
    else {
      if (2 < iVar4) {
        if (iVar4 != 3) goto loc_406DA1E;
        uVar5 = 2;
        goto loc_406D9F8;
      }
      if (iVar4 != 1) {
loc_406DA1E:
        puStack_1c = (undefined6 *)aFdIntrBogusFvp;
                    /* WARNING: Subroutine does not return */
        iStack_20 = 0x406da2a;
        _panic();
      }
    }
    if (*(int *)(param_1 + 0x140) != 0) {
      puStack_1c = (undefined6 *)((*(uint *)(param_1 + 0x15c) ^ 1) & 1);
      piVar6 = &iStack_20;
      iStack_20 = param_1;
      iStack_24 = 0x406da1a;
      sub_406DC10();
loc_406DAEA:
      *(int *)((int)piVar6 + -4) = param_1;
      *(undefined4 *)((int)piVar6 + -8) = 0x406daf2;
      _fc_start();
      return;
    }
    break;
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
  case :
    if (*(int *)(param_1 + 0x132) == 2) {
      iVar4 = *(int *)(param_1 + 0x154);
      *(int *)(param_1 + 0x154) = iVar4 + -1;
      if (iVar4 != 1 && -1 < iVar4 + -1) {
        puStack_1c = &aRetry;
        iStack_20 = param_1;
        iStack_24 = 0x406da8e;
        sub_406DB14();
        iStack_24 = 0;
        piVar6 = &iStack_28;
        iStack_28 = param_1;
        sub_406DC10();
        goto loc_406DAEA;
      }
      iVar4 = *(int *)(param_1 + 0x158);
      *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + -1;
      if (0 < iVar4) {
        puStack_1c = (undefined6 *)aRecalibrate;
        iStack_20 = param_1;
        iStack_24 = 0x406da64;
        sub_406DB14();
        *(undefined4 *)(param_1 + 0x154) = _fd_inner_retry;
        iStack_24 = param_1 + 0x60;
        piVar6 = &iStack_28;
        iStack_28 = param_1;
        sub_406E192();
        *(undefined4 *)(param_1 + 0x132) = 3;
        goto loc_406DAEA;
      }
    }
    else {
      if ((*(byte *)(param_1 + 0x15f) & 1) == 0) {
        puStack_1c = (undefined6 *)0x0;
        iStack_20 = param_1;
        iStack_24 = 0x406dac6;
        sub_406DC10();
        *(undefined4 *)(param_1 + 0x132) = 2;
      }
      else {
        puStack_1c = (undefined6 *)0x1;
        iStack_20 = param_1;
        iStack_24 = 0x406daae;
        iVar4 = sub_406DC10();
        if (iVar4 == 0) {
          *(undefined4 *)(param_1 + 0x132) = 2;
        }
      }
      if ((*(int *)(param_1 + 0x132) != 2) || (*(int *)(param_1 + 0x154) != 0)) {
        puStack_1c = &aRetry;
        piVar6 = &iStack_20;
        iStack_20 = param_1;
        iStack_24 = 0x406daea;
        sub_406DB14();
        goto loc_406DAEA;
      }
    }
  :
    puStack_1c = &aFatal;
    piVar7 = &iStack_20;
    iStack_20 = param_1;
    iStack_24 = 0x406db02;
    sub_406DB14();
  }
loc_406DB02:
  *(int *)((int)piVar7 + -4) = param_1;
  *(undefined4 *)((int)piVar7 + -8) = 0x406db0a;
  _fd_done();
  return;
}

