
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_machine_table(int param_1,int param_2,undefined4 param_3,int param_4,uint param_5,int param_6)

{
  undefined uVar2;
  undefined4 uVar1;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined auStack_58 [4];
  undefined4 auStack_54 [8];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  char acStack_20 [8];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0x10) {
    if (param_1 < 0x11) {
      if (param_1 == 0xd) {
        if ((param_2 == 0) && (param_4 == 1)) {
          uStack_18 = _tk_nin;
          uStack_14 = _tk_nout;
          uStack_10 = _dk_busy;
          iStack_c = 0;
          if (_bus_dinit._0_4_ != 0) {
            puVar4 = _bus_dinit;
            iVar6 = 0;
            do {
              if (-1 < *(sword *)(_bus_dinit + iVar6 + 0xc)) {
                iStack_c = iStack_c + 1;
              }
              puVar4 = (undefined *)((int)puVar4 + 0x2a);
              iVar6 = iVar6 + 0x2a;
            } while (*(int *)puVar4 != 0);
          }
          iStack_8 = 0;
          for (iVar6 = _ifnet; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x5a)) {
            iStack_8 = iStack_8 + 1;
          }
          puVar7 = &uStack_18;
          uVar5 = 0x14;
          goto loc_40953DE;
        }
      }
      else {
        if (param_1 != 0xe) {
          return 0;
        }
        iVar6 = 0;
        if (_bus_dinit._0_4_ != 0) {
          puVar4 = _bus_dinit;
          iVar3 = 0;
          do {
            if (param_2 == *(sword *)(_bus_dinit + iVar3 + 0xc)) break;
            puVar4 = (undefined *)((int)puVar4 + 0x2a);
            iVar3 = iVar3 + 0x2a;
            iVar6 = iVar6 + 1;
          } while (*(int *)puVar4 != 0);
          iVar6 = iVar6 * 0x2a;
          if (*(int *)(_bus_dinit + iVar6) != 0) {
            puVar7 = &uStack_34;
            _strncpy(acStack_20,*(undefined4 *)(_bus_dinit + iVar6 + 0x16),6);
            iVar3 = _strlen(acStack_20);
            acStack_20[iVar3] = _bus_dinit[iVar6 + 5] + '0';
            acStack_20[iVar3 + 1] = '\0';
            if (param_2 < _dk_ndrive) {
              uStack_34 = *(undefined4 *)(_dk_time + param_2 * 4);
              uStack_30 = *(undefined4 *)(_dk_seek + param_2 * 4);
              uStack_2c = *(undefined4 *)(_dk_xfer + param_2 * 4);
              uStack_28 = *(undefined4 *)(_dk_wds + param_2 * 4);
              uStack_24 = *(undefined4 *)(_dk_bps + param_2 * 4);
              uVar5 = 0x1c;
              goto loc_40953DE;
            }
          }
        }
      }
      return 0xffffffff;
    }
    if (param_1 == 0x4002) {
      puVar7 = (undefined4 *)&_cpu_clk;
      uVar5 = 1;
    }
    else if (param_1 < 0x4003) {
      if (param_1 != 0x4000) {
        return 0;
      }
      puVar7 = (undefined4 *)&_cpu_rev;
      uVar5 = 1;
    }
    else {
      if (param_1 != 0x4003) {
        return 0;
      }
      puVar7 = &_nbic_present;
      uVar5 = 4;
    }
    goto loc_40953DE;
  }
  uVar5 = __cpu_rev >> 0x1c;
  if (uVar5 == 5) {
loc_40953C4:
    auStack_54[0] = 0;
  }
  else {
    if (uVar5 < 6) {
      if (uVar5 == 3) goto loc_40953C4;
    }
    else if (uVar5 == 9) goto loc_40953C4;
    auStack_54[0] = 1;
  }
  puVar7 = auStack_54;
  uVar5 = 0x20;
loc_40953DE:
  if (param_5 < uVar5) {
    uVar5 = param_5;
  }
  if (uVar5 != 0) {
    if (param_6 == 0) {
      uVar2 = _copyoutmsg(puVar7,param_3,uVar5);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
    else {
      uVar2 = _copyinmsg(param_3,auStack_58,uVar5);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        _bcopy(auStack_58,puVar7,uVar5);
      }
    }
  }
  uVar1 = 0xffffffff;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar1 = 1;
  }
  return uVar1;
}

