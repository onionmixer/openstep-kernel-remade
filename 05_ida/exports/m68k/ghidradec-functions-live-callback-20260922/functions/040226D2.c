
undefined4 _ip_getmoptions(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  
  iVar1 = _m_get(1,0xe);
  *param_3 = iVar1;
  if (param_2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(*(int *)(param_2 + 4) + param_2);
  }
  if (param_1 == 4) {
    iVar1 = *param_3;
    puVar5 = (undefined *)(*(int *)(iVar1 + 4) + iVar1);
    *(undefined2 *)(iVar1 + 8) = 1;
    if (piVar3 == (int *)0x0) {
loc_4022788:
      *puVar5 = 1;
    }
    else {
      *puVar5 = *(undefined *)(piVar3 + 1);
    }
loc_402278C:
    uVar2 = 0;
  }
  else {
    if (param_1 < 5) {
      if (param_1 == 3) {
        iVar1 = *param_3;
        puVar4 = (undefined4 *)(*(int *)(iVar1 + 4) + iVar1);
        *(undefined2 *)(iVar1 + 8) = 4;
        if (((piVar3 != (int *)0x0) && (*piVar3 != 0)) && (iVar1 = _in_ifaddr, _in_ifaddr != 0)) {
          do {
            if (*piVar3 == *(int *)(iVar1 + 0x20)) break;
            iVar1 = *(int *)(iVar1 + 0x40);
          } while (iVar1 != 0);
          if (iVar1 != 0) {
            *puVar4 = *(undefined4 *)(iVar1 + 4);
            goto loc_402278C;
          }
        }
        *puVar4 = 0;
        goto loc_402278C;
      }
    }
    else if (param_1 == 5) {
      iVar1 = *param_3;
      puVar5 = (undefined *)(*(int *)(iVar1 + 4) + iVar1);
      *(undefined2 *)(iVar1 + 8) = 1;
      if (piVar3 == (int *)0x0) goto loc_4022788;
      *puVar5 = *(undefined *)((int)piVar3 + 5);
      goto loc_402278C;
    }
    uVar2 = 0x2d;
  }
  return uVar2;
}

