/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160bd4. */
void power_init()
{
  int v0; // ebx
  __int64 v1; // rax
  int v2; // [esp+4h] [ebp-4h] BYREF

  if ( !dword_1DF224 ) /*0x160be2*/
  {
    if ( !PMConnect() ) /*0x160be8*/
    {
      if ( !PMGetPowerEvent(&v2) ) /*0x160bfb*/
      {
        switch ( v2 ) /*0x160c18*/
        {
          case 1: /*0x160c18*/
          case 9: /*0x160c18*/
            dword_1E5E4C = 1; /*0x160c4c*/
            PMSetPowerState(1, 1); /*0x160c5a*/
            break; /*0x160c62*/
          case 2: /*0x160c18*/
          case 8: /*0x160c18*/
          case 10: /*0x160c18*/
            dword_1E5E4C = 2; /*0x160c64*/
            PMSetPowerState(1, 2); /*0x160c72*/
            dword_1E5E4C = 0; /*0x160c77*/
            PMSetPowerState(1, 0); /*0x160c85*/
            break; /*0x160c8d*/
          case 3: /*0x160c18*/
          case 4: /*0x160c18*/
          case 11: /*0x160c18*/
            if ( dword_1E5E4C ) /*0x160c97*/
            {
              dword_1E5E4C = 0; /*0x160c99*/
              PMSetPowerState(1, 0); /*0x160ca7*/
            }
            goto LABEL_9; /*0x160ca7*/
          case 7: /*0x160c18*/
LABEL_9:
            PMUpdateClock(); /*0x160caf*/
            break; /*0x160caf*/
          default:
            break;
        }
      }
      v0 = calloutEntryAllocate(power_callout, 0); /*0x160cb8*/
      v1 = calloutDeadlineFromInterval(1010000000, 0); /*0x160cd0*/
      calloutEntryDispatchDelayed(v0, v1, HIDWORD(v1)); /*0x160cd8*/
    }
    dword_1E5E4C = 0; /*0x160cdd*/
    dword_1DF224 = 1; /*0x160ce7*/
  }
}
