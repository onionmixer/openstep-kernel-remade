/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116e58 */

int _bind(int param_1,sockaddr *param_2,socklen_t param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _getsock(*puVar1);
  iVar4 = 0;
  if (iVar3 != 0) {
    uVar2 = _sockargs(&local_8,puVar1[1],puVar1[2],8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    iVar4 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      uVar2 = _sobind(*(undefined4 *)(iVar3 + 0x18),local_8);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
      iVar4 = _m_freem(local_8);
    }
  }
  return iVar4;
}

