
/* WARNING: Control flow encountered bad instruction data */

void _bcopy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  
  if (0 < (int)param_3) {
    if (param_1 < param_2) {
      puVar6 = (undefined *)(param_3 + (int)param_1);
      puVar9 = (undefined *)(param_3 + (int)param_2);
      uVar2 = (uint)puVar9 & 3;
      uVar1 = uVar2;
      while ((uVar1 != 0 && (wVar3 = (sword)uVar2 - 1, uVar2 = (uint)wVar3, wVar3 != 0xffff))) {
        puVar6 = puVar6 + -1;
        puVar9 = puVar9 + -1;
        *puVar9 = *puVar6;
        param_3 = param_3 - 1;
        uVar1 = param_3;
      }
      switch(param_3 & 0x1c) {
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case :
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    if (param_2 != param_1) {
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
      puVar7 = param_2;
      switch(param_3 & 0x1c) {
      case :
        goto loc_4092d80;
      case :
        goto loc_4092d7e;
      case :
        goto loc_4092d7c;
      case :
        goto loc_4092d7a;
      case :
        goto loc_4092d78;
      case :
        goto loc_4092d76;
      case :
        goto loc_4092d74;
      }
      while (param_3 = uVar2 - 0x20, 0x1f < (int)uVar2) {
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d74:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
loc_4092d76:
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d78:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
loc_4092d7a:
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d7c:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
loc_4092d7e:
        param_1 = puVar4 + 1;
        param_2 = puVar7 + 1;
        *puVar7 = *puVar4;
loc_4092d80:
        puVar4 = param_1 + 1;
        puVar7 = param_2 + 1;
        *param_2 = *param_1;
        uVar2 = param_3;
      }
      puVar5 = puVar4;
      puVar8 = puVar7;
      if ((param_3 & 2) != 0) {
        puVar5 = (undefined4 *)((int)puVar4 + 2);
        puVar8 = (undefined4 *)((int)puVar7 + 2);
        *(undefined2 *)puVar7 = *(undefined2 *)puVar4;
      }
      if ((param_3 & 1) != 0) {
        *(undefined *)puVar8 = *(undefined *)puVar5;
      }
    }
  }
  return;
}

