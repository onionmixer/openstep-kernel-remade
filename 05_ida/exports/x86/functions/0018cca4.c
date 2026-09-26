/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cca4. */
int __cdecl mini_mon(const char *a1, int a2, int *a3)
{
  bool v3; // zf
  int v4; // ebx
  int v5; // ebx
  int v7; // [esp+0h] [ebp-14h]
  _BOOL4 v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  v9 = splhigh(); /*0x18ccb2*/
  v8 = strcmp(a1, aRestart) == 0; /*0x18cccf*/
  v3 = strcmp(a1, aPanic_0) == 0; /*0x18cce2*/
  v4 = v3; /*0x18cce7*/
  if ( v3 ) /*0x18ccec*/
    a3 = &savedregs; /*0x18ccee*/
  if ( v8 ) /*0x18ccfa*/
  {
    DoAlert(a2, aRestartOrHaltT); /*0x18cd05*/
    v8 = 1; /*0x18cd0a*/
  }
  else
  {
    DoAlert(a2, &unk_1E22D6); /*0x18cd1d*/
  }
  if ( v4 ) /*0x18cd27*/
    kmdumplog(); /*0x18cd29*/
  if ( v8 ) /*0x18cd32*/
  {
    do /*0x18cda7*/
    {
      v5 = kmtrygetc(); /*0x18cd39*/
      if ( v5 == 114 ) /*0x18cd3e*/
      {
        if ( kernel_task ) /*0x18cd47*/
        {
          reboot_how = 0; /*0x18cd49*/
          calloutDispatch((int)halt_thread, 0); /*0x18cd5a*/
        }
        else
        {
          boot(1, 4, v7); /*0x18cd68*/
        }
      }
      if ( v5 == 104 ) /*0x18cd73*/
      {
        if ( kernel_task ) /*0x18cd7c*/
        {
          reboot_how = 8; /*0x18cd7e*/
          calloutDispatch((int)halt_thread, 0); /*0x18cd8f*/
        }
        else
        {
          boot(1, 12, v7); /*0x18cd9c*/
        }
      }
    }
    while ( v5 == -1 ); /*0x18cda7*/
  }
  else
  {
    do /*0x18cdbf*/
      miniMonLoop((int)a1, v4, (int)a3); /*0x18cdb5*/
    while ( v4 ); /*0x18cdbf*/
  }
  if ( !nmi_stay ) /*0x18cdcc*/
    DoRestore(); /*0x18cdce*/
  nmi_stay = 0; /*0x18cdd3*/
  return splx(v9); /*0x18cde9*/
}
