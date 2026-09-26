/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9b90 */

int _IOAddToBdevsw(undefined4 param_1,undefined *param_2,undefined *param_3,undefined *param_4,
                  undefined *param_5,char param_6)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  pcVar2 = (char *)&_bdevsw;
  iVar3 = 0;
  if (0 < _nblkdev) {
    do {
      iVar1 = 0x18;
      bVar6 = true;
      pcVar4 = pcVar2;
      pcVar5 = (char *)&DAT_001e512c;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) break;
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x18;
    } while (iVar3 < _nblkdev);
  }
  if ((-1 < iVar3) && (iVar3 < _nblkdev)) {
    iVar1 = 0x18;
    bVar6 = true;
    pcVar2 = (char *)(&_bdevsw + iVar3 * 6);
    pcVar4 = (char *)&DAT_001e512c;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar6);
    if (bVar6) {
      (&_bdevsw)[iVar3 * 6] = param_1;
      (&PTR__nodev_001e2cf8)[iVar3 * 6] = param_2;
      (&PTR__nodev_001e2cfc)[iVar3 * 6] = param_3;
      (&PTR__nodev_001e2d00)[iVar3 * 6] = param_4;
      (&PTR__nodev_001e2d04)[iVar3 * 6] = param_5;
      (&DAT_001e2d08)[iVar3 * 6] = 0;
      if (param_6 == '\0') {
        return iVar3;
      }
      (&DAT_001e2d08)[iVar3 * 6] = 0x400;
      return iVar3;
    }
  }
  return -1;
}

