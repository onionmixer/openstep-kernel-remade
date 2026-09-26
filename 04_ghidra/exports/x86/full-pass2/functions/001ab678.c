/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab678 */

undefined4 FUN_001ab678(int param_1)

{
  undefined4 uVar1;
  uint local_c;
  uint local_8;
  
  if ((*(int *)(param_1 + 0x158) == 0) && (*(int *)(param_1 + 0x15c) == 0)) {
    uVar1 = 0;
  }
  else {
    _IOGetTimestamp(&local_c);
    if ((local_8 < *(uint *)(param_1 + 0x15c)) ||
       ((*(uint *)(param_1 + 0x15c) == local_8 && (local_c < *(uint *)(param_1 + 0x158))))) {
      uVar1 = __udivdi3(*(uint *)(param_1 + 0x158) - local_c,
                        (*(int *)(param_1 + 0x15c) - local_8) -
                        (uint)(*(uint *)(param_1 + 0x158) < local_c),1000000,0);
    }
    else {
      *(undefined4 *)(param_1 + 0x158) = 0;
      *(undefined4 *)(param_1 + 0x15c) = 0;
      uVar1 = 0;
    }
  }
  return uVar1;
}

