
/* WARNING: Removing unreachable block (ram,0xf00a8b44) */
/* WARNING: Removing unreachable block (ram,0xf00a8aac) */
/* WARNING: Removing unreachable block (ram,0xf00a89e0) */
/* WARNING: Removing unreachable block (ram,0xf00a8a90) */
/* WARNING: Removing unreachable block (ram,0xf00a8adc) */
/* WARNING: Removing unreachable block (ram,0xf00a89d4) */
/* WARNING: Removing unreachable block (ram,0xf00a8980) */

undefined8 _syscall(uint *param_1,undefined4 param_2)

{
  sword sVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  sword *psVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar8;
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
  uVar3 = *param_1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = _active_threads;
  if ((uVar3 & 0x40) != 0) {
    _panic(&aSyscall);
  }
  uVar6 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x28) + 0x84);
  *(uint *)((int)register0x00000038 + -0x20) = param_1[4];
  iVar4 = *_active_u;
  *(undefined4 *)((int)register0x00000038 + -0x14) = uVar6;
  *(int *)((int)register0x00000038 + -0x1c) = iVar4;
  if (iVar4 == 0) {
    _exception(5,0x700,0);
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = _active_u[0x5d];
    *(int *)((int)register0x00000038 + -0xc) = _active_u[0x5e];
    _syncfpu(param_1);
    uVar3 = *(uint *)((int)register0x00000038 + -0x20);
    bVar8 = uVar3 < _nsysent;
    **(int **)((int)register0x00000038 + -0x14) = (int)param_1;
    if (bVar8) {
      *(undefined **)((int)register0x00000038 + -0x24) = _sysent + uVar3 * 8;
    }
    else {
      *(undefined **)((int)register0x00000038 + -0x24) = unk_F010AA00;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    psVar7 = *(sword **)((int)register0x00000038 + -0x24);
    sVar1 = *psVar7;
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    if (sVar1 < 7) {
      iVar4 = *(int *)((int)register0x00000038 + -0x14);
      puVar2 = param_1 + 0xb;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + -0x14);
      *(uint *)(iVar5 + 4) = param_1[0xb];
      *(uint *)(iVar5 + 8) = param_1[0xc];
      *(uint *)(iVar5 + 0xc) = param_1[0xd];
      *(uint *)(iVar5 + 0x10) = param_1[0xe];
      *(uint *)(iVar5 + 0x14) = param_1[0xf];
      *(uint *)(iVar5 + 0x18) = param_1[0x10];
      iVar4 = param_1[0x11] + 0x5c;
      _copyin(iVar4,iVar5 + 0x1c,(*psVar7 + -6) * 4);
      if (iVar4 != 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
        _unix_syscall_return(*(undefined4 *)((int)register0x00000038 + -0x18));
      }
      iVar4 = *(int *)((int)register0x00000038 + -0x14);
      puVar2 = (uint *)(iVar4 + 4);
    }
    *(uint **)(iVar4 + 0x24) = puVar2;
    iVar5 = *(int *)((int)register0x00000038 + -0x14);
    *(undefined4 *)(iVar5 + 0x30) = 0;
    iVar4 = iVar5 + 0x28;
    *(uint *)(iVar5 + 0x34) = param_1[0xc];
    _setjmp();
    if (iVar4 == 0) {
      *(undefined *)(*(int *)((int)register0x00000038 + -0x14) + 0x39) = 3;
      (**(code **)(*(int *)((int)register0x00000038 + -0x24) + 4))
                (*(undefined4 *)(dword_F0133DDC + 0x24));
      *(int *)((int)register0x00000038 + -0x18) =
           (int)*(char *)(*(int *)((int)register0x00000038 + -0x14) + 0x38);
    }
    else if ((*(int *)((int)register0x00000038 + -0x18) == 0) &&
            (*(char *)(*(int *)((int)register0x00000038 + -0x14) + 0x39) != '\x02')) {
      *(undefined4 *)((int)register0x00000038 + -0x18) = 4;
    }
    _unix_syscall_return(*(undefined4 *)((int)register0x00000038 + -0x18));
  }
  return CONCAT44(param_2,param_1);
}
