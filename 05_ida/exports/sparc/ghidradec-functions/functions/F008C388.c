
/* WARNING: Removing unreachable block (ram,0xf008c42c) */
/* WARNING: Removing unreachable block (ram,0xf008c400) */
/* WARNING: Removing unreachable block (ram,0xf008c39c) */
/* WARNING: Removing unreachable block (ram,0xf008c394) */
/* WARNING: Removing unreachable block (ram,0xf008c3e8) */
/* WARNING: Removing unreachable block (ram,0xf008c418) */
/* WARNING: Removing unreachable block (ram,0xf008c43c) */
/* WARNING: Removing unreachable block (ram,0xf008c38c) */

undefined8 _autoconf(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined (*pauVar2) [16];
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  sub_F008C44C();
  _IOInitGeneralFuncs();
  _volCheckInit();
  puVar4 = &_pseudo_inits;
  puVar3 = DAT_f012eaf0;
  pauVar2 = paNxconditionloc;
  iVar1 = DAT_f012eaf0._0_4_;
  while (paNxconditionloc = pauVar2, iVar1 != 0) {
    (**(code **)puVar3)(*puVar4);
    puVar3 = (undefined *)((int)puVar3 + 8);
    puVar4 = puVar4 + 2;
    pauVar2 = paNxconditionloc;
    iVar1 = *(int *)puVar3;
  }
  _objc_msgSend(pauVar2,paAlloc);
  dword_F0130FF0 = pauVar2;
  _objc_msgSend();
  _kernel_thread(_IOTask_kern,sub_F008C65C,0);
  _objc_msgSend(dword_F0130FF0,paLockwhen,1);
  _objc_msgSend(dword_F0130FF0,paFree);
  return CONCAT44(param_2,param_1);
}
