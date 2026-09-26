
/* WARNING: Removing unreachable block (ram,0xf00103f8) */
/* WARNING: Removing unreachable block (ram,0xf00103a4) */

undefined8 _getrusage(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar2;
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
  piVar2 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar2;
  if (iVar1 == -1) {
    iVar1 = _active_u + 0x1b4;
  }
  else {
    if (iVar1 != 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F001040C;
    }
    _thread_read_times(_active_threads,(undefined *)((int)register0x00000038 + -0x18),
                       (undefined *)((int)register0x00000038 + -0x10));
    iVar1 = _active_u;
    *(undefined4 *)(_active_u + 0x16c) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(iVar1 + 0x170) = *(undefined4 *)((int)register0x00000038 + -0x14);
    iVar1 = _active_u;
    *(undefined4 *)(_active_u + 0x174) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(iVar1 + 0x178) = *(undefined4 *)((int)register0x00000038 + -0xc);
    iVar1 = _active_u + 0x16c;
  }
  _copyout(iVar1,piVar2[1],0x48);
  *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
locret_F001040C:
  return CONCAT44(param_2,param_1);
}

