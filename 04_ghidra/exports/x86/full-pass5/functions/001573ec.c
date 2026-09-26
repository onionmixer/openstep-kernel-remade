/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001573ec */

undefined4 _exception_parse_reply(int param_1)

{
  undefined4 uVar1;
  
  if ((((*(int *)(param_1 + 0x14) == 0x12) && (*(int *)(param_1 + 0x18) == 0x20)) &&
      (*(int *)(param_1 + 0x28) == 0x9c4)) && (*(int *)(param_1 + 0x2c) == _exc_code_proto)) {
    uVar1 = *(undefined4 *)(param_1 + 0x30);
    if ((*(int *)(param_1 + 8) == 0x100) && (_ipc_kmsg_cache == 0)) {
      _ipc_kmsg_cache = param_1;
    }
    else if (*(int *)(param_1 + 8) < 1) {
      _ipc_kmsg_free(param_1);
    }
    else {
      _kfree(param_1,*(int *)(param_1 + 8));
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    _ipc_kmsg_destroy(param_1);
    uVar1 = 0xfffffed3;
  }
  return uVar1;
}

