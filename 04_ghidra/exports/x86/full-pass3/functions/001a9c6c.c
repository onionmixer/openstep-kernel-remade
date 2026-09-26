/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9c6c */

int _IOAddToCdevswAt(int param_1,undefined *param_2,undefined *param_3,undefined *param_4,
                    undefined *param_5,undefined *param_6,undefined *param_7,undefined4 param_8,
                    undefined *param_9,undefined *param_10,undefined *param_11,undefined *param_12)

{
  int iVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  char *pcVar4;
  bool bVar5;
  
  if (param_1 == -1) {
    ppuVar2 = &_cdevsw;
    param_1 = 0;
    if (0 < _nchrdev) {
      do {
        iVar1 = 0x2c;
        bVar5 = true;
        ppuVar3 = ppuVar2;
        pcVar4 = (char *)&DAT_001e5100;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *(char *)ppuVar3 == *pcVar4;
          ppuVar3 = (undefined **)((int)ppuVar3 + 1);
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) break;
        param_1 = param_1 + 1;
        ppuVar2 = ppuVar2 + 0xb;
      } while (param_1 < _nchrdev);
    }
  }
  if ((-1 < param_1) && (param_1 < _nchrdev)) {
    iVar1 = 0x2c;
    bVar5 = true;
    ppuVar2 = &_cdevsw + param_1 * 0xb;
    pcVar4 = (char *)&DAT_001e5100;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *(char *)ppuVar2 == *pcVar4;
      ppuVar2 = (undefined **)((int)ppuVar2 + 1);
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      (&_cdevsw)[param_1 * 0xb] = param_2;
      (&PTR__nulldev_001e2f3c)[param_1 * 0xb] = param_3;
      (&PTR__cnread_001e2f40)[param_1 * 0xb] = param_4;
      (&PTR__cnwrite_001e2f44)[param_1 * 0xb] = param_5;
      (&PTR__cnioctl_001e2f48)[param_1 * 0xb] = param_6;
      (&PTR__nulldev_001e2f4c)[param_1 * 0xb] = param_7;
      *(undefined4 *)(param_1 * 0x2c + 0x1e2f50) = param_8;
      (&PTR__cnselect_001e2f54)[param_1 * 0xb] = param_9;
      (&PTR__nodev_001e2f58)[param_1 * 0xb] = param_10;
      (&PTR__cngetc_001e2f5c)[param_1 * 0xb] = param_11;
      (&PTR__cnputc_001e2f60)[param_1 * 0xb] = param_12;
      return param_1;
    }
  }
  return -1;
}

