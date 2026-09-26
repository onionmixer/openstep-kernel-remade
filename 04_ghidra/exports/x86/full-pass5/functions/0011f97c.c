/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011f97c */

void FUN_0011f97c(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  
  pcVar1 = (char *)_if_type(param_2);
  iVar6 = 0xe;
  iVar2 = 0;
  bVar10 = true;
  pcVar8 = s_10MB_Ethernet_001db81f;
  do {
    pcVar7 = pcVar1;
    pcVar9 = pcVar8;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar9 = pcVar8 + 1;
    pcVar7 = pcVar1 + 1;
    bVar10 = *pcVar1 == *pcVar8;
    pcVar1 = pcVar7;
    pcVar8 = pcVar9;
  } while (bVar10);
  if (!bVar10) {
    iVar2 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar9[-1];
  }
  if (iVar2 == 0) {
    uVar3 = _kalloc(0x10);
    uVar4 = _if_name(param_2);
    uVar5 = _if_unit(param_2);
    uVar3 = _if_attach(0,FUN_0011f704,FUN_0011fa48,FUN_0011fb48,FUN_0011f5a8,uVar4,uVar5,
                       "Internet Protocol",0x5dc,2,0x1000,uVar3);
    iVar2 = _if_private(uVar3);
    *(undefined4 *)(iVar2 + 0xc) = param_2;
    uVar3 = _if_private(uVar3);
    _if_control(param_2,"getaddr",uVar3);
    _printf(s_IP_protocol_enabled_for_interfac_001db83b,uVar4,uVar5,s_10MB_Ethernet_001db82d);
  }
  return;
}

