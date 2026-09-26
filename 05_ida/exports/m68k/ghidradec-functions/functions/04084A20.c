
byte _snd_link_resume(uint param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  
  if (param_1 == dword_40B511A) {
    bVar8 = &unk_40B50D0 < unk_40B50D0;
    bVar7 = SBORROW4(0x40b50d0,(int)unk_40B50D0);
    bVar4 = (int)&unk_40B50D0 - (int)unk_40B50D0 < 0;
    bVar5 = (undefined4 **)unk_40B50D0 == &unk_40B50D0;
    if (!bVar5) {
      do {
        puVar3 = unk_40B50D0;
        unk_40B50D0 = (undefined4 *)unk_40B50D0[0xb];
        if ((undefined4 **)unk_40B50D0 == &unk_40B50D0) {
          dword_40B50D4 = &unk_40B50D0;
        }
        else {
          unk_40B50D0[0xc] = &unk_40B50D0;
        }
        (**(code **)(param_1 + 0x3a))(puVar3,1,0);
      } while ((undefined4 **)unk_40B50D0 != &unk_40B50D0);
      bVar8 = false;
      bVar7 = false;
      bVar5 = true;
      bVar4 = false;
    }
  }
  else {
    bVar8 = param_1 < dword_40B5158;
    bVar7 = SBORROW4(param_1,dword_40B5158);
    bVar4 = (int)(param_1 - dword_40B5158) < 0;
    bVar5 = false;
    if (param_1 == dword_40B5158) {
      bVar8 = &unk_40B50D8 < unk_40B50D8._0_4_;
      iVar1 = (int)&unk_40B50D8 - (int)unk_40B50D8._0_4_;
      bVar6 = unk_40B50D8._0_4_ == &unk_40B50D8;
      puVar2 = unk_40B50D8._0_4_;
      while( true ) {
        bVar4 = iVar1 < 0;
        bVar7 = SBORROW4(0x40b50d8,(int)puVar2);
        bVar5 = true;
        unk_40B50D8._0_4_ = puVar2;
        if (bVar6) break;
        unk_40B50D8._0_4_ = *(undefined8 **)((int)puVar2 + 0x2c);
        if (unk_40B50D8._0_4_ == &unk_40B50D8) {
          unk_40B50D8._4_4_ = &unk_40B50D8;
        }
        else {
          *(undefined8 **)(unk_40B50D8._0_4_ + 6) = &unk_40B50D8;
        }
        (**(code **)(param_1 + 0x3a))(puVar2,0,0);
        bVar8 = &unk_40B50D8 < unk_40B50D8._0_4_;
        iVar1 = (int)&unk_40B50D8 - (int)unk_40B50D8._0_4_;
        bVar6 = unk_40B50D8._0_4_ == &unk_40B50D8;
        puVar2 = unk_40B50D8._0_4_;
      }
    }
  }
  return bVar8 << 4 | bVar4 << 3 | bVar5 << 2 | bVar7 << 1 | bVar8;
}
