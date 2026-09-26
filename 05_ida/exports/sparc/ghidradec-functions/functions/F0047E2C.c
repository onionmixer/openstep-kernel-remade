
/* WARNING: Removing unreachable block (ram,0xf004810c) */
/* WARNING: Removing unreachable block (ram,0xf00480f0) */
/* WARNING: Removing unreachable block (ram,0xf0048080) */
/* WARNING: Removing unreachable block (ram,0xf0048000) */
/* WARNING: Removing unreachable block (ram,0xf0047fdc) */
/* WARNING: Removing unreachable block (ram,0xf0048030) */
/* WARNING: Removing unreachable block (ram,0xf0047f98) */
/* WARNING: Removing unreachable block (ram,0xf0047f60) */
/* WARNING: Removing unreachable block (ram,0xf0047ecc) */
/* WARNING: Removing unreachable block (ram,0xf0047e74) */
/* WARNING: Removing unreachable block (ram,0xf0047f50) */
/* WARNING: Removing unreachable block (ram,0xf0047f88) */
/* WARNING: Removing unreachable block (ram,0xf0048040) */
/* WARNING: Removing unreachable block (ram,0xf0047fcc) */
/* WARNING: Removing unreachable block (ram,0xf0048010) */
/* WARNING: Removing unreachable block (ram,0xf0047f38) */
/* WARNING: Removing unreachable block (ram,0xf0048100) */
/* WARNING: Removing unreachable block (ram,0xf00480cc) */
/* WARNING: Removing unreachable block (ram,0xf00480b0) */
/* WARNING: Removing unreachable block (ram,0xf0047e44) */
/* WARNING: Removing unreachable block (ram,0xf0047e68) */

undefined8 sub_F0047E2C(int param_1,int param_2,uint param_3,uint param_4)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  code *pcVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  uint *puVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
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
  iVar8 = *(int *)(param_1 + 0x30);
  wVar1 = *(word *)(iVar8 + 0x42);
  if (1 < param_3) {
    _panic(aSpecRdwr);
  }
  if (param_3 == 0) {
    if (*(int *)(param_2 + 0x14) != 0) {
      _smark(iVar8,4);
      iVar10 = *(int *)(param_1 + 0x28);
      goto loc_F0047E80;
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x28);
loc_F0047E80:
    if (iVar10 == 4) {
      if (param_3 == 0) {
        pcVar6 = *(code **)(DAT_f011c9f8 + (uint)(wVar1 >> 8) * 0x2c);
      }
      else {
        _smark(iVar8,0x42);
        pcVar6 = *(code **)(DAT_f011c9f8 + (uint)(wVar1 >> 8) * 0x2c + 4);
      }
      iVar2 = (int)(sword)wVar1;
      (*pcVar6)(iVar2,param_2);
      goto locret_F0048138;
    }
    iVar2 = 0x2d;
    if (iVar10 != 3) goto locret_F0048138;
    if (*(int *)(param_2 + 0x14) != 0) {
      puVar9 = *(uint **)(iVar8 + 0x3c);
      iVar10 = *(int *)(param_2 + 8);
      while( true ) {
        iVar2 = iVar10;
        .udiv(iVar10,0x2000);
        .urem(iVar10,0x2000);
        iVar7 = 0x2000 - iVar10;
        if (*(int *)(param_2 + 0x14) < 0x2000 - iVar10) {
          iVar7 = *(int *)(param_2 + 0x14);
        }
        iVar3 = 0x2000;
        .udiv(0x2000,*(undefined4 *)(iVar8 + 0x48));
        iVar4 = iVar2;
        .umul(iVar2,iVar3);
        _rablock = iVar4 + iVar3;
        _rasize = 0x2000;
        puVar5 = puVar9;
        if (param_3 == 0) {
          if (iVar4 < 0) {
            puVar5 = (uint *)0x2000;
            _geteblk();
            _bzero(puVar5[8],puVar5[5]);
            puVar5[10] = 0;
          }
          else if (*(int *)(iVar8 + 0x44) + 1 == iVar2) {
            _breada(puVar9,iVar4,0x2000,_rablock,0x2000);
          }
          else {
            _bread(puVar9,iVar4,0x2000);
          }
          *(int *)(iVar8 + 0x44) = iVar2;
        }
        else if (iVar7 == 0x2000) {
          _getblk(puVar9,iVar4,0x2000);
        }
        else {
          _bread(puVar9,iVar4,0x2000);
        }
        if ((int)(puVar5[5] - puVar5[10]) < iVar7) {
          iVar7 = puVar5[5] - puVar5[10];
        }
        if ((*puVar5 & 4) != 0) break;
        iVar2 = puVar5[8] + iVar10;
        _uiomove(iVar2,iVar7,param_3,param_2);
        if (param_3 == 0) {
          if (iVar7 + iVar10 == 0x2000) {
            *puVar5 = *puVar5 | 0x80;
          }
          _brelse(puVar5);
        }
        else {
          if ((param_4 & 4) == 0) {
            if (iVar7 + iVar10 == 0x2000) {
              *puVar5 = *puVar5 | 0x80;
              _bawrite();
            }
            else {
              _bdwrite(puVar5);
            }
          }
          else {
            _bwrite(puVar5);
          }
          _smark(iVar8,0x42);
        }
        if (((iVar2 != 0) || (*(int *)(param_2 + 0x14) < 1)) || (iVar7 == 0)) goto locret_F0048138;
        iVar10 = *(int *)(param_2 + 8);
      }
      iVar2 = 5;
      _brelse(puVar5,iVar7);
      goto locret_F0048138;
    }
  }
  iVar2 = 0;
locret_F0048138:
  return CONCAT44(param_2,iVar2);
}
