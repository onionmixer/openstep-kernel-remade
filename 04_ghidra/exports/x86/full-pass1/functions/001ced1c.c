/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ced1c */

int _objc_getClass(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_2c [8];
  undefined4 local_24;
  
  local_24 = param_1;
  iVar1 = _NXHashGet(DAT_001e5600,local_2c);
  if (iVar1 == 0) {
    iVar2 = (*(code *)PTR_FUN_001e561c)(param_1);
    if (iVar2 != 0) {
      iVar1 = _NXHashGet(DAT_001e5600,local_2c);
    }
  }
  return iVar1;
}

