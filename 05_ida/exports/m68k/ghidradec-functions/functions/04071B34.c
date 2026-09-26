
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _km_try_slot(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint3 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  _bzero(&_km_coni,0x80);
  uVar2 = param_1 << 0x18;
  if ((*(uint *)(uVar2 | 0xf0fffff0) & 0xc0000000) == 0xc0000000) {
    byte_40B6964 = (undefined)param_1;
    byte_40B6965 = (undefined)param_2;
    if ((*(uint *)(uVar2 | 0xf0ffffe0) & 0xff000000) == 0xa5000000) {
      byte_40B6966 = *(char *)(uVar2 | 0xf0ffffd8);
      uVar3 = (uint3)(((uint)*(byte *)(uVar2 | 0xf0ffffb8) << 0x18) >> 8);
      unk_40B6970 = CONCAT31((uint3)*(byte *)(uVar2 | 0xf0ffffc8) |
                             (uint3)(((uint)*(byte *)(uVar2 | 0xf0ffffc0) << 0x10) >> 8) | uVar3,
                             *(undefined *)(uVar2 | 0xf0ffffd0));
      if (uVar3 != 0xf00000) {
        uVar2 = param_1 << 0x1c;
      }
      dword_40B6974 = unk_40B6970 | uVar2;
      if (uVar3 == 0xf00000) {
        iVar7 = 0x18;
      }
      else {
        iVar7 = 0x1c;
      }
      unk_40B6970 = param_1 << iVar7 | unk_40B6970;
      unk_40B6978._0_4_ = sub_4071A12(0);
      unk_40B6978._0_4_ = byte_40B6966 * 4 * unk_40B6978._0_4_;
      iVar7 = sub_4071A12(1);
      if ((param_2 < iVar7) && (-1 < param_2)) {
        param_2 = param_2 * 5;
        dword_40B6968 = sub_4071A12(param_2 + 4);
        dword_40B696C = sub_4071A12(param_2 + 5);
        iVar4 = sub_4071A12(param_2 + 6);
        _km_coni = sub_4071A12(iVar4);
        dword_40B6940 = sub_4071A12(iVar4 + 1);
        dword_40B6944 = sub_4071A12(iVar4 + 2);
        dword_40B6948 = sub_4071A12(iVar4 + 3);
        _unk_40B694C = sub_4071A12(iVar4 + 4);
        _unk_40B6950 = sub_4071A12(iVar4 + 5);
        dword_40B6954 = sub_4071A12(iVar4 + 6);
        dword_40B6958 = sub_4071A12(iVar4 + 7);
        dword_40B695C = sub_4071A12(iVar4 + 8);
        iVar7 = iVar4 + 10;
        dword_40B6960 = sub_4071A12(iVar4 + 9);
        iVar4 = 1;
        iVar8 = 0xc;
        do {
          iVar1 = iVar7 + 1;
          uVar5 = sub_4071A12(iVar7);
          uVar2 = param_1 << 0x1c;
          if ((uVar5 & 0xff000000) == 0xf0000000) {
            uVar2 = param_1 << 0x18;
          }
          *(uint *)((int)&unk_40B6970 + iVar8) = uVar2 | uVar5;
          uVar2 = param_1 << 0x1c;
          if ((uVar5 & 0xff000000) == 0xf0000000) {
            uVar2 = param_1 << 0x18;
          }
          *(uint *)((int)&dword_40B6974 + iVar8) = uVar2 | uVar5;
          iVar7 = iVar7 + 2;
          uVar6 = sub_4071A12(iVar1);
          *(undefined4 *)((int)&unk_40B6978 + iVar8) = uVar6;
          iVar8 = iVar8 + 0xc;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 6);
        _unk_40B6950 = _unk_40B6950 | 1;
        return 1;
      }
    }
  }
  return 0;
}
