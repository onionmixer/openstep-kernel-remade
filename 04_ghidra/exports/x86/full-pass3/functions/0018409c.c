/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018409c */

undefined4 _sdsize(short param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_001840ec((int)param_1);
  if (iVar1 != 0) {
    uVar2 = _objc_msgSend(iVar1,PTR_s_blockSize_001f93a8);
    return uVar2;
  }
  return 0xffffffff;
}

