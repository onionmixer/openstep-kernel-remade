/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5d0c */

int FUN_001a5d0c(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_c;
  undefined *local_8;
  
  piVar2 = &DAT_001e50c4;
  puVar1 = PTR_s_No_Label_001e50c8;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      local_c = param_1;
      local_8 = PTR_s_IODevice_001fa108;
      iVar3 = _objc_msgSendSuper(&local_c,PTR_s_stringFromReturn__001f9490,param_3);
      return iVar3;
    }
    if (*piVar2 == param_3) break;
    puVar1 = (undefined *)piVar2[3];
    piVar2 = piVar2 + 2;
  }
  return piVar2[1];
}

