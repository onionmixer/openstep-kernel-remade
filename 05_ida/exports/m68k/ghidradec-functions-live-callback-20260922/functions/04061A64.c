
undefined4 sub_4061A64(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  bVar2 = true;
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
loc_4061A82:
    piVar5 = (int *)*param_1;
    if (piVar5 != param_1) {
      do {
        if ((param_2 <= (uint)piVar5[6]) && ((uint)piVar5[6] < param_3)) {
          iVar3 = sub_406197E(param_1,piVar5);
          if (iVar3 == 1) {
            bVar2 = false;
          }
          else if ((iVar3 != 0) && (iVar3 == 2)) goto loc_4061A82;
        }
        piVar5 = (int *)piVar5[2];
        if (piVar5 == param_1) break;
      } while( true );
    }
    param_3 = param_3 - param_2;
    uVar1 = param_1[4];
    if ((uVar1 != 0) && (uVar1 < param_3)) {
      param_3 = uVar1;
    }
    iVar3 = sub_4061A64(param_1[7],param_1[8] + param_2,param_3 + param_1[8] + param_2);
    if (iVar3 != 0) {
      iVar4 = 5;
    }
    _thread_wakeup_prim(param_1,0,0);
    if ((iVar4 == 5) || (!bVar2)) {
      return 5;
    }
  }
  return 0;
}

