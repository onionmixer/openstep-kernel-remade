/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125ca4 */

void _icmp_send(byte *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  
  uVar3 = (uint)param_1 & 0xffffff80;
  uVar2 = *param_1 & 0xf;
  *(uint *)(uVar3 + 4) = *(int *)(uVar3 + 4) + uVar2 * 4;
  sVar5 = (short)(uVar2 * 4);
  *(short *)(uVar3 + 8) = *(short *)(uVar3 + 8) - sVar5;
  iVar4 = *(int *)(uVar3 + 4) + uVar3;
  *(undefined2 *)(iVar4 + 2) = 0;
  uVar1 = _in_cksum(uVar3,(int)*(short *)(param_1 + 2) + uVar2 * -4);
  *(undefined2 *)(iVar4 + 2) = uVar1;
  *(uint *)(uVar3 + 4) = *(int *)(uVar3 + 4) + uVar2 * -4;
  *(short *)(uVar3 + 8) = *(short *)(uVar3 + 8) + sVar5;
  _ip_output(uVar3,param_2,0,0,0);
  return;
}

