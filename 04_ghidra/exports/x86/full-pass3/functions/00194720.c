/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194720 */

undefined4 _eisa_id(short param_1,int *param_2)

{
  uchar uVar1;
  int iVar2;
  ushort port;
  
  if (DAT_001e7744 == 0) {
    iVar2 = _strncmp((char *)0xfffd9,&DAT_001e2c54,4);
    if (iVar2 == 0) {
      DAT_001e2c50 = 1;
    }
    DAT_001e7744 = 1;
  }
  if (DAT_001e2c50 != 0) {
    port = param_1 << 0xc | 0xc80;
    uVar1 = _inb(port);
    *(uchar *)((int)param_2 + 3) = uVar1;
    uVar1 = _inb(port + 1);
    *(uchar *)((int)param_2 + 2) = uVar1;
    uVar1 = _inb(port + 2);
    *(uchar *)((int)param_2 + 1) = uVar1;
    uVar1 = _inb(port + 3);
    *(uchar *)param_2 = uVar1;
    if (*param_2 != -1) {
      return 1;
    }
  }
  return 0;
}

