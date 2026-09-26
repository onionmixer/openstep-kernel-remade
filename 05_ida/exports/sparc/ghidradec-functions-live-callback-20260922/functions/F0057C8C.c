
/* WARNING: Removing unreachable block (ram,0xf0057d78) */
/* WARNING: Removing unreachable block (ram,0xf0057d94) */
/* WARNING: Removing unreachable block (ram,0xf0057d14) */

undefined8 _ipc_marequest_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if ((_ipc_marequest_size == 0) &&
     (_ipc_marequest_size = _ipc_marequest_max >> 8, _ipc_marequest_size < 0x10)) {
    _ipc_marequest_size = 0x10;
  }
  _ipc_marequest_mask = _ipc_marequest_size - 1;
  if ((_ipc_marequest_size & _ipc_marequest_mask) != 0) {
    uVar4 = 1;
    for (_ipc_marequest_mask = _ipc_marequest_mask | 1;
        _ipc_marequest_size = _ipc_marequest_mask + 1,
        (_ipc_marequest_size & _ipc_marequest_mask) != 0;
        _ipc_marequest_mask = _ipc_marequest_mask | uVar4) {
      uVar4 = uVar4 << 1;
    }
  }
  iVar1 = _ipc_marequest_size << 3;
  _kalloc();
  uVar4 = _ipc_marequest_size;
  uVar3 = 0;
  iVar5 = iVar1;
  _ipc_marequest_table = iVar1;
  if (_ipc_marequest_size != 0) {
    do {
      *(undefined4 *)(iVar1 + uVar3 * 8) = 0;
      *(undefined4 *)(iVar5 + 4) = 0;
      uVar3 = uVar3 + 1;
      iVar5 = iVar5 + 8;
    } while (uVar3 < uVar4);
  }
  uVar2 = 0x10;
  _zinit(0x10,_ipc_marequest_max << 4,0x10,0,aIpcMsgAccepted);
  _ipc_marequest_zone = uVar2;
  _zchange();
  return CONCAT44(param_2,param_1);
}

