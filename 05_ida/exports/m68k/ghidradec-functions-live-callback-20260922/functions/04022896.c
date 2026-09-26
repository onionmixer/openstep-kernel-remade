
undefined4 _rip_output(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  sword sVar5;
  undefined4 uVar6;
  
  sVar5 = 0;
  iVar1 = *(int *)(param_2 + 8);
  if ((*(sword *)(iVar1 + 0x2e) == 0xff) || (puVar3 = param_1, *(sword *)(iVar1 + 0x2e) == 2)) {
    iVar4 = *(int *)((int)param_1 + param_1[1] + 0xc);
    iVar2 = _in_ifaddr;
    if (iVar4 != 0) {
      for (; (iVar2 != 0 && (iVar4 != *(int *)(iVar2 + 4))); iVar2 = *(int *)(iVar2 + 0x40)) {
      }
      iVar4 = 0;
      if (iVar2 != 0) {
        iVar4 = *(int *)(iVar2 + 0x20);
      }
      if (iVar4 == 0) {
        uVar6 = 0x31;
        goto loc_40229AC;
      }
    }
    *(undefined4 *)((int)param_1 + param_1[1] + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  }
  else {
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      sVar5 = *(sword *)(puVar3 + 2) + sVar5;
    }
    puVar3 = (undefined4 *)_m_get(0,2);
    if (puVar3 == (undefined4 *)0x0) {
      uVar6 = 0x37;
loc_40229AC:
      _m_freem(param_1);
      return uVar6;
    }
    puVar3[1] = 0x68;
    *(undefined2 *)(puVar3 + 2) = 0x14;
    *puVar3 = param_1;
    iVar4 = puVar3[1];
    *(undefined *)((int)puVar3 + iVar4 + 1) = 0;
    *(undefined2 *)((int)puVar3 + iVar4 + 6) = 0;
    *(undefined *)((int)puVar3 + iVar4 + 9) = *(undefined *)(iVar1 + 0x2f);
    *(sword *)((int)puVar3 + iVar4 + 2) = sVar5 + 0x14;
    param_1 = puVar3;
    if ((*(byte *)(iVar1 + 0x4d) & 1) == 0) {
      *(undefined4 *)((int)puVar3 + iVar4 + 0xc) = 0;
    }
    else {
      if (*(sword *)(iVar1 + 0x1c) != 2) {
        uVar6 = 0x2f;
        goto loc_40229AC;
      }
      *(undefined4 *)((int)puVar3 + iVar4 + 0xc) = *(undefined4 *)(iVar1 + 0x20);
    }
    *(undefined4 *)((int)puVar3 + iVar4 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined *)((int)puVar3 + iVar4 + 8) = 0xff;
  }
  uVar6 = _ip_output(param_1,*(undefined4 *)(iVar1 + 0x34),iVar1 + 0x38,
                     *(word *)(param_2 + 2) & 0x32 | 0x22,*(undefined4 *)(iVar1 + 0x4e));
  return uVar6;
}

