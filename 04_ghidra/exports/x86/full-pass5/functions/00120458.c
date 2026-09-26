/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120458 */

void FUN_00120458(int *param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined4 uVar9;
  uint *puVar10;
  int iVar11;
  byte bVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  bool bVar16;
  
  pcVar1 = (char *)_if_type(param_2);
  iVar11 = 0x12;
  iVar2 = 0;
  bVar16 = true;
  pcVar14 = s_4_16Mb_Token_Ring_001db8a8;
  do {
    pcVar13 = pcVar1;
    pcVar15 = pcVar14;
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    pcVar15 = pcVar14 + 1;
    pcVar13 = pcVar1 + 1;
    bVar16 = *pcVar1 == *pcVar14;
    pcVar1 = pcVar13;
    pcVar14 = pcVar15;
  } while (bVar16);
  if (!bVar16) {
    iVar2 = (uint)(byte)pcVar13[-1] - (uint)(byte)pcVar15[-1];
  }
  if (iVar2 == 0) {
    iVar2 = _if_unit(param_2);
    if (*param_1 == iVar2) {
      uVar3 = _if_name(param_2);
      iVar4 = _if_mtu(param_2);
      iVar11 = param_1[2];
      if (param_1[2] == 0) {
        iVar11 = DAT_001db8a4;
      }
      if (iVar4 + -8 < iVar11) {
        iVar11 = iVar4 + -8;
      }
      uVar5 = _kalloc(0x20);
      uVar6 = _if_attach(0,FUN_0011fddc,FUN_0011fbdc,FUN_0012075c,FUN_00120648,uVar3,iVar2,
                         "Internet Protocol",iVar11,2,0x1000,uVar5 & 0xfffffffc);
      puVar7 = (undefined4 *)_if_private(uVar6);
      *puVar7 = 0;
      if ((*(byte *)(param_1 + 1) & 1) == 0) {
        puVar10 = (uint *)_if_private(uVar6);
        *puVar10 = *puVar10 & 0xfffffffe;
      }
      else {
        pbVar8 = (byte *)_if_private(uVar6);
        *pbVar8 = *pbVar8 | 1;
        iVar11 = _if_private(uVar6);
        uVar9 = _NXCreateHashTable(_SRHash,_SRIsEqual,_NXNoEffectFree,0,0,0);
        *(undefined4 *)(iVar11 + 4) = uVar9;
      }
      if (param_1[3] < 8) {
        bVar12 = (byte)param_1[3];
        if (6 < bVar12) {
          bVar12 = 6;
        }
        iVar11 = _if_private(uVar6);
        *(byte *)(iVar11 + 0x18) = bVar12 << 5 | 0x10;
      }
      else {
        iVar11 = _if_private(uVar6);
        *(undefined1 *)(iVar11 + 0x18) = 0x10;
      }
      iVar11 = _if_private(uVar6);
      *(undefined4 *)(iVar11 + 0x14) = param_2;
      iVar11 = _if_private(uVar6);
      _if_control(param_2,"getaddr",iVar11 + 8);
      _printf(s_IP_protocol_enabled_for_interfac_001db8ba,uVar3,iVar2);
      _printf(s_IEEE_802_2_Null_Sap_protocol_ena_001db8e2,uVar3,iVar2);
    }
  }
  return;
}

