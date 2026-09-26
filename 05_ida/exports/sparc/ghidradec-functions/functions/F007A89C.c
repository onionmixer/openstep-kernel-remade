
/* WARNING: Removing unreachable block (ram,0xf007a950) */
/* WARNING: Removing unreachable block (ram,0xf007a938) */
/* WARNING: Removing unreachable block (ram,0xf007a920) */
/* WARNING: Removing unreachable block (ram,0xf007a8f0) */
/* WARNING: Removing unreachable block (ram,0xf007a8cc) */
/* WARNING: Removing unreachable block (ram,0xf007a914) */
/* WARNING: Removing unreachable block (ram,0xf007a92c) */
/* WARNING: Removing unreachable block (ram,0xf007a944) */
/* WARNING: Removing unreachable block (ram,0xf007a960) */
/* WARNING: Removing unreachable block (ram,0xf007a8b4) */

undefined8 _kern_serv_shutdown(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar5 = *param_1;
  if (*(int *)(iVar5 + 0x4d0) == 0) {
    iVar1 = *(int *)(iVar5 + 0x30);
  }
  else {
    _objc_unregisterModule(*(int *)(iVar5 + 0x4d0),0);
    iVar1 = *(int *)(iVar5 + 0x30);
  }
  if (iVar1 != 0) {
    sub_F007ACEC(iVar5 + 0x24);
    *(undefined4 *)(iVar5 + 0x30) = 0;
  }
  iVar4 = 0;
  iVar1 = iVar5;
  do {
    if (*(int *)(iVar1 + 0x18c) != 0) {
      _port_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8));
      *(undefined4 *)(iVar1 + 0x18c) = 0;
      *(undefined4 *)(iVar1 + 400) = 0;
    }
    iVar4 = iVar4 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar4 < 0x32);
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x14));
  _port_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x1c));
  _port_set_deallocate_EXTERNAL(*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x20));
  _kfree(*(undefined4 *)(iVar5 + 0x44),*(undefined4 *)(iVar5 + 0x48));
  uVar3 = 0x4d4;
  _kfree(iVar5,0x4d4);
  uVar2 = _active_threads;
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return CONCAT44(uVar3,uVar2);
}
