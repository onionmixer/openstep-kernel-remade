
/* WARNING: Removing unreachable block (ram,0xf006bfd4) */
/* WARNING: Removing unreachable block (ram,0xf006bf70) */
/* WARNING: Removing unreachable block (ram,0xf006bf8c) */
/* WARNING: Removing unreachable block (ram,0xf006bfe4) */
/* WARNING: Removing unreachable block (ram,0xf006bf5c) */

undefined8 _cpu_up(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 unaff_l0;
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
  iVar3 = (&_processor_ptr)[param_1];
  do {
    do {
    } while (unk_F0135118._0_4_ != 0);
    puVar1 = unk_F0135118;
    _simple_lock_try();
  } while (puVar1 == (undefined *)0x0);
  _splusclock();
  do {
    do {
    } while (*(int *)(iVar3 + 0x13c) != 0);
    piVar2 = (int *)(iVar3 + 0x13c);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  (&dword_F013476C)[param_1 * 8] = 1;
  DAT_f013c04c = DAT_f013c04c + 1;
  _pset_add_processor(_default_pset,iVar3);
  *(undefined4 *)(iVar3 + 0x114) = 1;
  *(undefined4 *)(iVar3 + 0x13c) = 0;
  _splx(puVar1);
  unk_F0135118._0_4_ = 0;
  return CONCAT44(param_2,param_1);
}
