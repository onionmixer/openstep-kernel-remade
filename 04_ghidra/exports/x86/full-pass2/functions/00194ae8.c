/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00194ae8 */

undefined4 _cnioctl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0x20007471) {
    iVar1 = *_active_u;
    iVar3 = _get_posix_proc((int)*(short *)(iVar1 + 0x30));
    _cons_tp = &_cons;
    iVar2 = *(int *)(*(int *)(iVar3 + 0x10) + 8);
    if (*(int *)(iVar2 + 4) == iVar1) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar3 + 0x10) + 8) + 0xc) = 0;
    }
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xbfffffff;
    uVar4 = 0;
  }
  else {
    uVar4 = (*(code *)(&PTR__cnioctl_001e2f48)[(uint)(byte)_cons_tp[0x39] * 0xb])
                      ((int)*(short *)(_cons_tp + 0x38),param_2,param_3,param_4);
  }
  return uVar4;
}

