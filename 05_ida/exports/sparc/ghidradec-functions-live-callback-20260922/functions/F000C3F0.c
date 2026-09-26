
/* WARNING: Removing unreachable block (ram,0xf000c584) */
/* WARNING: Removing unreachable block (ram,0xf000c538) */
/* WARNING: Removing unreachable block (ram,0xf000c4ec) */
/* WARNING: Removing unreachable block (ram,0xf000c474) */
/* WARNING: Removing unreachable block (ram,0xf000c438) */
/* WARNING: Removing unreachable block (ram,0xf000c488) */
/* WARNING: Removing unreachable block (ram,0xf000c514) */
/* WARNING: Removing unreachable block (ram,0xf000c55c) */
/* WARNING: Removing unreachable block (ram,0xf000c4b0) */
/* WARNING: Removing unreachable block (ram,0xf000c42c) */

undefined8 _load_init_program(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = 0;
  do {
    if ((_boothowto & 0x10) != 0) {
      _printf(aInitProgram);
      _gets(_init_program_name,_init_program_name);
    }
    if (((iVar3 != 0) && ((_boothowto & 0x10) == 0)) && (_init_attempts._0_4_ == 1)) {
      _printf(aLoadOfSErrnoDT,_init_program_name,iVar3,aEtcInit);
      iVar3 = 0;
      _bcopy(aEtcInit,_init_program_name,10);
    }
    _init_attempts._0_4_ = _init_attempts._0_4_ + 1;
    if (iVar3 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
      _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),
                   (undefined *)((int)register0x00000038 + -0x1c),_page_size,1);
      if (*(int *)((int)register0x00000038 + -0x1c) == 0) {
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
      }
      _copyout(_init_program_name,*(undefined4 *)((int)register0x00000038 + -0x1c),0x81);
      *(int *)((int)register0x00000038 + -0x18) = *(int *)((int)register0x00000038 + -0x1c);
      uVar1 = *(int *)((int)register0x00000038 + -0x1c) + 0x8fU & 0xfffffff0;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar1;
      _copyout(&_init_args,uVar1,0x80);
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      *(int *)((int)register0x00000038 + -0x14) = *(int *)((int)register0x00000038 + -0x1c);
      uVar1 = *(int *)((int)register0x00000038 + -0x1c) + 0x8fU & 0xfffffff0;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar1;
      _copyout((undefined *)((int)register0x00000038 + -0x18),uVar1,0xc);
      iVar3 = dword_F0133DDC;
      DAT_f0134a44._4_4_ = 0;
      _init_exec_args = *(undefined4 *)((int)register0x00000038 + -0x18);
      DAT_f0134a44._0_4_ = *(undefined4 *)((int)register0x00000038 + -0x1c);
      uVar2 = *(undefined4 *)(dword_F0133DDC + 0x24);
      *(undefined4 **)(dword_F0133DDC + 0x24) = &_init_exec_args;
      _execve();
      *(undefined4 *)(dword_F0133DDC + 0x24) = uVar2;
    }
    else {
      _printf(aLoadOfSFailedE,_init_program_name,iVar3);
      iVar3 = 0;
      _boothowto = _boothowto | 0x10;
    }
  } while (iVar3 != 0);
  return CONCAT44(param_2,aEtcInit);
}

