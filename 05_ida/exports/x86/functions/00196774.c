/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196774. */
int __cdecl -[kmDevice restore](kmDevice *self, SEL a2)
{
  int v2; // ebx
  _DWORD *v4; // edx
  int v5; // eax
  int v6; // ecx

  v2 = 0; /*0x196778*/
  if ( kmAlertConsole ) /*0x196781*/
  {
    (*(void (__stdcall **)(int))(kmAlertConsole + 8))(kmAlertConsole); /*0x196787*/
    (*(void (__stdcall **)(int))kmAlertConsole)(kmAlertConsole); /*0x196791*/
    kmAlertConsole = 0; /*0x196793*/
    return 0; /*0x19679d*/
  }
  else if ( kmId ) /*0x1967ab*/
  {
    dword_1E776C(*((_DWORD *)kmId + 66), sel_lock); /*0x1967c7*/
    v4 = kmId; /*0x1967c9*/
    if ( *((_DWORD *)kmId + 69) == 3 ) /*0x1967d9*/
    {
      v5 = *((_DWORD *)kmId + 71); /*0x1967db*/
      if ( v5 ) /*0x1967e3*/
      {
        *((_DWORD *)kmId + 71) = v5 - 1; /*0x1967ef*/
        if ( v5 == 1 ) /*0x1967f8*/
        {
          v6 = v4[70]; /*0x1967fa*/
          v4[69] = v6; /*0x196800*/
          if ( v6 == 3 ) /*0x196809*/
          {
            IOLog(aKmdeviceRecurs); /*0x196845*/
          }
          else
          {
            v2 = (*(int (__cdecl **)(_DWORD))(v4[68] + 8))(v4[68]); /*0x196817*/
            (**((void (***)(void))kmId + 68))(); /*0x196827*/
            *((_DWORD *)kmId + 68) = 0; /*0x19682e*/
          }
        }
      }
      else
      {
        v2 = 16; /*0x1967e5*/
      }
    }
    else
    {
      v2 = 22; /*0x196850*/
    }
    dword_1E7770(*((_DWORD *)kmId + 66), sel_unlock); /*0x19686d*/
    return v2; /*0x19686f*/
  }
  else
  {
    return 0; /*0x1967ad*/
  }
}
