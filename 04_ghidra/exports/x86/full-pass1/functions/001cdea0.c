/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdea0 */

char __regparm3 _NXObjectMapPrototype(char param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  int unaff_EBX;
  
  pbVar1 = (byte *)(unaff_EBX + param_3 * 8);
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 + (byte)unaff_EBX;
  return param_1 - CARRY1(bVar2,(byte)unaff_EBX);
}

