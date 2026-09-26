/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c5604 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001c5604(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint local_3c;
  uint local_38;
  int local_28;
  short local_24;
  short local_20;
  short local_1c;
  short local_18;
  uint local_14;
  uint local_10;
  
  local_10 = 0;
  local_14 = 0;
  uVar2 = *(undefined4 *)(param_4 + 0x30);
  uVar3 = *(undefined4 *)(param_4 + 0x34);
  iVar4 = *(int *)(param_4 + 0xc);
  iVar5 = *(int *)(param_4 + 0x10);
  _objc_msgSend(param_1,PTR_s_savePlaneAndSegmentSettings_001f95cc);
  local_24 = (short)iVar4;
  local_1c = (short)uVar2;
  iVar9 = (int)local_24 - (int)local_1c >> 4;
  iVar7 = *param_3 >> 4;
  local_20 = (short)iVar5;
  local_18 = (short)uVar3;
  uVar10 = (int)local_20 - (int)local_18;
  uVar8 = (uint)(0x10000 / (longlong)(*param_3 >> 3));
  local_38 = uVar10 / uVar8;
  local_28 = iVar9 * 2 + 0xa0000 + iVar7 * (uVar10 % uVar8) * 2;
  local_3c = (local_38 + 1) * uVar8;
  _objc_msgSend(param_1,PTR_s_setWriteSegment__001f95c8,local_38 & 0xff);
  _objc_msgSend(param_1,PTR_s_setReadSegment__001f95c4,local_38 & 0xff);
  uVar1 = *(ushort *)(param_4 + 0x20);
  puVar11 = (uint *)(param_4 + 0x248);
  if (local_1c <= local_24) {
    local_10 = *(uint *)(&DAT_001e53d8 + ((int)*(short *)(param_4 + 0x28) - (int)local_24) * 4);
  }
  bVar6 = (short)((uint)iVar4 >> 0x10) <= (short)((uint)uVar2 >> 0x10);
  if (bVar6) {
    local_14 = ~*(uint *)(&DAT_001e53d8 +
                         (0x10 - ((iVar4 >> 0x10) - (int)*(short *)(param_4 + 0x2a))) * 4);
  }
  for (; (int)uVar10 < (iVar5 >> 0x10) - (int)local_18; uVar10 = uVar10 + 1) {
    if (local_3c == uVar10) {
      local_28 = (uVar10 % uVar8) * iVar7 * 2 + 0xa0000 + iVar9 * 2;
      local_38 = local_38 + 1;
      local_3c = uVar8 + uVar10;
      _objc_msgSend(param_1,PTR_s_setWriteSegment__001f95c8,local_38 & 0xff);
      _objc_msgSend(param_1,PTR_s_setReadSegment__001f95c4,local_38 & 0xff);
    }
    if (local_1c <= local_24) {
      _objc_msgSend(param_1,PTR_s__readBpp4planar_toBpp2packed32__001f95c0,local_28,&DAT_001e8734);
      _DAT_001e8734 = ~local_10 & _DAT_001e8734 | local_10 & *puVar11;
      puVar11 = puVar11 + 1;
      _objc_msgSend(param_1,PTR_s__writeBpp2packed32_toBpp4planar__001f95bc,&DAT_001e8734,local_28);
    }
    if (bVar6) {
      if ((uVar1 & 0xf) == 0) {
        puVar11 = puVar11 + 1;
      }
      else {
        _objc_msgSend(param_1,PTR_s__readBpp4planar_toBpp2packed32__001f95c0,local_28 + 2,
                      &DAT_001e8738);
        _DAT_001e8738 = ~local_14 & _DAT_001e8738 | local_14 & *puVar11;
        puVar11 = puVar11 + 1;
        _objc_msgSend(param_1,PTR_s__writeBpp2packed32_toBpp4planar__001f95bc,&DAT_001e8738,
                      local_28 + 2);
      }
    }
    local_28 = local_28 + iVar7 * 2;
  }
  _objc_msgSend(param_1,PTR_s_restorePlaneAndSegmentSettings_001f95b8);
  return;
}

