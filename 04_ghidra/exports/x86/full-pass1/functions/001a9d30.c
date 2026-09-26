/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9d30 */

int _IOAddToCdevsw(undefined *param_1,undefined *param_2,undefined *param_3,undefined *param_4,
                  undefined *param_5,undefined *param_6,undefined4 param_7,undefined *param_8,
                  undefined *param_9,undefined *param_10,undefined *param_11)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined **ppuVar4;
  char *pcVar5;
  bool bVar6;
  
  ppuVar2 = &_cdevsw;
  iVar3 = 0;
  if (0 < _nchrdev) {
    do {
      iVar1 = 0x2c;
      bVar6 = true;
      ppuVar4 = ppuVar2;
      pcVar5 = (char *)&DAT_001e5100;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *(char *)ppuVar4 == *pcVar5;
        ppuVar4 = (undefined **)((int)ppuVar4 + 1);
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) break;
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 0xb;
    } while (iVar3 < _nchrdev);
  }
  if ((-1 < iVar3) && (iVar3 < _nchrdev)) {
    iVar1 = 0x2c;
    bVar6 = true;
    ppuVar2 = &_cdevsw + iVar3 * 0xb;
    pcVar5 = (char *)&DAT_001e5100;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *(char *)ppuVar2 == *pcVar5;
      ppuVar2 = (undefined **)((int)ppuVar2 + 1);
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      (&_cdevsw)[iVar3 * 0xb] = param_1;
      (&PTR__nulldev_001e2f3c)[iVar3 * 0xb] = param_2;
      (&PTR__cnread_001e2f40)[iVar3 * 0xb] = param_3;
      (&PTR__cnwrite_001e2f44)[iVar3 * 0xb] = param_4;
      (&PTR__cnioctl_001e2f48)[iVar3 * 0xb] = param_5;
      (&PTR__nulldev_001e2f4c)[iVar3 * 0xb] = param_6;
      *(undefined4 *)(iVar3 * 0x2c + 0x1e2f50) = param_7;
      (&PTR__cnselect_001e2f54)[iVar3 * 0xb] = param_8;
      (&PTR__nodev_001e2f58)[iVar3 * 0xb] = param_9;
      (&PTR__cngetc_001e2f5c)[iVar3 * 0xb] = param_10;
      (&PTR__cnputc_001e2f60)[iVar3 * 0xb] = param_11;
      return iVar3;
    }
  }
  return -1;
}

