
/* WARNING: Removing unreachable block (ram,0xf0034ec8) */
/* WARNING: Removing unreachable block (ram,0xf0034e04) */
/* WARNING: Removing unreachable block (ram,0xf0034d48) */
/* WARNING: Removing unreachable block (ram,0xf0034edc) */
/* WARNING: Removing unreachable block (ram,0xf0034f08) */
/* WARNING: Removing unreachable block (ram,0xf0034d5c) */
/* WARNING: Removing unreachable block (ram,0xf0034d28) */

undefined8 _tcp_reass(int *param_1,int *param_2,int param_3)

{
  sword sVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
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
  iVar7 = *(int *)(param_1[8] + 0x1c);
  if (param_2 != (int *)0x0) {
    piVar5 = (int *)*param_1;
    if (piVar5 == param_1) {
      piVar3 = (int *)piVar5[1];
    }
    else {
      iVar6 = piVar5[6];
      while (iVar6 == param_2[6] || iVar6 - param_2[6] < 0) {
        piVar5 = (int *)*piVar5;
        if (piVar5 == param_1) {
          piVar3 = (int *)piVar5[1];
          goto loc_F0034CC8;
        }
        iVar6 = piVar5[6];
      }
      piVar3 = (int *)piVar5[1];
    }
loc_F0034CC8:
    if (piVar3 != param_1) {
      iVar6 = (piVar3[6] + (int)*(sword *)((int)piVar3 + 10)) - param_2[6];
      if (iVar6 < 1) {
        piVar5 = (int *)*piVar3;
      }
      else {
        if (*(sword *)((int)param_2 + 10) <= iVar6) {
          DAT_f013a81c._0_4_ = DAT_f013a81c._0_4_ + 1;
          DAT_f013a81c._4_4_ = DAT_f013a81c._4_4_ + (int)*(sword *)((int)param_2 + 10);
          _m_freem(param_3);
          uVar8 = 0;
          goto locret_F0034F14;
        }
        _m_adj(param_3,iVar6);
        *(sword *)((int)param_2 + 10) = *(sword *)((int)param_2 + 10) - (sword)iVar6;
        param_2[6] = param_2[6] + iVar6;
        piVar5 = (int *)*piVar3;
      }
    }
    DAT_f013a81c._16_4_ = DAT_f013a81c._16_4_ + 1;
    DAT_f013a81c._20_4_ = DAT_f013a81c._20_4_ + (int)*(sword *)((int)param_2 + 10);
    param_2[5] = param_3;
    if (piVar5 == param_1) {
loc_F0034E18:
      piVar5 = (int *)piVar5[1];
    }
    else {
      sVar1 = *(sword *)((int)param_2 + 10);
      while( true ) {
        iVar6 = (param_2[6] + (int)sVar1) - piVar5[6];
        if (iVar6 < 1) break;
        if (iVar6 < *(sword *)((int)piVar5 + 10)) {
          piVar5[6] = piVar5[6] + iVar6;
          *(sword *)((int)piVar5 + 10) = *(sword *)((int)piVar5 + 10) - (sword)iVar6;
          _m_adj(piVar5[5]);
          piVar5 = (int *)piVar5[1];
          goto loc_F0034E1C;
        }
        piVar5 = (int *)*piVar5;
        piVar3 = (int *)piVar5[1];
        iVar6 = piVar3[5];
        *(int *)(*piVar3 + 4) = piVar3[1];
        *(int *)piVar3[1] = *piVar3;
        _m_freem(iVar6);
        if (piVar5 == param_1) goto loc_F0034E18;
        sVar1 = *(sword *)((int)param_2 + 10);
      }
      piVar5 = (int *)piVar5[1];
    }
loc_F0034E1C:
    *param_2 = *piVar5;
    param_2[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = param_2;
    *piVar5 = (int)param_2;
  }
  if (*(sword *)(param_1 + 2) < 3) {
    uVar8 = 0;
  }
  else {
    param_2 = (int *)*param_1;
    if (param_2 == param_1) {
      uVar8 = 0;
    }
    else {
      iVar6 = param_1[0x10];
      if (param_2[6] == iVar6) {
        if (*(sword *)(param_1 + 2) == 3) {
          if (*(sword *)((int)param_2 + 10) != 0) {
            uVar8 = 0;
            goto locret_F0034F14;
          }
          iVar4 = (int)*(sword *)((int)param_2 + 10);
          iVar6 = param_1[0x10];
        }
        else {
          iVar4 = (int)*(sword *)((int)param_2 + 10);
        }
        while( true ) {
          param_1[0x10] = iVar6 + iVar4;
          bVar2 = *(byte *)((int)param_2 + 0x21);
          *(int *)(*param_2 + 4) = param_2[1];
          *(int *)param_2[1] = *param_2;
          piVar5 = param_2 + 5;
          uVar8 = bVar2 & 1;
          param_2 = (int *)*param_2;
          if ((*(word *)(iVar7 + 6) & 0x20) == 0) {
            _sbappend(iVar7 + 0x24,*piVar5);
          }
          else {
            _m_freem(*piVar5);
          }
          if ((param_2 == param_1) || (iVar6 = param_1[0x10], param_2[6] != iVar6)) break;
          iVar4 = (int)*(sword *)((int)param_2 + 10);
        }
        _sowakeup(iVar7,iVar7 + 0x24);
      }
      else {
        uVar8 = 0;
      }
    }
  }
locret_F0034F14:
  return CONCAT44(param_2,uVar8);
}
