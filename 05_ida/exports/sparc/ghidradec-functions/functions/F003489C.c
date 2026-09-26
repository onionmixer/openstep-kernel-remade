
/* WARNING: Removing unreachable block (ram,0xf0034a10) */
/* WARNING: Removing unreachable block (ram,0xf0034a00) */
/* WARNING: Removing unreachable block (ram,0xf00348e4) */

undefined8 _rip_output(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  sword sVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar6 = *(int *)(param_2 + 8);
  sVar7 = 0;
  if ((*(sword *)(iVar6 + 0x2e) == 0xff) || (piVar8 = param_1, *(sword *)(iVar6 + 0x2e) == 2)) {
    iVar2 = *(int *)((int)param_1 + param_1[1] + 0xc);
    if (iVar2 == 0) {
      uVar4 = *(undefined4 *)(iVar6 + 0x10);
    }
    else {
      iVar3 = 0;
      if (_in_ifaddr != 0) {
        iVar3 = *(int *)(_in_ifaddr + 4);
        iVar5 = _in_ifaddr;
        while ((iVar3 != iVar2 && (iVar5 = *(int *)(iVar5 + 0x40), iVar5 != 0))) {
          iVar3 = *(int *)(iVar5 + 4);
        }
        iVar3 = 0;
        if (iVar5 != 0) {
          iVar3 = *(int *)(iVar5 + 0x20);
        }
      }
      if (iVar3 == 0) {
        piVar8 = (int *)0x31;
        goto loc_F0034A10;
      }
      uVar4 = *(undefined4 *)(iVar6 + 0x10);
    }
    *(undefined4 *)((int)param_1 + param_1[1] + 0x10) = uVar4;
  }
  else {
    for (; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      sVar7 = sVar7 + *(sword *)(piVar8 + 2);
    }
    piVar1 = (int *)0x0;
    _m_get(0,2);
    if (piVar1 == (int *)0x0) {
      piVar8 = (int *)0x37;
loc_F0034A10:
      _m_freem(param_1);
      param_1 = piVar8;
      goto locret_F0034A18;
    }
    piVar1[1] = 0x68;
    *(undefined2 *)(piVar1 + 2) = 0x14;
    iVar2 = piVar1[1];
    *piVar1 = (int)param_1;
    *(undefined *)((int)piVar1 + iVar2 + 1) = 0;
    *(undefined2 *)((int)piVar1 + iVar2 + 6) = 0;
    *(char *)((int)piVar1 + iVar2 + 9) = (char)*(undefined2 *)(iVar6 + 0x2e);
    *(sword *)((int)piVar1 + iVar2 + 2) = sVar7 + 0x14;
    if ((*(word *)(iVar6 + 0x4c) & 1) == 0) {
      *(undefined4 *)((int)piVar1 + iVar2 + 0xc) = 0;
    }
    else {
      piVar8 = (int *)0x2f;
      param_1 = piVar1;
      if (*(sword *)(iVar6 + 0x1c) != 2) goto loc_F0034A10;
      *(undefined4 *)((int)piVar1 + iVar2 + 0xc) = *(undefined4 *)(iVar6 + 0x20);
    }
    *(undefined4 *)((int)piVar1 + iVar2 + 0x10) = *(undefined4 *)(iVar6 + 0x10);
    *(undefined *)((int)piVar1 + iVar2 + 8) = 0xff;
    param_1 = piVar1;
  }
  _ip_output(param_1,*(undefined4 *)(iVar6 + 0x34),iVar6 + 0x38,*(word *)(param_2 + 2) & 0x10 | 0x22
             ,*(undefined4 *)(iVar6 + 0x50));
locret_F0034A18:
  return CONCAT44(param_2,param_1);
}
