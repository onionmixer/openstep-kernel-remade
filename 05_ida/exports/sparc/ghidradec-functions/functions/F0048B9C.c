
/* WARNING: Removing unreachable block (ram,0xf0048f0c) */
/* WARNING: Removing unreachable block (ram,0xf0048ec8) */
/* WARNING: Removing unreachable block (ram,0xf0048e88) */
/* WARNING: Removing unreachable block (ram,0xf0048e60) */
/* WARNING: Removing unreachable block (ram,0xf0048e2c) */
/* WARNING: Removing unreachable block (ram,0xf0048d9c) */
/* WARNING: Removing unreachable block (ram,0xf0048d70) */
/* WARNING: Removing unreachable block (ram,0xf0048dbc) */
/* WARNING: Removing unreachable block (ram,0xf0048d18) */
/* WARNING: Removing unreachable block (ram,0xf0048f30) */
/* WARNING: Removing unreachable block (ram,0xf0048cb0) */
/* WARNING: Removing unreachable block (ram,0xf0048c88) */
/* WARNING: Removing unreachable block (ram,0xf0048c48) */
/* WARNING: Removing unreachable block (ram,0xf0048c40) */
/* WARNING: Removing unreachable block (ram,0xf0048c7c) */
/* WARNING: Removing unreachable block (ram,0xf0048c94) */
/* WARNING: Removing unreachable block (ram,0xf0048cd0) */
/* WARNING: Removing unreachable block (ram,0xf0048cec) */
/* WARNING: Removing unreachable block (ram,0xf0048db4) */
/* WARNING: Removing unreachable block (ram,0xf0048de0) */
/* WARNING: Removing unreachable block (ram,0xf0048d78) */
/* WARNING: Removing unreachable block (ram,0xf0048e10) */
/* WARNING: Removing unreachable block (ram,0xf0048e48) */
/* WARNING: Removing unreachable block (ram,0xf0048e74) */
/* WARNING: Removing unreachable block (ram,0xf0048eb8) */
/* WARNING: Removing unreachable block (ram,0xf0048eec) */
/* WARNING: Removing unreachable block (ram,0xf0048f44) */
/* WARNING: Removing unreachable block (ram,0xf0048bf8) */
/* WARNING: Removing unreachable block (ram,0xf0048c04) */

undefined8 _realloccg(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar8;
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
  iVar7 = *(int *)(param_1 + 0x50);
  if ((((*(uint *)(iVar7 + 0x30) < param_4) || ((param_4 & ~*(uint *)(iVar7 + 0x4c)) != 0)) ||
      (*(uint *)(iVar7 + 0x30) < param_5)) || ((param_5 & ~*(uint *)(iVar7 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDOs,(int)*(sword *)(param_1 + 0x46),*(undefined4 *)(iVar7 + 0x30),param_4,
            param_5,iVar7 + 0xd4);
    _panic(aRealloccgBadSi);
  }
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
loc_F0048C60:
    if (param_2 == 0) {
      _printf(aDev0xXBsizeDBp,(int)*(sword *)(param_1 + 0x46),*(undefined4 *)(iVar7 + 0x30),0,
              iVar7 + 0xd4);
      _panic(aRealloccgBadBp);
      uVar5 = *(undefined4 *)(iVar7 + 0xbc);
    }
    else {
      uVar5 = *(undefined4 *)(iVar7 + 0xbc);
    }
    iVar1 = param_2;
    .div(param_2,uVar5);
    iVar4 = param_1;
    _fragextend(param_1,iVar1,param_2,param_4,param_5);
    if (iVar4 != 0) {
      uVar5 = *(undefined4 *)(iVar7 + 100);
      while( true ) {
        puVar3 = *(uint **)(param_1 + 0x40);
        _bread(puVar3,iVar4 << ((byte)uVar5 & 0x1f),param_4);
        if ((*puVar3 & 4) != 0) break;
        puVar2 = puVar3;
        _brealloc(puVar3,param_5);
        if (puVar2 != (uint *)0x0) {
          iVar1 = param_5 - param_4;
          *puVar3 = *puVar3 | 2;
          _bzero(puVar3[8] + param_4,iVar1);
          iVar7 = param_1 + 0xc;
          (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar7);
          goto loc_F0048F0C;
        }
        uVar5 = *(undefined4 *)(iVar7 + 100);
      }
      _brelse(puVar3);
      puVar3 = (uint *)0x0;
      goto locret_F0048F50;
    }
    if (*(int *)(iVar7 + 0x24) <= param_3) {
      param_3 = 0;
    }
    if (*(int *)(iVar7 + 0x80) == 0) {
      iVar4 = *(int *)(iVar7 + 0x28);
      .umul(iVar4,*(int *)(iVar7 + 0x3c) + -2);
      .div();
      uVar8 = *(uint *)(iVar7 + 0x30);
      if (iVar4 <= *(int *)(iVar7 + 0xcc)) {
        _log(5,aSOptimizationC_0,iVar7 + 0xd4);
        *(undefined4 *)(iVar7 + 0x80) = 1;
      }
    }
    else {
      uVar8 = param_5;
      if (*(int *)(iVar7 + 0x80) == 1) {
        if (4 < *(int *)(iVar7 + 0x3c)) {
          iVar4 = *(int *)(iVar7 + 0x28);
          .umul();
          .div();
          if (*(int *)(iVar7 + 0xcc) <= iVar4) {
            _log(5,aSOptimizationC,iVar7 + 0xd4);
            *(undefined4 *)(iVar7 + 0x80) = 0;
          }
        }
      }
      else {
        *(undefined4 *)(iVar7 + 0x80) = 1;
      }
    }
    iVar4 = param_1;
    _hashalloc(param_1,iVar1,param_3,uVar8,_alloccg);
    if (0 < iVar4) {
      puVar2 = *(uint **)(param_1 + 0x40);
      _bread(puVar2,param_2 << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),param_4);
      if ((*puVar2 & 4) == 0) {
        puVar3 = *(uint **)(param_1 + 0x40);
        _getblk(puVar3,iVar4 << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),param_5);
        _bcopy(puVar2[8],puVar3[8],param_4);
        iVar1 = param_5 - param_4;
        _bzero(puVar3[8] + param_4,iVar1);
        if ((*puVar2 & 0x200) != 0) {
          *puVar2 = *puVar2 & 0xfffffdff;
          *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + -1;
        }
        _brelse(puVar2);
        _free_block(param_1,param_2,param_4);
        if ((int)param_5 < (int)uVar8) {
          _free_block(param_1,iVar4 + ((int)param_5 >> ((byte)*(undefined4 *)(iVar7 + 0x54) & 0x1f))
                      ,uVar8 - param_5);
          iVar4 = *(int *)(param_1 + 0x28);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x28);
        }
        iVar7 = param_1 + 0xc;
        (**(code **)(iVar4 + 0x80))(iVar7);
loc_F0048F0C:
        .div(iVar1,iVar7);
        *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + iVar1;
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
      }
      else {
        _brelse(puVar2);
        puVar3 = (uint *)0x0;
      }
      goto locret_F0048F50;
    }
  }
  else {
    iVar6 = *(int *)(iVar7 + 0xc4);
    iVar1 = *(int *)(iVar7 + 0x28);
    uVar5 = *(undefined4 *)(iVar7 + 0x60);
    iVar4 = *(int *)(iVar7 + 0xcc);
    .umul(iVar1,*(undefined4 *)(iVar7 + 0x3c));
    .div();
    if (0 < ((iVar6 << ((byte)uVar5 & 0x1f)) + iVar4) - iVar1) goto loc_F0048C60;
  }
  _fsfull(iVar7,1);
  puVar3 = (uint *)0x0;
locret_F0048F50:
  return CONCAT44(param_2,puVar3);
}
