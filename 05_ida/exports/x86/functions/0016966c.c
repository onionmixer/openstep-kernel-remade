/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16966c. */
int __cdecl calloutRemoveAll(int a1, int a2)
{
  int *v2; // edx
  int *v3; // ecx
  int *v4; // edx
  int *v5; // ecx
  int v7; // [esp+Ch] [ebp-4h]

  v7 = splsched(); /*0x169680*/
  do /*0x16969d*/
  {
    while ( dword_1E7244 ) /*0x16968b*/
      ; /*0x169689*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x16969d*/
  v2 = (int *)dword_1E7250; /*0x16969f*/
  while ( v2 != &dword_1E7250 ) /*0x1696ab*/
  {
    if ( v2[2] == a1 && v2[3] == a2 ) /*0x1696b5*/
    {
      v3 = (int *)*v2; /*0x1696b7*/
      *(_DWORD *)(*v2 + 4) = v2[1]; /*0x1696bc*/
      *(_DWORD *)v2[1] = *v2; /*0x1696c4*/
      --dword_1E7260; /*0x1696c6*/
      v2[7] = 0; /*0x1696cc*/
      if ( v2 >= &dword_1E6A44 && v2 < &dword_1E7244 ) /*0x1696e1*/
      {
        *v2 = (int)&dword_1E7248; /*0x1696e3*/
        v2[1] = dword_1E724C; /*0x1696ef*/
        *(_DWORD *)v2[1] = v2; /*0x1696f5*/
        dword_1E724C = (int)v2; /*0x1696f7*/
      }
      v2 = v3; /*0x1696fd*/
    }
    else
    {
      v2 = (int *)*v2; /*0x169704*/
    }
  }
  v4 = (int *)dword_1E7258; /*0x169708*/
  while ( v4 != &dword_1E7258 ) /*0x169714*/
  {
    if ( v4[2] == a1 && v4[3] == a2 ) /*0x16971e*/
    {
      v5 = (int *)*v4; /*0x169720*/
      *(_DWORD *)(*v4 + 4) = v4[1]; /*0x169725*/
      *(_DWORD *)v4[1] = *v4; /*0x16972d*/
      v4[7] = 0; /*0x16972f*/
      if ( v4 >= &dword_1E6A44 && v4 < &dword_1E7244 ) /*0x169744*/
      {
        *v4 = (int)&dword_1E7248; /*0x169746*/
        v4[1] = dword_1E724C; /*0x169752*/
        *(_DWORD *)v4[1] = v4; /*0x169758*/
        dword_1E724C = (int)v4; /*0x16975a*/
      }
      v4 = v5; /*0x169760*/
    }
    else
    {
      v4 = (int *)*v4; /*0x169764*/
    }
  }
  _InterlockedExchange(&dword_1E7244, 0); /*0x16976a*/
  return splx(v7); /*0x16977c*/
}
