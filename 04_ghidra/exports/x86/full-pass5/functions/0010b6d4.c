/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b6d4 */

int _getdomainname(char *param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (*(undefined4 **)(DAT_001e875c + 0x24))[1];
  if (_domainnamelen + 1U < uVar2) {
    uVar2 = _domainnamelen + 1U;
  }
  uVar1 = _copyout(&_domainname,**(undefined4 **)(DAT_001e875c + 0x24),uVar2);
  iVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  return iVar3;
}

