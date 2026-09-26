/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf4fc */

void FUN_001cf4fc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  uint local_8;
  
  iVar1 = _getsectdatafromheaderinfo(param_1,"__OBJC","__string_object",&local_8);
  if ((iVar1 != 0) && (local_8 != 0)) {
    uVar2 = _objc_getClass("NXConstantString");
    for (local_c = 0; local_c < local_8 / 0xc; local_c = local_c + 1) {
      *(undefined4 *)(iVar1 + local_c * 0xc) = uVar2;
    }
  }
  return;
}

