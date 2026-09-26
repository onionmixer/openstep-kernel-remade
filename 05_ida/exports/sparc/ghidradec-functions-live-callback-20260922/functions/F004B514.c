
/* WARNING: Removing unreachable block (ram,0xf004b9f8) */
/* WARNING: Removing unreachable block (ram,0xf004b888) */
/* WARNING: Removing unreachable block (ram,0xf004b85c) */
/* WARNING: Removing unreachable block (ram,0xf004b96c) */
/* WARNING: Removing unreachable block (ram,0xf004b9e0) */
/* WARNING: Removing unreachable block (ram,0xf004b8ec) */
/* WARNING: Removing unreachable block (ram,0xf004b800) */
/* WARNING: Removing unreachable block (ram,0xf004b7c0) */
/* WARNING: Removing unreachable block (ram,0xf004b724) */
/* WARNING: Removing unreachable block (ram,0xf004b6d4) */
/* WARNING: Removing unreachable block (ram,0xf004b664) */
/* WARNING: Removing unreachable block (ram,0xf004b5c4) */
/* WARNING: Removing unreachable block (ram,0xf004b600) */
/* WARNING: Removing unreachable block (ram,0xf004b6b0) */
/* WARNING: Removing unreachable block (ram,0xf004b70c) */
/* WARNING: Removing unreachable block (ram,0xf004b77c) */
/* WARNING: Removing unreachable block (ram,0xf004b7d8) */
/* WARNING: Removing unreachable block (ram,0xf004b8c8) */
/* WARNING: Removing unreachable block (ram,0xf004b914) */
/* WARNING: Removing unreachable block (ram,0xf004b99c) */
/* WARNING: Removing unreachable block (ram,0xf004b8b4) */
/* WARNING: Removing unreachable block (ram,0xf004b87c) */
/* WARNING: Removing unreachable block (ram,0xf004b8a4) */
/* WARNING: Removing unreachable block (ram,0xf004ba58) */
/* WARNING: Removing unreachable block (ram,0xf004b568) */

undefined8
_direnter(int param_1,char *param_2,uint param_3,int param_4,undefined4 param_5,undefined4 param_6)

{
  sword sVar1;
  word wVar2;
  char cVar4;
  int iVar3;
  char *pcVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int *piVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined *puVar9;
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
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  iVar7 = 0;
  piVar8 = *(int **)((int)register0x00000038 + 0x5c);
  if (*param_2 != '\0') {
    cVar4 = *param_2;
    pcVar5 = param_2;
    do {
      pcVar5 = pcVar5 + 1;
      if (cVar4 == '/') {
        iVar6 = 0xd;
        goto locret_F004BA60;
      }
      cVar4 = *pcVar5;
      iVar7 = iVar7 + 1;
    } while (cVar4 != '\0');
  }
  if (iVar7 == 0) {
    _panic(aDirenter);
    cVar4 = *param_2;
  }
  else {
    cVar4 = *param_2;
  }
  if (cVar4 == '.') {
    if (iVar7 == 1) {
loc_F004B5A4:
      if (param_3 == 2) {
        iVar6 = 0x42;
      }
      else if ((piVar8 == (int *)0x0) ||
              (_dirlook(param_1,param_2,piVar8), iVar6 = param_1, param_1 == 0)) {
        iVar6 = 0x11;
      }
      goto locret_F004BA60;
    }
    if (iVar7 == 2) {
      if (param_2[1] == '.') goto loc_F004B5A4;
      *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  }
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  if (param_3 == 0) goto loc_F004B72C;
  iVar6 = *(int *)((int)register0x00000038 + 0x54);
  while ((*(word *)(iVar6 + 0x44) & 1) != 0) {
    *(word *)(iVar6 + 0x44) = *(word *)(iVar6 + 0x44) | 0x10;
    _sleep(iVar6,10);
    iVar6 = *(int *)((int)register0x00000038 + 0x54);
  }
  iVar6 = *(int *)((int)register0x00000038 + 0x54);
  wVar2 = *(word *)(iVar6 + 0x44);
  sVar1 = *(sword *)(iVar6 + 0x66);
  *(word *)(iVar6 + 0x44) = wVar2 | 1;
  if (sVar1 == 0) {
    *(word *)(iVar6 + 0x44) = wVar2 & 0xfffe;
    if ((wVar2 & 0x10) != 0) {
      *(word *)(iVar6 + 0x44) = wVar2 & 0xffee;
      _wakeup(iVar6);
    }
    iVar6 = 2;
    goto locret_F004BA60;
  }
  if (sVar1 == 0x7fff) {
    *(word *)(iVar6 + 0x44) = wVar2 & 0xfffe;
    if ((wVar2 & 0x10) != 0) {
      *(word *)(iVar6 + 0x44) = wVar2 & 0xffee;
      _wakeup(iVar6);
    }
    iVar6 = 0x1f;
    goto locret_F004BA60;
  }
  *(sword *)(iVar6 + 0x66) = sVar1 + 1;
  *(word *)(iVar6 + 0x44) = *(word *)(iVar6 + 0x44) | 0x40;
  _iupdat(iVar6,1);
  iVar6 = *(int *)((int)register0x00000038 + 0x54);
  wVar2 = *(word *)(iVar6 + 0x44);
  *(word *)(iVar6 + 0x44) = wVar2 & 0xfffe;
  if ((wVar2 & 0x10) == 0) goto loc_F004B72C;
  *(word *)(iVar6 + 0x44) = wVar2 & 0xffee;
  _wakeup(iVar6);
  wVar2 = *(word *)(param_1 + 0x44);
  while ((wVar2 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 | 0x10;
    _sleep(param_1,10);
loc_F004B72C:
    wVar2 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  iVar6 = 0x14;
  if ((*(word *)(param_1 + 100) & 0xf000) == 0x4000) {
    if (*(sword *)(param_1 + 0x66) == 0) {
      iVar6 = 2;
      goto loc_F004B9E8;
    }
    iVar6 = param_1;
    _iaccess(param_1,0x40);
    if (iVar6 == 0) {
      if (((param_3 == 2) &&
          (iVar6 = *(int *)((int)register0x00000038 + 0x54),
          (*(word *)(iVar6 + 100) & 0xf000) == 0x4000)) && (param_4 != param_1)) {
        _iaccess(iVar6,0x80);
        iVar3 = *(int *)((int)register0x00000038 + -0x14);
        if (iVar6 == 0) {
          iVar6 = *(int *)((int)register0x00000038 + 0x54);
          sub_F004CEAC(iVar6,param_1);
          iVar3 = *(int *)((int)register0x00000038 + -0x14);
          if (iVar6 == 0) goto loc_F004B7F0;
        }
      }
      else {
loc_F004B7F0:
        puVar9 = (undefined *)((int)register0x00000038 + -0x20);
        iVar6 = param_1;
        sub_F004BA68(param_1,param_2,iVar7,puVar9,(undefined *)((int)register0x00000038 + -0x24));
        if (iVar6 == 0) {
          iVar3 = *(int *)((int)register0x00000038 + -0x24);
          if (iVar3 == 0) {
            iVar6 = param_1;
            _iaccess(param_1,0x80);
            if (iVar6 == 0) {
              if (param_3 == 0) {
                iVar6 = param_1;
                sub_F004C544(param_1,(undefined *)((int)register0x00000038 + 0x54),param_6);
                iVar3 = *(int *)((int)register0x00000038 + -0x14);
                if (iVar6 != 0) goto loc_F004B9EC;
              }
              iVar6 = param_1;
              _diraddentry(param_1,param_2,iVar7,puVar9,
                           *(undefined4 *)((int)register0x00000038 + 0x54),param_4);
              if (iVar6 == 0) {
                if (piVar8 == (int *)0x0) {
                  iVar3 = *(int *)((int)register0x00000038 + -0x14);
                  if (param_3 != 0) goto loc_F004B9EC;
                  _irele(*(undefined4 *)((int)register0x00000038 + 0x54));
                }
                else {
                  iVar7 = *(int *)((int)register0x00000038 + 0x54);
                  while ((*(word *)(iVar7 + 0x44) & 1) != 0) {
                    *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 0x10;
                    _sleep(iVar7,10);
                    iVar7 = *(int *)((int)register0x00000038 + 0x54);
                  }
                  iVar7 = *(int *)((int)register0x00000038 + 0x54);
                  *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 1;
                  *piVar8 = iVar7;
                }
              }
              else {
                iVar3 = *(int *)((int)register0x00000038 + -0x14);
                if (param_3 != 0) goto loc_F004B9EC;
                iVar7 = *(int *)((int)register0x00000038 + 0x54);
                if ((*(word *)(*(int *)((int)register0x00000038 + 0x54) + 100) & 0xf000) == 0x4000)
                {
                  *(sword *)(param_1 + 0x66) = *(sword *)(param_1 + 0x66) + -1;
                  iVar7 = *(int *)((int)register0x00000038 + 0x54);
                }
                *(undefined2 *)(iVar7 + 0x66) = 0;
                *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 0x40;
                _irele();
                *(undefined4 *)((int)register0x00000038 + 0x54) = 0;
              }
              goto loc_F004B9E8;
            }
            iVar3 = *(int *)((int)register0x00000038 + -0x14);
          }
          else {
            if (param_3 == 1) {
              _iput(iVar3);
              iVar6 = 0x11;
              goto loc_F004B9E8;
            }
            if (param_3 < 2) {
              if (piVar8 != (int *)0x0) {
                *piVar8 = iVar3;
                iVar6 = 0x11;
                goto loc_F004B9E8;
              }
              _iput(iVar3);
              iVar3 = *(int *)((int)register0x00000038 + -0x14);
            }
            else if (param_3 == 2) {
              sub_F004BD00(param_4,*(undefined4 *)((int)register0x00000038 + 0x54),param_1,param_2,
                           iVar7,iVar3,puVar9);
              _iput(*(undefined4 *)((int)register0x00000038 + -0x24));
              iVar3 = *(int *)((int)register0x00000038 + -0x14);
              iVar6 = param_4;
              if (*(sword *)(*(int *)((int)register0x00000038 + -0x24) + 0x66) == 0) {
                _vnode_uncache(*(int *)((int)register0x00000038 + -0x24) + 0xc);
                iVar3 = *(int *)((int)register0x00000038 + -0x14);
              }
            }
            else {
              iVar3 = *(int *)((int)register0x00000038 + -0x14);
            }
          }
        }
        else {
          iVar3 = *(int *)((int)register0x00000038 + -0x14);
        }
      }
    }
    else {
      iVar3 = *(int *)((int)register0x00000038 + -0x14);
    }
  }
  else {
loc_F004B9E8:
    iVar3 = *(int *)((int)register0x00000038 + -0x14);
  }
loc_F004B9EC:
  if (iVar3 != 0) {
    _brelse();
  }
  if ((iVar6 != 0) && (iVar7 = *(int *)((int)register0x00000038 + 0x54), param_3 != 0)) {
    *(sword *)(iVar7 + 0x66) = *(sword *)(iVar7 + 0x66) + -1;
    *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 0x40;
  }
  wVar2 = *(word *)(param_1 + 0x44);
  *(word *)(param_1 + 0x44) = wVar2 & 0xfffe;
  if ((wVar2 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 & 0xffee;
    _wakeup(param_1);
  }
locret_F004BA60:
  return CONCAT44(param_2,iVar6);
}

