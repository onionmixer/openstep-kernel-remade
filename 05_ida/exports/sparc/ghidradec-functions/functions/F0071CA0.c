
/* WARNING: Removing unreachable block (ram,0xf0071d6c) */
/* WARNING: Removing unreachable block (ram,0xf0071cbc) */

undefined8 _thread_setrun(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (*(int *)(param_1 + 0x70) != _sched_tick) {
    _update_priority(param_1);
  }
  uVar1 = unk_F01350CC._0_4_;
  if ((int)DAT_f01350d4._0_4_ < 1) {
    if (*(int *)(param_1 + 0x194) == 0) {
      puVar4 = _default_pset;
    }
    else {
      _need_ast = _need_ast | 4;
      puVar4 = _master_processor;
    }
    _run_queue_enqueue(puVar4,param_1);
    if ((param_2 != 0) && (*(int *)(_active_threads + 0x58) < *(int *)(param_1 + 0x58))) {
      *(undefined4 *)(_processor_ptr + 0x124) = 0;
      _need_ast = _need_ast | 4;
    }
  }
  else {
    puVar4 = *(undefined **)(unk_F01350CC._0_4_ + 0x10c);
    puVar3 = *(undefined **)(unk_F01350CC._0_4_ + 0x110);
    puVar2 = puVar3;
    if (puVar4 != unk_F01350CC) {
      *(undefined **)(puVar4 + 0x110) = puVar3;
      puVar2 = (undefined *)unk_F01350CC._4_4_;
    }
    unk_F01350CC._4_4_ = puVar2;
    if (puVar3 != unk_F01350CC) {
      *(undefined **)(puVar3 + 0x10c) = puVar4;
      puVar4 = (undefined *)unk_F01350CC._0_4_;
    }
    unk_F01350CC._0_4_ = puVar4;
    DAT_f01350d4._0_4_ = DAT_f01350d4._0_4_ + -1;
    *(int *)(uVar1 + 0x118) = param_1;
    *(undefined4 *)(uVar1 + 0x114) = 3;
  }
  return CONCAT44(param_2,param_1);
}
