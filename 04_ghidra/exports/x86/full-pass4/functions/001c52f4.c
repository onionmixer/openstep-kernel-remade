/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c52f4 */

void FUN_001c52f4(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  sbyte sVar8;
  byte bVar9;
  uint uVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  uint local_3c;
  uint local_38;
  uint *local_14;
  short local_c;
  short local_8;
  
  iVar2 = param_4[0xc];
  iVar5 = param_4[0xd];
  _objc_msgSend(param_1,PTR_s_savePlaneAndSegmentSettings_001f95cc);
  uVar13 = param_4[9];
  local_8 = (short)iVar5;
  if ((short)uVar13 < local_8) {
    uVar13 = CONCAT22((short)(uVar13 >> 0x10),local_8);
  }
  if ((short)((uint)iVar5 >> 0x10) < (short)(uVar13 >> 0x10)) {
    uVar13 = uVar13 & 0xffff | (iVar5 >> 0x10) << 0x10;
  }
  local_c = (short)iVar2;
  sVar11 = ((short)param_4[8] - local_c & 0xfff0U) + local_c;
  param_4[3] = CONCAT22(sVar11 + 0x20,sVar11);
  param_4[4] = uVar13;
  uVar1 = *(ushort *)(param_4 + 8);
  bVar9 = (byte)uVar1 & 0xf;
  sVar8 = bVar9 * '\x02';
  bVar9 = bVar9 * -2 + 0x20;
  local_14 = (uint *)(param_4 + 0x92);
  iVar5 = (int)(short)uVar13 - (int)(short)param_4[9];
  puVar3 = (uint *)(param_4 + *param_4 * 0x10 + iVar5 + 0x12);
  puVar4 = (uint *)(param_4 + *param_4 * 0x10 + iVar5 + 0x52);
  iVar12 = (int)sVar11 - (int)local_c >> 4;
  iVar6 = *param_3 >> 4;
  uVar7 = (uint)(0x10000 / (longlong)(*param_3 >> 3));
  uVar10 = (int)(short)uVar13 - (int)local_8;
  local_38 = uVar10 / uVar7;
  iVar5 = iVar12 * 2 + 0xa0000 + (uVar10 % uVar7) * iVar6 * 2;
  local_3c = (local_38 + 1) * uVar7;
  _objc_msgSend(param_1,PTR_s_setWriteSegment__001f95c8,local_38 & 0xff);
  _objc_msgSend(param_1,PTR_s_setReadSegment__001f95c4,local_38 & 0xff);
  for (; (int)uVar10 < ((int)uVar13 >> 0x10) - (int)local_8; uVar10 = uVar10 + 1) {
    if (local_3c == uVar10) {
      iVar5 = (uVar10 % uVar7) * iVar6 * 2 + 0xa0000 + iVar12 * 2;
      local_38 = local_38 + 1;
      local_3c = uVar7 + uVar10;
      _objc_msgSend(param_1,PTR_s_setWriteSegment__001f95c8,local_38 & 0xff);
      _objc_msgSend(param_1,PTR_s_setReadSegment__001f95c4,local_38 & 0xff);
    }
    if (local_c <= sVar11) {
      _objc_msgSend(param_1,PTR_s__readBpp4planar_toBpp2packed32__001f95c0,iVar5,&DAT_001e872c);
      *local_14 = DAT_001e872c;
      local_14 = local_14 + 1;
      DAT_001e872c = ~(*puVar4 << sVar8) & DAT_001e872c | *puVar3 << sVar8;
      _objc_msgSend(param_1,PTR_s__writeBpp2packed32_toBpp4planar__001f95bc,&DAT_001e872c,iVar5);
    }
    if ((short)(sVar11 + 0x20) <= (short)((uint)iVar2 >> 0x10)) {
      if ((uVar1 & 0xf) == 0) {
        local_14 = local_14 + 1;
      }
      else {
        _objc_msgSend(param_1,PTR_s__readBpp4planar_toBpp2packed32__001f95c0,iVar5 + 2,&DAT_001e8730
                     );
        *local_14 = DAT_001e8730;
        local_14 = local_14 + 1;
        DAT_001e8730 = ~(*puVar4 >> (bVar9 & 0x1f)) & DAT_001e8730 | *puVar3 >> (bVar9 & 0x1f);
        _objc_msgSend(param_1,PTR_s__writeBpp2packed32_toBpp4planar__001f95bc,&DAT_001e8730,
                      iVar5 + 2);
      }
    }
    iVar5 = iVar5 + iVar6 * 2;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  _objc_msgSend(param_1,PTR_s_restorePlaneAndSegmentSettings_001f95b8);
  return;
}

