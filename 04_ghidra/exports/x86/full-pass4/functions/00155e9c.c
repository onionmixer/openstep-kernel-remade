/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155e9c */

undefined4 _port_type(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [4];
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    return 4;
  }
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_c);
  if ((iVar1 == 0) &&
     (iVar1 = _ipc_right_info(param_1,param_2,local_c,&local_8,local_10), iVar1 == 0)) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
  }
  if (iVar1 != 0) {
    return 4;
  }
  local_8 = local_8 & 0x1f0000;
  if (local_8 == 0x30000) {
LAB_00155f3c:
    uVar2 = 7;
  }
  else {
    if (local_8 < 0x30001) {
      if (local_8 != 0x10000) {
        if (local_8 != 0x20000) goto LAB_00155f4c;
        goto LAB_00155f3c;
      }
    }
    else {
      if (local_8 == 0x80000) {
        uVar2 = 9;
        goto LAB_00155f56;
      }
      if (local_8 < 0x80001) {
        if (local_8 != 0x40000) {
LAB_00155f4c:
                    /* WARNING: Subroutine does not return */
          _panic(s_convert_port_type__strange_port_t_001deafd);
        }
      }
      else if (local_8 != 0x100000) goto LAB_00155f4c;
    }
    uVar2 = 1;
  }
LAB_00155f56:
  *param_3 = uVar2;
  return 0;
}

