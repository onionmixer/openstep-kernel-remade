
/* WARNING: Removing unreachable block (ram,0xf008a5a8) */
/* WARNING: Removing unreachable block (ram,0xf008a584) */
/* WARNING: Removing unreachable block (ram,0xf008a560) */
/* WARNING: Removing unreachable block (ram,0xf008a520) */
/* WARNING: Removing unreachable block (ram,0xf008a538) */
/* WARNING: Removing unreachable block (ram,0xf008a568) */
/* WARNING: Removing unreachable block (ram,0xf008a59c) */
/* WARNING: Removing unreachable block (ram,0xf008a5d8) */
/* WARNING: Removing unreachable block (ram,0xf008a510) */

undefined8 _fake_u(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
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
  iVar4 = *(int *)(*(int *)(param_2 + 0xc) + 0x38);
  iVar3 = *(int *)(param_2 + 0x84);
  _bcopy(iVar4 + 8,param_1 + 8,0x11);
  _bcopy(iVar3 + 4,param_1 + 0x1c,0x20);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iVar4 + 0x1c);
  _bcopy(iVar4 + 0x30,param_1 + 0x70,0x84);
  iVar1 = param_1 + 0x6a4;
  *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(iVar3 + 0x44);
  *(undefined4 *)(param_1 + 0x69c) = *(undefined4 *)(iVar4 + 0x164);
  *(undefined2 *)(param_1 + 0x6a0) = *(undefined2 *)(iVar4 + 0x168);
  _memcpy(iVar1,iVar4 + 0x16c,0x48);
  _splusclock();
  do {
    do {
    } while (*(int *)(param_2 + 0x20) != 0);
    piVar2 = (int *)(param_2 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  _thread_read_times(param_2,(undefined *)((int)register0x00000038 + -0x18),
                     (undefined *)((int)register0x00000038 + -0x10));
  *(undefined4 *)(param_2 + 0x20) = 0;
  _splx(iVar1);
  *(undefined4 *)(param_1 + 0x6ac) = *(undefined4 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_1 + 0x6b0) = *(undefined4 *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(param_1 + 0x6a4) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(param_1 + 0x6a8) = *(undefined4 *)((int)register0x00000038 + -0x14);
  _memcpy(param_1 + 0x6ec,iVar4 + 0x1b4,0x48);
  return CONCAT44(param_2,param_1);
}

