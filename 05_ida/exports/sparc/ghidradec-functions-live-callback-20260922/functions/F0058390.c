
/* WARNING: Removing unreachable block (ram,0xf0058434) */
/* WARNING: Removing unreachable block (ram,0xf00583d4) */
/* WARNING: Removing unreachable block (ram,0xf00583dc) */
/* WARNING: Removing unreachable block (ram,0xf00583f0) */
/* WARNING: Removing unreachable block (ram,0xf00583b8) */

undefined8 _ipc_mqueue_move(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar4;
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
  iVar4 = param_2 + 4;
  iVar1 = *(int *)(param_2 + 4);
joined_r0xf00583a4:
  do {
    do {
      iVar3 = iVar1;
      if (iVar3 == 0) {
        return CONCAT44(iVar4,param_1 + 8);
      }
      iVar1 = iVar4;
      _ipc_kmsg_queue_next(iVar4,iVar3);
    } while (*(int *)(iVar3 + 0x1c) != param_3);
    _ipc_kmsg_rmqueue(iVar4,iVar3);
    while (iVar2 = param_1 + 8, _ipc_thread_dequeue(), iVar2 != 0) {
      _thread_go();
      if (*(uint *)(iVar3 + 0x18) <= *(uint *)(iVar2 + 0x9c)) {
        *(undefined4 *)(iVar2 + 0x98) = 0;
        *(int *)(iVar2 + 0x9c) = iVar3;
        iVar3 = *(int *)(param_3 + 0x34);
        *(int *)(param_3 + 0x34) = iVar3 + 1;
        *(int *)(iVar2 + 0xa0) = iVar3;
        goto joined_r0xf00583a4;
      }
      *(undefined4 *)(iVar2 + 0x98) = 0x10004004;
      *(undefined4 *)(iVar2 + 0x9c) = *(undefined4 *)(iVar3 + 0x18);
    }
    _ipc_kmsg_enqueue(param_1 + 4,iVar3);
  } while( true );
}

