/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187108 */

undefined8 __regparm3 __bios32(undefined2 param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 unaff_EBX;
  undefined2 in_ES;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte bVar6;
  byte bVar7;
  byte in_OF;
  byte in_NT;
  undefined8 uVar8;
  undefined2 uStack_12;
  undefined2 uStack_a;
  
  bVar7 = 0;
  uStack_a = (undefined2)((uint)param_3 >> 0x10);
  uStack_12 = (undefined2)((uint)unaff_EBX >> 0x10);
  uRam00187166 = *(undefined2 *)(param_4 + 0x20);
                    /* WARNING: Read-only address (ram,0x00187166) is written */
  uRam00187162 = *(undefined4 *)(param_4 + 0x2c);
                    /* WARNING: Read-only address (ram,0x00187162) is written */
  uVar1 = *(undefined4 *)(param_4 + 8);
  uVar2 = *(undefined4 *)(param_4 + 0x14);
  uVar3 = *(undefined4 *)(param_4 + 0x18);
  uVar4 = *(undefined4 *)(param_4 + 0x1c);
  DAT_001e17c8 = param_4;
  DAT_001e17d0 = *(undefined4 *)(param_4 + 4);
  DAT_001e17d4 = *(undefined4 *)(param_4 + 0x10);
  bVar6 = 0;
  uVar8 = func_0x00000000();
  iVar5 = DAT_001e17c8;
  DAT_001e17d4 = (undefined4)((ulonglong)uVar8 >> 0x20);
  DAT_001e17c4 = (undefined4)uVar8;
  DAT_001e17cc = (ushort)(in_NT & 1) * 0x4000 | (ushort)(in_OF & 1) * 0x800 |
                 (ushort)(bVar7 & 1) * 0x400 | (ushort)(bVar6 & 1) * 0x200 |
                 (ushort)(in_TF & 1) * 0x100 | (ushort)(in_SF & 1) * 0x80 |
                 (ushort)(in_ZF & 1) * 0x40 | (ushort)(in_AF & 1) * 0x10 | (ushort)(in_PF & 1) * 4 |
                 (ushort)(in_CF & 1);
  DAT_001e17c0 = in_ES;
  *(undefined4 *)(DAT_001e17c8 + 0x10) = DAT_001e17d4;
  *(undefined4 *)(iVar5 + 4) = DAT_001e17c4;
  *(undefined2 *)(iVar5 + 0x24) = DAT_001e17c0;
  *(ushort *)(iVar5 + 0x28) = DAT_001e17cc;
  *(undefined4 *)(iVar5 + 8) = uVar1;
  *(undefined4 *)(iVar5 + 0xc) = extraout_ECX;
  *(undefined4 *)(iVar5 + 0x14) = uVar2;
  *(undefined4 *)(iVar5 + 0x18) = uVar3;
  *(undefined4 *)(iVar5 + 0x1c) = uVar4;
  return CONCAT44(CONCAT22(param_2,uStack_12),CONCAT22(param_1,uStack_a));
}

