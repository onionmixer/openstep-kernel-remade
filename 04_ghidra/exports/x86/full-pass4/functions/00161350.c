/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161350 */

void _processor_init(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0x1f;
  *(undefined4 *)(param_1 + 0x108) = 0;
  iVar1 = param_1;
  do {
    *(int *)(iVar1 + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    iVar1 = iVar1 + 8;
  } while (iVar1 <= param_1 + 0xf8);
  *(int *)(param_1 + 0x110) = param_1 + 0x10c;
  *(int *)(param_1 + 0x10c) = param_1 + 0x10c;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(int *)(param_1 + 0x138) = param_1 + 0x134;
  *(int *)(param_1 + 0x134) = param_1 + 0x134;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = param_2;
  return;
}

