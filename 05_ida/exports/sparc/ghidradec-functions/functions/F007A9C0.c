
/* WARNING: Removing unreachable block (ram,0xf007aa7c) */
/* WARNING: Removing unreachable block (ram,0xf007aa58) */
/* WARNING: Removing unreachable block (ram,0xf007aa3c) */
/* WARNING: Removing unreachable block (ram,0xf007aa20) */
/* WARNING: Removing unreachable block (ram,0xf007aa48) */
/* WARNING: Removing unreachable block (ram,0xf007aa60) */
/* WARNING: Removing unreachable block (ram,0xf007aa9c) */
/* WARNING: Removing unreachable block (ram,0xf007a9dc) */

undefined8 _kern_serv_get_log(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 uVar5;
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
  piVar4 = (int *)*param_1;
  if (piVar4[0xc] == 0) {
    _port_deallocate_EXTERNAL(piVar4[2],param_2);
    uVar5 = 0x65;
  }
  else {
    iVar2 = piVar4[9];
    if (piVar4[10] == iVar2) {
      piVar4[6] = param_2;
    }
    else {
      uVar3 = (piVar4[10] - iVar2) + _page_mask & ~_page_mask;
      _vm_read_EXTERNAL(piVar4[0x133],iVar2,uVar3,(undefined *)((int)register0x00000038 + -0xc),
                        (undefined *)((int)register0x00000038 + -0x10));
      _kern_serv_log_data(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                          piVar4[10] - piVar4[9] >> 5);
      _port_deallocate_EXTERNAL(piVar4[2],param_2);
      iVar2 = piVar4[2];
      _vm_deallocate_EXTERNAL(iVar2,*(undefined4 *)((int)register0x00000038 + -0xc),uVar3);
      _splusclock();
      do {
        do {
        } while (*piVar4 != 0);
        piVar1 = piVar4;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      *piVar4 = 0;
      piVar4[10] = piVar4[9];
      _splx(iVar2);
    }
    uVar5 = 0;
  }
  return CONCAT44(param_2,uVar5);
}
