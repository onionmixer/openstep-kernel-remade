
/* WARNING: Removing unreachable block (ram,0xf0047b90) */
/* WARNING: Removing unreachable block (ram,0xf0047c00) */
/* WARNING: Removing unreachable block (ram,0xf0047b7c) */
/* WARNING: Removing unreachable block (ram,0xf0047c10) */
/* WARNING: Removing unreachable block (ram,0xf0047c8c) */
/* WARNING: Removing unreachable block (ram,0xf0047c24) */

undefined8 sub_F0047AEC(int *param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
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
  iVar4 = *(int *)(*param_1 + 0x30);
  wVar1 = *(word *)(iVar4 + 0x42);
  switch(*(undefined4 *)(*param_1 + 0x28)) {
  case :
    iVar5 = (int)(sword)wVar1;
    if (wVar1 >> 8 < _nblkdev) {
      (**(code **)(_bdevsw + (uint)(wVar1 >> 8) * 0x18))(iVar5,param_2);
    }
    else {
      iVar5 = 6;
    }
    bVar6 = false;
    if (iVar5 == 0) {
      _set_blocksize(iVar4,(int)(sword)wVar1);
      bVar6 = true;
    }
    goto loc_F0047CAC;
  case :
  case :
    *(word *)((int)register0x00000038 + -10) = wVar1;
    while (wVar1 = *(word *)((int)register0x00000038 + -10), wVar1 >> 8 < _nchrdev) {
      iVar3 = (int)(sword)wVar1;
      iVar5 = *param_1;
      while (iVar2 = iVar3, _isclosing(iVar3,*(undefined4 *)(iVar5 + 0x28)), iVar2 != 0) {
        _sleep(iVar4,0x28);
        iVar5 = *param_1;
      }
      iVar5 = iVar3;
      (**(code **)(_cdevsw + (uint)(wVar1 >> 8) * 0x2c))
                (iVar3,param_2,(undefined *)((int)register0x00000038 + -10));
      if (*(sword *)((int)register0x00000038 + -10) == iVar3) goto loc_F0047CA8;
      if (((iVar5 != 0) && (iVar5 != 0xb)) && (bVar6 = iVar5 == 0, iVar5 != 0x11))
      goto loc_F0047CAC;
      iVar5 = *param_1;
      _specvp(iVar5,(int)*(sword *)((int)register0x00000038 + -10),4);
      iVar4 = *(int *)(iVar5 + 0x30);
      _vn_rele(*param_1);
      *param_1 = iVar5;
    }
    iVar5 = 6;
    goto locret_F0047CC0;
  :
    iVar5 = 0;
    break;
  case :
    _printf(aSpecOpenGotAVf);
  case :
    iVar5 = 0x2d;
  }
loc_F0047CA8:
  bVar6 = iVar5 == 0;
loc_F0047CAC:
  if (bVar6) {
    *(int *)(iVar4 + 100) = *(int *)(iVar4 + 100) + 1;
  }
locret_F0047CC0:
  return CONCAT44(param_2,iVar5);
}

