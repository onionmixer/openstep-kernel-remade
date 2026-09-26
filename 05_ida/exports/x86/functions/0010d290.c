/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d290. */
int __cdecl select(int a1, fd_set *a2, fd_set *a3, fd_set *a4, timeval *a5)
{
  _DWORD *v5; // ebx
  unsigned int v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v16; // [esp+Ch] [ebp-10h]
  int *v17; // [esp+10h] [ebp-Ch]
  _DWORD v18[2]; // [esp+14h] [ebp-8h] BYREF

  v5 = (_DWORD *)dword_1E875C; /*0x10d299*/
  v17 = *(int **)(dword_1E875C + 36); /*0x10d2a2*/
  v16 = dword_1E875C + 136; /*0x10d2ab*/
  qmemcpy((void *)(dword_1E875C + 136), &unk_1D10DC, 0xD0u); /*0x10d2bc*/
  if ( *v17 > 256 ) /*0x10d2c7*/
    *v17 = 256; /*0x10d2c9*/
  v6 = (unsigned int)(*v17 + 31) >> 5; /*0x10d2d9*/
  v7 = v17[1]; /*0x10d2dc*/
  if ( !v7 || (v8 = copyin(v7, v16, 4 * v6), (v5[85] = v8) == 0) ) /*0x10d300*/
  {
    v9 = v17[2]; /*0x10d309*/
    if ( !v9 || (v10 = copyin(v9, v5 + 42, 4 * v6), (v5[85] = v10) == 0) ) /*0x10d330*/
    {
      v11 = v17[3]; /*0x10d339*/
      if ( !v11 || (v12 = copyin(v11, v5 + 50, 4 * v6), (v5[85] = v12) == 0) ) /*0x10d360*/
      {
        v13 = v17[4]; /*0x10d365*/
        if ( v13 ) /*0x10d36a*/
        {
          v14 = copyin(v13, v5 + 82, 8); /*0x10d376*/
          v5[85] = v14; /*0x10d37b*/
          if ( !v14 ) /*0x10d386*/
          {
            if ( itimerfix(v5 + 82) ) /*0x10d389*/
            {
              v5[85] = 22; /*0x10d395*/
            }
            else if ( v5[82] || v5[83] ) /*0x10d3ad*/
            {
              getthetime(v18); /*0x10d3c8*/
              timevaladd((_DWORD *)(v16 + 192), v18); /*0x10d3d7*/
            }
            else
            {
              v5[84] = 1; /*0x10d3b6*/
            }
          }
        }
      }
    }
  }
  return selcont(); /*0x10d3e7*/
}
