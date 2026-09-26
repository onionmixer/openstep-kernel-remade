/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cb18 */

undefined4 _unexport(void *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &_exported;
  iVar2 = _exported;
  do {
    if (iVar2 == 0) {
      return 0x16;
    }
    iVar2 = _bcmp((void *)(*piVar3 + 0x20),param_1,8);
    if (iVar2 == 0) {
      uVar1 = **(ushort **)(*piVar3 + 0x28);
      if ((*param_2 == uVar1) &&
         (iVar2 = _bcmp(*(ushort **)(*piVar3 + 0x28) + 1,param_2 + 1,(uint)uVar1), iVar2 == 0)) {
        iVar2 = *piVar3;
        *piVar3 = *(int *)(iVar2 + 0x2c);
        _exportfree(iVar2);
        return 0;
      }
    }
    iVar2 = *piVar3;
    piVar3 = (int *)(iVar2 + 0x2c);
    iVar2 = *(int *)(iVar2 + 0x2c);
  } while( true );
}

