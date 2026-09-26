/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00144280 */

undefined4 FUN_00144280(int *param_1,undefined4 *param_2)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = param_1[0xc];
  if ((*(ushort *)(iVar1 + 0x44) & 0x46) != 0) {
    *(ushort *)(iVar1 + 0x44) = *(ushort *)(iVar1 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(iVar1 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar1 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(iVar1 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar1 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(iVar1 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(iVar1 + 0x4c) = 0;
      *(undefined4 *)(iVar1 + 0x84) = _iuniqtime;
    }
    *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xb9;
  }
  *param_2 = *(undefined4 *)(&_iftovt_tab + (uint)(*(ushort *)(iVar1 + 100) >> 0xd) * 4);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)(iVar1 + 100);
  *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(iVar1 + 0x68);
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)(iVar1 + 0x6a);
  param_2[3] = (int)*(short *)(iVar1 + 0x46);
  param_2[4] = *(undefined4 *)(iVar1 + 0x48);
  *(undefined2 *)(param_2 + 5) = *(undefined2 *)(iVar1 + 0x66);
  if (param_1[10] == 1) {
    param_2[6] = *(undefined4 *)(*param_1 + 0x14);
  }
  else {
    param_2[6] = *(undefined4 *)(iVar1 + 0x6c);
  }
  param_2[8] = *(undefined4 *)(iVar1 + 0x74);
  param_2[9] = 0;
  param_2[10] = *(undefined4 *)(iVar1 + 0x7c);
  param_2[0xb] = 0;
  param_2[0xc] = *(undefined4 *)(iVar1 + 0x84);
  param_2[0xd] = 0;
  *(undefined2 *)(param_2 + 0xe) = *(undefined2 *)(iVar1 + 0x8c);
  iVar3 = (**(code **)(param_1[7] + 0x80))(param_1);
  param_2[0xf] = (uint)(iVar3 * *(int *)(iVar1 + 0xcc)) >> 9;
  uVar2 = *(ushort *)(iVar1 + 100) & 0xf000;
  if (uVar2 == 0x2000) {
    param_2[7] = 0x2000;
  }
  else {
    if (uVar2 == 0x6000) {
      uVar4 = (**(code **)(param_1[7] + 0x80))(param_1);
    }
    else {
      uVar4 = *(undefined4 *)(param_1[9] + 0x10);
    }
    param_2[7] = uVar4;
  }
  return 0;
}

