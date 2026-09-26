
void _lpr_csr_or(byte param_1)

{
  sword sVar1;
  
  if ((_dma_chip == 0x139) && ((bRam0200f000 & 0x80) != 0)) {
    sVar1 = 100;
    do {
      if ((bRam0200f002 & 0x40) != 0) break;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    do {
    } while ((bRam0200f002 & 0x40) != 0);
  }
  bRam0200f000 = param_1 | bRam0200f000;
  return;
}

