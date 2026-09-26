/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010dee4 */

void _ttrstrt(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _spltty();
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ttrstrt_001daf3a);
  }
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  (*(code *)(&PTR__ttstart_001db008)[*(char *)(param_1 + 0x47) * 0xc])(param_1);
  _splx(uVar1);
  return;
}

