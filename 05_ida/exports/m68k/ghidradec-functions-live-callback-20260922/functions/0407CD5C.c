
undefined4 sub_407CD5C(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined uStack_56;
  undefined3 uStack_55;
  undefined uStack_52;
  undefined uStack_51;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  if ((*(byte *)((int)param_1 + 0xb) & 2) == 0) {
    uVar3 = 0;
  }
  else {
    _bzero(&uStack_56,0x52);
    _uStack_56 = CONCAT13(0x1b,(int3)(((uint)*(byte *)(*(int *)(*param_1 + 8) + 0x1d) << 0x1d) >> 8)
                         );
    uStack_52 = 2;
    uStack_51 = 0;
    uStack_46 = 0;
    uStack_42 = 0;
    uStack_4a = 0;
    uStack_3e = 0x14;
    uVar3 = sub_407E678(param_1,&uStack_56,0);
    iVar1 = *param_1;
    uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
            0xfffff;
    if ((((uVar2 ^ *_event_middle) & 0x80000) != 0) &&
       (*_event_middle = *_event_middle + 0x80000, (*_event_middle & 0xfff80000) == 0)) {
      *_event_high = *_event_high + 1;
    }
    *(undefined4 *)(iVar1 + 0xba) = *_event_high;
    *(uint *)(iVar1 + 0xb6) = *_event_middle | uVar2;
    *(undefined4 *)*param_1 = 0;
    param_1[2] = param_1[2] & 0xfffffffd;
    *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) | 2;
  }
  return uVar3;
}

