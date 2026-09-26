
void sub_407C894(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  
  puVar1 = (undefined4 *)*param_1;
  bVar5 = false;
  iVar2 = *(int *)((int)param_1 + 0xd2);
  piVar3 = *(int **)((int)param_1 + 0xca);
  iVar7 = 0;
  do {
    sub_407CC7A(param_1,param_2);
    if (iVar7 == 0) {
      iVar7 = -1;
    }
    else {
      if (iVar7 < 0) {
        _printf(aWaitingForDriv);
        iVar7 = 1;
      }
      else {
        _printf(&asc_40A6047);
        iVar7 = iVar7 + 1;
      }
      if (param_2 == 0) {
        _timeout(sub_407CB90,puVar1,_hz * 2);
        _sleep(puVar1,0x28);
      }
      else {
        _delay(1000000);
      }
    }
    iVar6 = sub_407CCEE(param_1,param_2);
  } while ((iVar6 == 0) && (iVar7 < 0x14));
  if (0 < iVar7) {
    _printf(&asc_40A6049);
  }
  uVar4 = param_1[2];
  param_1[2] = uVar4 & 0xfffffffb;
  if (iVar7 < 0x14) {
    param_1[2] = uVar4 & 0xfffffffb | 2;
    sub_407E348(param_1,param_2);
    sub_407CA92(param_1);
    if ((**(byte **)((int)puVar1 + 0xb2) & 0x1f) == 5) {
      *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x800;
    }
    else {
      *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xf7ff;
      iVar7 = _kalloc(0x4c);
      uVar4 = iVar7 + 0xfU & 0xfffffff0;
      iVar6 = sub_407CC0E(param_1,param_2,uVar4,0x3c);
      if ((iVar6 == 0) && (*(char *)(uVar4 + 2) < '\0')) {
        *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) | 0x800;
      }
      _kfree(iVar7,0x4c);
    }
    if ((param_1[2] & 0x400) == 0) {
      _printf(aDiskUnformatte);
    }
    else if ((param_1[2] & 4) != 0) {
      _printf(aDiskLabelS,iVar2 + 0xc);
      _printf(aDiskCapacityDm,(uint)(piVar3[1] * *piVar3) >> 0x14,piVar3[1]);
    }
    if ((*(byte *)((int)param_1 + 10) & 8) != 0) {
      _printf(aDiskIsWritePro);
    }
  }
  else {
    bVar5 = true;
  }
  sub_407CBA2(param_1,param_2);
  if (bVar5) {
    *puVar1 = 0;
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xff7d;
  }
  else if (param_2 == 1) {
    sub_407F250(param_1);
  }
  return;
}
