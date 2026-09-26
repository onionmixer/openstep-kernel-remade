/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00197134 */

undefined4 FUN_00197134(int param_1)

{
  if (((*(uint *)(param_1 + 0x40) & 0x121) == 0) && (*(int *)(param_1 + 0x18) != 0)) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x20;
    if ((int)*(short *)(&_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2) <
        *(int *)(param_1 + 0x18)) {
      _calloutDispatchUnique(FUN_001971e4,param_1);
    }
    else {
      _ns_timeout(FUN_001971e4,param_1,1000,0,4);
    }
  }
  else if (*(int *)(param_1 + 0x18) <=
           (int)*(short *)(&_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) {
    if ((*(uint *)(param_1 + 0x40) & 0x40) != 0) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffffbf;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x40) & 0x1000);
      _selthreadclear(param_1 + 0x2c);
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffefff;
    }
  }
  return 0;
}

