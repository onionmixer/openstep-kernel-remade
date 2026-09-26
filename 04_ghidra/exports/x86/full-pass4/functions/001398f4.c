/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001398f4 */

bool _stillopen(short param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = (undefined4 *)(&_stable)[(uint)param_1._1_1_ + (uint)(byte)param_1 & 0xf];
      puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if ((*(short *)((int)puVar1 + 0x42) == param_1) && (puVar1[0xb] == param_2)) {
      iVar2 = iVar2 + puVar1[0x19];
    }
  }
  return iVar2 != 0;
}

