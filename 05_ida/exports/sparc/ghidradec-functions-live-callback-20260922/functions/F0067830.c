
/* WARNING: Removing unreachable block (ram,0xf00678bc) */
/* WARNING: Removing unreachable block (ram,0xf0067874) */
/* WARNING: Removing unreachable block (ram,0xf00678a0) */
/* WARNING: Removing unreachable block (ram,0xf0067848) */

undefined8 _mach_ports_lookup(int param_1,int *param_2,undefined4 *param_3)

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
  if (param_1 == 0) {
    uVar5 = 4;
  }
  else {
    iVar1 = 0x10;
    _kalloc();
    if (iVar1 == 0) {
      uVar5 = 6;
    }
    else {
      do {
        do {
        } while (*(int *)(param_1 + 100) != 0);
        piVar2 = (int *)(param_1 + 100);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      if (*(int *)(param_1 + 0x68) == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        _kfree(iVar1,0x10);
        uVar5 = 4;
      }
      else {
        iVar4 = 0;
        iVar3 = param_1;
        do {
          uVar5 = *(undefined4 *)(iVar3 + 0x78);
          _ipc_port_copy_send();
          *(undefined4 *)(iVar4 + iVar1) = uVar5;
          iVar3 = iVar3 + 4;
          iVar4 = iVar4 + 4;
        } while (iVar3 <= param_1 + 0xc);
        *(undefined4 *)(param_1 + 100) = 0;
        *param_2 = iVar1;
        *param_3 = 4;
        uVar5 = 0;
      }
    }
  }
  return CONCAT44(param_2,uVar5);
}

