/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194f0c */

void _rtcput(int param_1,uchar param_2)

{
  byte bVar1;
  int iVar2;
  
  if (DAT_001e36a8 != 0) {
    _outb(0x70,'\n');
    _outb(0x71,'&');
    _outb(0x70,'\v');
    _outb(0x71,'\x02');
    DAT_001e36a8 = 0;
  }
  _outb(0x70,'\v');
  bVar1 = _inb(0x71);
  _outb(0x70,'\v');
  _outb(0x71,bVar1 | 0x80);
  iVar2 = 0;
  do {
    _outb(0x70,(uchar)iVar2);
    _outb(0x71,*(uchar *)(iVar2 + param_1));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  _outb(0x70,'2');
  _outb(0x71,param_2);
  _outb(0x70,'\v');
  _outb(0x71,bVar1 & 0x7f);
  return;
}

