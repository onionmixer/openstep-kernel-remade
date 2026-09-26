/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001138c8 */

undefined4 _syselect(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(_active_u + 0x168) == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 6;
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)(&PTR__cnselect_001e2f54)[(uint)*(byte *)(_active_u + 0x16d) * 0xb])
                      ((int)*(short *)(_active_u + 0x16c),param_2);
  }
  return uVar1;
}

