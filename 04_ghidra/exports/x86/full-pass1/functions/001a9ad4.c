/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9ad4 */

int _IOAddToBdevswAt(int param_1,undefined4 param_2,undefined *param_3,undefined *param_4,
                    undefined *param_5,undefined *param_6,char param_7)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  if (param_1 == -1) {
    pcVar2 = (char *)&_bdevsw;
    param_1 = 0;
    if (0 < _nblkdev) {
      do {
        iVar1 = 0x18;
        bVar5 = true;
        pcVar3 = pcVar2;
        pcVar4 = (char *)&DAT_001e512c;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) break;
        param_1 = param_1 + 1;
        pcVar2 = pcVar2 + 0x18;
      } while (param_1 < _nblkdev);
    }
  }
  if ((-1 < param_1) && (param_1 < _nblkdev)) {
    iVar1 = 0x18;
    bVar5 = true;
    pcVar2 = (char *)(&_bdevsw + param_1 * 6);
    pcVar3 = (char *)&DAT_001e512c;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar5);
    if (bVar5) {
      (&_bdevsw)[param_1 * 6] = param_2;
      (&PTR__nodev_001e2cf8)[param_1 * 6] = param_3;
      (&PTR__nodev_001e2cfc)[param_1 * 6] = param_4;
      (&PTR__nodev_001e2d00)[param_1 * 6] = param_5;
      (&PTR__nodev_001e2d04)[param_1 * 6] = param_6;
      (&DAT_001e2d08)[param_1 * 6] = 0;
      if (param_7 == '\0') {
        return param_1;
      }
      (&DAT_001e2d08)[param_1 * 6] = 0x400;
      return param_1;
    }
  }
  return -1;
}

