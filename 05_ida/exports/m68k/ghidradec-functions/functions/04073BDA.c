
int _np_ioctl_common(byte param_1,int param_2,int *param_3,undefined4 param_4,int param_5)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 unaff_A6;
  byte **ppbVar8;
  byte *pbStack_28;
  byte bStack_6;
  byte bStack_5;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  uStack_4 = (undefined2)((uint)unaff_A6 >> 0x10);
  uStack_2 = (undefined2)unaff_A6;
  iVar3 = (sword)(word)param_1 * 0x14c;
  pbVar7 = _np_softc + iVar3;
  iVar5 = 0;
  if (param_2 == -0x7ffb9982) {
    if (*param_3 == 0) {
      *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) & 0xfffffeff;
      return 0;
    }
    *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) | 0x100;
    return 0;
  }
  if (param_2 < -0x7ffb9981) {
    if (param_2 == -0x7ffb9983) {
      return 0;
    }
loc_407411C:
    return 6;
  }
  if (param_2 != -0x3fed8fff) {
    return 6;
  }
  if (param_5 != 0) {
    sVar1 = *(sword *)param_3;
    if (sVar1 == 4) {
      return 6;
    }
    if (sVar1 < 5) {
      if ((sVar1 < 3) && (-1 < sVar1)) {
        return 6;
      }
    }
    else if (sVar1 == 6) {
      return 6;
    }
  }
  if (*(sword *)param_3 == 0) {
    if (*(int *)((int)param_3 + 2) == 0) {
      pbStack_28 = (byte *)(iVar3 + 0x40c3b36);
      _lock_write();
      if ((*(int *)(_np_softc + iVar3 + 0x126) != 2) && (*(int *)(_np_softc + iVar3 + 0x126) != 6))
      {
        piVar2 = (int *)(_np_softc + iVar3 + 0x126);
        while (*(int *)(_np_softc + iVar3 + 0x126) != 0) {
          pbStack_28 = (byte *)0x28;
          _sleep(piVar2);
          if ((*piVar2 == 2) || (*piVar2 == 6)) break;
        }
      }
      ppbVar8 = &pbStack_28;
      pbStack_28 = pbVar7;
      _np_power_off();
    }
    else {
      pbStack_28 = (byte *)(iVar3 + 0x40c3b36);
      _lock_write();
      ppbVar8 = (byte **)&stack0xffffffdc;
      if ((*(int *)(_np_softc + iVar3 + 0x126) == 0) || (*(int *)(_np_softc + iVar3 + 0x126) == 7))
      {
        pbStack_28 = pbVar7;
        iVar5 = _np_power_on();
        ppbVar8 = (byte **)&stack0xffffffdc;
      }
    }
    *(int *)((int)ppbVar8 + -4) = iVar3 + 0x40c3b36;
    *(undefined4 *)((int)ppbVar8 + -8) = 0x4073cfe;
    _lock_done();
    return iVar5;
  }
  if ((*(int *)(_np_softc + iVar3 + 0x126) == 0) || (*(int *)(_np_softc + iVar3 + 0x126) == 7)) {
    return 0x50;
  }
  switch(*(undefined2 *)param_3) {
  case :
    if ((((0x1ff < *(uint *)((int)param_3 + 2)) || (0x7e < *(int *)((int)param_3 + 10) - 1U)) ||
        (*(int *)((int)param_3 + 6) < 1)) || (*(int *)((int)param_3 + 0xe) < 1)) goto loc_4073DAA;
    *(uint *)(_np_softc + iVar3 + 0x132) = *(uint *)((int)param_3 + 2);
    *(undefined4 *)(_np_softc + iVar3 + 0x13a) = *(undefined4 *)((int)param_3 + 10);
    *(undefined4 *)(_np_softc + iVar3 + 0x13e) = *(undefined4 *)((int)param_3 + 0xe);
    *(undefined4 *)(_np_softc + iVar3 + 0x136) = *(undefined4 *)((int)param_3 + 6);
    uVar4 = *(uint *)(_np_softc + iVar3 + 0x106);
    uVar6 = 1;
    goto loc_40740C8;
  case :
    if (*(byte *)((int)param_3 + 2) < 2) {
      _np_softc[iVar3 + 0x143] = *(byte *)((int)param_3 + 2);
      return 0;
    }
loc_4073DAA:
    iVar5 = 0x16;
    break;
  case :
    *(undefined4 *)((int)param_3 + 2) = 0;
    *(undefined4 *)((int)param_3 + 6) = 0;
    if (*(int *)(_np_softc + iVar3 + 0x126) == 1) {
      do {
        pbStack_28 = (byte *)0x28;
        _sleep(_np_softc + iVar3 + 0x126);
      } while (*(int *)(_np_softc + iVar3 + 0x126) == 1);
    }
    if ((*(int *)(_np_softc + iVar3 + 0x126) == 3) || (*(int *)(_np_softc + iVar3 + 0x126) == 4)) {
loc_407408C:
      *(undefined4 *)((int)param_3 + 2) = 1;
      return 0;
    }
    pbStack_28 = &bStack_5;
    iVar5 = _np_serial_cmd(pbVar7,1);
    if (iVar5 == 0) {
      if ((bStack_5 & 0x20) != 0) {
        *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 1;
      }
      if ((bStack_5 & 0x10) != 0) {
        pbStack_28 = &bStack_6;
        iVar5 = _np_serial_cmd(pbVar7,0x1f);
        if (iVar5 != 0) goto loc_4073F34;
        *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 2;
        *(uint *)((int)param_3 + 6) =
             (CONCAT22(CONCAT11(bStack_6,bStack_5),uStack_4) & 0x7fffffff) >> 0x19;
      }
      if ((bStack_5 & 8) != 0) {
        *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 4;
      }
      if ((bStack_5 & 2) == 0) {
loc_4073F20:
        pbStack_28 = &bStack_5;
        iVar5 = _np_serial_cmd(pbVar7,0x1f);
        if (iVar5 == 0) {
          if ((bStack_5 & 4) != 0) {
            *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x80;
          }
          if ((*(uint *)(_np_softc + iVar3 + 0x106) & 0x10) != 0) {
            *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x200;
            return 0;
          }
          return 0;
        }
      }
      else {
        pbStack_28 = &bStack_5;
        iVar5 = _np_serial_cmd(pbVar7,2);
        if (iVar5 == 0) {
          if ((bStack_5 & 0x40) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 8;
          }
          if ((bStack_5 & 0x10) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x10;
          }
          if ((bStack_5 & 8) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x20;
          }
          if ((bStack_5 & 4) != 0) {
            *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x40;
          }
          pbStack_28 = &bStack_5;
          iVar5 = _np_serial_cmd(pbVar7,4);
          if (iVar5 == 0) {
            if ((bStack_5 & 0x70) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x100;
            }
            if ((bStack_5 & 0x40) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x500;
            }
            if ((bStack_5 & 0x20) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x900;
            }
            if ((bStack_5 & 0x10) != 0) {
              *(word *)(param_3 + 1) = *(word *)(param_3 + 1) | 0x1100;
            }
            goto loc_4073F20;
          }
        }
      }
    }
loc_4073F34:
    if (iVar5 == 0x51) {
      *(uint *)((int)param_3 + 2) = *(uint *)((int)param_3 + 2) | 0x40;
      iVar5 = 0;
    }
    break;
  case :
    if (*(int *)(_np_softc + iVar3 + 0x126) != 1) {
      pbStack_28 = &bStack_5;
      iVar5 = _np_serial_cmd(pbVar7,0x5d);
      if ((iVar5 != 0) && (iVar5 == 0x51)) {
        iVar5 = 0;
      }
    }
    break;
  case :
    do {
      if (*(int *)(_np_softc + iVar3 + 0x126) == 1) {
        do {
          pbStack_28 = (byte *)0x28;
          _sleep(_np_softc + iVar3 + 0x126);
        } while (*(int *)(_np_softc + iVar3 + 0x126) == 1);
      }
      pbStack_28 = &bStack_5;
      iVar5 = _np_serial_cmd(pbVar7,0xb);
      if (iVar5 == 0) {
        switch(bStack_5) {
        case :
          *(undefined4 *)((int)param_3 + 2) = 0;
          return 0;
        case :
          goto loc_407408C;
        :
          return 5;
        case :
          *(undefined4 *)((int)param_3 + 2) = 2;
          return 0;
        case :
          *(undefined4 *)((int)param_3 + 2) = 3;
          return 0;
        case :
          *(undefined4 *)((int)param_3 + 2) = 4;
          return 0;
        }
      }
    } while (iVar5 == 0x51);
    break;
  case :
    if (((*(uint *)(_np_softc + iVar3 + 0x106) & 0x10) != 0) || (*(int *)((int)param_3 + 2) == 0)) {
      if ((*(uint *)(_np_softc + iVar3 + 0x106) & 0x10) == 0) {
        return 0;
      }
      if (*(int *)((int)param_3 + 2) == 0) {
        *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) | 0x20;
        *(uint *)(_np_softc + iVar3 + 0x106) = *(uint *)(_np_softc + iVar3 + 0x106) & 0xffffffef;
        return 0;
      }
      return 0;
    }
    uVar4 = *(uint *)(_np_softc + iVar3 + 0x106);
    uVar6 = 0x30;
loc_40740C8:
    *(uint *)(_np_softc + iVar3 + 0x106) = uVar6 | uVar4;
    break;
  :
    goto loc_407411C;
  }
  return iVar5;
}
