
/* WARNING: Removing unreachable block (ram,0xf006487c) */
/* WARNING: Removing unreachable block (ram,0xf00648b4) */
/* WARNING: Removing unreachable block (ram,0xf00648d4) */

undefined8 _exception_parse_reply(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if (*(int *)(param_1 + 0x14) == 0x12) {
    if (*(int *)(param_1 + 0x18) == 0x20) {
      if (*(int *)(param_1 + 0x28) == 0x9c4) {
        if (*(int *)(param_1 + 0x2c) == _exc_code_proto) {
          uVar2 = *(undefined4 *)(param_1 + 0x30);
          if (*(int *)(param_1 + 8) == 0x100) {
            iVar1 = param_1;
            if (_ipc_kmsg_cache == 0) goto locret_F00648E0;
            iVar1 = *(int *)(param_1 + 8);
          }
          else {
            iVar1 = *(int *)(param_1 + 8);
          }
          if (iVar1 < 1) {
            _ipc_kmsg_free(param_1);
            iVar1 = _ipc_kmsg_cache;
          }
          else {
            _kfree(param_1);
            iVar1 = _ipc_kmsg_cache;
          }
          goto locret_F00648E0;
        }
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  _ipc_kmsg_destroy(param_1);
  uVar2 = 0xfffffed3;
  iVar1 = _ipc_kmsg_cache;
locret_F00648E0:
  _ipc_kmsg_cache = iVar1;
  return CONCAT44(param_2,uVar2);
}
