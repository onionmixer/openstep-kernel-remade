/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ceac */

void _rwuio(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  
  if (((**(uint **)(DAT_001e875c + 0x24) < (uint)_active_u[0x57]) &&
      (iVar1 = *(int *)(_active_u[0x54] + **(uint **)(DAT_001e875c + 0x24) * 4), iVar1 != 0)) &&
     (iVar1 != -0x10000)) {
    if (param_2 == 0) {
      uVar2 = *(uint *)(iVar1 + 8) & 1;
    }
    else {
      uVar2 = *(uint *)(iVar1 + 8) & 2;
    }
    if (uVar2 != 0) {
      param_1[5] = 0;
      param_1[3] = 0;
      iVar6 = *param_1;
      local_c = 0;
      if (0 < param_1[1]) {
        do {
          if ((*(int *)(iVar6 + 4) < 0) ||
             (iVar4 = *(int *)(iVar6 + 4) + param_1[5], param_1[5] = iVar4, iVar4 < 0)) {
            *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
            return;
          }
          iVar6 = iVar6 + 8;
          local_c = local_c + 1;
        } while (local_c < param_1[1]);
      }
      iVar6 = param_1[5];
      while( true ) {
        iVar4 = param_1[5];
        param_1[2] = *(int *)(iVar1 + 0x1c);
        iVar5 = _set_label((int *)(DAT_001e875c + 0x28));
        if (iVar5 == 0) {
          uVar3 = (*(code *)**(undefined4 **)(iVar1 + 0x14))(iVar1,param_2,param_1);
          *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
        }
        else if (param_1[5] == iVar6) {
          if ((_active_u[0x50] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) == 0) {
            *(undefined1 *)(DAT_001e875c + 0x69) = 2;
          }
          else {
            *(undefined1 *)(DAT_001e875c + 0x68) = 4;
          }
        }
        *(int *)(DAT_001e875c + 0x60) = iVar6 - param_1[5];
        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + (iVar4 - param_1[5]);
        if (*(char *)(DAT_001e875c + 0x68) == '\0') break;
        iVar4 = _fspause(*(uint *)(iVar1 + 8) & 0x1000);
        if (iVar4 == 0) {
          return;
        }
      }
      return;
    }
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  return;
}

