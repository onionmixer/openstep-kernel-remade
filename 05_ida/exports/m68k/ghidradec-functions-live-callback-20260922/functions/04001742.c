
undefined4 _copywithin(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_3 != 0) {
    if ((int)param_3 < 1) {
      return 0x16;
    }
    if (param_1 < param_2) {
      param_1 = (undefined4 *)(param_3 + (int)param_1);
      param_2 = (undefined4 *)(param_3 + (int)param_2);
      uVar2 = (uint)param_2 & 3;
      uVar1 = uVar2;
      while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
        param_1 = (undefined4 *)((int)param_1 + -1);
        param_2 = (undefined4 *)((int)param_2 + -1);
        *(undefined *)param_2 = *(undefined *)param_1;
        param_3 = param_3 - 1;
        uVar1 = param_3;
      }
      uVar2 = param_3;
      switch(param_3 & 0x1c) {
      case :
        goto loc_4001802;
      case :
        goto loc_4001800;
      case :
        goto loc_40017fe;
      case :
        goto loc_40017fc;
      case :
        goto loc_40017fa;
      case :
        goto loc_40017f8;
      case :
        goto loc_40017f6;
      }
      while (param_3 = uVar2 - 0x20, 0x1f < (int)uVar2) {
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017f6:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017f8:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017fa:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017fc:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_40017fe:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_4001800:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
loc_4001802:
        param_1 = param_1 + -1;
        param_2 = param_2 + -1;
        *param_2 = *param_1;
        uVar2 = param_3;
      }
      if ((param_3 & 2) != 0) {
        param_1 = (undefined4 *)((int)param_1 + -2);
        param_2 = (undefined4 *)((int)param_2 + -2);
        *(undefined2 *)param_2 = *(undefined2 *)param_1;
      }
      if ((param_3 & 1) != 0) {
        *(undefined *)((int)param_2 + -1) = *(undefined *)((int)param_1 + -1);
      }
    }
    else if (param_2 != param_1) {
      uVar2 = -(int)param_2 & 3;
      uVar1 = uVar2;
      while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
        *(undefined *)param_2 = *(undefined *)param_1;
        param_3 = param_3 - 1;
        param_1 = (undefined4 *)((int)param_1 + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = param_3;
      }
      uVar2 = param_3;
      puVar4 = param_1;
      puVar6 = param_2;
      switch(param_3 & 0x1c) {
      case :
        goto loc_40017a4;
      case :
        goto loc_40017a2;
      case :
        goto loc_40017a0;
      case :
        goto loc_400179e;
      case :
        goto loc_400179c;
      case :
        goto loc_400179a;
      case :
        goto loc_4001798;
      }
      while (param_3 = uVar2 - 0x20, 0x1f < (int)uVar2) {
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_4001798:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
loc_400179a:
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_400179c:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
loc_400179e:
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_40017a0:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
loc_40017a2:
        param_1 = puVar4 + 1;
        param_2 = puVar6 + 1;
        *puVar6 = *puVar4;
loc_40017a4:
        puVar4 = param_1 + 1;
        puVar6 = param_2 + 1;
        *param_2 = *param_1;
        uVar2 = param_3;
      }
      puVar5 = puVar4;
      puVar7 = puVar6;
      if ((param_3 & 2) != 0) {
        puVar5 = (undefined4 *)((int)puVar4 + 2);
        puVar7 = (undefined4 *)((int)puVar6 + 2);
        *(undefined2 *)puVar6 = *(undefined2 *)puVar4;
      }
      if ((param_3 & 1) != 0) {
        *(undefined *)puVar7 = *(undefined *)puVar5;
      }
    }
  }
  return 0;
}

