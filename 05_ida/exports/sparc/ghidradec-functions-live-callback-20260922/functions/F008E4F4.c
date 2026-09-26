
/* WARNING: Removing unreachable block (ram,0xf008e580) */
/* WARNING: Removing unreachable block (ram,0xf008e600) */
/* WARNING: Removing unreachable block (ram,0xf008e5e4) */
/* WARNING: Removing unreachable block (ram,0xf008e5a8) */
/* WARNING: Removing unreachable block (ram,0xf008e538) */
/* WARNING: Removing unreachable block (ram,0xf008e550) */
/* WARNING: Removing unreachable block (ram,0xf008e5b8) */
/* WARNING: Removing unreachable block (ram,0xf008e5f0) */
/* WARNING: Removing unreachable block (ram,0xf008e578) */
/* WARNING: Removing unreachable block (ram,0xf008e564) */
/* WARNING: Removing unreachable block (ram,0xf008e51c) */

undefined8 -[KernDevice attachInterruptPort:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined6 *puVar1;
  int iVar2;
  undefined5 *puVar3;
  undefined (*pauVar4) [20];
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar6;
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
  if (*(int *)(param_1 + 4) == 0) {
    iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
    _ipc_object_copyin(iVar2,param_3,0x14,(undefined *)((int)register0x00000038 + -0x14));
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0xc);
      _objc_msgSend(iVar2,paInterrupts_0);
      if ((iVar2 == 0) ||
         (_objc_msgSend(iVar2,paCount_0), puVar3 = paList, puVar1 = paAlloc, iVar2 == 0)) {
        _ipc_port_release_send(*(undefined4 *)((int)register0x00000038 + -0x14));
      }
      else {
        iVar6 = 0;
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)((int)register0x00000038 + -0x14);
        _objc_msgSend(puVar3,puVar1);
        _objc_msgSend();
        *(undefined5 **)(param_1 + 8) = puVar3;
        if (0 < iVar2) {
          do {
            iVar5 = *(int *)(param_1 + 8);
            pauVar4 = paKerndeviceinte;
            _objc_msgSend(paKerndeviceinte,paAlloc);
            _objc_msgSend();
            _objc_msgSend(iVar5,paAddobject,pauVar4);
            iVar6 = iVar6 + 1;
            if (iVar5 == 0) {
              _objc_msgSend(param_1,paDetachinterrup);
              _ipc_port_release_send(*(undefined4 *)(param_1 + 4));
              *(undefined4 *)(param_1 + 4) = 0;
              goto loc_F008E58C;
            }
          } while (iVar6 < iVar2);
        }
      }
    }
    else {
      param_1 = 0;
    }
  }
  else {
loc_F008E58C:
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}

