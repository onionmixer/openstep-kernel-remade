
/* WARNING: Removing unreachable block (ram,0xf002d2a0) */
/* WARNING: Removing unreachable block (ram,0xf002d314) */
/* WARNING: Removing unreachable block (ram,0xf002d2d4) */
/* WARNING: Removing unreachable block (ram,0xf002d210) */
/* WARNING: Removing unreachable block (ram,0xf002d1f4) */
/* WARNING: Removing unreachable block (ram,0xf002d2fc) */
/* WARNING: Removing unreachable block (ram,0xf002d2ec) */
/* WARNING: Removing unreachable block (ram,0xf002d330) */
/* WARNING: Removing unreachable block (ram,0xf002d410) */
/* WARNING: Removing unreachable block (ram,0xf002d17c) */

undefined8 _rtrequest(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  code *pcVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar6 = 0;
  uVar3 = (uint)*(word *)(param_2 + 4);
  uVar11 = 0;
  if (0x10 < uVar3) {
    uVar11 = 0x2f;
    goto locret_F002D418;
  }
  (**(code **)(_afswitch + uVar3 * 8))(param_2 + 4,(undefined *)((int)register0x00000038 + -0x10));
  uVar9 = *(uint *)((int)register0x00000038 + -0x10);
  if ((*(word *)(param_2 + 0x24) & 4) == 0) {
    uVar9 = *(uint *)((int)register0x00000038 + -0xc);
    puVar1 = _rtnet;
  }
  else {
    puVar1 = _rthost;
  }
  piVar7 = (int *)(puVar1 + (uVar9 & 7) * 4);
  puVar1 = _afswitch;
  pcVar10 = *(code **)(_afswitch + uVar3 * 8 + 4);
  _spltty();
  piVar4 = (int *)*piVar7;
  piVar8 = piVar7;
  if (piVar4 != (int *)0x0) {
    iVar2 = piVar4[1];
    do {
      piVar5 = piVar4;
      iVar6 = (int)piVar5 + iVar2;
      if (*(uint *)((int)piVar5 + iVar2) == uVar9) {
        iVar2 = iVar6 + 4;
        if ((*(word *)(param_2 + 0x24) & 4) == 0) {
          if (*(sword *)(iVar6 + 4) == *(sword *)(param_2 + 4)) {
            iVar2 = iVar6 + 4;
            (*pcVar10)(iVar2,param_2 + 4);
            if (iVar2 != 0) goto loc_F002D20C;
          }
        }
        else {
          _bcmp(iVar2,param_2 + 4,0x10);
          if (iVar2 == 0) {
loc_F002D20C:
            iVar2 = iVar6 + 0x14;
            _bcmp(iVar2,param_2 + 0x14,0x10);
            piVar4 = piVar5;
            if (iVar2 == 0) break;
          }
        }
      }
      piVar4 = (int *)*piVar5;
      piVar8 = piVar5;
      if (piVar4 == (int *)0x0) break;
      iVar2 = piVar4[1];
    } while( true );
  }
  if (param_1 == -0x7fcf8df6) {
    if (piVar4 == (int *)0x0) {
      if ((*(word *)(param_2 + 0x24) & 2) == 0) {
        iVar6 = 0;
        if ((*(word *)(param_2 + 0x24) & 4) != 0) {
          iVar6 = param_2 + 4;
          _ifa_ifwithdstaddr();
        }
        if (iVar6 == 0) {
          iVar6 = param_2 + 0x14;
          _ifa_ifwithaddr();
          goto loc_F002D308;
        }
      }
      else {
        iVar6 = param_2 + 0x14;
        _ifa_ifwithdstaddr();
loc_F002D308:
        if (iVar6 == 0) {
          iVar6 = param_2 + 0x14;
          _ifa_ifwithnet();
          if (iVar6 == 0) {
            uVar11 = 0x33;
            goto loc_F002D410;
          }
        }
      }
      piVar4 = (int *)0x0;
      _m_get(0,5);
      if (piVar4 == (int *)0x0) {
        uVar11 = 0x37;
      }
      else {
        *piVar4 = *piVar7;
        *piVar7 = (int)piVar4;
        piVar4[1] = 0xc;
        iVar2 = piVar4[1];
        *(undefined2 *)(piVar4 + 2) = 0x30;
        *(uint *)((int)piVar4 + iVar2) = uVar9;
        *(undefined2 *)((int)piVar4 + iVar2 + 4) = *(undefined2 *)(param_2 + 4);
        *(undefined2 *)((int)piVar4 + iVar2 + 6) = *(undefined2 *)(param_2 + 6);
        *(undefined2 *)((int)piVar4 + iVar2 + 8) = *(undefined2 *)(param_2 + 8);
        *(undefined2 *)((int)piVar4 + iVar2 + 10) = *(undefined2 *)(param_2 + 10);
        *(undefined2 *)((int)piVar4 + iVar2 + 0xc) = *(undefined2 *)(param_2 + 0xc);
        *(undefined2 *)((int)piVar4 + iVar2 + 0xe) = *(undefined2 *)(param_2 + 0xe);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x10) = *(undefined2 *)(param_2 + 0x10);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x12) = *(undefined2 *)(param_2 + 0x12);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x14) = *(undefined2 *)(param_2 + 0x14);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x16) = *(undefined2 *)(param_2 + 0x16);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x18) = *(undefined2 *)(param_2 + 0x18);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x1a) = *(undefined2 *)(param_2 + 0x1a);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x1e) = *(undefined2 *)(param_2 + 0x1e);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x20) = *(undefined2 *)(param_2 + 0x20);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x22) = *(undefined2 *)(param_2 + 0x22);
        *(word *)((int)piVar4 + iVar2 + 0x24) = *(word *)(param_2 + 0x24) & 0x16 | 1;
        *(undefined2 *)((int)piVar4 + iVar2 + 0x26) = 0;
        *(undefined4 *)((int)piVar4 + iVar2 + 0x28) = 0;
        *(undefined4 *)((int)piVar4 + iVar2 + 0x2c) = *(undefined4 *)(iVar6 + 0x20);
      }
    }
    else {
      uVar11 = 0x11;
    }
  }
  else if (param_1 == -0x7fcf8df5) {
    if (piVar4 == (int *)0x0) {
      uVar11 = 3;
    }
    else {
      *piVar8 = *piVar4;
      if (*(sword *)(iVar6 + 0x26) < 1) {
        _m_free(piVar4);
      }
      else {
        *(word *)(iVar6 + 0x24) = *(word *)(iVar6 + 0x24) & 0xfffe;
        _rttrash = _rttrash + 1;
        *piVar4 = 0;
      }
    }
  }
loc_F002D410:
  _splx(puVar1);
locret_F002D418:
  return CONCAT44(param_2,uVar11);
}

