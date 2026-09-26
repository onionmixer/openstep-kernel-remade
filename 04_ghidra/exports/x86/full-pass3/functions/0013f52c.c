/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f52c */

undefined4 FUN_0013f52c(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_2 + 4);
  if (((uVar1 & 3) == 0) && ((int)(uint)uVar1 <= (int)(0x400 - (param_3 & 0x3ff)))) {
    uVar2 = *(ushort *)(param_2 + 6);
    if ((((uVar2 + 4 & 0xfffffffc) + 8 <= (uint)uVar1) && (uVar2 < 0x100)) &&
       ((_dirchk == 0 || (iVar3 = FUN_0013f5d8(param_2 + 8,(uint)uVar2), iVar3 == 0)))) {
      return 0;
    }
  }
  FUN_0013f5ac(param_1,s_mangled_entry_001ddf05,param_4);
  return 1;
}

