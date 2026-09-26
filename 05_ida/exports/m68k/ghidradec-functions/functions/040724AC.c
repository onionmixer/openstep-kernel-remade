
/* WARNING: Switch with 1 destination removed at 0x04072532 */

void _lpr_send(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_D0;
  sword sVar1;
  sword sVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int unaff_A2;
  char in_XF;
  undefined auStack_14 [8];
  
  puVar4 = auStack_14;
  uVar3 = CONCAT22((sword)((uint)in_D0 >> 0x10),
                   (word)(byte)(in_XF << 4 | (unaff_A2 < 0) << 3 | (unaff_A2 == 0) << 2));
  do {
    *(undefined4 *)(puVar4 + 4) = uVar3;
    puVar4 = (undefined *)0x200f000;
    sVar1 = 100;
    do {
      if (((bRam0200f002 & 0x20) == 0) || ((bRam0200f002 & 0x10) == 0)) break;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    uVar3 = param_2;
    if ((_dma_chip == 0x139) && ((bRam0200f000 & 0x80) != 0)) {
      sVar1 = 1;
      do {
        sVar2 = 100;
        do {
          if ((bRam0200f002 & 0x40) != 0) break;
          sVar2 = sVar2 + -1;
        } while (sVar2 != -1);
        do {
        } while ((bRam0200f002 & 0x40) != 0);
        sVar1 = sVar1 + -1;
      } while (sVar1 != -1);
    }
  } while( true );
}
