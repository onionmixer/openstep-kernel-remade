
undefined4 _rtrequest(int param_1,int param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  uint *puVar10;
  uint uStack_c;
  uint uStack_8;
  
  puVar10 = (uint *)0x0;
  uVar8 = 0;
  uVar6 = (uint)*(word *)(param_2 + 4);
  if (0x10 < uVar6) {
    return 0x2f;
  }
  (*(code *)(&_afswitch)[uVar6 * 2])(param_2 + 4,&uStack_c);
  if ((*(byte *)(param_2 + 0x25) & 4) == 0) {
    puVar9 = _rtnet;
    uVar7 = uStack_8;
  }
  else {
    puVar9 = _rthost;
    uVar7 = uStack_c;
  }
  puVar1 = (undefined4 *)(puVar9 + (uVar7 & 7) * 4);
  pcVar2 = (&off_40AE86A)[uVar6 * 2];
  puVar5 = puVar1;
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3)
  {
    puVar10 = (uint *)(puVar3[1] + (int)puVar3);
    if (uVar7 == *puVar10) {
      if ((*(byte *)(param_2 + 0x25) & 4) == 0) {
        if ((*(sword *)(param_2 + 4) == *(sword *)(puVar10 + 1)) &&
           (iVar4 = (*pcVar2)(puVar10 + 1,param_2 + 4), iVar4 != 0)) {
loc_401DBBC:
          iVar4 = _bcmp(puVar10 + 5,param_2 + 0x14,0x10);
          if (iVar4 == 0) break;
        }
      }
      else {
        iVar4 = _bcmp(puVar10 + 1,param_2 + 4,0x10);
        if (iVar4 == 0) goto loc_401DBBC;
      }
    }
    puVar5 = puVar3;
  }
  if (param_1 != -0x7fcf8df6) {
    if (param_1 != -0x7fcf8df5) {
      return 0;
    }
    if (puVar3 == (undefined4 *)0x0) {
      return 3;
    }
    *puVar5 = *puVar3;
    if (0 < *(sword *)((int)puVar10 + 0x26)) {
      *(word *)(puVar10 + 9) = *(word *)(puVar10 + 9) & 0xfffe;
      _rttrash = _rttrash + 1;
      *puVar3 = 0;
      return 0;
    }
    _m_free(puVar3);
    return 0;
  }
  if (puVar3 != (undefined4 *)0x0) {
    return 0x11;
  }
  if ((*(word *)(param_2 + 0x24) & 2) == 0) {
    iVar4 = 0;
    if ((*(word *)(param_2 + 0x24) & 4) != 0) {
      iVar4 = _ifa_ifwithdstaddr(param_2 + 4);
    }
    if (iVar4 != 0) goto loc_401DC84;
    iVar4 = _ifa_ifwithaddr(param_2 + 0x14);
  }
  else {
    iVar4 = _ifa_ifwithdstaddr(param_2 + 0x14);
  }
  if ((iVar4 == 0) && (iVar4 = _ifa_ifwithnet(param_2 + 0x14), iVar4 == 0)) {
    return 0x33;
  }
loc_401DC84:
  puVar5 = (undefined4 *)_m_get(0,5);
  if (puVar5 == (undefined4 *)0x0) {
    uVar8 = 0x37;
  }
  else {
    *puVar5 = *puVar1;
    *puVar1 = puVar5;
    puVar5[1] = 0xc;
    *(undefined2 *)(puVar5 + 2) = 0x30;
    puVar10 = (uint *)(puVar5[1] + (int)puVar5);
    *puVar10 = uVar7;
    puVar10[1] = *(uint *)(param_2 + 4);
    puVar10[2] = *(uint *)(param_2 + 8);
    puVar10[3] = *(uint *)(param_2 + 0xc);
    puVar10[4] = *(uint *)(param_2 + 0x10);
    puVar10[5] = *(uint *)(param_2 + 0x14);
    puVar10[6] = *(uint *)(param_2 + 0x18);
    puVar10[7] = *(uint *)(param_2 + 0x1c);
    puVar10[8] = *(uint *)(param_2 + 0x20);
    *(word *)(puVar10 + 9) = *(word *)(param_2 + 0x24) & 0x16 | 1;
    *(undefined2 *)((int)puVar10 + 0x26) = 0;
    puVar10[10] = 0;
    puVar10[0xb] = *(uint *)(iVar4 + 0x20);
  }
  return uVar8;
}

