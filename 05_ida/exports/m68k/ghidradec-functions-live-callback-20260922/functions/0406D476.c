
bool sub_406D476(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  _fc_flags_bclr(param_1,0x208);
  if (_fd_polling_mode == 0) {
    _fc_start_timer(param_1,30000000);
  }
  *(undefined4 *)(param_1 + 0x23e) = 0x406d62e;
  *(int *)(param_1 + 0x242) = param_1;
  iVar1 = _sfa_arbitrate(*(undefined4 *)(param_1 + 0x23a),param_1 + 0x23e);
  if (iVar1 != 0) {
    if (_fd_polling_mode == 0) {
      _fd_thread_block(param_1 + 0x18,0x208,param_1 + 0x14);
    }
    else {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
      iVar1 = 0;
      if (0 < param_2) {
        do {
          if ((*(uint *)(param_1 + 0x18) & 0x200) != 0) break;
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_2);
      }
      if (param_2 == iVar1) {
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
      }
    }
  }
  bVar2 = (*(uint *)(param_1 + 0x18) & 8) == 0;
  if (bVar2) {
    _fc_stop_timer(param_1);
  }
  else {
    _sfa_abort(*(undefined4 *)(param_1 + 0x23a),param_1 + 0x23e,2);
  }
  bVar2 = !bVar2;
  if (!bVar2) {
    if (_machine_type == '\0') {
      _disr_shadow = _disr_shadow | 2;
      *(byte *)(_slot_id_bmap + 0x2012004) = _disr_shadow;
    }
    else {
      _fc_flpctl_bset(param_1,0x40);
    }
    if ((*(int *)(*(int *)(param_1 + 0x23a) + 0x12) != 2) &&
       ((*(uint *)(param_1 + 0x18) & 0x20000) != 0)) {
      _install_scanned_intr(0x1a63,_dma_intr,param_1 + 0x26);
    }
  }
  return bVar2;
}

