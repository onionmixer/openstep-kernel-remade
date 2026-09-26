
/* WARNING: Removing unreachable block (ram,0xf003caa0) */
/* WARNING: Removing unreachable block (ram,0xf003cb60) */
/* WARNING: Removing unreachable block (ram,0xf003cb24) */
/* WARNING: Removing unreachable block (ram,0xf003cae8) */
/* WARNING: Removing unreachable block (ram,0xf003ca38) */
/* WARNING: Removing unreachable block (ram,0xf003c9f8) */
/* WARNING: Removing unreachable block (ram,0xf003c980) */
/* WARNING: Removing unreachable block (ram,0xf003c810) */
/* WARNING: Removing unreachable block (ram,0xf003c7e8) */
/* WARNING: Removing unreachable block (ram,0xf003c7fc) */
/* WARNING: Removing unreachable block (ram,0xf003c94c) */
/* WARNING: Removing unreachable block (ram,0xf003c998) */
/* WARNING: Removing unreachable block (ram,0xf003ca10) */
/* WARNING: Removing unreachable block (ram,0xf003ca4c) */
/* WARNING: Removing unreachable block (ram,0xf003cb10) */
/* WARNING: Removing unreachable block (ram,0xf003cb38) */
/* WARNING: Removing unreachable block (ram,0xf003cb6c) */
/* WARNING: Removing unreachable block (ram,0xf003cab8) */
/* WARNING: Removing unreachable block (ram,0xf003c7d4) */

undefined8
_rfscall(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
        int *param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
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
  DAT_f013a9b8._0_4_ = DAT_f013a9b8._0_4_ + 1;
  iVar2 = *(int *)(DAT_f013a9b8 + param_2 * 4 + 8);
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_3;
  *(int *)(DAT_f013a9b8 + param_2 * 4 + 8) = iVar2 + 1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  bVar1 = false;
  iVar10 = *(int *)((int)register0x00000038 + 0x5c);
  iVar2 = *(int *)(param_1 + 0x2c) << ((byte)*(undefined2 *)(unk_F010CF0E + param_2 * 2) & 0x1f);
  iVar9 = 0;
  do {
    iVar3 = param_1;
    sub_F003C3AC(param_1,iVar10);
    if (param_2 == 9) {
      _clntkudp_once();
    }
    do {
      iVar7 = 0;
      iVar4 = iVar2;
      .div(iVar2,10);
      *(int *)((int)register0x00000038 + -0x20) = iVar4;
      iVar5 = iVar2;
      .rem(iVar2,10);
      *(int *)((int)register0x00000038 + -0x1c) = iVar5 * 100000;
      *(int *)((int)register0x00000038 + -0x28) = iVar4;
      *(int *)((int)register0x00000038 + -0x24) = iVar5 * 100000;
      iVar4 = iVar3;
      (*(code *)**(undefined4 **)(iVar3 + 4))
                (iVar3,param_2,*(undefined4 *)((int)register0x00000038 + -0x2c),param_4,param_5,
                 param_6,(undefined *)((int)register0x00000038 + -0x28));
      switch(iVar4) {
      case :
      case :
      case :
      case :
      case :
      case :
      case :
loc_F003C988:
        bVar11 = iVar7 == 0;
        break;
      :
        if (iVar4 == 0x12) {
          bVar11 = (*(uint *)(param_1 + 0x14) & 0xa0000000) != 0x80000000;
          if (bVar11) {
            *(undefined4 *)((int)register0x00000038 + -0x18) = 0x12;
            *(undefined4 *)((int)register0x00000038 + -0x14) = 4;
            iVar7 = 0;
            goto loc_F003C910;
          }
        }
        else {
          iVar7 = -(*(int *)(param_1 + 0x14) >> 0x1f);
          bVar11 = iVar7 == 0;
loc_F003C910:
          if (!bVar11) {
            iVar5 = iVar2 * 4;
            iVar2 = 300;
            if (iVar5 < 0x12d) {
              iVar2 = iVar5;
            }
            if ((*(uint *)(param_1 + 0x14) & 0x40000000) == 0) {
              *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
              _printf(aNfsServerSNotR,param_1 + 0x34);
            }
            bVar11 = iVar7 == 0;
            if (!bVar1) {
              if (*(int *)(_active_u + 0x164) != 0) {
                bVar1 = true;
                _uprintf(aNfsServerSNotR_0,param_1 + 0x34);
              }
              goto loc_F003C988;
            }
          }
        }
      }
    } while (!bVar11);
    _clntkudp_once(iVar3,0);
    if (iVar4 != 0) {
      DAT_f013a9b8._4_4_ = DAT_f013a9b8._4_4_ + 1;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x10000000;
      if (iVar4 != 0x12) {
        *(int *)((int)register0x00000038 + -0x18) = iVar4;
        *(undefined4 *)((int)register0x00000038 + -0x14) = 0x16;
        param_2 = param_2 * 4;
        uVar8 = *(undefined4 *)(_rfsnames + param_2);
        iVar2 = iVar4;
        _clnt_sperrno(iVar4);
        _printf(aNfsSFailedForS,uVar8,param_1 + 0x34,iVar2);
        if (*(int *)(_active_u + 0x164) != 0) {
          uVar8 = *(undefined4 *)(_rfsnames + param_2);
          _clnt_sperrno(iVar4);
          _uprintf(aNfsSFailedForS_0,uVar8,param_1 + 0x34,iVar4);
        }
      }
      goto loc_F003CB24;
    }
    if (param_6 == (int *)0x0) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (*param_6 != 0xd) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (iVar9 != 0) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (*(sword *)(iVar10 + 2) != 0) {
      uVar6 = *(uint *)(param_1 + 0x14);
      goto loc_F003CAC8;
    }
    if (*(sword *)(iVar10 + 6) == 0) {
      uVar6 = *(uint *)(param_1 + 0x14);
loc_F003CAC8:
      if ((int)uVar6 < 0) {
        if ((uVar6 & 0x40000000) != 0) {
          _printf(aNfsServerSOk,param_1 + 0x34);
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xbfffffff;
        }
        if (bVar1) {
          _uprintf(aNfsServerSOk_0,param_1 + 0x34);
        }
      }
      else {
        *(uint *)(param_1 + 0x14) = uVar6 & 0xefffffff;
      }
loc_F003CB24:
      sub_F003C6F0(iVar3);
      iVar2 = *(int *)((int)register0x00000038 + -0x18);
      if (iVar9 != 0) {
        _crfree(iVar9);
        iVar2 = *(int *)((int)register0x00000038 + -0x18);
      }
      uVar8 = *(undefined4 *)((int)register0x00000038 + -0x14);
      if ((iVar2 != 0) && (*(int *)((int)register0x00000038 + -0x14) == 0)) {
        _printf(aRfscallReStatu);
        _panic(&aRfscall);
        uVar8 = *(undefined4 *)((int)register0x00000038 + -0x14);
      }
      return CONCAT44(param_2,uVar8);
    }
    _crdup();
    *(undefined2 *)(iVar10 + 2) = *(undefined2 *)(iVar10 + 6);
    sub_F003C6F0(iVar3);
    iVar9 = iVar10;
  } while( true );
}
