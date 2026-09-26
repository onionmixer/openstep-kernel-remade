
/* WARNING: Removing unreachable block (ram,0xf004cba0) */
/* WARNING: Removing unreachable block (ram,0xf004cb6c) */
/* WARNING: Removing unreachable block (ram,0xf004cb30) */
/* WARNING: Removing unreachable block (ram,0xf004ca88) */
/* WARNING: Removing unreachable block (ram,0xf004ca30) */
/* WARNING: Removing unreachable block (ram,0xf004c92c) */
/* WARNING: Removing unreachable block (ram,0xf004c880) */
/* WARNING: Removing unreachable block (ram,0xf004c8e8) */
/* WARNING: Removing unreachable block (ram,0xf004c958) */
/* WARNING: Removing unreachable block (ram,0xf004ca50) */
/* WARNING: Removing unreachable block (ram,0xf004cb1c) */
/* WARNING: Removing unreachable block (ram,0xf004cb3c) */
/* WARNING: Removing unreachable block (ram,0xf004cb88) */
/* WARNING: Removing unreachable block (ram,0xf004cbd4) */
/* WARNING: Removing unreachable block (ram,0xf004c868) */

undefined8 _dirremove(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  sword sVar2;
  word wVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
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
  pcVar4 = param_2;
  _strlen();
  if (pcVar4 == (char *)0x0) {
    _panic(aDirremove);
    cVar1 = *param_2;
  }
  else {
    cVar1 = *param_2;
  }
  if (cVar1 == '.') {
    if (pcVar4 == (char *)0x1) {
      iVar9 = 0x16;
      goto locret_F004CBE0;
    }
    if (pcVar4 == (char *)0x2) {
      if (param_2[1] == '.') {
        iVar9 = 0x42;
        goto locret_F004CBE0;
      }
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  }
  wVar3 = *(word *)(param_1 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  while ((wVar3 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar3 | 0x10;
    _sleep(param_1,10);
    wVar3 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  iVar7 = 0x14;
  if ((*(word *)(param_1 + 100) & 0xf000) != 0x4000) goto loc_F004CB5C;
  iVar9 = param_1;
  _iaccess(param_1,0xc0);
  iVar5 = *(int *)((int)register0x00000038 + -0x24);
  if (iVar9 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x20) = 2;
    iVar9 = param_1;
    sub_F004BA68(param_1,param_2,pcVar4,(undefined *)((int)register0x00000038 + -0x20),
                 (undefined *)((int)register0x00000038 + -0x24));
    iVar5 = *(int *)((int)register0x00000038 + -0x24);
    if (iVar9 == 0) {
      if (iVar5 == 0) {
loc_F004C988:
        iVar7 = 2;
        goto loc_F004CB5C;
      }
      if (param_3 == 0) {
        wVar3 = *(word *)(param_1 + 100);
      }
      else {
        if (param_3 != iVar5) goto loc_F004C988;
        wVar3 = *(word *)(param_1 + 100);
      }
      if ((wVar3 & 0x200) == 0) {
        iVar7 = *(int *)((int)register0x00000038 + -0x24);
loc_F004C9E4:
        iVar5 = *(int *)(iVar7 + 0x18);
      }
      else {
        sVar2 = *(sword *)(*(int *)(_active_u + 0x1c) + 2);
        iVar7 = *(int *)((int)register0x00000038 + -0x24);
        if ((sVar2 == 0) || (sVar2 == *(sword *)(param_1 + 0x68))) goto loc_F004C9E4;
        if (*(sword *)(*(int *)((int)register0x00000038 + -0x24) + 0x68) != sVar2) {
          iVar7 = 1;
          goto loc_F004CB5C;
        }
        iVar5 = *(int *)(iVar7 + 0x18);
      }
      if (iVar5 == 0) {
        if ((param_4 == 0) || ((*(word *)(iVar7 + 100) & 0xf000) != 0x4000)) {
loc_F004CA50:
          _dnlc_remove(param_1 + 0xc,param_2);
          puVar8 = *(undefined4 **)((int)register0x00000038 + -0x10);
          if ((*(uint *)((int)register0x00000038 + -0x1c) & 0x3ff) == 0) {
            *puVar8 = 0;
          }
          else {
            *(sword *)((int)puVar8 + (4 - *(int *)((int)register0x00000038 + -0x18))) =
                 *(sword *)((int)puVar8 + (4 - *(int *)((int)register0x00000038 + -0x18))) +
                 *(sword *)(puVar8 + 1);
          }
          _bwrite(*(undefined4 *)((int)register0x00000038 + -0x14));
          *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
          iVar5 = *(int *)((int)register0x00000038 + -0x24);
          *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
          *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 0x40;
          iVar7 = (int)*(char *)(dword_F0133DDC + 0x38);
          if ((iVar7 == 0) && (iVar7 = iVar9, 0 < *(sword *)(iVar5 + 0x66))) {
            if (param_4 == 0) {
              iVar6 = *(int *)((int)register0x00000038 + -0x24);
            }
            else {
              iVar6 = *(int *)((int)register0x00000038 + -0x24);
              if ((*(word *)(iVar5 + 100) & 0xf000) == 0x4000) {
                *(sword *)(iVar5 + 0x66) = *(sword *)(iVar5 + 0x66) + -2;
                *(sword *)(param_1 + 0x66) = *(sword *)(param_1 + 0x66) + -1;
                _dnlc_remove(iVar5 + 0xc,&asc_F010EB18);
                _dnlc_remove(*(int *)((int)register0x00000038 + -0x24) + 0xc,&asc_F010EB20);
                _itrunc(*(undefined4 *)((int)register0x00000038 + -0x24),0);
                iVar5 = *(int *)((int)register0x00000038 + -0x24);
                goto loc_F004CB60;
              }
            }
            *(sword *)(iVar6 + 0x66) = *(sword *)(iVar6 + 0x66) + -1;
          }
        }
        else if (*(sword *)(iVar7 + 0x66) == 2) {
          sub_F004CDC4(iVar7,*(undefined4 *)(param_1 + 0x48));
          if (iVar7 != 0) goto loc_F004CA50;
          iVar7 = 0x42;
        }
        else {
          iVar7 = 0x42;
        }
      }
      else {
        iVar7 = 0x10;
      }
loc_F004CB5C:
      iVar5 = *(int *)((int)register0x00000038 + -0x24);
      iVar9 = iVar7;
    }
  }
loc_F004CB60:
  if (iVar5 == 0) {
    iVar7 = *(int *)((int)register0x00000038 + -0x14);
  }
  else {
    _iput();
    iVar7 = *(int *)((int)register0x00000038 + -0x14);
    if (*(sword *)(*(int *)((int)register0x00000038 + -0x24) + 0x66) == 0) {
      _vnode_uncache(*(int *)((int)register0x00000038 + -0x24) + 0xc);
      iVar7 = *(int *)((int)register0x00000038 + -0x14);
    }
  }
  if (iVar7 == 0) {
    wVar3 = *(word *)(param_1 + 0x44);
  }
  else {
    _brelse();
    wVar3 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = wVar3 & 0xfffe;
  if ((wVar3 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar3 & 0xffee;
    _wakeup(param_1);
  }
locret_F004CBE0:
  return CONCAT44(param_2,iVar9);
}
