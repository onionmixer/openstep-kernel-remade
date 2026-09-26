/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3d9c */

undefined4 FUN_001a3d9c(char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  
  puVar1 = DAT_001e866c;
  while( true ) {
    if ((undefined4 **)puVar1 == &DAT_001e866c) {
      return 0xfffffd40;
    }
    sVar4 = 0x50;
    pcVar2 = (char *)_objc_msgSend(*puVar1,PTR_s_name_001f9228);
    iVar3 = _strncmp(param_1,pcVar2,sVar4);
    if (iVar3 == 0) break;
    puVar1 = (undefined4 *)puVar1[2];
  }
  *param_2 = *puVar1;
  *param_3 = puVar1[1];
  return 0;
}

