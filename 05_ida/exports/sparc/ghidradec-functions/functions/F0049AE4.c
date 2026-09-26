
/* WARNING: Removing unreachable block (ram,0xf0049e0c) */
/* WARNING: Removing unreachable block (ram,0xf0049df4) */
/* WARNING: Removing unreachable block (ram,0xf0049dcc) */
/* WARNING: Removing unreachable block (ram,0xf0049d48) */
/* WARNING: Removing unreachable block (ram,0xf0049b84) */
/* WARNING: Removing unreachable block (ram,0xf0049d28) */
/* WARNING: Removing unreachable block (ram,0xf0049cbc) */
/* WARNING: Removing unreachable block (ram,0xf0049c7c) */
/* WARNING: Removing unreachable block (ram,0xf0049c5c) */
/* WARNING: Removing unreachable block (ram,0xf0049bbc) */
/* WARNING: Removing unreachable block (ram,0xf0049b4c) */
/* WARNING: Removing unreachable block (ram,0xf0049b20) */
/* WARNING: Removing unreachable block (ram,0xf0049b3c) */
/* WARNING: Removing unreachable block (ram,0xf0049bb0) */
/* WARNING: Removing unreachable block (ram,0xf0049bc8) */
/* WARNING: Removing unreachable block (ram,0xf0049c6c) */
/* WARNING: Removing unreachable block (ram,0xf0049cb0) */
/* WARNING: Removing unreachable block (ram,0xf0049cdc) */
/* WARNING: Removing unreachable block (ram,0xf0049d34) */
/* WARNING: Removing unreachable block (ram,0xf0049b94) */
/* WARNING: Removing unreachable block (ram,0xf0049d74) */
/* WARNING: Removing unreachable block (ram,0xf0049ddc) */
/* WARNING: Removing unreachable block (ram,0xf0049e00) */
/* WARNING: Removing unreachable block (ram,0xf0049e4c) */
/* WARNING: Removing unreachable block (ram,0xf0049b08) */

undefined8 _alloccgblk(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  if (param_3 == 0) {
    uVar2 = *(uint *)(param_2 + 0x28);
loc_F0049D40:
    param_3 = param_1;
    _mapsearch(param_1,param_2,uVar2,*(undefined4 *)(param_1 + 0x38));
    if ((int)param_3 < 0) {
      iVar6 = 0;
      goto locret_F0049E58;
    }
    *(uint *)(param_2 + 0x28) = param_3;
  }
  else {
    param_3 = param_3 & -*(int *)(param_1 + 0x38);
    .rem(param_3,*(undefined4 *)(param_1 + 0xbc));
    uVar2 = param_1;
    _isblock(param_1,param_2 + 0x3d8,(int)param_3 >> ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f))
    ;
    if (uVar2 == 0) {
      iVar7 = *(int *)(param_1 + 0x7c);
      uVar1 = param_3;
      .umul(param_3,iVar7);
      iVar6 = *(int *)(param_1 + 0xac);
      uVar5 = uVar1;
      .div();
      uVar2 = param_3;
      if (*(int *)(uVar5 * 4 + param_2 + 0x54) != 0) {
        if (*(int *)(param_1 + 0x358) == 0) {
          .umul(iVar6,uVar5);
          uVar2 = iVar6 + -1 + iVar7;
          .div(uVar2,iVar7);
        }
        else {
          iVar8 = param_2 + uVar5 * 0x10 + 0xd4;
          .rem(uVar1,iVar6);
          uVar9 = *(undefined4 *)(param_1 + 0xa8);
          .rem();
          iVar7 = uVar1 << 3;
          .div(iVar7,uVar9);
          iVar6 = iVar7;
          if (iVar7 < 8) {
            iVar3 = iVar7 << 1;
            do {
              if (0 < *(sword *)(iVar3 + iVar8)) break;
              iVar6 = iVar6 + 1;
              iVar3 = iVar3 + 2;
            } while (iVar6 < 8);
          }
          iVar3 = iVar6 << 1;
          if (iVar6 == 8) {
            iVar6 = 0;
            iVar3 = 0;
            if (0 < iVar7) {
              iVar4 = 0;
              do {
                iVar3 = iVar6 << 1;
                if (0 < *(sword *)(iVar4 + iVar8)) goto loc_F0049C48;
                iVar6 = iVar6 + 1;
                iVar4 = iVar4 + 2;
              } while (iVar6 < iVar7);
              iVar3 = iVar6 * 2;
            }
          }
loc_F0049C48:
          if (0 < *(sword *)(iVar8 + iVar3)) {
            uVar1 = uVar5;
            .rem(uVar5,*(undefined4 *)(param_1 + 0x358));
            iVar7 = uVar5 - uVar1;
            .umul(iVar7,*(undefined4 *)(param_1 + 0xac));
            .div();
            iVar3 = iVar3 + uVar1 * 0x10 + param_1;
            if (*(sword *)(iVar3 + 0x35c) == -1) {
              _printf(aPosDIDFsS,uVar1,iVar6,param_1 + 0xd4);
              _panic(aAlloccgblkCylG);
            }
            iVar6 = (int)*(sword *)(iVar3 + 0x35c);
            while( true ) {
              uVar5 = param_1;
              _isblock(param_1,param_2 + 0x3d8,iVar7 + iVar6);
              if (uVar5 != 0) break;
              uVar5 = (uint)*(byte *)(param_1 + iVar6 + 0x560);
              if ((uVar5 == 0) || (0x1a9cU - iVar6 < uVar5)) {
                _printf(aPosDIDFsS_0,uVar1,iVar6,param_1 + 0xd4);
                _panic(aAlloccgblkCanT);
                goto loc_F0049D40;
              }
              iVar6 = iVar6 + uVar5;
            }
            param_3 = iVar7 + iVar6 << ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f);
            goto loc_F0049D68;
          }
        }
      }
      goto loc_F0049D40;
    }
  }
loc_F0049D68:
  _clrblock(param_1,param_2 + 0x3d8,(int)param_3 >> ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f));
  *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + -1;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;
  iVar6 = *(int *)(((int)*(uint *)(param_2 + 0xc) >> ((byte)*(undefined4 *)(param_1 + 0x70) & 0x1f))
                   * 4 + param_1 + 0x2d8) +
          (*(uint *)(param_2 + 0xc) & ~*(uint *)(param_1 + 0x6c)) * 0x10;
  *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -1;
  uVar2 = param_3;
  .umul(param_3,*(undefined4 *)(param_1 + 0x7c));
  uVar9 = *(undefined4 *)(param_1 + 0xac);
  uVar1 = uVar2;
  .div();
  .rem(uVar2,uVar9);
  uVar9 = *(undefined4 *)(param_1 + 0xa8);
  .rem();
  iVar6 = uVar2 << 3;
  .div(iVar6,uVar9);
  iVar6 = iVar6 * 2 + uVar1 * 0x10 + param_2;
  *(sword *)(iVar6 + 0xd4) = *(sword *)(iVar6 + 0xd4) + -1;
  iVar6 = uVar1 * 4 + param_2;
  *(int *)(iVar6 + 0x54) = *(int *)(iVar6 + 0x54) + -1;
  *(char *)(param_1 + 0xd0) = *(char *)(param_1 + 0xd0) + '\x01';
  iVar6 = *(int *)(param_2 + 0xc);
  .umul(iVar6,*(undefined4 *)(param_1 + 0xbc));
  iVar6 = iVar6 + param_3;
locret_F0049E58:
  return CONCAT44(param_2,iVar6);
}
