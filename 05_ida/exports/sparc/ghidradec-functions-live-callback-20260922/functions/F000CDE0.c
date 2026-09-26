
/* WARNING: Removing unreachable block (ram,0xf000ce54) */
/* WARNING: Removing unreachable block (ram,0xf000ce20) */
/* WARNING: Removing unreachable block (ram,0xf000ce38) */
/* WARNING: Removing unreachable block (ram,0xf000ce60) */
/* WARNING: Removing unreachable block (ram,0xf000ce0c) */

undefined8 _wait4(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l3;
  undefined *puVar5;
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
  puVar4 = (undefined *)((int)register0x00000038 + -0x50);
  puVar5 = (undefined *)((int)register0x00000038 + -0x54);
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  puVar1 = (undefined *)puVar3[2];
  _wait1(puVar1,puVar4,puVar5,*puVar3,_wait4);
  if (puVar1 == (undefined *)0x0) {
    iVar2 = puVar3[3];
  }
  else {
    _unix_syscall_return();
    iVar2 = puVar3[3];
  }
  if (iVar2 != 0) {
    _copyout(puVar4,iVar2,0x48);
    puVar1 = puVar4;
  }
  if (puVar3[1] != 0) {
    _copyout(puVar5,puVar3[1],4);
    puVar1 = puVar5;
  }
  _unix_syscall_return(puVar1);
  return CONCAT44(param_2,param_1);
}

