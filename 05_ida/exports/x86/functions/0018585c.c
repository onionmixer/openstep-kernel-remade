/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18585c. */
int __cdecl sub_18585C(int a1)
{
  int result; // eax
  _DWORD *v2; // ebx
  _UNKNOWN **v3; // esi
  void (__cdecl *v4)(_DWORD, _DWORD, _DWORD); // eax
  _UNKNOWN **v5; // edx
  _UNKNOWN **v6; // eax

  result = *(_DWORD *)(a1 + 28); /*0x185864*/
  if ( dword_1E13EC == result ) /*0x18586d*/
  {
    dword_1E13EC = 0; /*0x18586f*/
  }
  else if ( panel_req_port == result ) /*0x185882*/
  {
    v2 = off_1E1404; /*0x185884*/
    if ( off_1E1404 != (_UNKNOWN *)&off_1E1404 ) /*0x185890*/
    {
      do /*0x1858e9*/
      {
        v3 = (_UNKNOWN **)*v2; /*0x185894*/
        v4 = (void (__cdecl *)(_DWORD, _DWORD, _DWORD))v2[3]; /*0x185896*/
        if ( v4 ) /*0x18589b*/
          v4(v2[4], v2[2], 0); /*0x1858a7*/
        v5 = (_UNKNOWN **)*v2; /*0x1858ac*/
        v6 = (_UNKNOWN **)v2[1]; /*0x1858ae*/
        if ( (_UNKNOWN **)*v2 == &off_1E1404 ) /*0x1858b7*/
          off_1E1408 = (_UNKNOWN **)v2[1]; /*0x1858b9*/
        else
          v5[1] = v6; /*0x1858c0*/
        if ( v6 == &off_1E1404 ) /*0x1858c8*/
          off_1E1404 = v5; /*0x1858ca*/
        else
          *v6 = v5; /*0x1858d4*/
        result = kfree((int)v2, 0x14u); /*0x1858d9*/
        v2 = v3; /*0x1858de*/
      }
      while ( v3 != &off_1E1404 ); /*0x1858e9*/
    }
    panel_req_port = 0; /*0x1858eb*/
  }
  return result; /*0x1858f8*/
}
