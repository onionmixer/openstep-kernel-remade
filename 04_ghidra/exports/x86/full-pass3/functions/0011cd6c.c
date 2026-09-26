/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cd6c */

int _copen(undefined4 param_1,uint param_2,ushort param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar2 = _falloc();
  if (iVar2 == 0) {
    iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
  }
  else {
    iVar1 = *(int *)(DAT_001e875c + 0x60);
    iVar3 = _vn_open(param_1,0,param_2,~*(ushort *)((int)_active_u + 0x16e) & 0xfff & param_3,
                     &local_8);
    if (iVar3 == 0) {
      *(uint *)(iVar2 + 8) = param_2 & 0xa000004b;
      if (((*(byte *)(*_active_u + 0x16) & 2) != 0) && (*(int *)(local_8 + 0x28) == 1)) {
        *(uint *)(iVar2 + 8) = param_2 & 0xa000004b | 0x40001000;
      }
      *(undefined2 *)(iVar2 + 0xc) = 1;
      *(int *)(iVar2 + 0x18) = local_8;
      *(undefined ***)(iVar2 + 0x14) = &_vnodefops;
      if (*(int *)(local_8 + 0x28) == 8) {
        *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | param_2 & 4;
      }
      *(int *)(_active_u[0x54] + iVar1 * 4) = iVar2;
    }
    else {
      *(undefined4 *)(_active_u[0x54] + iVar1 * 4) = 0;
      _crfree(*(undefined4 *)(iVar2 + 0x20));
      *(undefined2 *)(iVar2 + 0xe) = 0;
      _free_file(iVar2);
    }
  }
  return iVar3;
}

