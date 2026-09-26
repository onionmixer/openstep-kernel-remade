
/* WARNING: Control flow encountered unimplemented instructions */

void __switch_context0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  restoreFPUStateFrame(param_2[0x17]);
  if (_cpu_type != '\0') {
    *param_2 = param_3;
                    /* WARNING: Could not recover jumptable at 0x04001a88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)param_2[9])();
    return;
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
