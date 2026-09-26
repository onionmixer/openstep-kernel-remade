
/* WARNING: Removing unreachable block (ram,0xf002f77c) */
/* WARNING: Removing unreachable block (ram,0xf002f774) */
/* WARNING: Removing unreachable block (ram,0xf002f6dc) */
/* WARNING: Removing unreachable block (ram,0xf002f748) */
/* WARNING: Removing unreachable block (ram,0xf002f764) */
/* WARNING: Removing unreachable block (ram,0xf002f6f0) */
/* WARNING: Removing unreachable block (ram,0xf002f608) */

undefined8 _in_addmulti(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  int *piVar4;
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
  iVar2 = *param_1;
  _splnet();
  bVar5 = _in_ifaddr == 0;
  iVar3 = _in_ifaddr;
  if (!bVar5) {
    iVar1 = *(int *)(_in_ifaddr + 0x20);
    while (bVar5 = iVar3 == 0, iVar1 != param_2) {
      iVar3 = *(int *)(iVar3 + 0x40);
      if (iVar3 == 0) {
        bVar5 = true;
        break;
      }
      iVar1 = *(int *)(iVar3 + 0x20);
    }
  }
  if (bVar5) {
    piVar4 = (int *)0x0;
loc_F002F688:
    if (piVar4 == (int *)0x0) goto loc_F002F6A0;
    piVar4[3] = piVar4[3] + 1;
loc_F002F77C:
    _splx(param_1);
  }
  else {
    piVar4 = *(int **)(iVar3 + 0x44);
    if (piVar4 != (int *)0x0) {
      iVar3 = *piVar4;
      while ((iVar3 != iVar2 && (piVar4 = (int *)piVar4[5], piVar4 != (int *)0x0))) {
        iVar3 = *piVar4;
      }
      goto loc_F002F688;
    }
loc_F002F6A0:
    if (_in_ifaddr != 0) {
      iVar1 = *(int *)(_in_ifaddr + 0x20);
      iVar3 = _in_ifaddr;
      while ((iVar1 != param_2 && (iVar3 = *(int *)(iVar3 + 0x40), iVar3 != 0))) {
        iVar1 = *(int *)(iVar3 + 0x20);
      }
      iVar1 = 0;
      if ((iVar3 != 0) && (_m_getclr(0,0xf), iVar1 != 0)) {
        piVar4 = (int *)(iVar1 + *(int *)(iVar1 + 4));
        *(int *)(iVar1 + *(int *)(iVar1 + 4)) = iVar2;
        piVar4[1] = param_2;
        piVar4[3] = 1;
        piVar4[2] = iVar3;
        piVar4[5] = *(int *)(iVar3 + 0x44);
        *(int **)(iVar3 + 0x44) = piVar4;
        *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
        *(int *)((int)register0x00000038 + -0x14) = iVar2;
        if ((*(int *)(param_2 + 0x38) == 0) ||
           (iVar2 = param_2,
           _if_ioctl(param_2,0x80206931,(undefined *)((int)register0x00000038 + -0x28)), iVar2 != 0)
           ) {
          *(int *)(iVar3 + 0x44) = piVar4[5];
          _m_free(iVar1);
          piVar4 = (int *)0x0;
        }
        else {
          _igmp_joingroup(piVar4);
        }
        goto loc_F002F77C;
      }
    }
    _splx(param_1);
    piVar4 = (int *)0x0;
  }
  return CONCAT44(param_2,piVar4);
}

