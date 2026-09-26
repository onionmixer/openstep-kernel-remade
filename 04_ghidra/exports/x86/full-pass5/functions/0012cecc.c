/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cecc */

int _findexport(void *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _exported;
  do {
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = _bcmp((void *)(iVar2 + 0x20),param_1,8);
    if (iVar3 == 0) {
      uVar1 = **(ushort **)(iVar2 + 0x28);
      if ((*param_2 == uVar1) &&
         (iVar3 = _bcmp(*(ushort **)(iVar2 + 0x28) + 1,param_2 + 1,(uint)uVar1), iVar3 == 0)) {
        return iVar2;
      }
    }
    iVar2 = *(int *)(iVar2 + 0x2c);
  } while( true );
}

