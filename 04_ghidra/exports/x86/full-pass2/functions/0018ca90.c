/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ca90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _loutw(undefined2 param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  
  while (param_3 != 0) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    out(param_1,uVar1);
    LOCK();
    _DAT_001e7728 = _DAT_001e7728 + 1;
    UNLOCK();
    param_3 = param_3 + -1;
  }
  return;
}

