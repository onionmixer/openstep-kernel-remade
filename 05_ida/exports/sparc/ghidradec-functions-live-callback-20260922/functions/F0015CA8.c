
/* WARNING: Removing unreachable block (ram,0xf0015ec8) */
/* WARNING: Removing unreachable block (ram,0xf0015e90) */
/* WARNING: Removing unreachable block (ram,0xf0015e44) */
/* WARNING: Removing unreachable block (ram,0xf0015dc4) */
/* WARNING: Removing unreachable block (ram,0xf0015d74) */
/* WARNING: Removing unreachable block (ram,0xf0015d2c) */
/* WARNING: Removing unreachable block (ram,0xf0015d8c) */
/* WARNING: Removing unreachable block (ram,0xf0015e60) */
/* WARNING: Removing unreachable block (ram,0xf0015e04) */
/* WARNING: Removing unreachable block (ram,0xf0015eac) */
/* WARNING: Removing unreachable block (ram,0xf0015eec) */
/* WARNING: Removing unreachable block (ram,0xf0015cc8) */

undefined8 _selcont(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  int iVar8;
  int iVar9;
  undefined4 unaff_l3;
  int *piVar10;
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
  undefined auStackX_0 [92];
  
  iVar2 = dword_F0133DDC;
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
  iVar3 = *(int *)(dword_F0133DDC + 0x124);
  iVar8 = dword_F0133DDC + 0x58;
  piVar10 = *(int **)(dword_F0133DDC + 0x24);
  if (iVar3 < 0) {
    _thread_wait_result();
    if (iVar3 - 2U < 2) {
      *(undefined4 *)(iVar2 + 0x124) = 4;
    }
    else {
      *(undefined4 *)(iVar2 + 0x124) = 0;
    }
  }
  if (*(int *)(iVar2 + 0x124) < 1) {
    while( true ) {
      iVar9 = *_active_u;
      *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) | 0x400000;
      iVar3 = _nselcoll;
      iVar4 = iVar8;
      _selscan(iVar8,iVar2 + 0xb8,*piVar10);
      *(int *)(dword_F0133DDC + 0x30) = iVar4;
      cVar1 = *(char *)(dword_F0133DDC + 0x38);
      *(int *)(iVar2 + 0x124) = (int)cVar1;
      if (cVar1 != 0) break;
      if (*(int *)(dword_F0133DDC + 0x30) != 0) {
        iVar3 = *(int *)(iVar2 + 0x124);
        goto loc_F0015E6C;
      }
      iVar4 = *(int *)(iVar2 + 0x120);
      if (iVar4 != 0) {
        iVar3 = *(int *)(iVar2 + 0x124);
        goto loc_F0015E6C;
      }
      _splusclock();
      if (piVar10[4] == 0) {
        uVar7 = *(uint *)(iVar9 + 0x28);
      }
      else {
        _getthetime((undefined *)((int)register0x00000038 + -0x10));
        iVar6 = *(int *)((int)register0x00000038 + -0x10);
        iVar5 = *(int *)(iVar2 + 0x118);
        if (iVar6 != iVar5 && iVar5 <= iVar6) {
loc_F0015DC4:
          _splx(iVar4);
          iVar3 = *(int *)(iVar2 + 0x124);
          goto loc_F0015E6C;
        }
        if (iVar6 == iVar5) {
          if (*(int *)(iVar2 + 0x11c) <= *(int *)((int)register0x00000038 + -0xc))
          goto loc_F0015DC4;
          uVar7 = *(uint *)(iVar9 + 0x28);
        }
        else {
          uVar7 = *(uint *)(iVar9 + 0x28);
        }
      }
      if (((uVar7 & 0x400000) != 0) && (_nselcoll == iVar3)) {
        *(uint *)(iVar9 + 0x28) = uVar7 & 0xffbfffff;
        *(undefined4 *)(iVar2 + 0x124) = 0xffffffff;
        if (piVar10[4] != 0) {
          _sleep_with_continuation_and_deadline(&_selwait,0x1a,_selcont,iVar2 + 0x118);
          iVar3 = *(int *)(iVar2 + 0x124);
          goto loc_F0015E6C;
        }
        _sleep_with_continuation(&_selwait,0x1a,_selcont);
        break;
      }
      *(uint *)(iVar9 + 0x28) = uVar7 & 0xffbfffff;
      _splx(iVar4);
    }
    iVar3 = *(int *)(iVar2 + 0x124);
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x124);
  }
loc_F0015E6C:
  uVar7 = *piVar10 + 0x1fU >> 5;
  if (iVar3 == 0) {
    iVar3 = iVar2 + 0xb8;
    if (piVar10[1] != 0) {
      _copyout(iVar3,piVar10[1],uVar7 << 2);
      *(int *)(iVar2 + 0x124) = iVar3;
    }
    iVar3 = iVar2 + 0xd8;
    if (piVar10[2] != 0) {
      _copyout(iVar3,piVar10[2],uVar7 << 2);
      *(int *)(iVar2 + 0x124) = iVar3;
    }
    iVar3 = iVar2 + 0xf8;
    if (piVar10[3] != 0) {
      _copyout(iVar3,piVar10[3],uVar7 << 2);
      *(int *)(iVar2 + 0x124) = iVar3;
    }
  }
  if (*(int *)(iVar2 + 0x124) != 0) {
    *(char *)(dword_F0133DDC + 0x38) = (char)*(int *)(iVar2 + 0x124);
  }
  _unix_syscall_return(*(undefined4 *)(iVar2 + 0x124));
  return CONCAT44(param_2,param_1);
}

