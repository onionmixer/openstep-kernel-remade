
/* WARNING: Removing unreachable block (ram,0xf004c1f8) */
/* WARNING: Removing unreachable block (ram,0xf004c1a8) */
/* WARNING: Removing unreachable block (ram,0xf004c128) */
/* WARNING: Removing unreachable block (ram,0xf004c0d8) */
/* WARNING: Removing unreachable block (ram,0xf004c07c) */
/* WARNING: Removing unreachable block (ram,0xf004c044) */
/* WARNING: Removing unreachable block (ram,0xf004bfac) */
/* WARNING: Removing unreachable block (ram,0xf004bf98) */
/* WARNING: Removing unreachable block (ram,0xf004c01c) */
/* WARNING: Removing unreachable block (ram,0xf004c058) */
/* WARNING: Removing unreachable block (ram,0xf004c084) */
/* WARNING: Removing unreachable block (ram,0xf004c110) */
/* WARNING: Removing unreachable block (ram,0xf004c174) */
/* WARNING: Removing unreachable block (ram,0xf004c1c0) */
/* WARNING: Removing unreachable block (ram,0xf004c22c) */
/* WARNING: Removing unreachable block (ram,0xf004bf30) */

undefined8 sub_F004BF10(int param_1,int param_2,int param_3)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
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
  bool bVar5;
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
  wVar1 = *(word *)(param_1 + 0x44);
  iVar3 = 0;
  if ((wVar1 & 1) != 0) {
    do {
      *(word *)(param_1 + 0x44) = wVar1 | 0x10;
      _sleep(param_1,10);
      wVar1 = *(word *)(param_1 + 0x44);
    } while ((wVar1 & 1) != 0);
    wVar1 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = wVar1 | 1;
  if ((*(sword *)(param_1 + 0x66) == 0) || (*(uint *)(param_1 + 0x70) < 0x18)) {
    *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
      _wakeup(param_1);
      iVar3 = 0;
      goto locret_F004C238;
    }
loc_F004C1E4:
    iVar3 = 0;
  }
  else {
    iVar4 = param_1;
    _blkatoff(param_1,0,(undefined *)((int)register0x00000038 + -0xc));
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar4 == 0) {
      iVar3 = (int)*(char *)(dword_F0133DDC + 0x38);
      bVar5 = true;
    }
    else {
      bVar5 = iVar4 == 0;
      if (*(int *)(iVar2 + 0xc) != *(int *)(param_3 + 0x48)) {
        if ((*(sword *)(iVar2 + 0x12) == 2) &&
           ((*(uint *)(iVar2 + 0x14) & 0xffff0000) == 0x2e2e0000)) {
          *(sword *)(param_3 + 0x66) = *(sword *)(param_3 + 0x66) + 1;
          *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 0x40;
          _iupdat(param_3,1);
          _dnlc_remove(param_1 + 0xc,&asc_F010EA60);
          *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) =
               *(undefined4 *)(param_3 + 0x48);
          _dnlc_enter(param_1 + 0xc,&asc_F010EA68,param_3 + 0xc,0);
          _bwrite(iVar4);
          iVar3 = (int)*(char *)(dword_F0133DDC + 0x38);
          iVar4 = 0;
          if (iVar3 == 0) {
            wVar1 = *(word *)(param_1 + 0x44);
            *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) != 0) {
              *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
              _wakeup(param_1);
            }
            if (param_2 == 0) {
              iVar3 = 0;
              goto locret_F004C238;
            }
            wVar1 = *(word *)(param_3 + 0x44);
            *(word *)(param_3 + 0x44) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) == 0) goto loc_F004C130;
            *(word *)(param_3 + 0x44) = wVar1 & 0xffee;
            _wakeup(param_3);
            wVar1 = *(word *)(param_2 + 0x44);
            while ((wVar1 & 1) != 0) {
              *(word *)(param_2 + 0x44) = wVar1 | 0x10;
              _sleep(param_2,10);
loc_F004C130:
              wVar1 = *(word *)(param_2 + 0x44);
            }
            *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 1;
            if (*(sword *)(param_2 + 0x66) != 0) {
              *(sword *)(param_2 + 0x66) = *(sword *)(param_2 + 0x66) + -1;
              *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 0x40;
              _iupdat(param_2,1);
            }
            wVar1 = *(word *)(param_2 + 0x44);
            *(word *)(param_2 + 0x44) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) == 0) goto loc_F004C1C8;
            *(word *)(param_2 + 0x44) = wVar1 & 0xffee;
            _wakeup(param_2);
            wVar1 = *(word *)(param_3 + 0x44);
            while ((wVar1 & 1) != 0) {
              *(word *)(param_3 + 0x44) = wVar1 | 0x10;
              _sleep(param_3,10);
loc_F004C1C8:
              wVar1 = *(word *)(param_3 + 0x44);
            }
            *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 1;
            goto loc_F004C1E4;
          }
        }
        else {
          sub_F004CD8C(param_1,aMangledEntry,0);
          iVar3 = 0x16;
        }
        bVar5 = iVar4 == 0;
      }
    }
    if (bVar5) {
      wVar1 = *(word *)(param_1 + 0x44);
    }
    else {
      _brelse(iVar4);
      wVar1 = *(word *)(param_1 + 0x44);
    }
    *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
  }
locret_F004C238:
  return CONCAT44(param_2,iVar3);
}

