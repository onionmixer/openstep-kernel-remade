/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b674 */

int _sethostname(char *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar4 = _suser();
  uVar2 = DAT_001e875c;
  uVar5 = 0;
  if (iVar4 != 0) {
    if ((uint)puVar1[1] < 0x100) {
      _hostnamelen = puVar1[1];
      uVar3 = _copyin(*puVar1,&_hostname,puVar1[1]);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
      uVar5 = _hostnamelen;
      (&_hostname)[_hostnamelen] = 0;
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      uVar5 = uVar2;
    }
  }
  return uVar5;
}

