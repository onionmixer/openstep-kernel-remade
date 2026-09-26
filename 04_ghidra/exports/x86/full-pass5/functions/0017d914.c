/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d914 */

undefined4 * _vswap_allocate(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)0x0;
  iVar4 = 0;
  if (DAT_001e7290 < 2) {
    if (DAT_001e7290 == 1) {
      puVar3 = DAT_001e7288;
    }
  }
  else {
    uVar2 = 0;
    do {
      if ((undefined4 **)DAT_001e7288 != &DAT_001e7288) {
        puVar1 = DAT_001e7288;
        do {
          if ((((1 < (int)uVar2) || (puVar1[0xb] != 0)) &&
              (((uVar2 & 1) != 0 || (*(undefined ***)(puVar1[2] + 0x1c) == &_ufs_vnodeops)))) &&
             (iVar4 < (int)puVar1[6])) {
            puVar3 = puVar1;
            iVar4 = puVar1[6];
          }
          puVar1 = (undefined4 *)*puVar1;
        } while ((undefined4 **)puVar1 != &DAT_001e7288);
      }
    } while ((puVar3 == (undefined4 *)0x0) && (uVar2 = uVar2 + 1, (int)uVar2 < 4));
  }
  return puVar3;
}

