/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123440 */

void _inet_hash(int param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = _in_netof(*(undefined4 *)(param_1 + 4));
  if (uVar2 != 0) {
    cVar1 = (char)uVar2;
    while (cVar1 == '\0') {
      cVar1 = (char)(uVar2 >> 8);
      uVar2 = uVar2 >> 8;
    }
  }
  param_2[1] = uVar2;
  uVar2 = *(uint *)(param_1 + 4);
  *param_2 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  return;
}

