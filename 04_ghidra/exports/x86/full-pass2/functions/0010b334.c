/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b334 */

undefined4 _itimerfix(uint *param_1)

{
  uint uVar1;
  
  if ((*param_1 < 0x5f5e101) && (uVar1 = param_1[1], uVar1 < 1000000)) {
    if ((*param_1 == 0) && ((uVar1 != 0 && ((int)uVar1 < (int)_tick)))) {
      param_1[1] = _tick;
    }
    return 0;
  }
  return 0x16;
}

