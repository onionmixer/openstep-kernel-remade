
/* WARNING: Removing unreachable block (ram,0xf00babbc) */
/* WARNING: Removing unreachable block (ram,0xf00bab68) */
/* WARNING: Removing unreachable block (ram,0xf00baa84) */
/* WARNING: Removing unreachable block (ram,0xf00ba9e4) */
/* WARNING: Removing unreachable block (ram,0xf00ba9c8) */
/* WARNING: Removing unreachable block (ram,0xf00ba9d8) */
/* WARNING: Removing unreachable block (ram,0xf00ba98c) */
/* WARNING: Removing unreachable block (ram,0xf00baa64) */
/* WARNING: Removing unreachable block (ram,0xf00bab4c) */
/* WARNING: Removing unreachable block (ram,0xf00bac00) */
/* WARNING: Removing unreachable block (ram,0xf00ba9bc) */

undefined8 _zsa_process(int *param_1,undefined4 param_2)

{
  uint uVar1;
  word wVar3;
  sword sVar4;
  int iVar2;
  int iVar5;
  undefined uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  byte *pbVar8;
  sword sVar9;
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
  iVar7 = *param_1;
  pbVar8 = *(byte **)(*(int *)(iVar7 + 0x34) + 0x10);
  if (*(sword *)((int)param_1 + 10) != 0) {
    *(undefined2 *)((int)param_1 + 10) = 0;
    if ((*pbVar8 & 8) == 0) {
      if (*(char *)((int)&_zssoftCAR + (*(word *)(iVar7 + 0x38) & 0x1f)) != '\0') {
        uVar1 = *(uint *)(iVar7 + 0x40);
        goto loc_F00BA980;
      }
      if ((*(uint *)(iVar7 + 0x40) & 0x40000000) != 0) {
        uVar1 = *(uint *)(iVar7 + 0x40);
        goto loc_F00BA980;
      }
      if ((*(uint *)(iVar7 + 0x40) & 0x10) == 0) {
loc_F00BA9EC:
        uVar1 = *(uint *)(iVar7 + 0x40);
      }
      else {
        if ((*(uint *)(iVar7 + 0x3c) & 0x1000000) == 0) {
          _gsignal((int)*(sword *)(iVar7 + 0x44),1);
          _gsignal((int)*(sword *)(iVar7 + 0x44),0x13);
          _zsmctl(iVar7,0x80,2);
          _ttyflush(iVar7,3);
          goto loc_F00BA9EC;
        }
        uVar1 = *(uint *)(iVar7 + 0x40);
      }
      uVar1 = uVar1 & 0xffffffef;
    }
    else {
      uVar1 = *(uint *)(iVar7 + 0x40);
loc_F00BA980:
      if ((uVar1 & 0x10) != 0) {
        sVar4 = *(sword *)(param_1 + 2);
        goto loc_F00BA9FC;
      }
      _wakeup(iVar7 + 0x40);
      uVar1 = *(uint *)(iVar7 + 0x40) | 0x10;
    }
    *(uint *)(iVar7 + 0x40) = uVar1;
  }
  sVar4 = *(sword *)(param_1 + 2);
loc_F00BA9FC:
  if (sVar4 == 0) {
    sVar4 = *(sword *)((int)param_1 + 6);
  }
  else {
    *(undefined2 *)(param_1 + 2) = 0;
    *(undefined2 *)(param_1 + 0x44) = 0;
    *(undefined2 *)((int)param_1 + 0x112) = 0;
    sVar4 = *(sword *)((int)param_1 + 6);
  }
  if ((sVar4 != 0) && ((*pbVar8 & 0x80) == 0)) {
    *(undefined2 *)((int)param_1 + 6) = 0;
    wVar3 = *(word *)(iVar7 + 0x38);
    if (wVar3 == _kbddev) {
      if (wVar3 == _rconsdev) {
        _kbdreset(iVar7);
      }
    }
    else if ((wVar3 & 0x1f) == 3) {
      _mstrynextbaudrate(iVar7);
    }
    else if ((*(uint *)(iVar7 + 0x40) & 4) != 0) {
      uVar6 = 0;
      if ((*(uint *)(iVar7 + 0x3c) & 0x20) == 0) {
        uVar6 = *(undefined *)(iVar7 + 0x4f);
      }
      (**(code **)(DAT_f010b8e0 + *(char *)(iVar7 + 0x47) * 0x30))(uVar6,iVar7);
    }
  }
  iVar2 = 0;
  sVar4 = *(sword *)((int)param_1 + 0x112);
  do {
    sVar9 = (sword)iVar2;
    iVar5 = (int)sVar4;
    if (iVar5 == *(sword *)(param_1 + 0x44)) {
loc_F00BAB98:
      sVar4 = *(sword *)(param_1 + 0x46);
    }
    else {
      *(sword *)((int)param_1 + 0x112) = (sword)(iVar5 + 1);
      uVar6 = *(undefined *)((int)param_1 + iVar5 + 0xf);
      if (0xff < (iVar5 + 1) * 0x10000 >> 0x10) {
        *(undefined2 *)((int)param_1 + 0x112) = 0;
      }
      if ((*(uint *)(iVar7 + 0x40) & 4) == 0) {
        sVar4 = *(sword *)(param_1 + 0x46);
      }
      else {
        wVar3 = *(word *)(iVar7 + 0x38) & 0x1f;
        if (wVar3 == 3) {
          _msinput(uVar6,iVar7);
          sVar4 = *(sword *)(param_1 + 0x46);
        }
        else {
          if (wVar3 != 2) {
            (**(code **)(DAT_f010b8e0 + *(char *)(iVar7 + 0x47) * 0x30))(uVar6,iVar7);
            goto loc_F00BAB98;
          }
          _kbdIntHandler(uVar6,iVar7);
          sVar4 = *(sword *)(param_1 + 0x46);
        }
      }
    }
    if (sVar4 < 1) {
      if ((*(uint *)(iVar7 + 0x40) & 0x20) == 0) {
        sVar4 = *(sword *)((int)param_1 + 0x112);
      }
      else {
        _ndflush(iVar7 + 0x18,(int)*(sword *)((int)param_1 + 0x11a));
        *(uint *)(iVar7 + 0x40) = *(uint *)(iVar7 + 0x40) & 0xffffffdf;
        if (*(char *)(iVar7 + 0x47) == 0) {
          _zsstart(iVar7);
          sVar4 = *(sword *)((int)param_1 + 0x112);
        }
        else {
          (**(code **)(DAT_f010b8e0 + *(char *)(iVar7 + 0x47) * 0x30 + 0xc))(iVar7);
          sVar4 = *(sword *)((int)param_1 + 0x112);
        }
      }
    }
    else {
      sVar4 = *(sword *)((int)param_1 + 0x112);
    }
    iVar2 = iVar2 + 1;
    if ((sVar4 == *(sword *)(param_1 + 0x44)) ||
       (sVar9 = (sword)iVar2, 0x13 < iVar2 * 0x10000 >> 0x10)) {
      return CONCAT44(param_2,(uint)(0x13 < sVar9));
    }
    sVar4 = *(sword *)((int)param_1 + 0x112);
  } while( true );
}

