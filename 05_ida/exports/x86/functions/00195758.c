/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195758. */
int DoRestore()
{
  int v0; // ebx
  _DWORD *v2; // edx
  int v3; // eax
  int v4; // ecx

  v0 = 0; /*0x19575c*/
  if ( kmAlertConsole ) /*0x195765*/
  {
    (*(void (__stdcall **)(int))(kmAlertConsole + 8))(kmAlertConsole); /*0x19576b*/
    (*(void (__stdcall **)(int))kmAlertConsole)(kmAlertConsole); /*0x195775*/
    kmAlertConsole = 0; /*0x195777*/
    return 0; /*0x195781*/
  }
  else if ( kmId ) /*0x19578f*/
  {
    dword_1E776C(*((_DWORD *)kmId + 66), sel_lock); /*0x1957ab*/
    v2 = kmId; /*0x1957ad*/
    if ( *((_DWORD *)kmId + 69) == 3 ) /*0x1957bd*/
    {
      v3 = *((_DWORD *)kmId + 71); /*0x1957bf*/
      if ( v3 ) /*0x1957c7*/
      {
        *((_DWORD *)kmId + 71) = v3 - 1; /*0x1957d3*/
        if ( v3 == 1 ) /*0x1957dc*/
        {
          v4 = v2[70]; /*0x1957de*/
          v2[69] = v4; /*0x1957e4*/
          if ( v4 == 3 ) /*0x1957ed*/
          {
            IOLog(aKmdeviceRecurs); /*0x195829*/
          }
          else
          {
            v0 = (*(int (__cdecl **)(_DWORD))(v2[68] + 8))(v2[68]); /*0x1957fb*/
            (**((void (***)(void))kmId + 68))(); /*0x19580b*/
            *((_DWORD *)kmId + 68) = 0; /*0x195812*/
          }
        }
      }
      else
      {
        v0 = 16; /*0x1957c9*/
      }
    }
    else
    {
      v0 = 22; /*0x195834*/
    }
    dword_1E7770(*((_DWORD *)kmId + 66), sel_unlock); /*0x195851*/
    return v0; /*0x195853*/
  }
  else
  {
    return 0; /*0x195791*/
  }
}
