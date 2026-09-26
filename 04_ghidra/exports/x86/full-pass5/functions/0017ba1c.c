/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ba1c */

undefined4 FUN_0017ba1c(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = 0;
  _lock_read(param_1);
  iVar5 = *(int *)(param_1 + 0x10);
  do {
    if (iVar5 == param_1 + 0xc) {
      _lock_done(param_1);
      return local_8;
    }
    if ((*(byte *)(iVar5 + 0x18) & 5) == 0) {
      uVar1 = *(uint *)(iVar5 + 8);
      if ((uVar1 <= param_3) && (uVar2 = *(uint *)(iVar5 + 0xc), param_2 < uVar2)) {
        if (param_2 < uVar1) {
          param_2 = uVar1;
        }
        uVar4 = param_3;
        if (uVar2 <= param_3) {
          uVar4 = uVar2;
        }
        iVar3 = (*(int *)(iVar5 + 0x14) + param_2) - uVar1;
        iVar3 = FUN_0017bc50(*(undefined4 *)(iVar5 + 0x10),iVar3,(uVar4 + iVar3) - param_2);
        if (iVar3 != 0) goto LAB_0017baa1;
      }
    }
    else {
      iVar3 = FUN_0017ba1c(*(undefined4 *)(iVar5 + 0x10),param_2,param_3);
      if (iVar3 == 5) {
LAB_0017baa1:
        local_8 = 5;
      }
    }
    iVar5 = *(int *)(iVar5 + 4);
  } while( true );
}

