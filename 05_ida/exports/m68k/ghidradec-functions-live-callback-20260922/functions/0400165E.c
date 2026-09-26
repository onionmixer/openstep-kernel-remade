
uint _copyoutmsg(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  sword sVar3;
  word wVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_3 != 0) {
    if ((int)param_3 < 1) {
      return param_3;
    }
    uVar2 = -(int)param_2 & 3;
    uVar1 = uVar2;
    while ((uVar1 != 0 && (wVar4 = (sword)uVar2 - 1, uVar2 = (uint)wVar4, wVar4 != 0xffff))) {
      *(undefined *)param_2 = *(undefined *)param_1;
      uVar1 = param_3 - 1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
      param_3 = uVar1;
    }
    uVar2 = param_3 << 0x1e | param_3 >> 2;
    while( true ) {
      wVar4 = (word)(uVar2 >> 0x10);
      sVar3 = (sword)uVar2 + -1;
      uVar2 = CONCAT22(wVar4,sVar3);
      if (sVar3 == -1) break;
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    wVar4 = wVar4 >> 0xe;
    puVar5 = param_1;
    puVar6 = param_2;
    if ((wVar4 & 2) != 0) {
      puVar5 = (undefined4 *)((int)param_1 + 2);
      puVar6 = (undefined4 *)((int)param_2 + 2);
      *(undefined2 *)param_2 = *(undefined2 *)param_1;
    }
    if ((wVar4 & 1) != 0) {
      *(undefined *)puVar6 = *(undefined *)puVar5;
    }
  }
  return 0;
}

