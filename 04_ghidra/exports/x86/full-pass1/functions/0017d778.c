/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d778 */

void _vnode_pager_shutdown(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = DAT_001e7288;
  while ((undefined4 **)puVar2 != &DAT_001e7288) {
    DAT_001e7288 = puVar2;
    _vn_rele(puVar2[2]);
    puVar1 = (undefined4 *)*puVar2;
    puVar2 = (undefined4 *)puVar2[1];
    puVar3 = puVar2;
    if ((undefined4 **)puVar1 != &DAT_001e7288) {
      puVar1[1] = puVar2;
      puVar3 = DAT_001e728c;
    }
    DAT_001e728c = puVar3;
    if ((undefined4 **)puVar2 != &DAT_001e7288) {
      *puVar2 = puVar1;
      puVar1 = DAT_001e7288;
    }
    DAT_001e7288 = puVar1;
    DAT_001e7290 = DAT_001e7290 + -1;
    puVar2 = DAT_001e7288;
  }
  DAT_001e7288 = puVar2;
  return;
}

